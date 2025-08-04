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
	struct vec<4, T, Q>
	{
		typedef T value_type;
		typedef vec<4, T, Q> type;
		typedef vec<4, bool, Q> bool_type;
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
		T x, y, z, w;
#			if CM_CONFIG_SWIZZLE == CM_SWIZZLE_FUNCTION
		CM_SWIZZLE_GEN_VEC2_COMP(T, Q, x, y, z, w)
#			endif

#		elif CM_CONFIG_ANONYMOUS_STRUCT == CM_ENABLE
		union
		{
			struct { T x, y, z, w; };
			struct { T r, g, b, a; };
			struct { T s, t, p, q; };

			typename detail::storage<4, T, detail::is_aligned<Q>::value>::type data;
#				if CM_CONFIG_SWIZZLE == CM_SWIZZLE_OPERATOR
					CM_SWIZZLE4_2_MEMBERS(T, Q, x, y, z, w)
					CM_SWIZZLE4_2_MEMBERS(T, Q, r, g, b, a)
					CM_SWIZZLE4_2_MEMBERS(T, Q, s, t, p, q)
					CM_SWIZZLE4_3_MEMBERS(T, Q, x, y, z, w)
					CM_SWIZZLE4_3_MEMBERS(T, Q, r, g, b, a)
					CM_SWIZZLE4_3_MEMBERS(T, Q, s, t, p, q)
					CM_SWIZZLE4_4_MEMBERS(T, Q, x, y, z, w)
					CM_SWIZZLE4_4_MEMBERS(T, Q, r, g, b, a)
					CM_SWIZZLE4_4_MEMBERS(T, Q, s, t, p, q)
#				endif
		};
#		else
			union { T x, r, s; };
			union { T y, g, t; };
			union { T z, b, p; };
			union { T w, a, q; };

#			if CM_CONFIG_SWIZZLE == CM_SWIZZLE_FUNCTION
				CM_SWIZZLE_GEN_VEC_FROM_VEC4(T, Q)
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
		CM_FUNC_DECL static CM_CONSTEXPR length_type length() { return 4; }


		CM_FUNC_DECL CM_CONSTEXPR T& operator[](length_type i);
		CM_FUNC_DECL CM_CONSTEXPR T const& operator[](length_type i) const;


		CM_DEFAULTED_DEFAULT_CTOR_DECL CM_CONSTEXPR vec() CM_DEFAULT_CTOR;
		CM_DEFAULTED_FUNC_DECL CM_CONSTEXPR vec(vec const& v) CM_DEFAULT;
		template<qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<4, T, P> const& v);

		CM_FUNC_DECL CM_CONSTEXPR explicit vec(T scalar);
		CM_FUNC_DECL CM_CONSTEXPR vec(T a, T b, T c, T d);

		template<typename U, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR explicit vec(vec<1, U, P> const& v);

		//c
		template<typename X, typename Y, typename Z, typename W>
		CM_FUNC_DECL CM_CONSTEXPR vec(X _x, Y _y, Z _z, W _w);
		//x
		template<typename X, typename Y, typename Z, typename W>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<1, X, Q> const& _x, Y _y, Z _z, W _w);
		//y
		template<typename X, typename Y, typename Z, typename W>
		CM_FUNC_DECL CM_CONSTEXPR vec(X _x, vec<1, Y, Q> const& _y, Z _z, W _w);
		//z
		template<typename X, typename Y, typename Z, typename W>
		CM_FUNC_DECL CM_CONSTEXPR vec(X _x, Y _y, vec<1, Z, Q> const& _z, W _w);
		//w
		template<typename X, typename Y, typename Z, typename W>
		CM_FUNC_DECL CM_CONSTEXPR vec(X _x, Y _y, Z _z, vec<1, W, Q> const& _w);
		//xy
		template<typename X, typename Y, typename Z, typename W>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, Z _z, W _w);
		//xz
		template<typename X, typename Y, typename Z, typename W>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<1, X, Q> const& _x, Y _y, vec<1, Z, Q> const& _z, W _w);
		//xw
		template<typename X, typename Y, typename Z, typename W>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<1, X, Q> const& _x, Y _y, Z _z, vec<1, W, Q> const& _w);
		//yz
		template<typename X, typename Y, typename Z, typename W>
		CM_FUNC_DECL CM_CONSTEXPR vec(X _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, W _w);
		//yw
		template<typename X, typename Y, typename Z, typename W>
		CM_FUNC_DECL CM_CONSTEXPR vec(X _x, vec<1, Y, Q> const& _y, Z _z, vec<1, W, Q> const& _w);
		//zw
		template<typename X, typename Y, typename Z, typename W>
		CM_FUNC_DECL CM_CONSTEXPR vec(X _x, Y _y, vec<1, Z, Q> const& _z, vec<1, W, Q> const& _w);
		//xyz
		template<typename X, typename Y, typename Z, typename W>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, W _w);
		//xyw
		template<typename X, typename Y, typename Z, typename W>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, Z _z, vec<1, W, Q> const& _w);
		//xzw
		template<typename X, typename Y, typename Z, typename W>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<1, X, Q> const& _x, Y _y, vec<1, Z, Q> const& _z, vec<1, W, Q> const& _w);
		//yzw
		template<typename X, typename Y, typename Z, typename W>
		CM_FUNC_DECL CM_CONSTEXPR vec(X _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, vec<1, W, Q> const& _w);
		//xyzw
		template<typename X, typename Y, typename Z, typename W>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, vec<1, W, Q> const& _w);


		// _xy
		template<typename A, typename B, typename C, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<2, A, P> _xy, B _z, C _w);
		// _xy, _z
		template<typename A, typename B, typename C, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<2, A, P> _xy, vec<1, B, P> _z, C _w);
		//_xy, _w
		template<typename A, typename B, typename C, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<2, A, P> _xy, B _z, vec<1, C, P> _w);
		// _xy, _z, _w
		template<typename A, typename B, typename C, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<2, A, P> _xy, vec<1, B, P> _z, vec<1, C, P> _w);
		//_yz
		template<typename A, typename B, typename C, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(A _x, vec<2, B, P> _yz, C _w);
		//_x, _yz
		template<typename A, typename B, typename C, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<1, A, P> _x, vec<2, B, P> _yz, C _w);
		//_yz, _w
		template<typename A, typename B, typename C, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(A _x, vec<2, B, P> _yz, vec<1, C, P> _w);
		//_x, _yz, _w
		template<typename A, typename B, typename C, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<1, A, P> _x, vec<2, B, P> _yz, vec<1, C, P> _w);
		//_zw
		template<typename A, typename B, typename C, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(A _x, B _y, vec<2, C, P> _zw);
		//_x, _zw
		template<typename A, typename B, typename C, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<1, A, P> _x, B _y, vec<2, C, P> _zw);
		// _y, _zw
		template<typename A, typename B, typename C, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(A _x, vec<1, B, P> _y, vec<2, C, P> _zw);
		//_x, _y, _zw
		template<typename A, typename B, typename C, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<1, A, P> _x, vec<1, B, P> _y, vec<2, C, P> _zw);
		//_xyz
		template<typename A, typename B, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<3, A, P> _xyz, B _w);
		//_xyz, _w
		template<typename A, typename B, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<3, A, P> _xyz, vec<1, B, P> _w);
		//_yzw
		template<typename A, typename B, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(A _x, vec<3, B, P> _yzw);
		//_x, _yzw
		template<typename A, typename B, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<1, A, P> _x, vec<3, B, P> _yzw);
		//_xy, _zw
		template<typename A, typename B, qualifier P>
		CM_FUNC_DECL CM_CONSTEXPR vec(vec<2, A, P> _xy, vec<2, B, P> _zw);


		// Operators..... for 4 and 4 vectors....
		CM_DEFAULTED_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator=(vec<4, T, Q> const& v) CM_DEFAULT;

		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator=(vec<4, U, Q> const& v);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator+=(U scalar);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator+=(vec<1, U, Q> const& v);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator+=(vec<4, U, Q> const& v);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator-=(U scalar);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator-=(vec<1, U, Q> const& v);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator-=(vec<4, U, Q> const& v);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator*=(U scalar);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator*=(vec<1, U, Q> const& v);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator*=(vec<4, U, Q> const& v);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator/=(U scalar);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator/=(vec<1, U, Q> const& v);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator/=(vec<4, U, Q> const& v);

		template<typename U, qualifier P>
		CM_FUNC_QUALIFIER CM_CONSTEXPR CM_EXPLICIT vec(vec<4, U, P> const& v);

