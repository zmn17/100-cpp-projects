# 🗓️ Day 1: temperature-converter

## 🎯 Goal
This is a simple yet feature-rich command-line application written in C++ that converts temperatures between Celsius and Fahrenheit. It utilizes C++ streams and manipulators, along with ANSI escape codes, to provide a clear and colorful output for easy reading.

## ✨ Features
- Celsius to Fahrenheit Conversion: Converts input $C$ to $F$.
- Fahrenheit to Celsius Conversion: Converts input $F$ to $C$.
- Celsius to Kelvin Conversion: Converts input $C$ to $K$.
- Kelvin to Celsius Conversion: Converts input $K$ to $C$.
- Fahrenheit to Kelvin Conversion: Converts input $F$ to $K$.
- Kelvin to Fahrenheit Conversion: Converts input $K$ to $F$.
- Precision Formatting: Uses std::fixed and std::setprecision(2) to display results with two decimal places.
- Colorized Output: Uses ANSI escape codes for styling, making the units and calculated values distinct and easy to follow (e.g., Green  for Celsius/input, Blue for Fahrenheit/output).
- Formatted Table: Output is structured into aligned rows using std::setw.

## 🛠️ Tech Stack
* C++

## ⚙️ Requirements
- To compile and run this application, you need:
- A standard C++ compiler (e.g., GCC, Clang, or MSVC).
- C++11 or newer standard support.
- A terminal environment that supports ANSI escape codes for colored output (most modern terminals support this).

## Compile the Source Code
# Using g++
```bash
g++ main.cpp -o temperature-converter
./temperature-converter
```

## 🖼️ Screenshot
![Menu demo](temperature-converter/menu.png)
![Conversion demo](temperature-converter/demo.png)

