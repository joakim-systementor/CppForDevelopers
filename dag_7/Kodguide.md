# Kodguide dag 7

Grundexemplen utgår från C++17. Datorprojekten byggs med C++23. Nyare standardfunktioner hör till de valbara extraavsnitten efter grundgenomgången.

Studera ett delmoment i taget och förutsäg utskriften. Varje numrerad cpp-fil har en egen main och körfil. main.cpp är ett lösningsförslag till den sista uppgiften i Övningar.md: skriv eget först, jämför sedan. Filer som innehåller kommenterade fel ska byggas med felen kvar kommenterade i grundspåret.

## Exempel och förväntningar

| Fil | Delmoment | Prova eller förvänta |
|---|---|---|
| [01_references.cpp](01_references.cpp) | Referens och mutation | 21 21 |
| [02_pointers.cpp](02_pointers.cpp) | Adress, dereferering och nullptr | 20 |
| [03_const.cpp](03_const.cpp) | Const på objekt eller pekare | 20 15 |
| [04_storage.cpp](04_storage.cpp) | Automatisk/statisk/dynamisk lagring | 10 20 1 2 |
| [05_array.cpp](05_array.cpp) | new[] och delete[] | 10 20 30 |
| [06_lifetime.cpp](06_lifetime.cpp) | Scope och säkert pekarmål | 7; 42 |
| [07_span_cpp20.cpp](07_span_cpp20.cpp) | Valbar C++20-vy | 60 |
| [main.cpp](main.cpp) | Lösningsförslag till avslutningsövningen | Observed: 21; No value; Sum: 60 |

## Bygg och kör

Hämta kursmaterialet från GitHub. Öppna terminalen i dag_7, där CMakeLists.txt ligger. Kommandona nedan körs från den mappen.

```sh
cmake -S . -B build -G Ninja
cmake --build build
./build/day7_01_references.exe
./build/day7.exe
```

Körfilens namn är day7_ följt av det numrerade filnamnet utan .cpp. På Linux/macOS saknas normalt .exe. Bygg inte alla cpp-filer i ett enda g++-kommando eftersom de har varsin main. För ett enda mål:

```sh
cmake --build build --target day7_01_references
```

Extraexemplet använder funktioner introducerade i C++20 och byggs redan med kursens C++23-standard. Kör dess dayN_extra_20_-fil från build; byt N till dagens nummer. Överkursen är frivillig och kräver ingen extra byggflagga.

new/delete-exemplen visar mekaniken. Kör inte kommenterade exempel på hängande pekare. Pekare till lokala objekt ska inte delete-as. Nästa dag ersätts manuellt ägande med RAII.

## Gör egna övningar

Övningar.md finns i samma mapp. Lösningsförslag till delövningarna finns i bladet; main.cpp är för avslutningsövningen.

## Begrepp och syntax i exemplen

Förklaringarna används tillsammans med genomgången. Extraavsnittens begrepp behövs bara om du väljer dessa exempel.

### nullptr, & och *

nullptr är ett tomt pekarvärde. &objekt tar objektets adress. *pekare kommer åt objektet på adressen; pekaren måste avse ett giltigt objekt.

### new, delete och delete[]

new skapar ett dynamiskt objekt som måste frigöras med delete. new[] och delete[] hör ihop för arrayer. Detta visar mekaniken; välj senare normalt ägande bibliotekstyper.

### Lokal static

Den lokala räknaren i 04_storage.cpp initieras första gången körningen når deklarationen och behåller sitt värde mellan anrop. Dess lagring varar tills programmet avslutas.

