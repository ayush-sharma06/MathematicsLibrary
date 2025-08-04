#pragma once


#include "type_vec2.hpp"

#include <limits>
#include <cstddef>

namespace cm
{
	namespace detail
	{
		template<typename T, qualifier Q>
		struct mat<2, 2, T, Q>
		{
			typedef vec<2, T, Q> col_type;
			typedef vec<2, T, Q> row_type;
			typedef mat<2, 2, T, Q> type;
			typedef mat<2, 2, T, Q> transpose_type;
			typedef T value_type;

		private:
			col_type value[2];

		public:
			typedef length_t length_type;

			CM_FUNC_DECL static CM_CONSTEXPR length_type length() { return 2; }

			CM_FUNC_DECL CM_CONSTEXPR operator[](length_type i) CM_NOEXCEPT;
			CM_FUNC_DECL CM_CONSTEXPR operator[](length_type const& i) const CM_NOEXCEPT;

			CM_DEFAULTED_DEFAULT_CTOR_DECL CM_CONSTEXPR mat() CM_DEFAULT_CTOR;

		};
	}
}