#include <chrono>
#include <iostream>
#include <random>

int main() {
  // randomness engine
  unsigned seed =
      std::chrono::high_resolution_clock::now().time_since_epoch().count();
  std::mt19937 engine(seed);

  // create uniform integer distribution
  std::uniform_int_distribution<> dist(1, 80); // 1 - 80

  int to_be_guessed = dist(engine);
  int num;
  do {
    std::cout << "Guess: ";
    std::cin >> num;

    if (num < to_be_guessed)
      std::cout << "Its bigger.\n";
    else if (num > to_be_guessed) {
      std::cout << "Its smaller.\n";
    } else if (num == to_be_guessed) {
      std::cout << "hooraa! you got it!\n";
    }
  } while (num != to_be_guessed);
  return 0;
}
