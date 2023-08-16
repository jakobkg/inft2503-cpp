#include <iostream>
#include <string>
#include <vector>

int main() {
  std::string word1, word2, word3;
  std::cout << "Skriv inn et ord: ";
  std::cin >> word1;

  std::cout << "Skriv inn et ord til: ";
  std::cin >> word2;

  std::cout << "Og et tredje ord: ";
  std::cin >> word3;

  std::cout << std::endl;

  std::string sentence = word1 + ' ' + word2 + ' ' + word3 + '.';

  std::cout << "Du skrev " << sentence << std::endl;

  std::cout << "Første ord er " << word1.length() << " tegn," << std::endl;
  std::cout << "andre ord er " << word2.length() << " tegn," << std::endl;
  std::cout << "og tredje ord er " << word3.length() << " tegn." << std::endl;
  std::cout << std::endl;
  std::cout << "Hele setningen er " << sentence.length() << " tegn."
            << std::endl;
  std::cout << std::endl;

  std::string sentence2(sentence); // Kopi-konstruktør

  try {
    sentence2.at(10) = 'x';
    sentence2.at(11) = 'x';
    sentence2.at(12) = 'x';
  } catch (const std::exception &e) {
  }

  std::cout << "Sentence: " << sentence << std::endl;
  std::cout << "Sentence2: " << sentence2 << std::endl;
  std::cout << std::endl;

  size_t length = sentence.length() >= 5 ? 5 : sentence.length();

  std::string sentence_start(sentence.substr(0, length));

  std::cout << "Sentence: " << sentence << std::endl;
  std::cout << "Sentence start: " << sentence_start << std::endl;
  std::cout << std::endl;

  std::cout << "Setningen inneholder "
            << (sentence.find("hallo") == std::string::npos ? "ikke " : "")
            << "ordet \"hallo\"." << std::endl;

  std::string term("er");            // Søkeord
  std::vector<size_t> hit_positions; // Liste med treff

  size_t hit = sentence.find(term, 0); // Gjør første søk

  while (hit != std::string::npos) {    // Hvis det er et treff
    hit_positions.push_back(hit);       // Lagre treffet
    hit = sentence.find(term, hit + 2); // Søk videre
  }

  if (hit_positions.size() > 0) {
    std::cout << "\"er\" ble funnet på følgende posisjoner i setningen: ";

    for (auto position : hit_positions) {
      std::cout << position << ", ";
    }
  } else {
    std::cout << "\"er\" forekommer ikke i setningen.";
  }

  return 0;
}
