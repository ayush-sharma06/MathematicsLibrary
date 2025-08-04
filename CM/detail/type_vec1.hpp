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
	struct vec<1, T, Q>
	{
		typedef T value_type;
		typedef vec<1, T, Q> type;
		typedef vec<1, bool, Q> bool_type;

#		if CM_SILENT_WARNINGS == CM_ENABLE
#			if CM_COMPILER & CM_COMPILER_GCC
#				pragma GCC diagnostic push
#				pragma GCC diagnostic ignored "-Wpedantic"
#			elif CM_COMPILER & CM_COMPILER_CLANG
#				pragma clang diagnostic push
#				pragma clang diagnostic ignored "-Wgnu-anonymous-struct"
#				pragma clang diagnostic ignored "-Wnested-anon-types"
#			elif CM_COMPILER & CM_COMPILER_VC
#				pragma warning(push)
#				pragma warning(disable:4201)
#			endif
#		endif

#		if CM_CONFIG_XYZW_ONLY
			T x;
#		elif CM_CONFIG_ANONYMOUS_STRUCT == CM_ENABLE
			union
			{
				T x;
				T r;
				T s;

				typename detail::storage<1, T, detail::is_aligned<Q>::value>::type data;
			};
#		else
			union { T x, r, s; };
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
		CM_FUNC_DECL static CM_CONSTEXPR length_type length() { return 1; }

		CM_FUNC_DECL CM_CONSTEXPR T& operator[](length_type i);
		CM_FUNC_DECL CM_CONSTEXPR T const& operator[](length_type i) const;


		CM_DEFAULTED_DEFAULT_CTOR_DECL CM_CONSTEXPR vec() CM_DEFAULT_CTOR;
		CM_DEFAULTED_FUNC_DECL CM_CONSTEXPR vec(vec const& v) CM_DEFAULT;
		template<qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<1, T, P> const& v);

		CM_FUNC_DECL CM_CONSTEXPR explicit vec(T scalar);
		template<typename U, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR CM_EXPLICIT vec(vec<2, U, P> const& v);
		template<typename U, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR CM_EXPLICIT vec(vec<1, U, P> const& v);
		template<typename U, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR CM_EXPLICIT vec(vec<3, U, P> const& v);
		template<typename U, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR CM_EXPLICIT vec(vec<4, U, P> const& v);

		CM_DEFAULTED_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator=(vec const& v) CM_DEFAULT;

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator=(vec<1, U, Q> const& v);
		
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator+=(U scalar);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator+=(vec<1, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator-=(U scalar);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator-=(vec<1, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator*=(U scalar);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator*=(vec<1, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator/=(U scalar);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator/=(vec<1, U, Q> const& v);

		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator++();
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator--();
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator++(int);
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator--(int);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator%=(U scalar);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator%=(vec<1, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator&=(U scalar);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator&=(vec<1, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator|=(U scalar);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator|=(vec<1, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator^=(U scalar);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator^=(vec<1, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator<<=(U scalar);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator<<=(vec<1, U, Q> const& v);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator>>=(U scalar);

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>& operator>>=(vec<1, U, Q> const& v);
	};

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator+(vec<1, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator-(vec<1, T, Q> const& v);


	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator+(vec<1, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator+(T scalar, vec<1, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator+(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator-(vec<1, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator-(T scalar, vec<1, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator-(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator*(vec<1, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator*(T scalar, vec<1, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator*(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator/(vec<1, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator/(T scalar, vec<1, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator/(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator&(vec<1, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator&(T scalar, vec<1, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator&(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator|(vec<1, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator|(T scalar, vec<1, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator|(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator^(vec<1, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator^(T scalar, vec<1, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator^(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator<<(vec<1, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator<<(T scalar, vec<1, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator<<(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator>>(vec<1, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator>>(T scalar, vec<1, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator>>(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator~(vec<1, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator==(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q> operator!=(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2);

	template<qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, bool, Q> operator&&(vec<1, bool, Q> const& v1, vec<1, bool, Q> const& v2);

	template<qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, bool, Q> operator&&(vec<1, bool, Q> const& v1, vec<1, bool, Q> const& v2);
}

#ifndef CM_EXTERNAL_TEMPLATE
#include "type_vec1.inl"
#endif