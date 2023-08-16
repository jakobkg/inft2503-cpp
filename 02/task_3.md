# Oppgave 3

```
char text[5];
char *pointer = text;
char search_for = 'e';
cin >> text;
while (*pointer != search_for) {
  *pointer = search_for;
  pointer++;
}
```

I denne kodebiten er det to mulige feil som umiddelbart stikker seg ut. Den første er at man ukritisk plasserer brukerstyrt inn-data i et allokert minneområde uten å kontrollere at inn-dataen faktisk får plass i det allokerte minnet. I dette tilfellet er det `char text[5]` som er minneområdet som fylles med brukerstyrt input via `std::cin >> text`. Siden minneområdet som er tildelt for input er på fem byte vil det bare være plass til opptil fire tegn og en null-byte. Dersom brukeren skriver inn fem eller flere tegn vil dataen overskride det allokerte minnet til `char text[]` og potensielt begynne å overskrive annet program-minne! Om teksten brukeren skriver inn er lang nok vil programmet prøve å skrive utenfor sitt tillatte minneområde, og programmet tvangsavsluttes av operativsystemet med `SIGSEGV`.

Den andre tingen som stikker seg ut er at while-løkken som ser ut som den er ment å iterere gjennom teksten heller ikke har noen kontroll som stanser løkken når den har nådd slutten på teksten, så denne løkken fortsetter å kjøre og vil skrive `'e'` til bytes utenfor minneområdet til `char text[]` før den stanser. Dersom variabelen `char search_for` har blitt plassert på en høyere minneadresse enn `char text[]` vil løkken jobbe seg frem til punktet hvor `*pointer == search_for` og while-løkken stanser. Dersom `char search_for` er plassert på en *lavere* minneadresse enn `char text[]` vil while-løkken fortsette å skrive bokstaven `'e'` til program-minnet byte for byte til den enten tilfeldigvis når en annen adresse som allerede inneholder en `'e'` slik at løkken avsluttes, eller til løkken har jobbet seg utenfor det allokerte minneområdet til prosessen og operativsystemet tvangsavslutter programmet med `SIGSEGV`.