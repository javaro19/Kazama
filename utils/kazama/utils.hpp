// Copyright (c) JavarOwO
// SPDX-License-Identifier: MIT

#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <limits>
#include <random>
#include <cctype>

#ifdef _WIN32
#   include <windows.h>
#endif

namespace kazama {

    namespace {
        std::mt19937 gen(std::random_device{}());
    }

    inline void console_clear() {
        std::cout.flush();
#ifdef _WIN32
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO info;
        if (GetConsoleScreenBufferInfo(h, &info)) {
            DWORD charsWritten;
            DWORD size = info.dwSize.X * info.dwSize.Y;
            COORD pos = { 0,0 };
            FillConsoleOutputCharacter(h, ' ', size, pos, &charsWritten);
            FillConsoleOutputAttribute(h, info.wAttributes, size, pos, &charsWritten);
            SetConsoleCursorPosition(h, pos);
        }
        else {
            std::cout << "\033[2J\033[H";
            std::cout.flush();
        }
#else
        std::cout << "\033[2J\033[H";
        std::cout.flush();
#endif
    }

    inline void wait_s(int sec) {
        std::this_thread::sleep_for(std::chrono::seconds(sec));
    }

    inline void wait_ms(int milisec) {
        std::this_thread::sleep_for(std::chrono::milliseconds(milisec));
    }

    inline void input_clear() {
        std::cin.clear();
        if (std::cin.rdbuf()->in_avail() > 0) {
            std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
        }
    }

    [[nodiscard]] inline int irandom(int x, int y) {
        std::uniform_int_distribution<> disc(x, y);
        return disc(gen);
    }

    [[nodiscard]] inline double frandom(double x, double y) {
        std::uniform_real_distribution<> disc(x, y);
        return disc(gen);
    }

    inline void windows_default(const std::string& title) {
#ifdef _WIN32
        SetConsoleTitleW(std::wstring(title.begin(), title.end()).c_str());
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
#endif
    }

    inline void to_lower(std::string& s) {
        for (auto& c : s) {
            c = static_cast<char>(std::tolower(static_cast<unsigned char>(c)));
        }
    }

    inline void to_upper(std::string& s) {
        for (auto& c : s) {
            c = static_cast<char>(std::toupper(static_cast<unsigned char>(c)));
        }
    }

    inline void input(std::string& s) {
        std::getline(std::cin >> std::ws, s);
    }
}