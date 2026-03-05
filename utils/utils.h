#ifndef UTILS_H
#define UTILS_H
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

	void console_clear();

	void wait_s(int sec);

	void wait_ms(int milisec);

	void input_clear();

	int random(int x, int y);

	void windows_default(std::string title);

	void to_lower(std::string& s);

	void to_upper(std::string& s);

	void input(std::string& s);

}

#endif 


