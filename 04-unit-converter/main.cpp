#include <iostream>

void displaymenu() {
  std::cout << std::endl;
  std::cout << "1: cm -> inch \n";
  std::cout << "2: inch -> cm \n";
  std::cout << "3: kg -> lb \n";
  std::cout << "4: lb -> kg \n";
  std::cout << "5: Exit \n";
  std::cout << std::endl;
}
int main() {

  double a, b;
  double res;

  displaymenu();

  int option;
  std::cout << "option: ";
  do {
    // check if option is valid
    if (!(std::cin >> option)) {
      std::cout << "invalid";
      return 1;
    }

    if (option == 5)
      break;

    switch (option) {
    case 1:
      std::cout << "cm: ";
      std::cin >> a;
      res = a / 2.54;
      std::cout << "inch: " << res << std::endl;
      break;
    case 2:
      std::cout << "inch: ";
      std::cin >> a;
      res = a * 2.54;
      std::cout << "cm: " << res << std::endl;
      break;
    case 3:
      std::cout << "kg: ";
      std::cin >> a;
      res = a * 2.205;
      std::cout << "lb: " << res << std::endl;
      break;
    case 4:
      std::cout << "lb: ";
      std::cin >> a;
      res = a / 2.205;
      std::cout << "kg: " << res << std::endl;
      break;
    case 5:
      std::exit(0);
      break;
    default:
      std::cout << "\nchoose correct option from the menu.\n";
    }
    displaymenu();
  } while (option != 5);

  return 0;
}
