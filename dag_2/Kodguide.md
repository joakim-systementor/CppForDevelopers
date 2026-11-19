# Kodguide dag 2

Grundexemplen utgår från C++17. Datorprojekten byggs med C++23. Nyare standardfunktioner hör till de valbara extraavsnitten efter grundgenomgången.

Öppna ett delmoment i taget. Varje numrerad cpp-fil är ett eget litet program med en egen `main`. `main.cpp` är kvar som sammanhängande exempel. Bygg inte alla cpp-filer tillsammans med `g++ *.cpp`, eftersom flera av dem har varsin startpunkt.

## Exempel och förväntningar

| Fil | Delmoment | Prova eller förvänta |
|---|---|---|
| [01_types.cpp](01_types.cpp) | Bild 3: int, double, bool, char, string och sizeof | count 3, temperatur 21.5, alarm false; storlekar beror på plattform |
| [02_initialization.cpp](02_initialization.cpp) | Bild 4: {}, auto, const, constexpr och narrowing | count 5, saved 0, limit 90, maximum 100 |
| [03_division.cpp](03_division.cpp) | Bild 5: heltalsdivision och static_cast | 2, 2, 2.5 |
| [04_console_io.cpp](04_console_io.cpp) | Bild 6: cout, cerr, cin >>, getline, radslut och EOF | Mata 25 och sedan Ada Lovelace på nästa rad |
| [05_conditions.cpp](05_conditions.cpp) | Bild 7: if/else if/else, &&/\|\|/!, villkorsoperator; även switch | Alarm, Accepted, Start |
| [06_loops.cpp](06_loops.cpp) | Bild 8: for, while, do-while, range-for, break och continue | 0 1 2 / 3 2 1 / 1 2 / 10 20 30 / 0 2 3 |
| [07_line_parsing.cpp](07_line_parsing.cpp) | Bild 9: radtolkning, strömtillstånd, extra text, q och EOF | 12 godkänns; 12abc, två tal och tom rad avvisas |
| [08_exceptions.cpp](08_exceptions.cpp) | Bild 10: throw, typad catch, const referens och what | 80/20 godkänns; 101 fångas och nästa värde behandlas |
| [main.cpp](main.cpp) | Avslutning: sammanhängande mätvärdesprogram | 0/79 Normal; 80/100 Alarm; övriga intervallvärden avvisas |
| [extra_statistics.cpp](extra_statistics.cpp) | Lösningsförslag till statistikfördjupningen | Giltiga värden räknas; medelvärde eller No measurements |

## Bygg och kör

Hämta kursmaterialet från GitHub. Öppna terminalen i dag_2, där CMakeLists.txt ligger. Kommandona nedan körs från den mappen.

```sh
cmake -S . -B build -G Ninja
cmake --build build
./build/day2_01_types.exe
```

Körfilen för ett numrerat exempel heter `day2_` följt av filnamnet utan `.cpp`, exempelvis `day2_01_types.exe`. Det sammanhängande exemplet heter `day2.exe`. På Linux/macOS saknar CMake-körfiler normalt `.exe`.

För att bygga bara ett exempel:

```sh
cmake --build build --target day2_01_types
```

Avkommentera rader med avsiktliga fel först när du vill studera just det felet. Förutsäg utskriften, kör, ändra en sak och kör igen. stdout och stderr kan visas i olika ordning vid omdirigering; jämför dem separat.

`switch`, `do-while` och range-for kompletterar kontrollstrukturernas grundexempel. Presentationsbilderna behöver inte visa alla rader samtidigt: använd filen för att visa en konstruktion i taget. I/O-exemplet hanterar radslutet vid blandning av `>>` och `getline`; strikt radvalidering studeras separat i 07. Ändra `count` till 0 i 03 för att visa skyddet mot division med noll.

## Gör egna övningar

Övningsbladet Övningar.md finns i samma exempel-mapp. Ditt eget arbete görs i en separat labbmapp.

main.cpp är nu uttryckligen lösningsförslag till övningsbladets avslutande uppgift. Skriv själv från beskrivningen innan du jämför. Förslag till övriga delövningar finns i Övningar.md.

## Begrepp och syntax i exemplen

Förklaringarna används tillsammans med genomgången. Extraavsnittens begrepp behövs bara om du väljer dessa exempel.

### auto, const och constexpr

auto låter kompilatorn härleda typen från initialiseringen. const hindrar ändring genom detta namn. constexpr kräver här ett konstant uttryck som initialvärde.

### static_cast<double>(värde)

Gör en uttrycklig typkonvertering till double. Före division gör det att beräkningen blir flyttalsdivision.

### ?: och boolalpha

villkor ? a : b väljer ett av två uttryck. std::boolalpha skriver bool som true/false i stället för 1/0.

