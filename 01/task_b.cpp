#include <fstream>
#include <iostream>

void read_temperatures(double temperatures[], int length);

const char filename[] = "temperatures"; // Relativ fil til cwd
const int LENGTH = 5;

int main() {
  double temperatures[LENGTH];
  int less_than_ten = 0;
  int ten_to_twenty = 0;
  int more_than_twenty = 0;

  read_temperatures(temperatures, LENGTH);

  for (auto temperature : temperatures) {
    if (temperature < 10)
      less_than_ten++;
    else if (temperature > 20)
      more_than_twenty++;
    else
      ten_to_twenty++;
  }

  std::cout << "Antall under 10 er " << less_than_ten << std::endl;
  std::cout << "Antall mellom 10 og 20 er " << ten_to_twenty << std::endl;
  std::cout << "Antall over 20 er " << more_than_twenty << std::endl;

  return 0;
}

void read_temperatures(double temperatures[], int length) {
  std::ifstream temperature_file;
  temperature_file.open(filename);

  if (!temperature_file) {
    std::cout << "Noe gikk galt ved åpning av temperaturdata-fil" << std::endl;
    exit(1);
  }

  for (int i = 0; i < length; i++) {
    temperature_file >> temperatures[i];
  }

  temperature_file.close();
}
