# Övningar dag 11 - Mallar och STL-behållare

Arbeta självständigt med egen kod i egen mapp/kopia. Förutsäg före körning. Övningarna är träning, ingen examinerande inlämning. C++23 är redan valt.

## Delövning 1 - Funktionsmall

Skriv maximum för två värden av samma typ. Kör int, double och string. Prova och förklara ett blandat anrop.

**Klart när:** Tre korrekta resultat och förklaring av härledningsfelet.

**Lösningsförslag:** skriv först själv. Jämför sedan med del 1 under Lösningsförslag till delövningarna och [01_function.cpp](01_function.cpp).

## Delövning 2 - Klassmall

Skriv Collection<T> med add,size,const at. Skapa Collection<int> med 10,30 och Collection<string> med kitchen.

**Klart när:** Size 2, andra talet 30 och strängen kitchen.

**Lösningsförslag:** skriv först själv. Jämför sedan med del 2 under Lösningsförslag till delövningarna och [02_class.cpp](02_class.cpp).

## Delövning 3 - Behållare för räkning

Räkna ID-sekvensen 2,1,2,3 med map och unordered_map. Skriv map sorterat och jämför hashbehållaren med direkta uppslag.

**Klart när:** 1:1, 2:2, 3:1 i båda.

**Lösningsförslag:** skriv först själv. Jämför sedan med del 3 under Lösningsförslag till delövningarna och [07_map.cpp](07_map.cpp).

## Delövning 4 - Lagring och giltighet

Skapa vector 10,20, reserve(4), ta referens till första, lägg in 30 och ändra via referensen. Beskriv senare tillväxt över kapaciteten.

**Klart när:** Giltig referens i just detta fall och avvisat at(9).

**Lösningsförslag:** skriv först själv. Jämför sedan med del 4 under Lösningsförslag till delövningarna och [04_invalidation.cpp](04_invalidation.cpp).

## Avslutande uppgift - återskapa main.cpp

Skriv egen Collection<T> och main.cpp. Samlingen innehåller Measurement-poster {2,40},{1,20},{1,80}. Gruppera i map<int,Statistics> och skriv sensor-ID, antal, medelvärde i stigande ID-ordning. Använd gärna Measurement.hpp, men skriv själv klassmallen och grupperingsloopen. Parser och parallellisering ingår inte här.

Förväntad utskrift med angiven indata:

```text
1: count=2 mean=50
2: count=1 mean=40
```

**Klart när:** du kan förklara flödet och få angivna resultat med egen kod. Studera sedan [main.cpp](main.cpp) som ett lösningsförslag, inte enda tillåtna lösning.

## Visa gärna för en klasskamrat

Visa egen lösning, ett gränsfall och varför du valt arbetssättet. Be om en fråga eller förbättring. Återkoppling är frivillig; utan kamrat gör du egen kontroll och antecknar vad som fungerar och vad du vill fråga läraren.

## Lösningsförslag till delövningarna

Använd efter eget försök. Filerna visar principen; anpassa till övningens indata.

### Del 1 - Funktionsmall

Returnera first > second ? first : second. maximum(3,7.5) kan inte härleda samma T; maximum<double>(3,7.5) väljer konvertering uttryckligt.

Jämför med [01_function.cpp](01_function.cpp) och bygg egen variant.

### Del 2 - Klassmall

Lagra vector<T>. Add använder push_back; const at returnerar const T& från vector::at. Definiera i headern.

Jämför med [02_class.cpp](02_class.cpp) och bygg egen variant.

### Del 3 - Behållare för räkning

Öka counts[id]. Map-iteration följer nyckelordning. Använd at(1),at(2),at(3) för stabil hash-jämförelse; anta inte iterationsordning. Se också 08_unordered.cpp.

Jämför med [07_map.cpp](07_map.cpp) och bygg egen variant.

### Del 4 - Lagring och giltighet

Ingen reallokering sker från size 2 till 3 med capacity minst 4. Reallokering invalidaterar elementreferenser. Läs inte gammal referens; hämta elementet på nytt.

Jämför med [04_invalidation.cpp](04_invalidation.cpp) och bygg egen variant.

### Den avslutande uppgiften

[main.cpp](main.cpp) är ett komplett lösningsförslag. Jämför ansvar, livstid, felhantering och resultat; alternativa lösningar kan vara lika korrekta.
