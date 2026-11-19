#ifndef COURSE_WORK_QUEUE_HPP
#define COURSE_WORK_QUEUE_HPP

#include <condition_variable>
#include <deque>
#include <mutex>
#include <stdexcept>
#include <thread>

class WorkQueue {
public:
    void push(int value) {
        {
            std::lock_guard<std::mutex> lock{mutex_};

            if (closed_) {
                throw std::logic_error{"Queue is closed"};
            }

            values_.push_back(value);
        }

        changed_.notify_one();
    }

    bool pop(int& value) {
        std::unique_lock<std::mutex> lock{mutex_};

        changed_.wait(lock, [this] {
            return closed_ || !values_.empty();
        });

        if (values_.empty()) {
            return false;
        }

        value = values_.front();
        values_.pop_front();

        return true;
    }

    void close() {
        {
            std::lock_guard<std::mutex> lock{mutex_};
            closed_ = true;
        }

        changed_.notify_all();
    }

private:
    std::deque<int> values_;
    std::mutex mutex_;
    std::condition_variable changed_;
    bool closed_{};
};

// Declare immediately after starting a consumer.
class CloseQueueAndJoin {
public:
    CloseQueueAndJoin(WorkQueue& queue, std::thread& consumer) noexcept
        : queue_{queue}, consumer_{consumer} {
    }

    ~CloseQueueAndJoin() {
        queue_.close();
        consumer_.join();
    }

    CloseQueueAndJoin(const CloseQueueAndJoin&) = delete;
    CloseQueueAndJoin& operator=(const CloseQueueAndJoin&) = delete;

private:
    WorkQueue& queue_;
    std::thread& consumer_;
};

#endif
