# Kodguide dag 12

Grundexemplen utgår från C++17. Datorprojekten byggs med C++23. Nyare standardfunktioner hör till de valbara extraavsnitten efter grundgenomgången.

Standardalgoritmer, iteratorer och lambda. C++23 i hela bygget. Varje numrerad cpp-fil har egen main/körfil. Förutsäg före körning. Övningar.md finns i samma mapp; main.cpp är lösningsförslag till sista uppgiften efter eget försök.

## Exempel och förväntningar

| Fil | Delmoment | Prova eller förvänta |
|---|---|---|
| [01_iterators.cpp](01_iterators.cpp) | Halvöppet intervall | 3 1 2; Distance: 3 |
| [02_sort.cpp](02_sort.cpp) | Sorteringsordningar | 20 50 80; 80 50 20 |
| [03_find_count.cpp](03_find_count.cpp) | Sök/räkna | Found: 80; Count: 1 |
| [04_capture.cpp](04_capture.cpp) | Kopia/referens | true false |
| [05_transform.cpp](05_transform.cpp) | Omvandla/summera | 0.2 0.8 0.5; Mean: 50 |
| [06_erase.cpp](06_erase.cpp) | remove/erase | Before erase: 3; After erase: 2; 20 50 |
| [07_ranges_cpp23.cpp](07_ranges_cpp23.cpp) | Valbara views/to | 160 100 |
| [main.cpp](main.cpp) | Algoritmflöde | Values: 0 79 80 100; Alarms: 2; Mean: 64.75 |

## Bygg och kör

Hämta kursmaterialet från GitHub. Öppna terminalen i dag_12, där CMakeLists.txt ligger. Kommandona nedan körs från den mappen.

```sh
cmake -S . -B build -G Ninja
cmake --build build
./build/day12_01_iterators.exe
./build/day12.exe
```

På Linux/macOS saknas normalt .exe. Numrerade mål heter day12_ följt av filnamn utan .cpp. Bygg inte alla cpp-filer i ett g++-kommando eftersom de har varsin main. För ett mål:

```sh
cmake --build build --target day12_01_iterators
```

## Intervall och ranges

End derefereras aldrig. Remove_if krymper inte vector, erase gör det. Extra kombinerar C++20-views och C++23-to i vanligt bygge. Basdata lever tills vyn materialiserats. Övningens bortfiltrering ska inte överföras till uppgift 1:s parser, som avvisar felrader.

## Gör egna övningar

Arbeta självständigt med Övningar.md. Delarnas lösningsprinciper och hänvisningar finns där. Visa gärna för en klasskamrat; egen kontroll och anteckningar fungerar om ingen är tillgänglig.

## Begrepp och syntax i exemplen

Förklaringarna används tillsammans med genomgången. Extraavsnittens begrepp behövs bara om du väljer dessa exempel.

### Lambda, fångst och predikat

En lambda är ett funktionsobjekt som skrivs direkt där det behövs. [] anger fångster: [threshold] sparar en kopia, [&threshold] refererar till originalet. Ett predikat är en funktion som svarar true eller false.

### begin, end och intervall

begin betecknar första elementet och end positionen efter det sista. Algoritmernas intervall [begin, end) inkluderar inte end; en end-iterator får inte avrefereras.

### Ranges och | (extra)

Här kopplar | ihop range-adaptrar. filter väljer element och transform beräknar nya värden när vyn läses. Vyn äger inte automatiskt underlaget; ranges::to<std::vector<int>>() samlar resultatet i en ägande vector.

