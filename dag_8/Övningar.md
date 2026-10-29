# Övningar dag 8 - RAII och smarta pekare

Gör övningarna självständigt med egen kod. Visa gärna för en klasskamrat efteråt. Använd lösningsförslagen för jämförelse efter ditt eget försök; gör annars samma kontroller själv.

## Start

Skapa en C++23-labb. Utgå från dag 7:s beteende och ändra hur resurser ägs, inte vad beräkningen gör. Du behöver inte skriva egna minneshanterare eller trådar.

## A - ensamägande och flytt

1. Skapa ett int med make_unique och läs det genom ägaren.
2. Hämta en observatör med get. Flytta ägandet till en ny unique_ptr med std::move.
3. Visa att den gamla ägaren är tom, att den nya kan läsa och att observatören bara får användas medan objektet fortfarande lever.
4. Refaktorera dag 7:s array till make_unique<int[]>(3). Behåll utskriften 10 20 30 utan manuell delete[].

**Klart när:** inga råa pekare äger de dynamiska objekten och du kan ange vad som händer vid scope-slut.

## B - delad livstid och svag observation

1. Skapa ett shared_ptr till 42 och en kopia i ett inre block. Visa 2 ägare inne och 1 efter blocket.
2. Skapa separat en weak_ptr-observatör. Locka den medan en stark ägare finns; kontrollera att den är expired när ägaren har lämnat sitt scope.
3. Rita en förälder/barn-relation med två starka tillbaka-pilar. Föreslå en svag relation som kan bryta en ägandecykel utan att köra ett läckande program.

**Klart när:** du kan motivera varför weak inte förlänger livstiden och varför shared inte är automatiskt förstaval.

## C - RAII vid fel och filåtkomst

1. Öppna CMakeLists.txt med ifstream i ett begränsat scope och läs första raden. Ingen manuell close behövs för scope-städningen.
2. Använd en liten livstidsmarkör med destructor-utskrift och unique_ptr. Kasta ett runtime_error efter konstruktion och fånga det utanför scope.
3. Kontrollera att destruktionen sker före catch. Beskriv hur samma regel hjälper med verkliga resurser.

**Klart när:** du kan följa städningen på normal väg och felväg utan duplicerad delete-kod.

## Lösningsförslag till delövningarna

| Del | Förslag att jämföra med |
|---|---|
| A | 02_unique.cpp och 03_array.cpp |
| B | 04_shared.cpp och 05_weak.cpp |
| C | 01_raii.cpp och 06_exception.cpp |

Extra: [extra_20_array.cpp](extra_20_array.cpp) visar make_shared för arrayer i C++20. Använd delat ägande bara när uppgiften verkligen kräver det.

## Avslutningsövning - återskapa main.cpp

Skapa abstrakta Source med virtuell read och virtuell destructor samt ConstantSource som validerar 0-100. Äg en ConstantSource(80) med unique_ptr<Source>. Läs först genom en const rå observatör. Flytta ägaren, visa att den tidigare ägaren är tom och läs genom den nya. Försök skapa värde 101 med make_unique; fånga out_of_range och skriv Rejected. Ingen manuell new/delete ska finnas i lösningen.

```text
Observed: 80
Old owner empty: true
New owner: 80
Rejected
```

**Klart när:** utfallet stämmer och basdestructorn möjliggör korrekt destruktion genom basägaren. Lösningsförslag: main.cpp, efter ditt eget försök.

## Visa gärna för en klasskamrat

Visa ägaröverföringen och felvägen. Anteckna ägare respektive observatör i uppgift 1:s tänkta modell och motivera varför unique_ptr räcker för strategin.
