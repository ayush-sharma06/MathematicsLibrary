#include "compute_vector_relational.hpp"

namespace cm
{
	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR T& vec<4, T, Q>::operator[](typename vec<4, T, Q>::length_type i) {
		CM_ASSERT_LENGTH(i, this->length());
		switch (i)
		{
		default:
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		case 3:
			return w;
		}
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR T const& vec<4, T, Q>::operator[](typename vec<4, T, Q>::length_type i) const
	{
		CM_ASSERT_LENGTH(i, this->length());
		switch (i)
		{
		default:
		case 0:
			return x;
		case 1:
			return y;
		case 2:
			return z;
		case 3:
			return w;
		}
	}

#	if CM_CONFIG_DEFAULTED_DEFAULT_CTOR == CM_DISABLE
	template<typename T, qualifier Q>
	CM_DEFAULTED_DEFAULT_CTOR_QUALIFIER CM_CONSTEXPR vec<4, T, Q>::vec()
#		if CM_CONFIG_CTOR_INIT != CM_CTOR_INIT_DISABLE
		: x(0), y(0), z(0), w(0)
#		endif
	{
	}
#	endif

#	if CM_CONFIG_DEFAULTED_FUNCTIONS == CM_DISABLE
	template<typename T, qualifier Q>
	CM_DEFAULTED_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>::vec(vec<4, T, Q> const& v)
		: x(v.x), y(v.y), z(v.z), w(v.w)
	{
	}
#	endif

	template<typename T, qualifier Q>
	template<qualifier P>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>::vec(vec<4, T, P> const& v)
		: x(v.x), y(v.y), z(v.z), w(v.w)
	{
	}


	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>::vec(T scalar)
		: x(scalar), y(scalar), z(scalar), w(scalar)
	{
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>::vec(T a, T b, T c, T d)
		: x(a), y(b), z(c), w(d)
	{
	}

	template<typename T, qualifier Q>
	template<typename U, qualifier P>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>::vec(vec<1, U, P> const& v)
		: x(static_cast<T>(v.x)), y(static_cast<T>(v.x)), z(static_cast<T>(v.x)), w(static_cast<T>(v.x))
	{
	}

	//c
	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z, typename W>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>::vec(X _x, Y _y, Z _z, W _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_z)), w(static_cast<T>(_w))
	{
	}
	//x
	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z, typename W>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>::vec(vec<1, X, Q> const& _x, Y _y, Z _z, W _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_z)), w(static_cast<T>(_w))
	{
	}
	//y
	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z, typename W>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>::vec(X _x, vec<1, Y, Q> const& _y, Z _z, W _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z)), w(static_cast<T>(_w))
	{
	}
	//z
	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z, typename W>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>::vec(X _x, Y _y, vec<1, Z, Q> const& _z, W _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w))
	{
	}
	//w
	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z, typename W>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, Z _z, W _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_z)), w(static_cast<T>(_w.x))
	{
	}
	//xy
	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z, typename W>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(vec<1, X, Q> const& _x, Y _y, vec<1, Z, Q> const& _z, W _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z)), w(static_cast<T>(_w))
	{
	}
	//xz
	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z, typename W>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(vec<1, X, Q> const& _x, Y _y, Z _z, vec<1, W, Q> const& _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w))
	{
	}
	//xw
	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z, typename W>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(X _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, W _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_z)), w(static_cast<T>(_w.x))
	{
	}
	//yz
	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z, typename W>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>::vec(X _x, Y _y, Z _z, W _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w))
	{
	}
	//yw
	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z, typename W>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(X _x, vec<1, Y, Q> const& _y, Z _z, vec<1, W, Q> const& _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z)), w(static_cast<T>(_w.x))
	{
	}
	//zw
	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z, typename W>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(X _x, Y _y, vec<1, Z, Q> const& _z, vec<1, W, Q> const& _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w.x))
	{
	}
	//xyz
	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z, typename W>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, W _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w))
	{
	}
	//xyw
	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z, typename W>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, Z _z, vec<1, W, Q> const& _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z)), w(static_cast<T>(_w.x))
	{
	}
	//xzw
	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z, typename W>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(vec<1, X, Q> const& _x, Y _y, vec<1, Z, Q> const& _z, vec<1, W, Q> const& _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w.x))
	{
	}
	//yzw
	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z, typename W>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(X _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, vec<1, W, Q> const& _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w.x))
	{
	}
	//xyzw
	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z, typename W>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z, vec<1, W, Q> const& _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w.x))
	{
	}


	// _xy
	template<typename T, qualifier Q>
	template<typename A, typename B, typename C, qualifier P>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(vec<2, A, P> _xy, B _z, C _w)
		: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_z)), w(static_cast<T>(_w))
	{
	}
	// _xy, _z
	template<typename T, qualifier Q>
	template<typename A, typename B, typename C, qualifier P>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(vec<2, A, P> _xy, vec<1, B, P> _z, C _w)
		: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w))
	{
	}
	//_xy, _w
	template<typename T, qualifier Q>
	template<typename A, typename B, typename C, qualifier P>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(vec<2, A, P> _xy, B _z, vec<1, C, P> _w)
		: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_z)), w(static_cast<T>(_w.x))
	{
	}
	// _xy, _z, _w
	template<typename T, qualifier Q>
	template<typename A, typename B, typename C, qualifier P>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(vec<2, A, P> _xy, vec<1, B, P> _z, vec<1, C, P> _w)
		: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_z.x)), w(static_cast<T>(_w.x))
	{
	}
	//_yz
	template<typename T, qualifier Q>
	template<typename A, typename B, typename C, qualifier P>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(A _x, vec<2, B, P> _yz, C _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_yz.x)), z(static_cast<T>(_yz.y)), w(static_cast<T>(_w))
	{
	}
	//_x, _yz
	template<typename T, qualifier Q>
	template<typename A, typename B, typename C, qualifier P>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(vec<1, A, P> _x, vec<2, B, P> _yz, C _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_yz.x)), z(static_cast(_yz.y)), w(static_cast<T>(_w))
	{
	}

	// _yz, _w
	template<typename T, qualifier Q>
	template<typename A, typename B, typename C, qualifier P>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(A _x, vec<2, B, P> _yz, vec<1, C, P> _w)
		: x(static_cast<T>(_x)), y(static_cast<T>(_yz.x)), z(static_cast<T>(_yz.y)), w(static_cast<T>(_w.x))
	{
	}
	// _x, _yz, _w
	template<typename T, qualifier Q>
	template<typename A, typename B, typename C, qualifier P>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(vec<1, A, P> _x, vec<2, B, P> _yz, vec<1, C, P> _w)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_yz.x)), z(static_cast<T>(_yz.y)), w(static_cast<T>(_w.x))
	{
	}
	//_zw
	template<typename T, qualifier Q>
	template<typename A, typename B, typename C, qualifier P>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(A _x, B _y, vec<2, C, P> _zw)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_zw.x)), w(static_cast<T>(_zw.y))
	{
	}
	// _x, _zw
	template<typename T, qualifier Q>
	template<typename A, typename B, typename C, qualifier P>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(vec<1, A, P> _x, B _y, vec<2, C, P> _zw)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_zw.x)), w(static_cast<T>(_zw.y))
	{
	}
	//_y, _zw
	template<typename T, qualifier Q>
	template<typename A, typename B, typename C, qualifier P>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(A _x, vec<1, B, P> _y, vec<2, C, P> _zw)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_zw.x)), w(static_cast<T>(_zw.y))
	{
	}
	//_x, _y, _zw
	template<typename T, qualifier Q>
	template<typename A, typename B, typename C, qualifier P>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(vec<1, A, P> _x, vec<1, B, P> _y, vec<2, C, P> _zw)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast(_zw.x)), w(static_cast<T>(_zw.y))
	{
	}

	// _xyz
	template<typename T, qualifier Q>
	template<typename A, typename B, qualifier P>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(vec<3, A, P> _xyz, B _w)
		: x(static_cast<T>(_xyz.x)), y(static_cast<T>(_xyz.y)), z(static_cast<T>(_xyz.z)), w(static_cast<T>(_w))
	{
	}
	// _xyz, _w
	template<typename T, qualifier Q>
	template<typename A, typename B, qualifier P>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(vec<3, A, P> _xyz, vec<1, B, P> _w)
		: x(static_cast<T>(_xyz.x)), y(static_cast<T>(_xyz.y)), z(static_cast<T>(_xyz.z)), w(static_cast<T>(_w.x))
	{
	}
	//_yzw
	template<typename T, qualifier Q>
	template<typename A, typename B, qualifier P>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(A _x, vec<3, B, P> _yzw)
		: x(static_cast<T>(_x)), y(static_cast<T>(_yzw.x)), z(static_cast<T>(_yzw.y)), w(static_cast<T>(_yzw.z))
	{
	}
	// _x, _yzw
	template<typename T, qualifier Q>
	template<typename A, typename B, qualifier P>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(vec<1, A, P> _x, vec<3, B, P> _yzw)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_yzw.x)), z(static_cast<T>(_yzw.y)), w(static_cast<T>(_yzw.z))
	{
	}
	//_xy, _zw
	template<typename T, qualifier Q>
	template<typename A, typename B, qualifier P>
	CM_FUNC_DECL CM_CONSTEXPR vec<4, T, Q>::vec(vec<2, A, P> _xy, vec<2, B, P> _zw)
		: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_zw.x)), w(static_cast<T>(_zw.y))
	{
	}


