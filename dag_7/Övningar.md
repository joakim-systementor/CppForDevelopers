# Övningar dag 7 - referenser, pekare och minnesansvar

Skriv egen kod och gör övningarna självständigt. Visa gärna för en klasskamrat när du är klar. Lösningsförslag används för jämförelse efter ett eget försök. Kör inte avsiktligt ogiltiga minnesåtkomster.

## Start

Skapa en egen C++23-labb och rita vilket objekt varje namn hänvisar till. Rått dynamiskt ägande visas här för förståelse; smart ägande introduceras nästa dag. En adress till ett lokalt objekt får inte delete-as.

## A - referens och pekare

1. Skapa ett int med värdet 10 och en referens till det. Ändra till 20 genom referensen och öka med en funktion som tar int&.
2. Skapa separat en pekare till ett lokalt int. Skriv en funktion som ökar värdet bara om pekaren inte är nullptr.
3. Anropa med giltig pekare och nullptr. Förklara skillnaden mellan adressen och värdet på den adressen.

**Klart när:** referensexemplet ger 21 och nullfallet inte försöker dereferera.

## B - const och livstid

1. Visa en const int* som kan byta mål, och en int* const som kan ändra värdet men inte byta mål.
2. Skapa ett inre block med ett temporärt int. Förklara varför dess adress inte får läsas efter blocket.
3. Demonstrera en static-räknare över två funktionsanrop. Skilj statisk från automatisk lagringstid.

**Klart när:** du kan märka objekten i en skiss och peka ut när deras livstid slutar.

## C - dynamisk array och projektplan

1. Allokera en array med tre initierade int, fyll 10, 20, 30 och skriv dem.
2. Frigör med delete[] exakt en gång. Förklara varför en annan pekarkopia inte automatiskt blir nullptr.
3. Läs uppgift 1:s kontrakt. Skriv ansvar för parser, analys och presentation samt vem som äger indata och analysstrategin. Planera parser/sekventiellt läge före kommande mallar och trådar.

**Klart när:** det lilla programmet har matchad allokering/frigöring och projektplanen inte förutsätter att trådarna redan är undervisade.

## Lösningsförslag till delövningarna

| Del | Förslag att jämföra med |
|---|---|
| A | 01_references.cpp och 02_pointers.cpp |
| B | 03_const.cpp, 04_storage.cpp och 06_lifetime.cpp |
| C | 05_array.cpp; projektplanen har ingen enda rätt struktur |

Extra: [07_span_cpp20.cpp](07_span_cpp20.cpp) visar en icke-ägande C++20-vy. Den ändrar inte kravet på giltig livstid.

## Avslutningsövning - återskapa main.cpp

Skapa lokalt värde 20. Öka det till 21 med en funktion som tar int&. En separat print_if_present ska ta const int*: vid giltigt mål skriv Observed och värdet, vid nullptr skriv No value. Allokera därefter en dynamisk array med tre int, fyll 10/20/30, summera och skriv 60. Frigör arrayen korrekt. Skriv ingen kod som använder den efter frigöringen.

```text
Observed: 21
No value
Sum: 60
```

**Klart när:** programmet visar dessa rader och du kan ange varje pekares ägare eller observationsroll. Lösningsförslag: main.cpp, efter eget försök. Nästa dag refaktoreras arrayägandet till RAII.

## Visa gärna för en klasskamrat

Visa ett giltigt/null anrop, minnesskissen och projektplanen. Anteckna en risk med manuell städning om en funktion kastar innan delete.
