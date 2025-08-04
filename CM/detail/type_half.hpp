#pragma once


#include "setup.hpp"

namespace cm {
	namespace detail {
		typedef short hdata;

		CM_FUNC_DECL float toFloat32(hdata value);
		CM_FUNC_DECL hdata toFloat16(float const& value);
	}
}

#include "type_half.inl"