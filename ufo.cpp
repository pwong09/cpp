#include <iostream>
#include <cctype>
#include "ufo_functions.hpp"

int main() {
  greet();

//global scope variables
std::string codeword = "CODECADEMY";
std::string answer = "__________";

int misses = 0;
std::vector<char> incorrect;
bool guess = false;
char letter;

while (answer != codeword && misses < 7) {
  display_misses(misses);
  display_status(incorrect, answer);
  std::cout << "Please enter your guess: ";
  std::cin >> letter;
  letter = toupper(letter);
  for (int k = 0; k < codeword.length(); k++) {
    if (letter == codeword[k]) {
      answer[k] = letter;
      guess = true;
      std::cout << "\nCorrect!\n";
    } 
  }
  if (guess) {
    std::cout << "\nCorrect!\n";
   } else {
      std::cout << "\nIncorrect! The tractor beam pulls the person in further.\n";
      incorrect.push_back(letter);
      misses++;
    }
    guess = false;
  }

if (answer == codeword) {
  std::cout << "Hooray! You saved the person and earned a medal of honor!\n";
  std::cout << "The codeword was: " << codeword << "\n";
} else {
  std::cout << "Oh no! The UFO just flew away with another person!\n";
  std::cout << "The codeword was: " << codeword << "\n";
}

}
