int main() {
  double number;
  double *pointer = &number;
  double &reference = number;

  number = 1;    // Setter number til 1
  *pointer = 2;  // Setter number til 2
  reference = 3; // Setter number til 3
  return 0;
}