#	if CM_CONFIG_DEFAULTED_FUNCTIONS == CM_DISABLE
	template<typename T, qualifier Q>
	CM_DEFAULTED_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator=(vec<4, T, Q> const& v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		this->w = v.w;
		return *this;
	}
#	endif

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator=(vec<4, U, Q> const& v)
	{
		this->x = static_cast<T>(v.x);
		this->y = static_cast<T>(v.y);
		this->z = static_cast<T>(v.z);
		this->w = static_cast<T>(v.w);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator+=(U scalar)
	{
		this->x += static_cast<T>(scalar);
		this->y += static_cast<T>(scalar);
		this->z += static_cast<T>(scalar);
		this->w += static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator+=(vec<1, U, Q> const& v)
	{
		this->x += static_cast<T>(v.x);
		this->y += static_cast<T>(v.x);
		this->z += static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator+=(vec<4, U, Q> const& v)
	{
		this->x += static_cast<T>(v.x);
		this->y += static_cast<T>(v.y);
		this->z += static_cast<T>(v.z);
		this->w += static_cast<T>(v.w);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator-=(U scalar)
	{
		this->x -= static_cast<T>(scalar);
		this->y -= static_cast<T>(scalar);
		this->z -= static_cast<T>(scalar);
		this->w -= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator-=(vec<1, U, Q> const& v)
	{
		this->x -= static_cast<T>(v.x);
		this->y -= static_cast<T>(v.x);
		this->z -= static_cast<T>(v.x);
		this->w -= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator-=(vec<4, U, Q> const& v)
	{
		this->x -= static_cast<T>(v.x);
		this->y -= static_cast<T>(v.y);
		this->z -= static_cast<T>(v.z);
		this->w -= static_cast<T>(v.w);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator*=(U scalar)
	{
		this->x *= static_cast<T>(scalar);
		this->y *= static_cast<T>(scalar);
		this->z *= static_cast<T>(scalar);
		this->w *= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator*=(vec<1, U, Q> const& v)
	{
		this->x *= static_cast<T>(v.x);
		this->y *= static_cast<T>(v.x);
		this->z *= static_cast<T>(v.x);
		this->w *= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator*=(vec<4, U, Q> const& v)
	{
		this->x *= static_cast<T>(v.x);
		this->y *= static_cast<T>(v.y);
		this->z *= static_cast<T>(v.z);
		this->w *= static_cast<T>(v.w);
		return *this;
	}


	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator/=(U scalar)
	{
		this->x /= static_cast<T>(scalar);
		this->y /= static_cast<T>(scalar);
		this->z /= static_cast<T>(scalar);
		this->w /= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator/=(vec<1, U, Q> const& v)
	{
		this->x /= static_cast<T>(v.x);
		this->y /= static_cast<T>(v.x);
		this->z /= static_cast<T>(v.x);
		this->w /= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator/=(vec<4, U, Q> const& v)
	{
		this->x /= static_cast<T>(v.x);
		this->y /= static_cast<T>(v.y);
		this->z /= static_cast<T>(v.z);
		this->w /= static_cast<T>(v.w);
		return *this;
	}



	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator++()
	{
		++this->x;
		++this->y;
		++this->z;
		return *this;
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator--()
	{
		--this->x;
		--this->y;
		--this->z;
		return *this;
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> vec<4, T, Q>::operator++(int)
	{
		vec<4, T, Q> Result(*this);
		++*this;
		return Result;
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> vec<4, T, Q>::operator--(int)
	{
		vec<4, T, Q> Result(*this);
		--*this;
		return Result;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator%=(U scalar)
	{
		this->x %= static_cast<T>(scalar);
		this->y %= static_cast<T>(scalar);
		this->z %= static_cast<T>(scalar);
		this->w %= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator%=(vec<1, U, Q> const& v)
	{
		this->x %= static_cast<T>(v.x);
		this->y %= static_cast<T>(v.x);
		this->z %= static_cast<T>(v.x);
		this->w %= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator%=(vec<4, U, Q> const& v)
	{
		this->x %= static_cast<T>(v.x);
		this->y %= static_cast<T>(v.y);
		this->z %= static_cast<T>(v.z);
		this->w %= static_cast<T>(v.w);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator&=(U scalar)
	{
		this->x &= static_cast<T>(scalar);
		this->y &= static_cast<T>(scalar);
		this->z &= static_cast<T>(scalar);
		this->w &= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator&=(vec<1, U, Q> const& v)
	{
		this->x &= static_cast<T>(v.x);
		this->y &= static_cast<T>(v.x);
		this->z &= static_cast<T>(v.x);
		this->w &= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator&=(vec<4, U, Q> const& v)
	{
		this->x &= static_cast<T>(v.x);
		this->y &= static_cast<T>(v.y);
		this->z &= static_cast<T>(v.z);
		this->w &= static_cast<T>(v.w);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator|=(U scalar)
	{
		this->x |= static_cast<T>(scalar);
		this->y |= static_cast<T>(scalar);
		this->z |= static_cast<T>(scalar);
		this->w |= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator|=(vec<1, U, Q> const& v)
	{
		this->x |= static_cast<T>(v.x);
		this->y |= static_cast<T>(v.x);
		this->z |= static_cast<T>(v.x);
		this->w |= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator|=(vec<4, U, Q> const& v)
	{
		this->x |= static_cast<T>(v.x);
		this->y |= static_cast<T>(v.y);
		this->z |= static_cast<T>(v.z);
		this->w |= static_cast<T>(v.w);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator^=(U scalar)
	{
		this->x ^= static_cast<T>(scalar);
		this->y ^= static_cast<T>(scalar);
		this->z ^= static_cast<T>(scalar);
		this->w ^= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator^=(vec<1, U, Q> const& v)
	{
		this->x ^= static_cast<T>(v.x);
		this->y ^= static_cast<T>(v.x);
		this->z ^= static_cast<T>(v.x);
		this->w ^= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator^=(vec<4, U, Q> const& v)
	{
		this->x ^= static_cast<T>(v.x);
		this->y ^= static_cast<T>(v.y);
		this->z ^= static_cast<T>(v.z);
		this->w ^= static_cast<T>(v.w);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator<<=(U scalar)
	{
		this->x <<= static_cast<T>(scalar);
		this->y <<= static_cast<T>(scalar);
		this->z <<= static_cast<T>(scalar);
		this->w <<= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator<<=(vec<1, U, Q> const& v)
	{
		this->x <<= static_cast<T>(v.x);
		this->y <<= static_cast<T>(v.x);
		this->z <<= static_cast<T>(v.x);
		this->w <<= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator<<=(vec<4, U, Q> const& v)
	{
		this->x <<= static_cast<T>(v.x);
		this->y <<= static_cast<T>(v.y);
		this->z <<= static_cast<T>(v.z);
		this->w <<= static_cast<T>(v.w);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator>>=(U scalar)
	{
		this->x >>= static_cast<T>(scalar);
		this->y >>= static_cast<T>(scalar);
		this->z >>= static_cast<T>(scalar);
		this->w >>= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator>>=(vec<1, U, Q> const& v)
	{
		this->x >>= static_cast<T>(v.x);
		this->y >>= static_cast<T>(v.x);
		this->z >>= static_cast<T>(v.x);
		this->w >>= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q>& vec<4, T, Q>::operator>>=(vec<4, U, Q> const& v)
	{
		this->x >>= static_cast<T>(v.x);
		this->y >>= static_cast<T>(v.y);
		this->z >>= static_cast<T>(v.z);
		this->w >>= static_cast<T>(v.w);
		return *this;
	}



	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator+(vec<4, T, Q> const& v)
	{
		return v;
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator-(vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(-v.x, -v.y, -v.z, -v.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator+(vec<4, T, Q> const& v, T scalar)
	{
		return vec<4, T, Q>(v.x + scalar, v.y + scalar, v.z + scalar, v.w + scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator+(T scalar, vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(scalar + v.x, scalar + v.y, scalar + v.z, scalar + v.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator+(vec<4, T, Q> const& v1, vec<1, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x + v4.x, v1.y + v4.x, v1.z + v4.x, v1.w + v4.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator+(vec<1, T, Q> const& v1, vec<4, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x + v4.x, v1.x + v4.y, v1.x + v4.z, v1.x + v4.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator+(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x + v4.x, v1.y + v4.y, v1.z + v4.z, v1.w + v4.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator-(vec<4, T, Q> const& v, T scalar)
	{
		return vec<4, T, Q>(v.x - scalar, v.y - scalar, v.z - scalar, v.w - scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator-(T scalar, vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(scalar - v.x, scalar - v.y, scalar - v.z, scalar - v.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator-(vec<4, T, Q> const& v1, vec<1, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x - v4.x, v1.y - v4.x, v1.z - v4.x, v1.w - v4.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator-(vec<1, T, Q> const& v1, vec<4, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x - v4.x, v1.x - v4.y, v1.x - v4.z, v1.x - v4.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator-(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x - v4.x, v1.y - v4.y, v1.z - v4.z, v1.w - v4.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator*(vec<4, T, Q> const& v, T scalar)
	{
		return vec<4, T, Q>(v.x * scalar, v.y * scalar, v.z * scalar, v.w * scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator*(T scalar, vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(scalar * v.x, scalar * v.y, scalar * v.z, scalar * v.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator*(vec<4, T, Q> const& v1, vec<1, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x * v4.x, v1.y * v4.x, v1.z * v4.x, v1.w * v4.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator*(vec<1, T, Q> const& v1, vec<4, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x * v4.x, v1.x * v4.y, v1.x * v4.z, v1.x * v4.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator*(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x * v4.x, v1.y * v4.y, v1.z * v4.z, v1.w * v4.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator/(vec<4, T, Q> const& v, T scalar)
	{
		return vec<4, T, Q>(v.x / scalar, v.y / scalar, v.z / scalar, v.w / scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator/(T scalar, vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(scalar / v.x, scalar / v.y, scalar / v.z, scalar / v.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator/(vec<4, T, Q> const& v1, vec<1, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x / v4.x, v1.y / v4.x, v1.z / v4.x, v1.w / v4.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator/(vec<1, T, Q> const& v1, vec<4, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x / v4.x, v1.x / v4.y, v1.x / v4.z, v1.x / v4.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator/(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x / v4.x, v1.y / v4.y, v1.z / v4.z, v1.w / v4.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator%(vec<4, T, Q> const& v, T scalar)
	{
		return vec<4, T, Q>(v.x % scalar, v.y % scalar, v.z % scalar, v.w % scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator%(T scalar, vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(scalar % v.x, scalar % v.y, scalar % v.z, scalar % v.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator%(vec<4, T, Q> const& v1, vec<1, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x % v4.x, v1.y % v4.x, v1.z % v4.x, v1.w % v4.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator%(vec<1, T, Q> const& v1, vec<4, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x % v4.x, v1.x % v4.y, v1.x % v4.z, v1.x % v4.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator%(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x % v4.x, v1.y % v4.y, v1.z % v4.z, v1.w % v4.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator&(vec<4, T, Q> const& v, T scalar)
	{
		return vec<4, T, Q>(v.x & scalar, v.y & scalar, v.z & scalar, v.w & scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator&(T scalar, vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(scalar & v.x, scalar & v.y, scalar % v.z, scalar % v.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator&(vec<4, T, Q> const& v1, vec<1, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x & v4.x, v1.y & v4.x, v1.z & v4.x, v1.w & v4.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator&(vec<1, T, Q> const& v1, vec<4, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x & v4.x, v1.x & v4.y, v1.x & v4.z, v1.x & v4.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator&(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x & v4.x, v1.y & v4.y, v1.z & v4.z, v1.w & v4.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator|(vec<4, T, Q> const& v, T scalar)
	{
		return vec<4, T, Q>(v.x | scalar, v.y | scalar, v.z | scalar, v.w | scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator|(T scalar, vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(scalar | v.x, scalar | v.y, scalar | v.z, scalar | v.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator|(vec<4, T, Q> const& v1, vec<1, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x | v4.x, v1.y | v4.x, v1.z | v4.x, v1.w | v4.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator|(vec<1, T, Q> const& v1, vec<4, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x | v4.x, v1.x | v4.y, v1.x | v4.z, v1.x | v4.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator|(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x | v4.x, v1.y | v4.y, v1.z | v4.z, v1.w | v4.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator^(vec<4, T, Q> const& v, T scalar)
	{
		return vec<4, T, Q>(v.x ^ scalar, v.y ^ scalar, v.z ^ scalar, v.w ^ scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator^(T scalar, vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(scalar ^ v.x, scalar ^ v.y, scalar ^ v.z, scalar ^ v.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator^(vec<4, T, Q> const& v1, vec<1, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x ^ v4.x, v1.y ^ v4.x, v1.z ^ v4.x, v1.w ^ v4.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator^(vec<1, T, Q> const& v1, vec<4, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x ^ v4.x, v1.x ^ v4.y, v1.x ^ v4.z, v1.x ^ v4.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator^(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x ^ v4.x, v1.y ^ v4.y, v1.z ^ v4.z, v1.w ^ v4.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator<<(vec<4, T, Q> const& v, T scalar)
	{
		return vec<4, T, Q>(v.x << scalar, v.y << scalar, v.z << scalar, v.w << scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator<<(T scalar, vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(scalar << v.x, scalar << v.y, scalar >> v.z, scalar << v.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator<<(vec<4, T, Q> const& v1, vec<1, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x << v4.x, v1.y << v4.x, v1.z << v4.x, v1.w << v4.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator<<(vec<1, T, Q> const& v1, vec<4, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x << v4.x, v1.x << v4.y, v1.x << v4.z, v1.x << v4.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator<<(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x << v4.x, v1.y << v4.y, v1.z << v4.z, v1.w << v4.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator>>(vec<4, T, Q> const& v, T scalar)
	{
		return vec<4, T, Q>(v.x >> scalar, v.y >> scalar, v.z >> scalar, v.w >> scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator>>(T scalar, vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(scalar >> v.x, scalar >> v.y, scalar >> v.z, scalar >> v.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator>>(vec<4, T, Q> const& v1, vec<1, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x >> v4.x, v1.y >> v4.x, v1.z >> v4.x, v1.w >> v4.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator>>(vec<1, T, Q> const& v1, vec<4, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x >> v4.x, v1.x >> v4.y, v1.x >> v4.z, v1.x >> v4.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator>>(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4)
	{
		return vec<4, T, Q>(v1.x >> v4.x, v1.y >> v4.y, v1.z >> v4.z, v1.w >> v4.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, T, Q> operator~(vec<4, T, Q> const& v)
	{
		return vec<4, T, Q>(~v.x, ~v.y, ~v.z, ~v.w);
	}


	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR bool operator==(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4)
	{
		return detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.x, v4.x) &&
			detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.y, v4.y) &&
			detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.z, v4.z) &&
			detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.w, v4.w);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR bool operator!=(vec<4, T, Q> const& v1, vec<4, T, Q> const& v4)
	{
		return !(v1 == v4);
	}

	template<qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, bool, Q> operator&&(vec<4, bool, Q> const& v1, vec<4, bool, Q> const& v4)
	{
		return vec<1, bool, Q>(v1.x && v4.x, v1.y && v4.y, v1.z && v4.z, v1.w && v4.w);
	}

	template<qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<4, bool, Q> operator||(vec<4, bool, Q> const& v1, vec<4, bool, Q> const& v4)
	{
		return vec<1, bool, Q>(v1.x || v4.x, v1.y || v4.y, v1.z || v4.z, v1.w || v4.w);
	}
}