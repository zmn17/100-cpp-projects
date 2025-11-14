#include <iostream>

int main() {
  double weight, height;
  double bmi;

  std::cout << "your weight: ";
  std::cin >> weight;

  std::cout << "your height: ";
  std::cin >> height;

  bmi = (weight / (height * height));

  std::cout << "BMI: " << "\033[1;32m" << bmi << "\033[0m" << std::endl;
  return 0;
}
