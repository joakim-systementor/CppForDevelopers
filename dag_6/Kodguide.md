# Kodguide dag 6 - Operatoröverlagring och praktisk OOP

Grundexemplen utgår från C++17. Datorprojekten byggs med C++23. Nyare standardfunktioner hör till de valbara extraavsnitten efter grundgenomgången.

Studera ett delmoment i taget och förutsäg utskriften. Varje numrerad cpp-fil har en egen main och körfil. main.cpp är ett lösningsförslag till den sista uppgiften i Övningar.md: skriv eget först, jämför sedan. Filer som innehåller kommenterade fel ska byggas med felen kvar kommenterade i grundspåret.

## Exempel och förväntningar

| Fil | Delmoment | Prova eller förvänta |
|---|---|---|
| [01_compound.cpp](01_compound.cpp) | Plus-tilldelning och invariant | 1.25; Rejected; unchanged=1000000000 |
| [02_add.cpp](02_add.cpp) | Plus och oförändrade operander | 1625; 1250 |
| [03_compare.cpp](03_compare.cpp) | Equality och ordning | true; true |
| [04_stream.cpp](04_stream.cpp) | Strömoperator och två decimaler | 12.50 0.05 -0.05 |
| [05_account.cpp](05_account.cpp) | Komposition, privat saldo och kontrollerade handlingar | 100.00; 125.00; 95.00; avvisat uttag behåller 95.00; kopia 96.00 men konto 95.00 |
| [Account.hpp](Account.hpp) | Konto med egen invariant och Money som medlem | Positiva handlingar; inget negativt saldo; oförändrat vid fel |
| [Money.hpp](Money.hpp) | Värdetyp, validering och operatorer | Heltalsöre; gräns ±1 miljard |
| [main.cpp](main.cpp) | Lösningsförslag till avslutningsövningen | 16.25; equality/ordning true; 16.30 även efter fel |
| [06_compare_cpp20.cpp](06_compare_cpp20.cpp) | Valbar C++20-jämförelse | true true |

## Bygg och kör

Hämta kursmaterialet från GitHub. Öppna terminalen i dag_6, där CMakeLists.txt ligger. Kommandona nedan körs från den mappen.

```sh
cmake -S . -B build -G Ninja
cmake --build build
./build/day6_02_add.exe
./build/day6_05_account.exe
./build/day6.exe
```

Körfilens namn är day6_ följt av det numrerade filnamnet utan .cpp. På Linux/macOS saknas normalt .exe. Bygg inte alla cpp-filer i ett enda g++-kommando eftersom de har varsin main. För ett enda mål:

```sh
cmake --build build --target day6_02_add
```


Extraexemplet använder funktioner introducerade i C++20 och byggs redan med kursens C++23-standard. Kör dess dayN_extra_20_-fil från build; byt N till dagens nummer. Överkursen är frivillig och kräver ingen extra byggflagga.

## Följ kontots tillstånd

Läs i ordningen Money, dess operatorer och därefter Account. 05_account.cpp är ett separat exempel till delövning D; main.cpp fortsätter vara lösningsförslag till avslutningsövningen om Money.

```text
Start: 100.00
Deposited: 125.00
Withdrawn: 95.00
Rejected: 95.00
Copy: 96.00
Account: 95.00
```

Startvärdet och handlingarnas belopp anges i öre. Uttaget 100.00 avvisas efter att saldot blivit 95.00. balance() returnerar ett värde: när kopian ökas med 1.00 behåller kontot sitt saldo. Prova även delövning D:s gränsfall i egen kod.

## Gör egna övningar

Övningar.md finns i samma mapp. Lösningsförslag till delövningarna finns i bladet; main.cpp är för avslutningsövningen.

## Begrepp och syntax i exemplen

Förklaringarna används tillsammans med genomgången. Extraavsnittens begrepp behövs bara om du väljer dessa exempel.

### friend

Ger den namngivna fria funktionen tillgång till klassens privata medlemmar. Funktionen blir inte en medlemsfunktion för att den definieras som friend.

### this och return *this

this är en pekare till objektet som medlemsfunktionen anropas på. *this betecknar själva objektet; returtypen Money& gör att += returnerar en referens till det uppdaterade objektet.

### static constexpr och sifferavskiljare

static gör limit till en klassmedlem som inte lagras separat i varje Money-objekt. constexpr gör den till en konstant som kan användas i konstanta uttryck. Apostrofer i 1'000'000'000 förbättrar läsbarheten utan att ändra talet.

### setw, setfill och fill

setw(2) anger minsta bredd för nästa formaterade fält. setfill väljer utfyllnadstecken och gäller tills det ändras. fill() läser det gamla tecknet så exemplet kan återställa strömmens tillstånd.


### Värdetyp, invariant och komposition

En värdetyp representerar ett värde, exempelvis ett belopp. En invariant är en regel som ska gälla för färdiga objekt. Money har ett tillåtet beloppsintervall, medan Account dessutom kräver ett icke-negativt saldo. Komposition betyder här att Account innehåller ett Money-objekt och använder dess funktioner.

### Returvärde och kopieringstilldelning

Money balance() const returnerar en kopia av beloppet. Kopian kan ändras utan att kontot påverkas. balance_ = remaining använder Money-typens vanliga, kompilatorgenererade kopieringstilldelning för att ersätta medlemsvärdet; vi skriver ingen egen operator= här.

### require_positive och feltyper

require_positive är vår privata hjälpfunktion, inte en biblioteksfunktion. Den avvisar noll och negativa belopp med std::invalid_argument. withdraw avvisar otillräckligt saldo med std::out_of_range. Money kan också kasta out_of_range när en insättning skulle överskrida dess gräns. Kontrollerna sker innan saldot ändras.
