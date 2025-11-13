#include <iomanip>
#include <iostream>

void display_menu() {
  std::cout << "1: C -> F | F -> C" << std::endl;
  std::cout << "2: C -> K | K -> C" << std::endl;
  std::cout << "3: F -> K | K -> F" << std::endl;
  std::cout << "4: Exit" << std::endl;
}

template <typename T0, typename T1, typename T2, typename T3>
void print_row(std::ostream &os, T0 const &t0, T1 const &t1, T2 const &t2,
               T3 const &t3) {
  os << std::endl;

  // Units
  os << "\033[0;32m" << std::setw(1) << t0 << "\033[0m"
     << "\033[0;34m" << std::setw(10) << t1 << "\033[0m" << std::endl;

  os << "\033[1;32m" << std::setw(4) << std::fixed << std::setprecision(2) << t2
     << "\033[0m"
        "\033[1;34m"
     << std::setw(10) << std::fixed << std::setprecision(2) << t3 << "\033[0m"
     << std::endl;

  // Units
  os << "\033[0;34m" << std::setw(1) << t1 << "\033[0m"
     << "\033[0;32m" << std::setw(10) << t0 << "\033[0m" << std::endl;

  os << "\033[1;34m" << std::setw(4) << std::fixed << std::setprecision(2) << t3
     << "\033[0m"
     << "\033[1;32m" << std::setw(10) << std::fixed << std::setprecision(2)
     << t2 << "\033[0m" << std::endl;
  os << std::endl;
}

int main() {

  int option;
  do {
    // display the conversion menu
    display_menu();

    double Ctemp;
    double Ktemp;
    double Ftemp;

    std::cout << "option :";
    std::cin >> option;

    switch (option) {
    case 1:
      std::cout << "Temperature (C): ";
      std::cin >> Ctemp;
      Ftemp = (Ctemp * 1.8) + 32;
      print_row(std::cout, "C", "F", Ctemp, Ftemp);
      break;
    case 2:
      std::cout << "Temperature (C): ";
      std::cin >> Ctemp;
      Ktemp = Ctemp + 273.15;
      print_row(std::cout, "C", "K", Ctemp, Ktemp);
      break;
    case 3:
      std::cout << "Temperature (F): ";
      std::cin >> Ftemp;
      Ktemp = (Ftemp + 459.67) / 1.8;
      print_row(std::cout, "F", "K", Ftemp, Ktemp);
      break;
    case 4:
      std::exit(0);
    default:
      std::cout << "Please choose the correct option.\n";
    }

  } while (option != 0);

  return 0;
}
