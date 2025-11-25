# 🗓️ Day 4 : 07 currency converter

A simple, fast, and terminal-based **Currency Converter** written in
**C++**, using:

-   **cURL** for HTTP GET requests\
-   **nlohmann::json** for JSON parsing\
-   **ExchangeRatesAPI** (exchangeratesapi.io) for live currency data\
-   Clean screen UI + formatted output

This tool allows you to convert between any two supported currency
symbols (e.g., AUD → USD) with real-time exchange rates.

## ✨ Features

-   Convert any amount between **two currency symbols**
-   Fetches **live exchange rates**
-   Automatic uppercasing of currency codes
-   Clean terminal UI (`clearScreen()`)
-   JSON-based accuracy
-   Config file support for API key

## 📂 Project Structure

    .
    ├── src/
    │   ├── main.cpp
    ├── config
    └── README.md

## 🔧 Requirements

-   C++17 or later\
-   cURL library (libcurl)\
-   nlohmann::json\
-   API key from https://exchangeratesapi.io/

## 🔐 Config File

Create a file named:

    config

Put your API key:

    YOUR_API_KEY_HERE

## 🚀 Build & Run

Build:

    g++ main.cpp -lcurl

Run:

    ./app

## 🖥 Example Output

    ========== RATES ==========
    AUD: 1.78317
    USD: 1.15276
    ===========================
    12 AUD = 7.7576 USD

## 📦 Dependencies

-   nlohmann::json (header-only)
-   libcurl

## 📄 License

MIT License.
