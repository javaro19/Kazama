<div align="center">

# ⚔️ Kazama

### Lightweight, header-only utility library for C++

<p align="center">
  <img src="https://img.shields.io/badge/C%2B%2B-17%2B-00599C?style=for-the-badge&logo=c%2B%2B&logoColor=white"/>
  <img src="https://img.shields.io/badge/License-MIT-green?style=for-the-badge&logo=opensourceinitiative&logoColor=white"/>
  <img src="https://img.shields.io/badge/Header--Only-Yes-blueviolet?style=for-the-badge"/>
  <img src="https://img.shields.io/badge/Dependencies-None-ff69b4?style=for-the-badge"/>
</p>

<p align="center">
  <img src="https://img.shields.io/badge/Platform-Windows%20%7C%20Linux%20%7C%20macOS-0078D6?style=for-the-badge&logo=windows&logoColor=white"/>
  <img src="https://img.shields.io/badge/Author-Lumi-ff6b6b?style=for-the-badge&logo=github&logoColor=white"/>
  <img src="https://img.shields.io/badge/Status-Active-brightgreen?style=for-the-badge"/>
</p>

***

*Drop it in, include it, use it. No builds, no dependencies.*

</div>

***

## 📖 About the project

**Kazama** is a collection of authorial, header-only utility libraries for C++. Instead of writing the same things from scratch in every project - just copy the appropriate `.hpp` file and you're done.

All code is written with **minimalism**, **portability**, and **zero performance overhead** in mind. It uses only the standard C++ library - nothing more is needed.

***

## 📦 Contents

### `math.hpp` - Mathematical utilities

Mathematical functions available at compile time (`constexpr`).

| Function | Description |
|--------|------|
| `kazama::perc(x, y)` | Calculates `y`% of the absolute value `x`. Works with any numeric types. |
| `kazama::quad(a, b, c)` | Discriminant of quadratic equation - `b² - 4ac`. |

```cpp
auto discount     = kazama::perc(200.0, 15);       // 15% of 200 → 30.0
auto discriminant = kazama::quad(1.0, -3.0, 2.0);  // (-3)² - 4·1·2 = 1
```

***

### `utils.hpp` - General utilities

Useful functions for console handling, input, randomness, and strings.

#### 🖥️ Console

| Function | Description |
|--------|------|
| `kazama::console_clear()` | Clears the terminal. Uses native Win32 API on Windows, ANSI on others. |
| `kazama::console_setup(title)` | Sets console title and enables UTF-8 (Windows), sets terminal title (others). |

#### ⏱️ Time

| Function | Description |
|--------|------|
| `kazama::wait_s(s)` | Pauses execution for the specified number of seconds. |
| `kazama::wait_ms(ms)` | Pauses execution for the specified number of milliseconds. |

#### ⌨️ Input

| Function | Description |
|--------|------|
| `kazama::input(s)` | Reads entire line from `stdin`, skipping leading whitespace. |
| `kazama::input_clear()` | Clears the input buffer after read. |
| `kazama::trim(s)` | Removes leading and trailing whitespace from a string (in-place). |
| `kazama::prompt(question)` | Prints a question, reads a line from `stdin` and returns it trimmed. |

#### 🎲 Randomness

| Function | Description |
|--------|------|
| `kazama::irandom(x, y)` | Random integer from range `[x, y]`. |
| `kazama::frandom(x, y)` | Random floating-point `double` from range `[x, y]`. |

> Both functions use `std::mt19937` seeded by `std::random_device`.

#### 🔤 Strings

| Function | Description |
|--------|------|
| `kazama::to_lower(s)` | Converts string to lowercase (in-place). |
| `kazama::to_upper(s)` | Converts string to uppercase (in-place). |
| `kazama::is_alpha(s)` | Checks if every character is a letter. |
| `kazama::is_digit(s)` | Checks if every character is a digit. |
| `kazama::is_alnum(s)` | Checks if every character is a letter or digit. |
| `kazama::is_lower(s)` | Checks if every character is lowercase. |
| `kazama::is_upper(s)` | Checks if every character is uppercase. |
| `kazama::is_punct(s)` | Checks if every character is punctuation. |
| `kazama::is_space(s)` | Checks if every character is whitespace. |

***

## 🚀 Installation

Kazama is **header-only** - just copy the needed files to your project:

```
your-project/
├── kazama/
│   ├── math.hpp
│   └── utils.hpp
└── main.cpp
```

Then compile normally:

```bash
# GCC / Clang
g++ -std=c++17 main.cpp -o app

# MSVC
cl /std:c++17 main.cpp
```

> ⚠️ **C++17** or newer required.

***

## 💡 Usage example

```cpp
#include "kazama/math.hpp"
#include "kazama/utils.hpp"

int main() {
    // Console setup
    kazama::console_setup("My Application");
    kazama::console_clear();

    // Read name
    std::string name = kazama::prompt("Enter your name: ");
    kazama::to_lower(name);

    if (!kazama::is_alpha(name)) {
        // Name contains invalid characters
        return 1;
    }

    // Generate random number and calculate percentage
    int result        = kazama::irandom(1, 100);
    double threshold  = kazama::perc(result, 20); // 20% of result

    kazama::wait_ms(500);
    return 0;
}
```

***

## 🎯 Philosophy

```
Header-only     →  one file, zero configuration
No dependencies →  only standard C++ library
Minimalism      →  only what you really need
Cross-platform  →  Windows and POSIX handled where needed
constexpr       →  maximum work at compile time
```

***

## 📄 License

Project covered by **MIT** license - free for private and commercial use.

```
Copyright (c) Lumi
```

Details in [LICENSE](LICENSE) file.

***

<div align="center">

*Created by Lumi*

</div>
