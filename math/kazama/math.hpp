// Copyright (c) JavarOwO
// SPDX-License-Identifier: MIT

#pragma once

namespace kazama {

	template<typename T, typename U>
	inline constexpr T perc(T x, U y) {
		T abs_x = x < T(0) ? -x : x;
		T abs_y = static_cast<T>(y) < T(0) ? -static_cast<T>(y) : static_cast<T>(y);
		return (abs_x * abs_y) / T(100);
	}

	template<typename T>
	inline constexpr T quad(T a, T b, T c) {
		return b * b - T(4) * a * c;
	}
}
