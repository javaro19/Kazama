// Copyright (c) JavarOwO
// SPDX-License-Identifier: MIT

#pragma once

namespace kazama {

	template<typename T, typename U>
	inline constexpr T perc(T base, U pct) {
		return (base * static_cast<T>(pct)) / T(100);
	}

	template<typename T>
	inline constexpr T quad(T a, T b, T c) {
		return b * b - T(4) * a * c;
	}
}