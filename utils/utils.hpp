// Copyright (c) JavarOwO
// SPDX-License-Identifier: MIT

#pragma once
#include <iostream>
#include <cstdlib>
#include <chrono>
#include <thread>
#include <string>
#include <limits>
#include <random>
#include <ctime>
#ifdef _WIN32
#include <windows.h>
#undef max
#endif

namespace kazama {

    inline void console_clear() {
        std::cout.flush();
#ifdef _WIN32
        HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
        CONSOLE_SCREEN_BUFFER_INFO info;
        if (GetConsoleScreenBufferInfo(h, &info)) {
            DWORD charsWritten;
            COORD pos = { 0,0 };
            DWORD size = info.dwSize.X * info.dwSize.Y;
            FillConsoleOutputCharacter(h, ' ', size, pos, &charsWritten);
            FillConsoleOutputAttribute(h, info.wAttributes, size, pos, &charsWritten);
            SetConsoleCursorPosition(h, pos);
        }
        else {
            std::cout << "\033[2J\033[H";
        }
#else
        std::cout << "\033[2J\033[H";
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
        std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    }

    inline int random(int x, int y) {
        static std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<> disc(x, y);
        return disc(gen);
    }

    inline void windows_default(const std::string& title) {
#ifdef _WIN32
        std::wstring wtitle(title.begin(), title.end());
        SetConsoleTitleW(wtitle.c_str());
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