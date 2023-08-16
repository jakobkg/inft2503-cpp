# INFT2503: C++ for programmerere
Dette repoet inneholder løsningene mine på øvingsoppgavene i INFT2503, høsten 2023. Hver enkelt øving er satt opp som et separat CMake-prosjekt, så vanlig prosess for CMake-prosjekter brukes for hver øving for seg.

## Avhengigheter
Siden øvingene er skrevet i C++ og konfigurert som CMake-prosjekter kreves minst:

- En C++-kompilator
- CMake
- Make

Noen øvinger har også ekstra avhengigheter:

- Øving 4
  - GTKMM 3
- Øving 6
  - Boost
- Øving 10
  - SFML
  - GLM
  - Bullet

På de fleste Linux-distribusjoner er alle disse lett tilgjengelige fra pakke-systemet, og kan installeres med en kommando i 
terminalen.

### Debian-baserte distribusjoner (Ubuntu, Mint)
**Ikke testet, kan ha mangler**

`sudo apt install make cmake gcc libgtkmm-3.0-dev libboost-dev libsfml-dev libglm-dev libbullet-dev`

### Red Hat-distribusjoner (Fedora)
`sudo dnf install make cmake gcc gtkmm3.0-devel boost-devel sfml-devel glm-devel bullet-devel mesa-libGLU-devel`

### Arch-baserte distribusjoner (Arch, Manjaro, Garuda)
**Ikke testet, kan ha mangler**

`sudo pacman -S make cmake gcc gtkmm3 sfml glm bullet`

## Kompilere og kjøre oppgaver
Åpne mappen til oppgaven du vil jobbe med i favoritt-terminalen din (f.eks. `cd 04` for øving 4). Opprett en ny mappe for kompilerte filer, og åpne den (f.eks. `mkdir build && cd build`). Dette gjøres for å unngå at kodefiler og kompilerte programfiler blandes og lager masse rot i prosjektet! Kjør CMake for å konfigurere bygg-filer for prosjektet med `cmake ..`, om alt gikk som det skal vil du se `-- Build files have been written to: ...` på slutten av utskriften fra CMake.

Hver deloppgave er satt opp som separate kompileringsenheter i CMake-prosjektene. For eksempel inneholder øving 4 to separate oppgaver, `task_1.cpp` og `task_2.cpp`. Etter å ha kjørt CMake i forrige steg kan du nå kompilere oppgave 1 med `make task_1`, kompilere oppgave 2 med `make task_2` eller kompilere hele greia med `make all` eller bare `make`. Om du ikke er sikker på hvilke muligheter som fins, kjør `make help` for å få en liste over tilgjengelige oppgaver å kompilere!

Etter å ha kjørt en kompilering er den ferdige programfilen klar. Om du for eksempel gjorde `make task_1` finnes det nå en programfil som heter `task_1`. Kjør den med `./task_1`!