int main() {
  int a = 5;
  // int &b;
  // b kan ikke deklareres som en referanse uten å
  // spesifisere hvilken variabel den er en referanse til
  int *b; // Fikset ved å gjøre b til en u-initialisert peker
  int *c;
  // c = &b;
  // c er en peker (int*), &b er en referanse til en peker (int**),
  // disse to er ikke kompatible typer 
  c = b; // Fikset ved å endre &b til b, både b og c er av typen int*
  // *a = *b + *c;
  // *a er minneaddressen til a, denne kan ikke skrives til
  a = *b + *c; // Fikset ved å skrive til verdien til a og ikke addressen til a
  // &b = 2;
  // En referanse kan ikke referere til en verdi, kun til variabler
  *b = 2; // Fikset ved å behandle b som en peker, ikke en referanse
  return 0;
}
