# Kodguide dag 9

Grundexemplen utgår från C++17. Datorprojekten byggs med C++23. Nyare standardfunktioner hör till de valbara extraavsnitten efter grundgenomgången.

Testning, debugging och felsökning. C++23 i hela bygget. Varje numrerad cpp-fil har egen main/körfil. Förutsäg före körning. Övningar.md finns i samma mapp; main.cpp är lösningsförslag till sista uppgiften efter eget försök.

## Exempel och förväntningar

| Fil | Delmoment | Prova eller förvänta |
|---|---|---|
| [01_boundary.cpp](01_boundary.cpp) | Gränsvärden | 0: false; 79: false; 80/100: true |
| [02_debug.cpp](02_debug.cpp) | Avsiktlig loopbug | Total: 30; rättad kopia: 60 |
| [03_failing_test.cpp](03_failing_test.cpp) | Avsiktligt rött test | FAIL: 80 must trigger the alarm; status 1 |
| [04_source_location.cpp](04_source_location.cpp) | C++20-anropsplats | Fyra Caller-rader med anropsplatser och två Inside-rader med samma plats i loggfunktionen |
| [05_expected_cpp23.cpp](05_expected_cpp23.cpp) | Valbart resultat/fel | Value: 80; Error: Expected two integers |
| [tests/README.md](tests/README.md) | Åtta separata kontraktstester | Ett namngivet CTest-resultat per testprogram |
| [main.cpp](main.cpp) | Avslutningsövning | 0/79 Normal; 80/100 Alarm; Rejected |

## Bygg och kör

Hämta kursmaterialet från GitHub. Öppna terminalen i dag_9, där CMakeLists.txt ligger. Kommandona nedan körs från den mappen.

```sh
cmake -S . -B build -G Ninja -DCMAKE_BUILD_TYPE=Debug
cmake --build build
./build/day9_01_boundary.exe
./build/day9.exe
```

På Linux/macOS saknas normalt .exe. Numrerade mål heter day9_ följt av filnamn utan .cpp. Bygg inte alla cpp-filer i ett g++-kommando eftersom de har varsin main. För ett mål:

```sh
cmake --build build --target day9_01_boundary
```

Kör automatiska kontroller efter bygge:

```sh
ctest --test-dir build --output-on-failure
```

CTest kör åtta separata testprogram och visar en rad per testnamn. Varje program ger status 0 vid lyckade kontroller eller 1 vid fel. Explicita kontroller fungerar också i Release. Inga externa ramverk/bibliotek laddas ned.

Visa testnamn med `ctest --test-dir build -N`. Kör endast formatkontrollen med:

```sh
ctest --test-dir build -R "^day9_parser_format$" --output-on-failure
```

-R väljer testnamn med ett reguljärt uttryck; ^ och $ avgränsar hela namnet. `ctest --test-dir build --rerun-failed --output-on-failure` kör endast de tester som misslyckades senast. Filer och ansvarsområden finns i [testöversikten](tests/README.md).

## Debugger och avsiktliga fel

02_debug.cpp har avsiktlig loopbug: Total: 30. Rättad kopia ska ge 60. 03_failing_test.cpp ger avsiktligt status 1 och är inte registrerad i standardsviten. Rätta gränsjämförelsen i egen kopia.

```sh
gdb ./build/day9_02_debug.exe
```

I GDB:

```text
break total_values
run
next
next
next
print index
print total
watch total
continue
backtrace
quit
```

De tre next-kommandona tar denna version till loopens första kroppsrad, där index är initialiserat till 0. Läs inte ett visat index-värde innan initialiseringen körts. Bygg om arbetskopian efter rättning. values är en rå array; ersätt loopblocket med `for (int value : values) { total += value; }`, inte ett anrop till values.size(). source_location är C++20, expected C++23; båda byggs normalt. Hjälpparsern kräver två whitespace-separerade hela heltal utan extra token. From_chars accepterar inte inledande plus.

## Gör egna övningar

Arbeta självständigt med Övningar.md. Delarnas lösningsprinciper och hänvisningar finns där. Visa gärna för en klasskamrat; egen kontroll och anteckningar fungerar om ingen är tillgänglig.

## Begrepp och syntax i exemplen

Förklaringarna används tillsammans med genomgången. Extraavsnittens begrepp behövs bara om du väljer dessa exempel.

### inline i Measurement.hpp

Tillåter här att samma funktionsdefinition finns i flera översättningsenheter när headern inkluderas, förutsatt att språkets definitionsregler följs. Det garanterar inte att kompilatorn ersätter anropet med funktionskroppen.

### from_chars, ec och ptr

from_chars tolkar teckenintervallet [första, sista) till ett tal. ec är felkoden; std::errc{} betyder inget konverteringsfel. ptr pekar på första tecknet som inte lästes. Vi kräver både lyckad konvertering och att hela taltexten har lästs.

### data() + size()

data ger en pekare till strängens tecken och size dess längd. Summan pekar precis efter sista tecknet och används som intervallgräns, inte för att läsa ett tecken.

### assert och NDEBUG

assert avbryter programmet när villkoret är falskt, men kontrollen försvinner när makrot NDEBUG är definierat. Testprogrammets egna kontroller och returstatus måste därför fungera även då.