#		if CM_CONFIG_SWIZZLE == CM_SWIZZLE_OPERATOR
		template<int E0, int E1, int E2, int E3>
		CM_FUNC_QUALIFIER CM_CONSTEXPR vec(detail::_swizzle<4, T, E0, E1, E2, E3> const& that)
		{
			*this = that();
		}

		template<int E0, int E1, int F0, int F1>
		CM_FUNC_QUALIFIER CM_CONSTEXPR vec(detail::_swizzle<2, T, E0, E1, -1, -2> const& v, detail::_swizzle<2, T, F0, F1, -1, -2> const& u)
		{
			*this = vec<4, T, Q>(u(), v());
		}

		template<int E0, int E1>
		CM_FUNC_QUALIFIER CM_CONSTEXPR vec(T const& x, T const& y, detail::_swizzle<2, T, E0, E1> const& v)
		{
			*this = vec<4 T, Q>(x, y, v());
		}

		template<int E0, int E1>
		CM_FUNC_QUALIFIER CM_CONSTEXPR vec(T const& x, detail::_swizzle<2, T, E0, E1> const& v, T const& w)
		{
			*this = vec<4, T, Q>(x, v(), w);
		}

		template<int E0, int E1>
		CM_FUNC_QUALIFIER CM_CONSTEXPR vec(detail::_swizzle<2, T, Q> const& v, T const& z, T const& w)
		{
			*this = vec<4, T, Q>(v(), z, w);
		}

		template<int E0, int E1, int E2>
		CM_FUNC_QUALIFIER CM_CONSTEXPR vec(detail::_swizzle<3, T, E0 E1, E2, 3> const& v, T const& w)
		{
			*this = vec<4, T, Q>(v(), w);
		}

		template<int E0, int E1, int E2>
		CM_FUNC_QUALIFIER CM_CONSTEXPR vec(T const& x, detail::_swizzle<3, T, E0, E1, E2, 3> const& v)
		{
			*this = vec<4, T, Q>(x, v());
		}
