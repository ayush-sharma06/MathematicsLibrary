#include "compute_vector_relational.hpp"

namespace cm
{
	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR T& vec<3, T, Q>::operator[](typename vec<3, T, Q>::length_type i) {
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
		}
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR T const& vec<3, T, Q>::operator[](typename vec<3, T, Q>::length_type i) const
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
		}
	}

#	if CM_CONFIG_DEFAULTED_DEFAULT_CTOR == CM_DISABLE
	template<typename T, qualifier Q>
	CM_DEFAULTED_DEFAULT_CTOR_QUALIFIER CM_CONSTEXPR vec<3, T, Q>::vec()
#		if CM_CONFIG_CTOR_INIT != CM_CTOR_INIT_DISABLE
		: x(0), y(0), z(0)
#		endif
	{
	}
#	endif

#	if CM_CONFIG_DEFAULTED_FUNCTIONS == CM_DISABLE
	template<typename T, qualifier Q>
	CM_DEFAULTED_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>::vec(vec<3, T, Q> const& v)
		: x(v.x), y(v.y), z(v.z)
	{
	}
#	endif

	template<typename T, qualifier Q>
	template<qualifier P>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>::vec(vec<3, T, P> const& v)
		: x(v.x), y(v.y), z(v.z)
	{
	}


	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>::vec(T scalar)
		: x(scalar), y(scalar), z(scalar)
	{
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>::vec(T a, T b, T c)
		: x(a), y(b), z(c)
	{
	}

	template<typename T, qualifier Q>
	template<typename U, qualifier P>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>::vec(vec<1, U, P> const& v)
		: x(static_cast<T>(v.x)), y(static_cast<T>(v.x)), z(static_cast<T>(v.x))
	{
	}

	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>::vec(X _x, Y _y, Z _z)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_z))
	{
	}

	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>::vec(vec<1, X, Q> const& _x, Y _y, Z _z)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_z))
	{
	}

	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>::vec(X _x, vec<1, Y, Q> const& _y, Z _z)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z))
	{
	}

	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>::vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, Z _z)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z))
	{
	}

	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>::vec(X _x, Y _y, vec<1, Z, Q> const& _z)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y)), z(static_cast<T>(_z.x))
	{
	}

	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>::vec(vec<1, X, Q> const& _x, Y _y, vec<1, Z, Q> const& _z)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y)), z(static_cast<T>(_z.x))
	{
	}

	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>::vec(X _x, vec<1, Y, Q> const&  _y, vec<1, Z, Q> const& _z)
		: x(static_cast<T>(_x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z.x))
	{
	}

	template<typename T, qualifier Q>
	template<typename X, typename Y, typename Z>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>::vec(vec<1, X, Q> const& _x, vec<1, Y, Q> const& _y, vec<1, Z, Q> const& _z)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_y.x)), z(static_cast<T>(_z.x))
	{
	}

	template<typename T, qualifier Q>
	template<typename A, typename B, qualifier P>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>::vec(vec<2, A, P> const& _xy, B _z)
		: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_z))
	{ }

	template<typename T, qualifier Q>
	template<typename A, typename B, qualifier P>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>::vec(vec<2, A, P> const& _xy, vec<1, B, P> const& _z)
		: x(static_cast<T>(_xy.x)), y(static_cast<T>(_xy.y)), z(static_cast<T>(_z.x))
	{
	}

	template<typename T, qualifier Q>
	template<typename A, typename B, qualifier P>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>::vec(A _x, vec<2, B, P> const& _yz)
		: x(static_cast<T>(_x)), y(static_cast<T>(_yz.x)), z(static_cast<T>(_yz.y))
	{
	}

	template<typename T, qualifier Q>
	template<typename A, typename B, qualifier P>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>::vec(vec<1, A, P> const& _x, vec<2, B, P> const& _yz)
		: x(static_cast<T>(_x.x)), y(static_cast<T>(_yz.x)), z(static_cast<T>(_yz.y))
	{
	}

	template<typename T, qualifier Q>
	template<typename U, qualifier P>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>::vec(vec<3, U, P> const& v)
		: x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast<T>(v.z))
	{
	}

	template<typename T, qualifier Q>
	template<typename U, qualifier P>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>::vec(vec<4, U, P> const& v)
		: x(static_cast<T>(v.x)), y(static_cast<T>(v.y)), z(static_cast(v.z))
	{
	}



#	if CM_CONFIG_DEFAULTED_FUNCTIONS == CM_DISABLE
	template<typename T, qualifier Q>
	CM_DEFAULTED_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator=(vec<3, T, Q> const& v)
	{
		this->x = v.x;
		this->y = v.y;
		this->z = v.z;
		return *this;
	}
