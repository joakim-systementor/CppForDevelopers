# Kodguide dag 8

Studera ett delmoment i taget och förutsäg utskriften. Varje numrerad cpp-fil har en egen main och körfil. main.cpp är ett lösningsförslag till den sista uppgiften i Övningar.md: skriv eget först, jämför sedan. Filer som innehåller kommenterade fel ska byggas med felen kvar kommenterade i grundspåret.

## Exempel och förväntningar

| Fil | Delmoment | Prova eller förvänta |
|---|---|---|
| [01_raii.cpp](01_raii.cpp) | Filägarens scope | Första raden ur CMakeLists.txt; File scope ended |
| [02_unique.cpp](02_unique.cpp) | Ägaröverföring och observatör | Old owner empty: true; New owner/Observer: 42 |
| [03_array.cpp](03_array.cpp) | Ensamägd dynamisk array | 10 20 30 |
| [04_shared.cpp](04_shared.cpp) | Delat ägande | Owners: 2; Value: 42; Owners after scope: 1 |
| [05_weak.cpp](05_weak.cpp) | Svag observation och lock | Locked: 42; Expired: true |
| [06_exception.cpp](06_exception.cpp) | Automatisk destruktion vid fel | Acquired; Released; Caught |
| [extra_20_array.cpp](extra_20_array.cpp) | Valbar C++20-array med delat ägande | 10 0 2 |
| [main.cpp](main.cpp) | Lösningsförslag till avslutningsövningen | Observed: 80; Old owner empty: true; New owner: 80; Rejected |

## Bygg och kör

Hämta kursmaterialet från GitHub. Öppna terminalen i dag_8, där CMakeLists.txt ligger. Kommandona nedan körs från den mappen.

```sh
cmake -S . -B build -G Ninja
cmake --build build
./build/day8_01_raii.exe
./build/day8.exe
```

Körfilens namn är day8_ följt av det numrerade filnamnet utan .cpp. På Linux/macOS saknas normalt .exe. Bygg inte alla cpp-filer i ett enda g++-kommando eftersom de har varsin main. För ett enda mål:

```sh
cmake --build build --target day8_01_raii
```

Extraexemplet använder funktioner introducerade i C++20 och byggs redan med kursens C++23-standard. Kör dess dayN_extra_20_-fil från build; byt N till dagens nummer. Överkursen är frivillig och kräver ingen extra byggflagga.

Filövningen körs från dag_8 så att CMakeLists.txt hittas. Resource i undantagsdemonstrationen är en livstidsmarkör; filströmmen i första exemplet visar en verklig extern resurs.

## Gör egna övningar

Övningar.md finns i samma mapp. Lösningsförslag till delövningarna finns i bladet; main.cpp är för avslutningsövningen.

## Begrepp och syntax i exemplen

Förklaringarna används tillsammans med genomgången. Extraavsnittens begrepp behövs bara om du väljer dessa exempel.

### RAII och smarta pekare

RAII kopplar en resurs till ett objekts livstid. unique_ptr har ensamt ägande; shared_ptr delar ägande; weak_ptr observerar utan att hålla objektet vid liv.

### std::move och get

std::move tillåter att värdet behandlas som flyttbart; själva flytten utförs av operationen som tar emot det. get ger en icke-ägande rå pekare och överför inget ägande.

### weak_ptr::lock

Försöker skapa en shared_ptr som håller objektet vid liv. Resultatet är tomt om objektet redan har förstörts.

