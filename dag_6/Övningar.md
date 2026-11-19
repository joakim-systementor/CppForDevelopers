# Övningar dag 6 - Operatoröverlagring och praktisk OOP

Arbeta självständigt och skriv egen kod. Visa gärna för en klasskamrat efteråt. Lösningsförslag används efter eget försök; gör annars egen kontroll med provfallen.

## Start

Skapa en Money-typ i en egen C++23-labb. Lagra heltalsöre i long long. Giltigt intervall är -1 miljard till 1 miljard öre. Konstruktorfel ger out_of_range. Inga inmatningsloopar krävs.

## A - värde och addition

1. Skapa explicit konstruktor och en const getter för öre.
2. Implementera operator+ som returnerar ett nytt Money. Två giltiga operander ska inte ändras av additionen.
3. Prova 1250 + 375 och 100 + (-100). Resultaten ska vara 1625 och 0 öre.

**Klart när:** första operandens värde är oförändrat och ogiltiga resultat avvisas.

## B - jämförelse och text

1. Implementera == utifrån öre och < utifrån numerisk ordning.
2. Implementera operator<< som skriver till den mottagna strömmen och returnerar samma ström utan eget radslut.
3. Kontrollera 12.50, 0.05, -0.05 och 0.00. Återställ fill om du ändrar den.

**Klart när:** kedjad utskrift fungerar, och lika värden jämförs lika oavsett var objekten skapats.

## C - += och felväg

1. Implementera += så att den validerar ett nytt värde innan objektet ändras. Returnera Money&.
2. Låt + återanvända += i stället för att dubblera reglerna.
3. Sätt ett objekt till maxgränsen, addera 1 öre och kontrollera både undantag och oförändrat gammalt värde.

**Klart när:** testet avslöjar om en misslyckad operation redan har förstört tillståndet.

## D - Ett konto med eget ansvar

Använd din Money-typ eller materialets Money.hpp. Skriv Account själv innan du öppnar lösningsförslaget.

1. Lagra ett privat saldo som Money. Konstruktorn tar ett startsaldo och avvisar negativa värden med std::invalid_argument
2. Lägg till balance() const som returnerar saldot som ett värde, inte en skrivbar referens
3. Implementera deposit och withdraw. Beloppet måste vara större än noll; annars kastas std::invalid_argument. Uttag större än saldot ger std::out_of_range
4. Samla kontrollen av positiva belopp i en privat hjälpfunktion. Kontrollera allt innan saldot ändras. Låt deposit återanvända Money::operator+=
5. Börja med 10 000 öre, sätt in 2 500 och ta ut 3 000. Förvänta saldo 9 500 öre. Försök sedan ta ut 10 000 och kontrollera att saldot fortfarande är 9 500 efter felet
6. Prova noll och negativt belopp för båda handlingarna, uttag av exakt hela saldot samt insättning över Money-gränsen. Alla avvisade handlingar ska bevara saldot
7. Hämta en kopia via balance() och ändra kopian. Kontrollera att kontot inte ändras. Förklara varför Money tillåter negativa värden men Account inte tillåter negativt saldo

**Klart när:** varje giltig handling ger rätt saldo, varje avvisad handling bevarar saldot och kontots privata tillstånd inte kan ändras genom gettern. Kontot behöver inga egna överlagrade operatorer.

## Lösningsförslag till delövningarna

| Del | Förslag att jämföra med |
|---|---|
| A | [Money.hpp](Money.hpp) och 02_add.cpp |
| B | 03_compare.cpp och 04_stream.cpp |
| C | 01_compound.cpp |
| D | [Account.hpp](Account.hpp) och [05_account.cpp](05_account.cpp) |

Extra: prova C++20-exemplet [06_compare_cpp20.cpp](06_compare_cpp20.cpp). Beskriv vilken ordning medlemsvis jämförelse skapar. Det ingår inte i baskraven.

## Avslutningsövning - återskapa main.cpp

Använd din Money eller paketets Money.hpp. Skapa 1250 och 375 öre, addera dem och skriv totalsumman. Kontrollera equality mot 1625 och att 1250 är mindre än totalen. Addera 5 öre med +=. Försök därefter addera ett Money på maxgränsen till totalen; fånga felet och visa att totalen fortfarande är 16.30.

```text
Total: 16.25
Equal: true
Less: true
Updated: 16.30
Rejected: 16.30
```

**Klart när:** utskrift och tillstånd stämmer. Lösningsförslag: main.cpp, som läses efter ditt eget försök.

## Visa gärna för en klasskamrat

Visa att plus inte ändrar operanderna, att += kan göra det och att ett avvisat ändringsförsök bevarar värdet. Visa också ett avvisat uttag som bevarar saldot. Förklara varför withdraw är en namngiven handling och varför Account använder Money genom komposition.
