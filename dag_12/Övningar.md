# Övningar dag 12 - Standardalgoritmer, iteratorer och lambda

Arbeta självständigt med egen kod i egen mapp/kopia. Förutsäg före körning. Övningarna är träning, ingen examinerande inlämning. C++23 är redan valt.

## Delövning 1 - Intervall och sortering

Skriv vector 4,1,4,2 via iteratorer. Sortera stigande och sedan fallande, behåll dubbletter.

**Klart när:** 1 2 4 4 och 4 4 2 1.

**Lösningsförslag:** skriv först själv. Jämför sedan med del 1 under Lösningsförslag till delövningarna och [02_sort.cpp](02_sort.cpp).

## Delövning 2 - Sök och räkna larm

För 79,80,100,0: hitta första >=80 och räkna larm. Prova sedan gränsen 101.

**Klart när:** 80 och antal 2; ingen träff och antal 0 med 101.

**Lösningsförslag:** skriv först själv. Jämför sedan med del 2 under Lösningsförslag till delövningarna och [03_find_count.cpp](03_find_count.cpp).

## Delövning 3 - Fångat värde eller referens

Skapa två predikat vid threshold 80. Ändra till 90, testa 85 och förklara skillnaden.

**Klart när:** true för kopia, false för referens.

**Lösningsförslag:** skriv först själv. Jämför sedan med del 3 under Lösningsförslag till delövningarna och [04_capture.cpp](04_capture.cpp).

## Delövning 4 - Omvandla och ta bort

Normalisera 20,80,50 till 0.2,0.8,0.5. Separat: ta bort >=80 och visa size före/efter erase.

**Klart när:** Flyttalsnormalisering och kvarvarande 20,50.

**Lösningsförslag:** skriv först själv. Jämför sedan med del 4 under Lösningsförslag till delövningarna och [05_transform.cpp](05_transform.cpp).

## Avslutande uppgift - återskapa main.cpp

Börja med vector<int> {79,80,100,0,101}. Filtrera utanför 0-100 med erase_if, sortera stigande, räkna >=80 med count_if och beräkna mean med accumulate och flyttalsdivision. Om listan är tom, skriv No measurements och undvik division. Återskapa main.cpp själv. Detta är lokal filtrering; ändra inte uppgift 1:s krav att avvisa ogiltiga filrader.

Förväntad utskrift med angiven indata:

```text
Values: 0 79 80 100
Alarms: 2
Mean: 64.75
```

**Klart när:** du kan förklara flödet och få angivna resultat med egen kod. Studera sedan [main.cpp](main.cpp) som ett lösningsförslag, inte enda tillåtna lösning.

## Visa gärna för en klasskamrat

Visa egen lösning, ett gränsfall och varför du valt arbetssättet. Be om en fråga eller förbättring. Återkoppling är frivillig; utan kamrat gör du egen kontroll och antecknar vad som fungerar och vad du vill fråga läraren.

## Lösningsförslag till delövningarna

Använd efter eget försök. Filerna visar principen; anpassa till övningens indata.

### Del 1 - Intervall och sortering

Sort(begin,end) och strikt first > second för fallande. End derefereras inte; <= är fel sorteringsvillkor.

Jämför med [02_sort.cpp](02_sort.cpp) och bygg egen variant.

### Del 2 - Sök och räkna larm

Find_if-resultatet jämförs med end. Count_if använder samma domänvillkor men returnerar antal.

Jämför med [03_find_count.cpp](03_find_count.cpp) och bygg egen variant.

### Del 3 - Fångat värde eller referens

[threshold] lagrar 80. [&threshold] använder den levande variabeln som nu är 90. Returnera inte denna referenscapture från en funktion med lokal threshold.

Jämför med [04_capture.cpp](04_capture.cpp) och bygg egen variant.

### Del 4 - Omvandla och ta bort

Skapa destination med rätt size. Remove_if ger logiskt slut, erase krymper. Se 06_erase.cpp. C++20 erase_if förenklar borttagningen.

Jämför med [05_transform.cpp](05_transform.cpp) och bygg egen variant.

### Den avslutande uppgiften

[main.cpp](main.cpp) är ett komplett lösningsförslag. Jämför ansvar, livstid, felhantering och resultat; alternativa lösningar kan vara lika korrekta.
