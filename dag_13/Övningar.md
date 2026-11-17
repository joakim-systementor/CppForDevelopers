# Övningar dag 13 - Trådar, livstid och datakapplöpning

Arbeta självständigt med egen kod i egen mapp/kopia. Förutsäg före körning. Övningarna är träning, ingen examinerande inlämning. C++23 är redan valt.

## Delövning 1 - Resultat efter join

Skriv thread som beräknar 6*7 i separat result. Läs först efter join och markera livstiderna.

**Klart när:** 42 och förklaring av placeringen av läsningen.

**Lösningsförslag:** skriv först själv. Jämför sedan med del 1 under Lösningsförslag till delövningarna och [01_thread.cpp](01_thread.cpp).

## Delövning 2 - Jämför capture

Återskapa kopie- och referensexemplet med value 10. Ändra originalet till 20 mellan första konstruktionen och join. Starta sedan worker som ökar originalet.

**Klart när:** 11 och 21 utan samtidiga konflikter.

**Lösningsförslag:** skriv först själv. Jämför sedan med del 2 under Lösningsförslag till delövningarna och [02_capture.cpp](02_capture.cpp).

## Delövning 3 - Lokala delar och udda storlek

Summera 10,20,30,40,50 med två `std::thread`, dela vid `size / 2` och spara separata `long long`-summor. Anropa `join()` på båda trådarna före utskriften. Prova tom och en post.

**Klart när:** 150 totalt; tomt ger 0; en post räknas en gång.

**Lösningsförslag:** skriv först själv. Jämför sedan med del 3 under Lösningsförslag till delövningarna och [03_local_results.cpp](03_local_results.cpp).

## Delövning 4 - Delad räknare och worker-fel

Öka atomic<int> 1000 gånger i två workers. Förklara varför vanlig int vore fel. Separat: fånga ett worker-kast och överför till huvudtråden.

**Klart när:** 2000 och motivering; worker-fel hanteras efter join.

**Lösningsförslag:** skriv först själv. Jämför sedan med del 4 under Lösningsförslag till delövningarna och [04_atomic.cpp](04_atomic.cpp).

## Avslutande uppgift - återskapa main.cpp

Återskapa main.cpp med const vector<int> {1,2,3,4,5,6,7}. Dela vid size/2. Två `std::thread` summerar varsin del med `long long` och `0LL`. Anropa `join()` på båda före utskriften av antal, delar och total. Ingen atomic eller mutex behövs då workers skriver egna variabler. Prova tom lista, en post och jämnt antal; jämför med sekventiell accumulate. Tidmätning är inget krav här.

Förväntad utskrift med angiven indata:

```text
Items: 7
Parts: 6 22
Total: 28
```

**Klart när:** du kan förklara flödet och få angivna resultat med egen kod. Studera sedan [main.cpp](main.cpp) som ett lösningsförslag, inte enda tillåtna lösning.

## Visa gärna för en klasskamrat

Visa egen lösning, ett gränsfall och varför du valt arbetssättet. Be om en fråga eller förbättring. Återkoppling är frivillig; utan kamrat gör du egen kontroll och antecknar vad som fungerar och vad du vill fråga läraren.

## Lösningsförslag till delövningarna

Använd efter eget försök. Filerna visar principen; anpassa till övningens indata.

### Del 1 - Resultat efter join

Resultatet deklareras före tråden och fångas via referens. Ingen annan använder det under arbetet; join avslutar fasen.

Jämför med [01_thread.cpp](01_thread.cpp) och bygg egen variant.

### Del 2 - Jämför capture

Kopian lagrar 10 och skriver bara copied_result. Nästa worker får originalet i separat fas. Huvudtråden läser efter respektive join.

Jämför med [02_capture.cpp](02_capture.cpp) och bygg egen variant.

### Del 3 - Lokala delar och udda storlek

Mitten size/2 ger delar 30 och 120. Exempelfilen väljer i stället tre/två och ger 60/90; båda är giltiga delningar. Tomma intervall summeras från 0LL.

Jämför med [03_local_results.cpp](03_local_results.cpp) och bygg egen variant.

### Del 4 - Delad räknare och worker-fel

Varje ++ är atomiskt. För felet: se 05_worker_error.cpp, fånga current_exception och återkasta efter avslut. Låt inte kast lämna trådfunktionen.

Jämför med [04_atomic.cpp](04_atomic.cpp) och bygg egen variant.

### Den avslutande uppgiften

[main.cpp](main.cpp) är ett komplett lösningsförslag. Jämför ansvar, livstid, felhantering och resultat; alternativa lösningar kan vara lika korrekta.
