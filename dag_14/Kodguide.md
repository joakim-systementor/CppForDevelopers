# Kodguide dag 14

Mutex, låsning och tillståndsvariabler. Grundexemplen utgår från C++17. Hela projektet byggs med C++23. Varje numrerad cpp-fil har egen main/körfil. Förutsäg före körning. Övningar.md finns i samma mapp; main.cpp är lösningsförslag till sista uppgiften efter eget försök.

## Exempel och förväntningar

| Fil | Delmoment | Prova eller förvänta |
|---|---|---|
| [01_mutex.cpp](01_mutex.cpp) | Delad räknare | 4000 |
| [02_unique_lock.cpp](02_unique_lock.cpp) | Flexibelt lås | false; true; false |
| [03_scoped_lock.cpp](03_scoped_lock.cpp) | Två lås | 100 100 |
| [04_condition.cpp](04_condition.cpp) | Vänta på ready | 42 |
| [05_queue.cpp](05_queue.cpp) | Kö/close | 6 |
| [tests.cpp](tests.cpp) | Sekventiellt kökontrakt | Status 0, ingen felutskrift |
| [main.cpp](main.cpp) | Två konsumenter | Items: 6; Total: 21 |
| [06_latch.cpp](06_latch.cpp) | Extra C++20: Valbar samordning | 30 |
| [07_counting_semaphore.cpp](07_counting_semaphore.cpp) | Extra C++20: Två tillstånd för tre arbetare | 10 20 30 |
| [08_binary_semaphore.cpp](08_binary_semaphore.cpp) | Extra C++20: Signal mellan trådar | 42 |

## Bygg och kör

Hämta kursmaterialet från GitHub. Öppna terminalen i dag_14, där CMakeLists.txt ligger. Kommandona nedan körs från den mappen.

```sh
cmake -S . -B build -G Ninja
cmake --build build
./build/day14_01_mutex.exe
./build/day14.exe
```

På Linux/macOS saknas normalt .exe. Numrerade mål heter day14_ följt av filnamn utan .cpp. Bygg inte alla cpp-filer i ett g++-kommando eftersom de har varsin main. För ett mål:

```sh
cmake --build build --target day14_01_mutex
```

Kör automatiska kontroller efter bygge:

```sh
ctest --test-dir build --output-on-failure
```

CTest kör testprogrammet och bedömer returstatus. Explicita kontroller fungerar också i Release. Inga externa ramverk/bibliotek laddas ned.

## Köns kontrakt och felväg

close väcker alla, förbjuder push och låter redan köade poster tömmas. pop ger false när stängd och tom. Kön är obunden, håll övningsdata liten. Skapa en CloseQueueAndJoin direkt efter varje konsumenttråd. Vaktens destruktor stänger kön och anropar sedan join på den tråden. I main finns den första vakten redan när den andra tråden startas. Workers har separata resultat/felplatser. Tests.cpp kontrollerar sekventiellt kontrakt, inte alla interleavings. Latch är valbar C++20-överkurs.

## Gör egna övningar

Arbeta självständigt med Övningar.md. Delarnas lösningsprinciper och hänvisningar finns där. Visa gärna för en klasskamrat; egen kontroll och anteckningar fungerar om ingen är tillgänglig.

## Begrepp och syntax i exemplen

Förklaringarna används tillsammans med genomgången. Extraavsnittens begrepp behövs bara om du väljer dessa exempel.

### defer_lock och owns_lock

defer_lock skapar unique_lock utan att låsa direkt. lock() låser, unlock() släpper låset och owns_lock() anger om låsobjektet just nu äger det.

### Predikat, wait och notifiering

Predikatet är ett bool-villkor som kontrolleras under mutexen. wait släpper låset medan tråden väntar och återtar det före ny kontroll. notify_one väcker en väntare och notify_all alla; predikatet avgör om de får fortsätta.

### [this]

Lambdan sparar en pekare till det aktuella objektet så att den kan använda dess medlemmar. Det kopierar inte objektet och förlänger inte dess livstid.

### = delete

Markerar en funktion som förbjuden att använda. CloseQueueAndJoin(const CloseQueueAndJoin&) = delete förbjuder kopiering; den raderade operator= förbjuder kopieringstilldelning. Avsikten är att en stängningsvakt inte ska kopieras av misstag. Detta är skilt från uttrycket delete som frigör ett dynamiskt objekt.

### deque

deque är en ägande sekvens som kan lägga till och ta bort element i båda ändar; front läser första elementet och pop_front tar bort det.

### latch (extra C++20)

En latch är en engångsräknare: count_down minskar räknaren och wait väntar tills den nått noll.


## Semaforer (extra C++20)

Bild 12-13 visar counting_semaphore och binary_semaphore efter grundspåret och latch. Exemplen använder även jthread från dag 13:s extraavsnitt. acquire tar ett tillstånd eller väntar, release lämnar ett tillstånd. Antalet måste hållas inom max(). Counting-demon har två tillstånd och separata resultatplatser. Binary-demon börjar på noll och synkroniserar en skrivning före huvudtrådens läsning.

När provbyggen återupptas kan exemplen köras med följande kommandon från dagsmappen.

```sh
cmake --build build --target day14_07_counting_semaphore day14_08_binary_semaphore
./build/day14_07_counting_semaphore.exe
./build/day14_08_binary_semaphore.exe
```

Kör först den vanliga konfigureringsraden om byggmappen saknas eller behöver uppdateras. Exemplen är ännu inte provbyggda eller körda.
