#include <curl/curl.h>
#include <fstream>
#include <iostream>
#include <nlohmann/json.hpp>
#include <stdexcept>
#include <string>

using json = nlohmann::json;

// functions
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp);
std::string readConfig();
std::string get_data(const char *url);
void clearScreen();

int main() {
  // Data
  std::string fromSymbol, toSymbol;
  double amount;

  // get the data from user
  std::cout << "From: ";
  std::cin >> fromSymbol;
  std::transform(fromSymbol.begin(), fromSymbol.end(), fromSymbol.begin(),
                 ::toupper);

  std::cout << "To: ";
  std::cin >> toSymbol;

  std::transform(toSymbol.begin(), toSymbol.end(), toSymbol.begin(), ::toupper);

  std::cout << "amount: ";
  std::cin >> amount;

  // get the api key from config file
  std::string api_key = readConfig();

  // construct the url
  std::string getURL =
      "http://api.exchangeratesapi.io/v1/latest?access_key=" + api_key +
      "&symbols=" + fromSymbol + "," + toSymbol;

  // curl the url -> GET
  std::string data = get_data(getURL.c_str());

  // parse the json data
  json jsonData = json::parse(data);

  // get the rates and  convert it to double
  double from = jsonData["rates"][fromSymbol].get<double>();
  double to = jsonData["rates"][toSymbol].get<double>();

  // clear the screen once getting the input data
  clearScreen();

  // print the rate
  std::cout << "======== RATES ========" << std::endl;
  std::cout << fromSymbol << ": " << from << std::endl;
  std::cout << toSymbol << ": " << to << std::endl;
  std::cout << "=======================" << std::endl;

  // FORMULA: TO = AMOUNT * (TO_PER_EUR / FROM_PER_EUR)
  double finalValue = amount * (to / from);

  // output the final value
  std::cout << std::fixed << std::setprecision(2) << amount << " " << fromSymbol
            << " = " << finalValue << " " << toSymbol << std::endl;

  return 0;
}

// clear the screen
void clearScreen() { std::cout << "\033[2J\033[H" << std::flush; }

// Callback function to write the received data
size_t WriteCallback(void *contents, size_t size, size_t nmemb, void *userp) {
  // 1. casting userp -> string
  // 2. appending:
  //  2a. castring contents to char* (string)
  //  2b.length
  ((std::string *)userp)->append((char *)contents, size * nmemb);
  return size * nmemb;
}

std::string get_data(const char *url) {
  CURL *curl;
  CURLcode res;
  std::string readBuffer;

  // 1. initialize libcurl
  curl_global_init(CURL_GLOBAL_ALL);

  // 2. Get a curl handle
  curl = curl_easy_init();

  if (curl) {
    // 3. set options for the transfer
    curl_easy_setopt(curl, CURLOPT_URL, url);

    // Set the callback function to handle received data
    curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
    // Pass the string buffer to the callback function
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

    // 4. perform the request
    res = curl_easy_perform(curl);

    // check for errors
    if (res != CURLE_OK) {
      std::cerr << "curl_easy_perform() failed: " << curl_easy_strerror(res)
                << std::endl;
    } else {
      return readBuffer;
    }

    // 5. cleanup the curl handle
    curl_easy_cleanup(curl);
  }
  // 6. global cleanup
  curl_global_cleanup();

  return 0;
}

std::string readConfig() {
  std::ifstream file(std::string(getenv("HOME")) +
                     "/dev/100-cpp-projects/07-currency-converter/config");
  std::string line;

  while (std::getline(file, line)) {
    if (line.rfind("API_KEY=", 0) == 0) {
      return line.substr(8);
    }
  }
  throw std::runtime_error("API_KEY not found in config");
}
