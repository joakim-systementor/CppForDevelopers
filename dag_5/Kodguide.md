# Kodguide dag 5

Grundexemplen utgår från C++17. Datorprojekten byggs med C++23. Nyare standardfunktioner hör till de valbara extraavsnitten efter grundgenomgången.

Studera ett delmoment i taget och förutsäg utskriften. Varje numrerad cpp-fil har en egen main och körfil. main.cpp är ett lösningsförslag till den sista uppgiften i Övningar.md: skriv eget först, jämför sedan. Filer som innehåller kommenterade fel ska byggas med felen kvar kommenterade i grundspåret.

## Exempel och förväntningar

| Fil | Delmoment | Prova eller förvänta |
|---|---|---|
| [01_inheritance.cpp](01_inheritance.cpp) | Publikt arv och baskonstruktion | room: 25 |
| [02_virtual.cpp](02_virtual.cpp) | Virtuellt anrop och override | constant: 20; offset: 80 |
| [03_abstract.cpp](03_abstract.cpp) | Abstrakt kontrakt och basreferens | constant: 80 |
| [04_slicing.cpp](04_slicing.cpp) | Basvärde jämfört med basreferens | device; sensor |
| [05_composition.cpp](05_composition.cpp) | Komposition | true |
| [Source.hpp](Source.hpp) | Två källor med samma kontrakt | Värde 0-100; offset -50-50 |
| [main.cpp](main.cpp) | Lösningsförslag till avslutningsövningen | constant: 20 Normal; offset: 80 Alarm; Rejected |

ConstantSource lagrar ett färdigt värde och read() returnerar value_. OffsetSource lagrar en validerad förskjutning i value_ och read() returnerar 50 + value_. Med OffsetSource{30} lagras alltså 30 och read() ger 80.

## Bygg och kör

Hämta kursmaterialet från GitHub. Öppna terminalen i dag_5, där CMakeLists.txt ligger. Kommandona nedan körs från den mappen.

```sh
cmake -S . -B build -G Ninja
cmake --build build
./build/day5_01_inheritance.exe
./build/day5.exe
```

Körfilens namn är day5_ följt av det numrerade filnamnet utan .cpp. På Linux/macOS saknas normalt .exe. Bygg inte alla cpp-filer i ett enda g++-kommando eftersom de har varsin main. För ett enda mål:

```sh
cmake --build build --target day5_01_inheritance
```


## Gör egna övningar

Övningar.md finns i samma mapp. Lösningsförslag till delövningarna finns i bladet; main.cpp är för avslutningsövningen.

## Begrepp och syntax i exemplen

Förklaringarna används tillsammans med genomgången. Extraavsnittens begrepp behövs bara om du väljer dessa exempel.

### virtual och override

virtual gör en medlemsfunktion virtuell: anrop via basreferens eller baspekare kan välja objektets härledda implementation. override kräver att funktionen verkligen överskuggar en virtuell basfunktion; fel signatur ger kompileringsfel.

### final

Efter klassnamnet förbjuder final ytterligare arv från klassen. ConstantSource och OffsetSource kan fortfarande ärva från Source. Efter en virtuell medlemsfunktion förbjuder final ytterligare överskuggning av just den funktionen.

### = 0 och abstrakt klass

= 0 deklarerar en rent virtuell funktion, inte returvärdet noll. En klass med kvarvarande rent virtuella funktioner är abstrakt och kan inte användas för att skapa egna objekt.

### ~Source() och = default

~ markerar destruktorn som körs när objektet förstörs. = default begär kompilatorns standardimplementation. virtual säkerställer korrekt destruktion av ett härlett objekt när det tas bort genom en Source-pekare.

### explicit och const Source&

explicit repeterar dag 4:s skydd mot implicit konvertering via konstruktorn. const Source& är en referens till det befintliga objektet: ingen basobjektskopia skapas och objektet får inte ändras genom referensen.