#	endif

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator=(vec<3, U, Q> const& v)
	{
		this->x = static_cast<T>(v.x);
		this->y = static_cast<T>(v.y);
		this->z = static_cast<T>(v.z);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator+=(U scalar)
	{
		this->x += static_cast<T>(scalar);
		this->y += static_cast<T>(scalar);
		this->z += static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator+=(vec<1, U, Q> const& v)
	{
		this->x += static_cast<T>(v.x);
		this->y += static_cast<T>(v.x);
		this->z += static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator+=(vec<3, U, Q> const& v)
	{
		this->x += static_cast<T>(v.x);
		this->y += static_cast<T>(v.y);
		this->z += static_cast<T>(v.z);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator-=(U scalar)
	{
		this->x -= static_cast<T>(scalar);
		this->y -= static_cast<T>(scalar);
		this->z -= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator-=(vec<1, U, Q> const& v)
	{
		this->x -= static_cast<T>(v.x);
		this->y -= static_cast<T>(v.x);
		this->z -= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator-=(vec<3, U, Q> const& v)
	{
		this->x -= static_cast<T>(v.x);
		this->y -= static_cast<T>(v.y);
		this->z -= static_cast<T>(v.z);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator*=(U scalar)
	{
		this->x *= static_cast<T>(scalar);
		this->y *= static_cast<T>(scalar);
		this->z *= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator*=(vec<1, U, Q> const& v)
	{
		this->x *= static_cast<T>(v.x);
		this->y *= static_cast<T>(v.x);
		this->z *= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator*=(vec<3, U, Q> const& v)
	{
		this->x *= static_cast<T>(v.x);
		this->y *= static_cast<T>(v.y);
		this->z *= static_cast<T>(v.z);
		return *this;
	}


	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator/=(U scalar)
	{
		this->x /= static_cast<T>(scalar);
		this->y /= static_cast<T>(scalar);
		this->z /= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator/=(vec<1, U, Q> const& v)
	{
		this->x /= static_cast<T>(v.x);
		this->y /= static_cast<T>(v.x);
		this->z /= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator/=(vec<3, U, Q> const& v)
	{
		this->x /= static_cast<T>(v.x);
		this->y /= static_cast<T>(v.y);
		this->z /= static_cast<T>(v.z);
		return *this;
	}



	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator++()
	{
		++this->x;
		++this->y;
		++this->z;
		return *this;
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator--()
	{
		--this->x;
		--this->y;
		--this->z;
		return *this;
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> vec<3, T, Q>::operator++(int)
	{
		vec<3, T, Q> Result(*this);
		++*this;
		return Result;
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> vec<3, T, Q>::operator--(int)
	{
		vec<3, T, Q> Result(*this);
		--*this;
		return Result;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator%=(U scalar)
	{
		this->x %= static_cast<T>(scalar);
		this->y %= static_cast<T>(scalar);
		this->z %= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator%=(vec<1, U, Q> const& v)
	{
		this->x %= static_cast<T>(v.x);
		this->y %= static_cast<T>(v.x);
		this->z %= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator%=(vec<3, U, Q> const& v)
	{
		this->x %= static_cast<T>(v.x);
		this->y %= static_cast<T>(v.y);
		this->z %= static_cast<T>(v.z);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator&=(U scalar)
	{
		this->x &= static_cast<T>(scalar);
		this->y &= static_cast<T>(scalar);
		this->z &= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator&=(vec<1, U, Q> const& v)
	{
		this->x &= static_cast<T>(v.x);
		this->y &= static_cast<T>(v.x);
		this->z &= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator&=(vec<3, U, Q> const& v)
	{
		this->x &= static_cast<T>(v.x);
		this->y &= static_cast<T>(v.y);
		this->z &= static_cast<T>(v.z);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator|=(U scalar)
	{
		this->x |= static_cast<T>(scalar);
		this->y |= static_cast<T>(scalar);
		this->z |= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator|=(vec<1, U, Q> const& v)
	{
		this->x |= static_cast<T>(v.x);
		this->y |= static_cast<T>(v.x);
		this->z |= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator|=(vec<3, U, Q> const& v)
	{
		this->x |= static_cast<T>(v.x);
		this->y |= static_cast<T>(v.y);
		this->z |= static_cast<T>(v.z);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator^=(U scalar)
	{
		this->x ^= static_cast<T>(scalar);
		this->y ^= static_cast<T>(scalar);
		this->z ^= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator^=(vec<1, U, Q> const& v)
	{
		this->x ^= static_cast<T>(v.x);
		this->y ^= static_cast<T>(v.x);
		this->z ^= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator^=(vec<3, U, Q> const& v)
	{
		this->x ^= static_cast<T>(v.x);
		this->y ^= static_cast<T>(v.y);
		this->z ^= static_cast<T>(v.z);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator<<=(U scalar)
	{
		this->x <<= static_cast<T>(scalar);
		this->y <<= static_cast<T>(scalar);
		this->z <<= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator<<=(vec<1, U, Q> const& v)
	{
		this->x <<= static_cast<T>(v.x);
		this->y <<= static_cast<T>(v.x);
		this->z <<= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator<<=(vec<3, U, Q> const& v)
	{
		this->x <<= static_cast<T>(v.x);
		this->y <<= static_cast<T>(v.y);
		this->z <<= static_cast<T>(v.z);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator>>=(U scalar)
	{
		this->x >>= static_cast<T>(scalar);
		this->y >>= static_cast<T>(scalar);
		this->z >>= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator>>=(vec<1, U, Q> const& v)
	{
		this->x >>= static_cast<T>(v.x);
		this->y >>= static_cast<T>(v.x);
		this->z >>= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q>& vec<3, T, Q>::operator>>=(vec<3, U, Q> const& v)
	{
		this->x >>= static_cast<T>(v.x);
		this->y >>= static_cast<T>(v.y);
		this->z >>= static_cast<T>(v.z);
		return *this;
	}



	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator+(vec<3, T, Q> const& v)
	{
		return v;
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator-(vec<3, T, Q> const& v)
	{
		return vec<3, T, Q>(-v.x, -v.y, -v.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator+(vec<3, T, Q> const& v, T scalar)
	{
		return vec<3, T, Q>(v.x + scalar, v.y + scalar, v.z + scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator+(T scalar, vec<3, T, Q> const& v)
	{
		return vec<3, T, Q>(scalar + v.x, scalar + v.y, scalar + v.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator+(vec<3, T, Q> const& v1, vec<1, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x + v3.x, v1.y + v3.x, v1.z + v3.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator+(vec<1, T, Q> const& v1, vec<3, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x + v3.x, v1.x + v3.y, v1.x + v3.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator+(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x + v3.x, v1.y + v3.y, v1.z + v3.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator-(vec<3, T, Q> const& v, T scalar)
	{
		return vec<3, T, Q>(v.x - scalar, v.y - scalar, v.z - scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator-(T scalar, vec<3, T, Q> const& v)
	{
		return vec<3, T, Q>(scalar - v.x, scalar - v.y, scalar - v.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator-(vec<3, T, Q> const& v1, vec<1, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x - v3.x, v1.y - v3.x, v1.z - v3.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator-(vec<1, T, Q> const& v1, vec<3, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x - v3.x, v1.x - v3.y, v1.x - v3.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator-(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x - v3.x, v1.y - v3.y, v1.z - v3.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator*(vec<3, T, Q> const& v, T scalar)
	{
		return vec<3, T, Q>(v.x * scalar, v.y * scalar, v.z * scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator*(T scalar, vec<3, T, Q> const& v)
	{
		return vec<3, T, Q>(scalar * v.x, scalar * v.y, scalar * v.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator*(vec<3, T, Q> const& v1, vec<1, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x * v3.x, v1.y * v3.x, v1.z * v3.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator*(vec<1, T, Q> const& v1, vec<3, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x * v3.x, v1.x * v3.y, v1.x * v3.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator*(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x * v3.x, v1.y * v3.y, v1.z * v3.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator/(vec<3, T, Q> const& v, T scalar)
	{
		return vec<3, T, Q>(v.x / scalar, v.y / scalar, v.z / scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator/(T scalar, vec<3, T, Q> const& v)
	{
		return vec<3, T, Q>(scalar / v.x, scalar / v.y, scalar / v.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator/(vec<3, T, Q> const& v1, vec<1, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x / v3.x, v1.y / v3.x, v1.z / v3.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator/(vec<1, T, Q> const& v1, vec<3, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x / v3.x, v1.x / v3.y, v1.x / v3.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator/(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x / v3.x, v1.y / v3.y, v1.z / v3.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator%(vec<3, T, Q> const& v, T scalar)
	{
		return vec<3, T, Q>(v.x % scalar, v.y % scalar, v.z % scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator%(T scalar, vec<3, T, Q> const& v)
	{
		return vec<3, T, Q>(scalar % v.x, scalar % v.y, scalar % v.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator%(vec<3, T, Q> const& v1, vec<1, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x % v3.x, v1.y % v3.x, v1.z % v3.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator%(vec<1, T, Q> const& v1, vec<3, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x % v3.x, v1.x % v3.y, v1.x % v3.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator%(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x % v3.x, v1.y % v3.y, v1.z % v3.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator&(vec<3, T, Q> const& v, T scalar)
	{
		return vec<3, T, Q>(v.x & scalar, v.y & scalar, v.z & scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator&(T scalar, vec<3, T, Q> const& v)
	{
		return vec<3, T, Q>(scalar & v.x, scalar & v.y, scalar % v.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator&(vec<3, T, Q> const& v1, vec<1, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x & v3.x, v1.y & v3.x, v1.z & v3.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator&(vec<1, T, Q> const& v1, vec<3, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x & v3.x, v1.x & v3.y, v1.x & v3.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator&(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x & v3.x, v1.y & v3.y, v1.z & v3.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator|(vec<3, T, Q> const& v, T scalar)
	{
		return vec<3, T, Q>(v.x | scalar, v.y | scalar, v.z | scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator|(T scalar, vec<3, T, Q> const& v)
	{
		return vec<3, T, Q>(scalar | v.x, scalar | v.y, scalar | v.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator|(vec<3, T, Q> const& v1, vec<1, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x | v3.x, v1.y | v3.x, v1.z | v3.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator|(vec<1, T, Q> const& v1, vec<3, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x | v3.x, v1.x | v3.y, v1.x | v3.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator|(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x | v3.x, v1.y | v3.y, v1.z | v3.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator^(vec<3, T, Q> const& v, T scalar)
	{
		return vec<3, T, Q>(v.x ^ scalar, v.y ^ scalar, v.z ^ scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator^(T scalar, vec<3, T, Q> const& v)
	{
		return vec<3, T, Q>(scalar ^ v.x, scalar ^ v.y, scalar ^ v.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator^(vec<3, T, Q> const& v1, vec<1, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x ^ v3.x, v1.y ^ v3.x, v1.z ^ v3.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator^(vec<1, T, Q> const& v1, vec<3, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x ^ v3.x, v1.x ^ v3.y, v1.x ^ v3.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator^(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x ^ v3.x, v1.y ^ v3.y, v1.z ^ v3.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator<<(vec<3, T, Q> const& v, T scalar)
	{
		return vec<3, T, Q>(v.x << scalar, v.y << scalar, v.z << scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator<<(T scalar, vec<3, T, Q> const& v)
	{
		return vec<3, T, Q>(scalar << v.x, scalar << v.y, scalar >> v.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator<<(vec<3, T, Q> const& v1, vec<1, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x << v3.x, v1.y << v3.x, v1.z << v3.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator<<(vec<1, T, Q> const& v1, vec<3, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x << v3.x, v1.x << v3.y, v1.x << v3.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator<<(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x << v3.x, v1.y << v3.y, v1.z << v3.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator>>(vec<3, T, Q> const& v, T scalar)
	{
		return vec<3, T, Q>(v.x >> scalar, v.y >> scalar, v.z >> scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator>>(T scalar, vec<3, T, Q> const& v)
	{
		return vec<3, T, Q>(scalar >> v.x, scalar >> v.y, scalar >> v.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator>>(vec<3, T, Q> const& v1, vec<1, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x >> v3.x, v1.y >> v3.x, v1.z >> v3.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator>>(vec<1, T, Q> const& v1, vec<3, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x >> v3.x, v1.x >> v3.y, v1.x >> v3.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator>>(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3)
	{
		return vec<3, T, Q>(v1.x >> v3.x, v1.y >> v3.y, v1.z >> v3.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, T, Q> operator~(vec<3, T, Q> const& v)
	{
		return vec<3, T, Q>(~v.x, ~v.y, ~ v.z);
	}


	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR bool operator==(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3)
	{
		return detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.x, v3.x) &&
			detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.y, v3.y) &&
			detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.z, v3.z);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR bool operator!=(vec<3, T, Q> const& v1, vec<3, T, Q> const& v3)
	{
		return !(v1 == v3);
	}

	template<qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, bool, Q> operator&&(vec<3, bool, Q> const& v1, vec<3, bool, Q> const& v3)
	{
		return vec<1, bool, Q>(v1.x && v3.x, v1.y && v3.y, v1.z && v3.z);
	}

	template<qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<3, bool, Q> operator||(vec<3, bool, Q> const& v1, vec<3, bool, Q> const& v3)
	{
		return vec<1, bool, Q>(v1.x || v3.x, v1.y || v3.y, v1.z || v3.z);
	}
}