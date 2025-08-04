#pragma once

#include "qualifier.hpp"

#if CM_CONFIG_SWIZZLE == CM_SWIZZLE_OPERATOR
#	include "_swizzle.hpp"
#elif CM_CONFIG_SWIZZLE == CM_SWIZZLE_FUNCTION
#	include "_swizzle_func.hpp"
#endif

#include <cstddef>

namespace cm
{
	template<typename T, qualifier Q>
	struct vec<3, T, Q>
	{
		typedef T value_type;
		typedef vec<3, T, Q> type;
		typedef vec<3, bool, Q> bool_type;
		enum is_aligned
		{
			value = detail::is_aligned<Q>::value
		};

#		if CM_SILENT_WARNINGS == CM_ENABLE
#			if CM_COMPILER & CM_COMPILER_GCC
#				pragma GCC diagnostic push
#				pragma GCC diagnostic ignored "-Wpedantic"
#			elif CM_COMPILER & CM_COMPILER_CLANG
#				pragma clang diagnostic push
#				pragma clang diagnostic ignored "-Wgnu-anonymous-struct"
#				pragma clang diagnostic ignored "-Wnested-anonymous-types"
#			elif CM_COMPILER & CM_COMPILER_VC
#				pragma warning(push)
#				pragma warning(disable:4201)
#			endif
#		endif

#		if CM_CONFIG_XYZW_ONLY
		T x, y, z;
#			if CM_CONFIG_SWIZZLE == CM_SWIZZLE_FUNCTION
		CM_SWIZZLE_GEN_VEC2_COMP(T, Q, x, y, z)
#			endif

#		elif CM_CONFIG_ANONYMOUS_STRUCT == CM_ENABLE
		union
		{
			struct { T x, y, z; };
			struct { T r, g, b; };
			struct { T s, t, p; };

			typename detail::storage<3, T, detail::is_aligned<Q>::value>::type data;
#				if CM_CONFIG_SWIZZLE == CM_SWIZZLE_OPERATOR
			CM_SWIZZLE3_2_MEMBERS(T, Q, x, y, z)
				CM_SWIZZLE3_2_MEMBERS(T, Q, r, g, b)
				CM_SWIZZLE3_2_MEMBERS(T, Q, s, t, p)
				CM_SWIZZLE3_3_MEMBERS(T, Q, x, y, z)
				CM_SWIZZLE3_3_MEMBERS(T, Q, r, g, b)
				CM_SWIZZLE3_3_MEMBERS(T, Q, s, t, p)
				CM_SWIZZLE3_4_MEMBERS(T, Q, x, y, z)
				CM_SWIZZLE3_4_MEMBERS(T, Q, r, g, b)
				CM_SWIZZLE3_4_MEMBERS(T, Q, s, t, p)
#				endif
		};
#		else
		union { T x, r, s; };
		union { T y, g, t; };
		union { T z, b, p; };

#			if CM_CONFIG_SWIZZLE == CM_SWIZZLE_FUNCTION
		CM_SWIZZLE_GEN_VEC_FROM_VEC3(T, Q)
#			endif
#		endif

#		if CM_SILENT_WARNINGS == CM_ENABLE
#			if CM_COMPILER & CM_COMPILER_CLANG
#				pragma clang diagnostic pop
#			elif CM_COMPILER & CM_COMPILER_GCC
#				pragma GCC diagnostic pop
#			elif CM_COMPILER & CM_COMPILER_VC
#				pragma warning(pop)
#			endif
#		endif

		typedef length_t length_type;
		CM_FUNC_DECL static CM_CONSTEXPR length_type length() { return 3; }


		CM_FUNC_DECL CM_CONSTEXPR T& operator[](length_type i);
		CM_FUNC_DECL CM_CONSTEXPR T const& operator[](length_type i) const;


		CM_DEFAULTED_DEFAULT_CTOR_DECL CM_CONSTEXPR vec() CM_DEFAULT_CTOR;
		CM_DEFAULTED_FUNC_DECL CM_CONSTEXPR vec(vec const& v) CM_DEFAULT;
		template<qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<3, T, P> const& v);

		CM_FUNC_DECL CM_CONSTEXPR explicit vec(T scalar);
		CM_FUNC_DECL CM_CONSTEXPR vec(T a, T b, T c);

		template<typename U, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR explicit vec(vec<1, U, P> const& v);

		template<typename X, typename Y, typename Z>
		CM_FUNC_DECL CM_CONSTEXPR vec(X _x, Y _y, Z _z);
		template<typename X, typename Y, typename Z>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<1, X, Q> const& _x, Y _y, Z _z);
		template<typename X, typename Y, typename Z>
		CM_FUNC_DECL CM_CONSTEXPR vec(X _x, vec<1, Y, Q> const& _y, Z _z);
		template<typename X, typename Y, typename Z>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, Z _z);
		template<typename X, typename Y, typename Z>
		CM_FUNC_DECL CM_CONSTEXPR vec(X _x, Y _y, vec<1, Z, Q> const& _z);
		template<typename X, typename Y, typename Z>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<1, X, Q> const& _x, Y _y, vec<1, Z, Q> const& _z);
		template<typename X, typename Y, typename Z>
		CM_FUNC_DECL CM_CONSTEXPR vec(X _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z);
		template<typename X, typename Y, typename Z>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z);


		template<typename A, typename B, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<2, A, P> const& _xy, B _z);

		template<typename A, typename B, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<2, A, P> const& _xy, vec<1, B, P> const& _z);

		template<typename A, typename B, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(A _x, vec<2, B, P> const& _yz);

		template<typename A, typename B, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<1, A, P> const& _x, vec<2, B, P> const& _yz);

		template<typename U, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR CM_EXPLICIT vec(vec<4, U, P> const& v);

		template<typename U, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR CM_EXPLICIT vec(vec<3, U, P> const& v);

