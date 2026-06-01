// Copyright (c) Lumi
// SPDX-License-Identifier: MIT

#pragma once

#include <iostream>
#include <chrono>
#include <thread>
#include <string>
#include <limits>
#include <random>
#include <cctype>
#include <cassert>
#include <ios>
#include <algorithm>
#include <cstdio>
#include <cstddef>
#include <stdexcept>

#ifdef _WIN32
#   include <windows.h>
#endif

namespace kazama {

    namespace detail {
        inline std::mt19937 gen(std::random_device{}());

        template <typename Pred>
        inline bool is_x(const std::string& s, Pred pred) {
            if (s.empty()) return false;

            for (const auto& c : s) {
                if (!pred(static_cast<unsigned char>(c))) return false;
            }

            return true;
        }
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
            SetConsoleTextAttribute(h, info.wAttributes);
            SetConsoleCursorPosition(h, pos);
        }
        else {
            std::cout << "\033[0m\033[2J\033[H";
            std::cout.flush();
        }
#else
        std::cout << "\033[0m\033[2J\033[H";
        std::cout.flush();
#endif
    }

    inline void wait_s(int s) {
        std::this_thread::sleep_for(std::chrono::seconds(s));
    }

    inline void wait_ms(int ms) {
        std::this_thread::sleep_for(std::chrono::milliseconds(ms));
    }

    inline void input_clear() {
        std::cin.clear();
        if (std::cin.peek() == '\n' || std::cin.peek() == EOF) std::cin.ignore();
        else std::cin.ignore((std::numeric_limits<std::streamsize>::max)(), '\n');
    }

    [[nodiscard]] inline int irandom(int x, int y) {
        assert(x <= y);
        if (x > y) throw std::invalid_argument("x is greater than y!");

        std::uniform_int_distribution<> dist(x, y);
        return dist(detail::gen);
    }

    [[nodiscard]] inline double frandom(double x, double y) {
        assert(x <= y);
        if (x > y) throw std::invalid_argument("x is greater than y!");

        std::uniform_real_distribution<> dist(x, y);
        return dist(detail::gen);
    }

    inline void trim(std::string& s) {
        auto not_space = [](unsigned char c) { return !isspace(c); };
        s.erase(s.begin(), std::find_if(s.begin(), s.end(), not_space));
        s.erase(std::find_if(s.rbegin(), s.rend(), not_space).base(), s.end());
    }

    inline void console_setup(const std::string& title) {
        std::string t = title;
        trim(t);
        if (t.empty()) throw std::invalid_argument("Title cannot be empty!");

#ifdef _WIN32
        SetConsoleTitleW(std::wstring(t.begin(), t.end()).c_str());
        SetConsoleOutputCP(CP_UTF8);
        SetConsoleCP(CP_UTF8);
#else
        std::cout << "\033]0;" << t << "\007";
        std::cout.flush();
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

    inline void get() {
        std::string dummy;
        std::getline(std::cin, dummy);
    }

    [[nodiscard]] inline bool is_alpha(const std::string& s) { return detail::is_x(s, std::isalpha); }
    [[nodiscard]] inline bool is_punct(const std::string& s) { return detail::is_x(s, std::ispunct); }
    [[nodiscard]] inline bool is_digit(const std::string& s) { return detail::is_x(s, std::isdigit); }
    [[nodiscard]] inline bool is_lower(const std::string& s) { return detail::is_x(s, std::islower); }
    [[nodiscard]] inline bool is_upper(const std::string& s) { return detail::is_x(s, std::isupper); }
    [[nodiscard]] inline bool is_space(const std::string& s) { return detail::is_x(s, std::isspace); }
    [[nodiscard]] inline bool is_alnum(const std::string& s) { return detail::is_x(s, std::isalnum); }

    [[nodiscard]] inline std::string prompt(const std::string& question) {
        std::string answer;
        std::cout << question;
        std::getline(std::cin, answer);
        trim(answer);
        return answer;
    }

    [[nodiscard]] inline size_t count_chars(const std::string& s) {
        size_t chars = 0;

        for (unsigned char c : s) {
            if ((c & 0xC0) != 0x80) ++chars;
        }

        return chars;
    }
}