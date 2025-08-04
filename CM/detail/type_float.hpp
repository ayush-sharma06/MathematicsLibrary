#pragma once


#include "setup.hpp"

#if CM_COMPILER == CM_COMPILER_VC12
#	pragma warning(push)
#	pragma warning(disable: 4512)
#endif

namespace cm {
	namespace detail {
		template <typename T>
		union float_t
		{};

		template <>
		union float_t<float>
		{
			typedef int int_type;
			typedef float float_type;

			CM_CONSTEXPR float_t(float_type Num = 0.0f) : f(Num) {}
			CM_CONSTEXPR float_t& operator=(float_t const& x)
			{
				f = x.f;
				return *this;
			}

			CM_CONSTEXPR bool negative() const { return i < 0; }
			CM_CONSTEXPR int_type mantissa() const { return i & ((1 << 23) - 1); }
			CM_CONSTEXPR int_type exponent() const { return (i >> 23) & ((1 << 8) - 1); }

			int_type i;
			float_type f;
		};

		template <>
		union float_t<double>
		{
			typedef detail::int64 int_type;
			typedef double float_type;

			CM_CONSTEXPR float_t(float_type Num = static_cast<float_type>(0)) : f(Num) {}
			CM_CONSTEXPR float_t& operator=(float_t const& x)
			{
				f = x.f;
				return *this;
			}

			CM_CONSTEXPR bool negative() const { return i < 0; }
			CM_CONSTEXPR int_type mantissa() const { return i & ((1 << 52) - 1); }
			CM_CONSTEXPR int_type exponent() const { return (i >> 52) & ((1 << 11) - 1); }

			int_type i;
			float_type f;
		};
	}
}

#if CM_COMPILER == CM_COMPILER_VC12
#	pragma warning(pop)
#endif




// MODIFICATIONS:
// Add more precision upto 80 and 128 bits -> read challenges and detail.