#		if CM_CONFIG_SWIZZLE == CM_SWIZZLE_OPERATOR
		template<int E0, int E1, int E2>
		CM_FUNC_DECL CM_CONSTEXPR vec(detail::_swizzle<3, T, Q, E0, E1, E2, -1> const& that)
		{
			*this = that();
		}

		template<int E0, int E1>
		CM_FUNC_DECL CM_CONSTEXPR vec(detail::_swizzle<2, T, Q, E0, E1, -1, -2> const& v, T const& scalar)
		{
			*this = vec(v(), scalar);
		}

		template<int E0, int E1>
		CM_FUNC_DECL CM_CONSTEXPR vec(T const& scalar, detail::_swizzle<2, T, Q, E0, E1, -1, -2> const& v)
		{
			*this = vec(scalar, v());
		}
#		endif


		CM_DEFAULTED_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator=(vec const& v) CM_DEFAULT;

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator=(vec<3, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator+=(U scalar);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator+=(vec<1, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator+=(vec<3, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator-=(U scalar);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator-=(vec<1, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator-=(vec<3, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator*=(U scalar);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator*=(vec<1, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator*=(vec<3, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator/=(U scalar);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator/=(vec<1, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator/=(vec<3, U, Q> const& v);


		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator++();
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator--();
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator++(int);
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator--(int);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator%=(U scalar);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator%=(vec<1, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator%=(vec<3, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator&=(U scalar);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator&=(vec<1, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator&=(vec<3, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator|=(U scalar);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator|=(vec<1, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator|=(vec<3, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator^=(U scalar);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator^=(vec<1, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator^=(vec<3, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator<<=(U scalar);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator<<=(vec<1, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator<<=(vec<3, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator>>=(U scalar);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator>>=(vec<1, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q>& operator>>=(vec<3, U, Q> const& v);
	};

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator+(vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator-(vec<3, T, Q> const& v);


	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator+(vec<3, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator+(T scalar, vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator+(vec<3, T, Q> const& v1, vec<1, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator+(vec<1, T, Q> const& v1, vec<3, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator+(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator-(vec<3, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator-(T scalar, vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator-(vec<3, T, Q> const& v1, vec<1, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator-(vec<1, T, Q> const& v1, vec<3, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator-(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator*(vec<3, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator*(T scalar, vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator*(vec<3, T, Q> const& v1, vec<1, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator*(vec<1, T, Q> const& v1, vec<3, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator*(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator/(vec<3, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator/(T scalar, vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator/(vec<3, T, Q> const& v1, vec<1, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator/(vec<1, T, Q> const& v1, vec<3, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator/(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator%(vec<3, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator%(T scalar, vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator%(vec<3, T, Q> const& v1, vec<1, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator%(vec<1, T, Q> const& v1, vec<3, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator%(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator&(vec<3, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator&(T scalar, vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator&(vec<3, T, Q> const& v1, vec<1, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator&(vec<1, T, Q> const& v1, vec<3, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator&(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator|(vec<3, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator|(T scalar, vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator|(vec<3, T, Q> const& v1, vec<1, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator|(vec<1, T, Q> const& v1, vec<3, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator|(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator^(vec<3, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator^(T scalar, vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator^(vec<3, T, Q> const& v1, vec<1, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator^(vec<1, T, Q> const& v1, vec<3, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator^(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator<<(vec<3, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator<<(T scalar, vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator<<(vec<3, T, Q> const& v1, vec<1, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator<<(vec<1, T, Q> const& v1, vec<3, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator<<(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator>>(vec<3, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator>>(T scalar, vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator>>(vec<3, T, Q> const& v1, vec<1, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator>>(vec<1, T, Q> const& v1, vec<3, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator>>(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator~(vec<3, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator==(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, T, Q> operator!=(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3);

	template<qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, bool, Q> operator&&(vec<3, bool, Q> const& v1, vec<3, bool, Q> const& v3);

	template<qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<3, bool, Q> operator&&(vec<3, bool, Q> const& v1, vec<3, bool, Q> const& v3);
}

#ifndef CM_EXTERNAL_TEMPLATE
#include "type_vec3.inl"
#endif
