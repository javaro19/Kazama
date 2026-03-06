// Copyright (c) JavarOwO
// SPDX-License-Identifier: MIT

#include "utils.h"
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

	void console_clear() {
		std::cout.flush();
#ifdef _WIN32
		HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);
		CONSOLE_SCREEN_BUFFER_INFO info;
		if (GetConsoleScreenBufferInfo(h, &info)) {
			DWORD charsWritten;
			COORD pos = { 0,0 };
			FillConsoleOutputCharacter(h, ' ', info.dwSize.X * info.dwSize.Y, pos, &charsWritten);
			FillConsoleOutputAttribute(h, info.wAttributes, info.dwSize.X * info.dwSize.Y, pos, &charsWritten);
			SetConsoleCursorPosition(h, pos);
		} else {
			std::cout << "\033[2J\033[H";
		}
#else
		std::cout << "\033[2J\033[H";
#endif
	}

	void wait_s(int sec) {
		std::this_thread::sleep_for(std::chrono::seconds(sec));
	}

	void wait_ms(int milisec) {
		std::this_thread::sleep_for(std::chrono::milliseconds(milisec));
	}

	void input_clear() {
		std::cin.clear();
		std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
	}

	int random(int x, int y) {
		static std::mt19937 gen(std::random_device{}());
		std::uniform_int_distribution<> disc(x, y);
		return disc(gen);
	}

	void windows_default(std::string title) {
		std::wstring wtitle(title.begin(), title.end());
		SetConsoleTitle(wtitle.c_str());
		SetConsoleOutputCP(CP_UTF8);
		SetConsoleCP(CP_UTF8);
	}

	void to_lower(std::string& s) {
		for (auto& c : s) {
			c = std::tolower(static_cast<unsigned char>(c));
		}
	}

	void to_upper(std::string& s) {
		for (auto& c : s) {
			c = std::toupper(static_cast<unsigned char>(c));
		}
	}

	void input(std::string& s) {
		if (std::cin.peek() == '\n') {
			input_clear();
		}
		std::getline(std::cin, s);
	}

}
