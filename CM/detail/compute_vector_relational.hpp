#pragma once
#include "setup.hpp"
#include <limits>

namespace cm {
	namespace detail {
		template<typename T, bool isFloat>
		struct compute_equal {
			CM_FUNC_QUALIFIER CM_CONSTEXPR static bool call(T a, T b) {
				return a == b;
			}
		};
	}
}