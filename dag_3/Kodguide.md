# Kodguide dag 3

Grundexemplen utgår från C++17. Datorprojekten byggs med C++23. Nyare standardfunktioner hör till de valbara extraavsnitten efter grundgenomgången.

Öppna ett delmoment i taget. Varje numrerad cpp-fil är ett eget litet program med en egen `main`. `main.cpp` är kvar som sammanhängande exempel. Bygg inte alla cpp-filer tillsammans med `g++ *.cpp`, eftersom flera av dem har varsin startpunkt.

## Exempel och förväntningar

| Fil | Delmoment | Prova eller förvänta |
|---|---|---|
| [01_functions.cpp](01_functions.cpp) | Deklaration, definition, returvärde och void | Result: 7 |
| [02_parameters.cpp](02_parameters.cpp) | Värde, ändringsbar referens och const referens | Original 5, resultat 6; efter increment 6 |
| [03_scope.cpp](03_scope.cpp) | Scope och lokal livstid | Inside block 15; Outside block 10 |
| [04_overloading.cpp](04_overloading.cpp) | Överlagring, vidarebefordring och namespace | Default true; custom false |
| [05_modules.cpp](05_modules.cpp) | Header/implementation och separat länkning | Alarm; bygg tillsammans med sensor.cpp |
| [sensor.hpp](sensor.hpp) | Gränssnitt, enum class och include guard | Deklarationer för användning i flera källfiler |
| [sensor.cpp](sensor.cpp) | Funktionskontrakt och implementation | 0-100 valideras; standardtröskel 80 |
| [main.cpp](main.cpp) | Avslutning: modulärt program | Samma inmatningsbeteende som dag 2 |

## Bygg och kör

Hämta kursmaterialet från GitHub. Öppna terminalen i dag_3, där CMakeLists.txt ligger. Kommandona nedan körs från den mappen.

```sh
cmake -S . -B build -G Ninja
cmake --build build
./build/day3_01_functions.exe
```

Körfilen för ett numrerat exempel heter `day3_` följt av filnamnet utan `.cpp`, exempelvis `day3_01_functions.exe`. Det sammanhängande exemplet heter `day3.exe`. På Linux/macOS saknar CMake-körfiler normalt `.exe`.

För att bygga bara ett exempel:

```sh
cmake --build build --target day3_01_functions
```

Avkommentera rader med avsiktliga fel först när du vill studera just det felet. Förutsäg utskriften, kör, ändra en sak och kör igen. stdout och stderr kan visas i olika ordning vid omdirigering; jämför dem separat.


## Gör egna övningar

Övningsbladet Övningar.md finns i samma exempel-mapp. Ditt eget arbete görs i en separat labbmapp.

main.cpp är nu uttryckligen lösningsförslag till övningsbladets avslutande uppgift. Skriv själv från beskrivningen innan du jämför. Förslag till övriga delövningar finns i Övningar.md.

## Begrepp och syntax i exemplen

Förklaringarna används tillsammans med genomgången. Extraavsnittens begrepp behövs bara om du väljer dessa exempel.

### #ifndef, #define och #endif

Preprocessordirektiv: kontrollera om ett makronamn saknas, definiera namnet och avsluta villkoret. Tillsammans skyddar de en header mot upprepad inkludering i samma översättningsenhet.

### enum class och namespace

enum class definierar en egen typ med namngivna alternativ, exempelvis Status::alarm. namespace grupperar namn för att undvika namnkonflikter.

### std::expected och std::unexpected (extra)

expected<T, E> innehåller antingen ett lyckat värde av typen T eller ett fel av typen E. unexpected skapar felalternativet; has_value kontrollerar vilket alternativ som finns och error hämtar felet.

