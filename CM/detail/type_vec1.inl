#include "./compute_vector_relational.hpp"

namespace cm
{
	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR T& vec<1, T, Q>::operator[](typename vec<1, T, Q>::length_type) {
		return x;
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR T const& vec<1, T, Q>::operator[](typename vec<1, T, Q>::length_type) const
	{
		return x;
	}

#	if CM_CONFIG_DEFAULTED_DEFAULT_CTOR == CM_DISABLE
	template<typename T, qualifier Q>
	CM_DEFAULTED_DEFAULT_CTOR_QUALIFIER CM_CONSTEXPR vec<1, T, Q>::vec() CM_DEFAULT_CTOR
#		if CM_CONFIG_CTOR_INIT != CM_DISABLE
			: x(0)
#		endif
	{
	}
#	endif

#	if CM_CONFIG_DEFAULTED_FUNCTIONS  == CM_DISABLE
	template<typename T, qualifier Q>
	CM_DEFAULTED_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>::vec(vec<1, T, Q> const& v) CM_DEFAULT
		: x(v.x)
	{
	}
#	endif

	template<typename T, qualifier Q>
	template<qualifier P>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>::vec(vec<1, T, P> const& v)
		: x(v.x)
	{ }


	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>::vec(T scalar)
		: x(scalar)
	{ }

	template<typename T, qualifier Q>
	template<typename U, qualifier P>
	CM_FUNC_DECL CM_CONSTEXPR vec<1, T, Q>::vec(vec<2, U, P> const& v)
		: x(v.x)
	{ }

	template<typename T, qualifier Q>
	template<typename U, qualifier P>
	CM_DEFAULTED_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>::vec(vec<1, U, P> const& v)
		: x(v.x)
	{ }

	template<typename T, qualifier Q>
	template<typename U, qualifier P>
	CM_DEFAULTED_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>::vec(vec<3, U, P> const& v)
		: x(v.x)
	{
	}

	template<typename T, qualifier Q>
	template<typename U, qualifier P>
	CM_DEFAULTED_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>::vec(vec<4, U, P> const& v)
		: x(v.x)
	{
	}

#	if CM_CONFIG_DEFAULTED_FUNCTIONS == CM_DISABLE
	template<typename T, qualifier Q>
		CM_DEFAULTED_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator=(vec<1, T, Q> const& v)
		{
			this->x = v.x;
			return *this;
		}
#	endif

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator=(vec<1, U, Q> const& v)
	{
		this->x = static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator+=(U scalar)
	{
		this->x += static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator+=(vec<1, U, Q> const& v)
	{
		this->x += static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator-=(U scalar)
	{
		this->x -= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator-=(vec<1, U, Q> const& v)
	{
		this->x -= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator*=(U scalar)
	{
		this->x *= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator*=(vec<1, U, Q> const& v)
	{
		this->x *= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator/=(U scalar)
	{
		this->x /= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator/=(vec<1, U, Q> const& v)
	{
		this->x /= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator++()
	{
		++this->x;
		return *this;
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator--()
	{
		--this->x;
		return *this;
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q> vec<1, T, Q>::operator++(int)
	{
		vec<1, T, Q> Result(*this);
		++*this;
		return Result;
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q> vec<1, T, Q>::operator--(int)
	{
		vec<1, T, Q> Result(*this);
		--*this;
		return Result;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator%=(U scalar)
	{
		this->x %= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator%=(vec<1, U, Q> const& v)
	{
		this->x %= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator&=(U scalar)
	{
		this->x &= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator&=(vec<1, U, Q> const& v)
	{
		this->x &= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator|=(U scalar)
	{
		this->x |= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator|=(vec<1, U, Q> const& v)
	{
		this->x |= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator^=(U scalar)
	{
		this->x ^= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator^=(vec<1, U, Q> const& v)
	{
		this->x ^= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator<<=(U scalar)
	{
		this->x <<= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator<<=(vec<1, U, Q> const& v)
	{
		this->x <<= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator>>=(U scalar)
	{
		this->x >>= static_cast<T>(scalar);
		return *this;
	}

	template<typename T, qualifier Q>
	template<typename U>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& vec<1, T, Q>::operator>>=(vec<1, U, Q> const& v)
	{
		this->x >>= static_cast<T>(v.x);
		return *this;
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator+(vec<1, T, Q> const& v)
	{
		return v;
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator-(vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(-v.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator+(vec<1, T, Q> const& v, T scalar)
	{
		return vec<1, T, Q>(v.x + scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator+(T scalar, vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(scalar + v.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator+(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<1, T, Q>(v1.x + v2.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator-(vec<1, T, Q> const& v, T scalar)
	{
		return vec<1, T, Q>(v.x - scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator-(T scalar, vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(scalar - v.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator-(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<1, T, Q>(v1.x - v2.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator*(vec<1, T, Q> const& v, T scalar)
	{
		return vec<1, T, Q>(v.x * scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator*(T scalar, vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(scalar * v.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator*(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<1, T, Q>(v1.x * v2.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator/(vec<1, T, Q> const& v, T scalar)
	{
		return vec<1, T, Q>(v.x / scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator/(T scalar, vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(scalar / v.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator/(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<1, T, Q>(v1.x / v2.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator%(vec<1, T, Q> const& v, T scalar)
	{
		return vec<1, T, Q>(v.x % scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator%(T scalar, vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(scalar % v.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator%(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<1, T, Q>(v1.x % v2.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator&(vec<1, T, Q> const& v, T scalar)
	{
		return vec<1, T, Q>(v.x & scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator&(T scalar, vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(scalar & v.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator&(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<1, T, Q>(v1.x & v2.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator|(vec<1, T, Q> const& v, T scalar)
	{
		return vec<1, T, Q>(v.x | scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator|(T scalar, vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(scalar | v.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator|(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<1, T, Q>(v1.x | v2.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator^(vec<1, T, Q> const& v, T scalar)
	{
		return vec<1, T, Q>(v.x ^ scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator^(T scalar, vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(scalar ^ v.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator^(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<1, T, Q>(v1.x ^ v2.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator<<(vec<1, T, Q> const& v, T scalar)
	{
		return vec<1, T, Q>(v.x << scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator<<(T scalar, vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(scalar << v.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator<<(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<1, T, Q>(v1.x << v2.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator>>(vec<1, T, Q> const& v, T scalar)
	{
		return vec<1, T, Q>(v.x >> scalar);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator>>(T scalar, vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(scalar >> v.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator>>(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return vec<1, T, Q>(v1.x >> v2.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, T, Q>& operator~(vec<1, T, Q> const& v)
	{
		return vec<1, T, Q>(~v.x);
	}


	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR bool operator==(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		return detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.x, v2.x);
	}

	template<typename T, qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR bool operator!=(vec<1, T, Q> const& v1, vec<1, T, Q> const& v2)
	{
		/*return !(detail::compute_equal<T, std::numeric_limits<T>::is_iec559>::call(v1.x, v2.x));*/
		return !(v1 == v2);
	}

	template<qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, bool, Q> operator&&(vec<1, bool, Q> const& v1, vec<1, bool, Q> const& v2)
	{
		return vec<1, bool, Q>(v1.x && v2.x);
	}

	template<qualifier Q>
	CM_FUNC_QUALIFIER CM_CONSTEXPR vec<1, bool, Q> operator||(vec<1, bool, Q> const& v1, vec<1, bool, Q> const& v2)
	{
		return vec<1, bool, Q>(v1.x || v2.x);
	}
}