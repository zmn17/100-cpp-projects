#include <iostream>

void display_menu() {
  std::cout << "1: Add" << std::endl;
  std::cout << "2: Subtract" << std::endl;
  std::cout << "3: Multiply" << std::endl;
  std::cout << "4: Divide" << std::endl;
  std::cout << "5: Exit" << std::endl;
}

int main() {
  double a, b;
  int option;
  double res;

  do {
    display_menu();

    std::cout << "Enter your choice: ";
    if (!(std::cin >> option)) {
      std::cout << "Invalid input" << std::endl;
      return 1;
    }

    if (option == 5) {
      std::cout << "Exiting calculator...\n";
      break;
    }

    if (option >= 1 && option <= 4) {
      std::cout << "a: ";
      std::cin >> a;

      std::cout << "b: ";
      std::cin >> b;
    }

    switch (option) {
    case 1:
      res = a + b;
      std::cout << "Res: " << res << std::endl << std::endl;
      break;
    case 2:
      res = a - b;
      std::cout << "Res: " << res << std::endl << std::endl;
      break;
    case 3:
      res = a * b;
      std::cout << "Res: " << res << std::endl << std::endl;
      break;
    case 4:
      if (b != 0) {
        res = a / b;
        std::cout << "Res: " << res << std::endl << std::endl;
      } else {
        std::cout << "Error: Division by zero is not allowed.\n";
      }
      break;
    case 5:
      std::exit(0);
      break;
    default:
      std::cout << "Please choose correct option... \n";
    }
  } while (option != 5);

  return 0;
}