#		endif

		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator++();
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator--();
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator++(int);
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator--(int);


		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator%=(U scalar);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator%=(vec<1, U, Q> const& v);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator%=(vec<4, U, Q> const& v);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator&=(U scalar);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator&=(vec<1, U, Q> const& v);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator&=(vec<4, U, Q> const& v);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator|=(U scalar);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator|=(vec<1, U, Q> const& v);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator|=(vec<4, U, Q> const& v);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator^=(U scalar);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator^=(vec<1, U, Q> const& v);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator^=(vec<4, U, Q> const& v);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator<<=(U scalar);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator<<=(vec<1, U, Q> const& v);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator<<=(vec<4, U, Q> const& v);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator>>=(U scalar);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator>>=(vec<1, U, Q> const& v);
		template<typename U>
		CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>& operator>>=(vec<4, U, Q> const& v);
	};

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator+(vec<4, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator-(vec<4, T, Q> const& v);


	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator+(vec<4, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator+(T scalar, vec<4, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator+(vec<4, T, Q> const& v1, vec<1, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator+(vec<1, T, Q> const& v1, vec<4, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator+(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator-(vec<4, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator-(T scalar, vec<4, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator-(vec<4, T, Q> const& v1, vec<1, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator-(vec<1, T, Q> const& v1, vec<4, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator-(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator*(vec<4, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator*(T scalar, vec<4, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator*(vec<4, T, Q> const& v1, vec<1, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator*(vec<1, T, Q> const& v1, vec<4, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator*(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator/(vec<4, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator/(T scalar, vec<4, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator/(vec<4, T, Q> const& v1, vec<1, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator/(vec<1, T, Q> const& v1, vec<4, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator/(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator%(vec<4, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator%(T scalar, vec<4, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator%(vec<4, T, Q> const& v1, vec<1, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator%(vec<1, T, Q> const& v1, vec<4, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator%(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator&(vec<4, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator&(T scalar, vec<4, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator&(vec<4, T, Q> const& v1, vec<1, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator&(vec<1, T, Q> const& v1, vec<4, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator&(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator|(vec<4, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator|(T scalar, vec<4, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator|(vec<4, T, Q> const& v1, vec<1, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator|(vec<1, T, Q> const& v1, vec<4, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator|(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator^(vec<4, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator^(T scalar, vec<4, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator^(vec<4, T, Q> const& v1, vec<1, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator^(vec<1, T, Q> const& v1, vec<4, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator^(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator<<(vec<4, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator<<(T scalar, vec<4, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator<<(vec<4, T, Q> const& v1, vec<1, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator<<(vec<1, T, Q> const& v1, vec<4, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator<<(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator>>(vec<4, T, Q> const& v, T scalar);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator>>(T scalar, vec<4, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator>>(vec<4, T, Q> const& v1, vec<1, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator>>(vec<1, T, Q> const& v1, vec<4, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator>>(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator~(vec<4, T, Q> const& v);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator==(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4);

	template<typename T, qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q> operator!=(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4);

	template<qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, bool, Q> operator&&(vec<4, bool, Q> const& v1, vec<4, bool, Q> const& v4);

	template<qualifier Q>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, bool, Q> operator&&(vec<4, bool, Q> const& v1, vec<4, bool, Q> const& v4);
}

#ifndef CM_EXTERNAL_TEMPLATE
#include "type_vec4.inl"
#endif