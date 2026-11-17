# Kodguide dag 13

Trådar, livstid och datakapplöpning. Grundexemplen utgår från C++17. Hela projektet byggs med C++23. Varje numrerad cpp-fil har egen main/körfil. Förutsäg före körning. Övningar.md finns i samma mapp; main.cpp är lösningsförslag till sista uppgiften efter eget försök.

## Exempel och förväntningar

| Fil | Delmoment | Prova eller förvänta |
|---|---|---|
| [01_thread.cpp](01_thread.cpp) | Explicit join | 42 |
| [02_capture.cpp](02_capture.cpp) | Kopia/referens | 11 21 |
| [03_local_results.cpp](03_local_results.cpp) | Separata summor | 60 90 150 |
| [04_atomic.cpp](04_atomic.cpp) | Delat atomic-objekt | 2000 |
| [05_worker_error.cpp](05_worker_error.cpp) | Överfört worker-fel | Worker error |
| [main.cpp](main.cpp) | Udda intervall | Items: 7; Parts: 6 22; Total: 28 |
| [06_jthread.cpp](06_jthread.cpp) | Extra C++20: Scope-bunden join | 7 |
| [07_stop.cpp](07_stop.cpp) | Extra C++20: Samarbetsbaserat stopp | Stopped: true |

## Bygg och kör

Hämta kursmaterialet från GitHub. Öppna terminalen i dag_13, där CMakeLists.txt ligger. Kommandona nedan körs från den mappen.

```sh
cmake -S . -B build -G Ninja
cmake --build build
./build/day13_01_thread.exe
./build/day13.exe
```

På Linux/macOS saknas normalt .exe. Numrerade mål heter day13_ följt av filnamn utan .cpp. Bygg inte alla cpp-filer i ett g++-kommando eftersom de har varsin main. För ett mål:

```sh
cmake --build build --target day13_01_thread
```

## Livstid och avslut

Resultat och indata lever längre än workers. I grundexemplen läser huvudtråden resultat och fel efter explicit join. Osäker vanlig int-räknare beskrivs bara i kommentar; ingen datakapplöpning körs. Stop-token är C++20-överkurs, samarbetar med worker och avbryter inte tvångsmässigt. Små summeringar visar korrekthet, inte fart.

## Gör egna övningar

Arbeta självständigt med Övningar.md. Delarnas lösningsprinciper och hänvisningar finns där. Visa gärna för en klasskamrat; egen kontroll och anteckningar fungerar om ingen är tillgänglig.

## Begrepp och syntax i exemplen

Förklaringarna används tillsammans med genomgången. Extraavsnittens begrepp behövs bara om du väljer dessa exempel.

### join

join väntar tills tråden har avslutats. En joinable std::thread måste joinas eller detachas före destruktion, annars avslutas programmet via terminate.

### exception_ptr, current_exception och rethrow_exception

exception_ptr håller ett fångat undantag så att det kan föras vidare. current_exception hämtar det aktuella undantaget inuti catch. rethrow_exception kastar det igen i den tråd som ska hantera det.

### catch (...) och 0LL

catch (...) fångar alla C++-undantagstyper. LL gör heltalsliteralen 0 till long long; accumulate använder startvärdets typ som ackumulatortyp.

### atomic och load

En atomic stöder odelbara operationer på sitt värde. load läser värdet atomärt. Det gör inte automatiskt flera separata operationer eller flera fält till en gemensam odelbar uppdatering.

### jthread, stop_token och yield (extra C++20)

En joinable jthread begär stopp och joinar vid destruktion. Arbetet måste ändå kunna avslutas.

stop_requested kontrollerar om stopp begärts; request_stop begär ett samarbetsvilligt stopp utan att tvångsavsluta tråden. yield ger schemaläggaren möjlighet att köra en annan tråd och är ingen garanti om körordning.

