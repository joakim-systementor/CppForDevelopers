# Övningar dag 14 - Mutex, låsning och tillståndsvariabler

Arbeta självständigt med egen kod i egen mapp/kopia. Förutsäg före körning. Övningarna är träning, ingen examinerande inlämning. C++23 är redan valt.

## Delövning 1 - Delad räknare

Två workers ökar samma int 2000 gånger var med gemensam mutex. Skriv efter avslut. Markera skyddad data.

**Klart när:** 4000 och RAII-lås kring varje uppdatering.

**Lösningsförslag:** skriv först själv. Jämför sedan med del 1 under Lösningsförslag till delövningarna och [01_mutex.cpp](01_mutex.cpp).

## Delövning 2 - Två konton

Skapa Account med saldo 100 och mutex var. Kör 100 överföringar åt varje håll samtidigt och visa total/slutvärden.

**Klart när:** 100,100 och total 200.

**Lösningsförslag:** skriv först själv. Jämför sedan med del 2 under Lösningsförslag till delövningarna och [03_scoped_lock.cpp](03_scoped_lock.cpp).

## Delövning 3 - Vänta på flagga

Skriv ready-demo utan sleep. Ändra ready under samma mutex som wait läser. Kör flera gånger och förklara signal före wait.

**Klart när:** 42 efter join, inget beroende av vald fördröjning.

**Lösningsförslag:** skriv först själv. Jämför sedan med del 3 under Lösningsförslag till delövningarna och [04_condition.cpp](04_condition.cpp).

## Delövning 4 - Stängningskontrakt

Med WorkQueue: push 10,20, close, läs båda och kontrollera nästa pop=false. Prova push efter close och tom stängd kö.

**Klart när:** FIFO 10,20; avvisad push; avslut utan evig väntan.

**Lösningsförslag:** skriv först själv. Jämför sedan med del 4 under Lösningsförslag till delövningarna och [tests.cpp](tests.cpp).

## Avslutande uppgift - återskapa main.cpp

Återskapa main.cpp med WorkQueue.hpp som stöd. Starta två `std::thread` som poppar tills false. Varje konsument har eget count, long long-summa och exception_ptr; dela inte oskyddad summa. Huvudtråden pushar 1-6 och stänger. Skapa en `CloseQueueAndJoin` direkt efter varje tråd. Vaktens destruktor stänger kön och anropar sedan `join()`, även om starten av den andra tråden misslyckas. Vänta på båda före felrapport/resultat. Skriv bara sammanlagt antal och summa, då arbetsfördelningen får variera. Prova tom och en-post-kö.

Förväntad utskrift med angiven indata:

```text
Items: 6
Total: 21
```

**Klart när:** du kan förklara flödet och få angivna resultat med egen kod. Studera sedan [main.cpp](main.cpp) som ett lösningsförslag, inte enda tillåtna lösning.

## Visa gärna för en klasskamrat

Visa egen lösning, ett gränsfall och varför du valt arbetssättet. Be om en fråga eller förbättring. Återkoppling är frivillig; utan kamrat gör du egen kontroll och antecknar vad som fungerar och vad du vill fråga läraren.

## Lösningsförslag till delövningarna

Använd efter eget försök. Filerna visar principen; anpassa till övningens indata.

### Del 1 - Delad räknare

Dela samma mutex/counter. Lock_guard ligger i loopblocket och uppdatering sker inom det. Läs efter båda avslutats.

Jämför med [01_mutex.cpp](01_mutex.cpp) och bygg egen variant.

### Del 2 - Två konton

Scoped_lock tar två olika kontomutexar före minskning/ökning. Fälten har gemensam invariant. Anropa inte med samma konto.

Jämför med [03_scoped_lock.cpp](03_scoped_lock.cpp) och bygg egen variant.

### Del 3 - Vänta på flagga

Unique_lock och wait(lock,predicate) i konsumenten. Producent sätter ready under lock_guard och notifierar. Redan sant predikat ger ingen väntan.

Jämför med [04_condition.cpp](04_condition.cpp) och bygg egen variant.

### Del 4 - Stängningskontrakt

Close sätter closed under mutex och notify_all. Pop tömmer data, ger false när stängd och tom. Push kontrollerar closed under samma lås. Se 05_queue.cpp för samtidighet.

Jämför med [tests.cpp](tests.cpp) och bygg egen variant.

### Den avslutande uppgiften

[main.cpp](main.cpp) är ett komplett lösningsförslag. Jämför ansvar, livstid, felhantering och resultat; alternativa lösningar kan vara lika korrekta.
