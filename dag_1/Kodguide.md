# Kodguide dag 1

Grundexemplen utgår från C++17. Datorprojekten byggs med C++23. Nyare standardfunktioner hör till de valbara extraavsnitten efter grundgenomgången.

Källkod och byggfiler delas via GitHub. Kör kommandona från dag_1, där CMakeLists.txt ligger.

Öppna ett delmoment i taget. Varje numrerad cpp-fil är ett eget litet program med en egen `main`.
Bygg inte alla cpp-filer tillsammans med `g++ *.cpp`, eftersom flera av dem har varsin startpunkt.

## Exempel och förväntningar

| Fil | Delmoment | Prova eller förvänta |
|---|---|---|
| [01_hello.cpp](01_hello.cpp) | Första programmet; main, cout och returstatus | Hello, C++! |
| [02_exit_status.cpp](02_exit_status.cpp) | Körning och felstatus | Felmeddelande på stderr; exitkod 1 är avsiktlig |
| [03_linking.cpp](03_linking.cpp) | Kompilering/länkning över två källfiler | Bygg med greeting.cpp: Hello from two source files! |
| [main_fel1.cpp](main_fel1.cpp) | Övning | Skriv era observationer |
| [main_fel2.cpp](main_fel2.cpp) | Övning | Skriv era observationer |
| [main_fel3.cpp](main_fel3.cpp) | Övning | Skriv era observationer |
| [main_fel4.cpp](main_fel4.cpp) | Övning | Skriv era observationer |
| [Makefile](Makefile) | Make och beroenden | make bygger main.exe; andra körningen behöver inte bygga om |
| [Makefile_v2](Makefile_v2) | Variabler och städmål | make -f Makefile_v2; make -f Makefile_v2 clear |
| [CMakeLists.txt](CMakeLists.txt) | Genererat bygge | Konfigurera med CMake; bygg med Ninja |
| [losning_logik.cpp](losning_logik.cpp) | Lösningsförslag till logikfelet | Hello World! |
| [losning_namn.cpp](losning_namn.cpp) | Lösningsförslag till namn/syntax | Hello World! |
| [losning_lankning.cpp](losning_lankning.cpp) | Lösningsförslag till saknad definition | Hello World! |

## Bygg och kör

Kör från mappen `dag_1` med fungerande UCRT64-verktyg:

```sh
cmake -S . -B build -G Ninja
cmake --build build
./build/day1_01_hello.exe
```

Körfilen för ett numrerat exempel heter `day1_` följt av filnamnet utan `.cpp`, exempelvis `day1_01_hello.exe`.
`main.cpp` kompileras till `day1.exe`.
På Linux/macOS saknar CMake-körfiler normalt `.exe`.

För att bygga bara ett exempel:

```sh
cmake --build build --target day1_01_hello
```

Avkommentera rader med avsiktliga fel först när du vill studera just det felet. Förutsäg utskriften, kör, ändra en sak och kör igen. stdout och stderr kan visas i olika ordning vid omdirigering; jämför dem separat.

Felövningarna `main_fel*.cpp` ingår inte i det lyckade CMake-bygget - de hör till övningarna. Bygg dem var för sig med `g++ -std=c++23 -Wall -Wextra -Wpedantic main_felN.cpp -o fault.exe`. Make kräver riktiga tabbar i Makefile och körs i UCRT64-terminalen.

## Gör egna övningar

Övningsbladet Övningar.md finns i samma exempel-mapp. Ditt eget arbete görs i en separat labbmapp.

main.cpp är nu uttryckligen lösningsförslag till övningsbladets avslutande uppgift. Skriv själv från beskrivningen innan du jämför. Förslag till övriga delövningar finns i Övningar.md.

## Begrepp och syntax i exemplen

Förklaringarna används tillsammans med genomgången. Extraavsnittens begrepp behövs bara om du väljer dessa exempel.

### Kompilator, länkare och byggverktyg

Kompilatorn översätter C++ till objektkod. Länkaren kopplar ihop objektkod och bibliotek till programmet. Make och Ninja kör byggstegen; CMake genererar byggbeskrivningen åt dem.

### #include och main

#include gör en headers deklarationer tillgängliga. main är programmets startfunktion; return 0 anger lyckat avslut.

### std:: och <<

std är standardbibliotekets namnrymd. :: väljer ett namn i en namnrymd eller klass. Med std::cout skickar << värden till utströmmen.

