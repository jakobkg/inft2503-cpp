# Oppgave 2

De gitte linjene med kode:

```
char *line = nullptr;   // eller char *line = 0;
strcpy(line, "Dette er en tekst");
```

Første linje setter variabelen `line` til å være en peker til minneadresse `0x0`.

Ifølge `man strcpy` har `strcpy` signaturen `char *strcpy(char *restrict dst, const char *restrict src);`, det vil si at metoden forsøker å kopiere innholdet fra det andre argumentet sitt til adressen angitt i det første argumentet. Andre linje forsøker altså å kopiere teksten `"Dette er en tekst"` til minneadesse `0x0`. Siden minneadressen `0x0` ikke er skrivbar vil dette programmet i de fleste tilfeller tvangsavsluttes av operativsystemet med `SIGSEGV`, "segmentation fault".

I situasjoner der det ikke er noe operativsystem som følger med på slikt, som f.eks. i embedded, kan dette føre til at man begynner å skrive til minneadresse `0x0` og begynnner å overskrive kode-sektoren av programmet som er lastet inn i minnet.