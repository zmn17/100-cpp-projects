// =========================================================================
// FILE: password_generator.cpp
// DESCRIPTION: A command-line utility for generating password.
//              Supports positional arguments (<script> <op> <size>) and
// AUTHOR: Zamin Ahmadi (Developer)
// CREATED: 2025-11-16
// =========================================================================

#include <iostream>
#include <random>
#include <string>

int main(int argc, char *argv[]) {
  // Password Generator Header - Usage
  if (argc != 3) {
    std::cerr << "============================================================"
              << std::endl;
    std::cerr << "       C++ Command-Line Password Generator Usage Error      "
              << std::endl;
    std::cerr << "============================================================"
              << std::endl;
    std::cerr << "Usage: " << argv[0] << " <option> <size>" << std::endl;
    std::cerr << "Example: " << argv[0] << " -s 16" << std::endl;
    return 1;
  }

  // password length
  int passwd_size;

  // get the password size from argument
  if (argc == 3 && std::string(argv[1]) == "-s") {
    passwd_size = std::stoi(argv[2]);
  }

  // characters collection
  std::string chars = "ABCDEFGHIJKLMNOPQRSTUVWXYZ"
                      "abcdefghijklmnopqrstuvwxyz"
                      "0123456789"
                      "!@#$%&*()-_+=";

  // randomness engine -> for random index
  std::random_device rd;
  std::mt19937 gen(rd());
  // range: chars size
  std::uniform_int_distribution<> dist(0, chars.size() - 1);

  // size of collection
  size_t chars_size = chars.size();

  // string password
  std::string password;
  password.reserve(passwd_size);

  // creating password
  for (int i = 0; i < passwd_size; i++) {
    password += chars[dist(gen)];
  }

  // output -> password and its size
  std::cout << "\033[44m\033[1;30m" << password << "\033[0m" << std::endl;
  std::cout << "Size: " << "\033[1;33m" << password.size() << "\033[0m"
            << std::endl;

  return 0;
}
