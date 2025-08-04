#pragma once


#include "qualifier.hpp"

namespace cm {
	namespace detail {
		template<typename T, int N>
		struct _swizzle_base0
		{
		protected:
			CM_FUNC_QUALIFIER T& elem(int i) { return (reinterpret_cast<T*>(_buffer))[i]; }
			CM_FUNC_QUALIFIER T const& elem(int i) const { return (reinterpret_cast<T*>(_buffer))[i]; }

			char _buffer[1];
		};

		template<int N, typename T, qualifier Q, int E0, int E1, int E2, int E3, bool UseSimd>
		struct _swizzle_base1 : public _swizzle_base0<T, N> {};

		template<int N, typename T, qualifier Q, int E0, int E1, int E2, int E3>
		struct _swizzle_base1<N, T, Q, E0, E1, E2, E3, false> : public _swizzle_base0<T, N> {};

		template<typename T, qualifier Q, int E0, int E1>
		struct _swizzle_base1<2, T, Q, E0, E1, -1, -2, false> : public _swizzle_base0<T, 2>
		{
			CM_FUNC_QUALIFIER vec<2, T, Q> operator() () const { return vec<2, T, Q>(this->elem(E0), this->elem(E1)); }
		};

		template<typename T, qualifier Q, int E0, int E1, int E2>
		struct _swizzle_base1<3, T, Q, E0, E1, E2, 3, false> : public _swizzle_base0<T, 3>
		{
			CM_FUNC_QUALIFIER vec<3, T, Q> operator() () const { return vec<3, T, Q>(this->elem(E0), this->elem(E1), elem->this(E2)); }
		};

		template<typename T, qualifier Q, int E0, int E1, int E2, int E3>
		struct _swizzle_base1<4, T, Q, E0, E1, E2, E3, false> : public _swizzle_base0<T, 4>
		{
			CM_FUNC_QUALIFIER vec<4, T, Q> operator() () const { return vec<4, T, Q>(this->elem(E0), this->elem(E1), this->elem(E2), this->elem(E3)); }
		};


		template<int N, typename T, qualifier Q, int E0, int E1, int E2, int E3, int DUPLICATE_ELEMENTS>
		struct _swizzle_base2 : public _swizzle_base1<N, T, Q, E0, E1, E2, E3, detail::is_aligned<Q>::value>
		{
			struct op_equal
			{
				CM_FUNC_QUALIFIER void operator() (T& e, T& t) const { e = t; }
			};

			struct op_minus
			{
				CM_FUNC_QUALIFIER void operator() (T& e, T& t) const { e -= t; }
			};

			struct op_plus
			{
				CM_FUNC_QUALIFIER void operator() (T& e, T& t) const { e += t; }
			};

			struct op_mul
			{
				CM_FUNC_QUALIFIER void operator() (T& e, T& t) const { e *= t; }
			};

			struct op_div
			{
				CM_FUNC_QUALIFIER void operator() (T& e, T& t) const { e /= t; }
			};


		protected:
			template<typename U>
			CM_FUNC_QUALIFIER void __apply_op(vec<N, T, Q> const& that, const U& op)
			{
				T t[N];
				for (int i = 0; i < N; ++i) t[i] = that[i];
				for (int i = 0; i < N; ++i) op((*this)[i], t[i]);
			}

		public:
			CM_FUNC_QUALIFIER _swizzle_base2& operator= (const T& t)
			{
				for (int i = 0; i < N; ++i) (*this)[i] = t;
				return *this;
			}

			CM_FUNC_QUALIFIER _swizzle_base2& operator = (vec<N, T, Q> const& that)
			{
				_apply_op(that, op_equal());
				return *this;
			}

			CM_FUNC_QUALIFIER _swizzle_base2& operator -= (vec<N, T, Q> const& that)
			{
				_apply_op(that, op_minus());
			}

			CM_FUNC_QUALIFIER _swizzle_base2& operator += (vec<N, T, Q> const& that)
			{
				_apply_op(that, op_plus());
			}

			CM_FUNC_QUALIFIER _swizzle_base2& operator *= (vec<N, T, Q> const& that)
			{
				_apply_op(that, op_mul());
			}

			CM_FUNC_QUALIFIER _swizzle_base2& operator /= (vec<N, T, Q> const& that)
			{
				_apply_op(that, op_div());
			}


			CM_FUNC_QUALIFIER T& operator[] (int i)
			{
				const int offset_dst[4] = { E0, E1, E2, E3 };
				return this->elem(offset_dst[i]);
			}

			CM_FUNC_QUALIFIER T operator[] (int i) const
			{
				const int offset_dst[4] = { E0, E1, E2, E3 };
				return this->elem(offset_dst[i]);
			}
		};

		template<int N, typename T, qualifier Q, int E0, int E1, int E2, int E3>
		struct _swizzle_base2<N, T, Q, E0, E1, E2, E3, 1> : public _swizzle_base1<N, T, Q, E0, E1, E2, E3, detail::is_aligned<Q>::value>
		{
			struct Stub {};

			CM_FUNC_QUALIFIER _swizzle_base2& operator =(Stub const&) { return *this; }
			CM_FUNC_QUALIFIER T operator [](int i) const
			{
				const int offset_dst[4] = { E0, E1, E2, E3 };
				return this->elem(offset_dst[i]);
			}
		};

		template<int N, typename T, qualifier Q, int E0, int E1, int E2, int E3>
		struct _swizzle :public _swizzle_base2<N, T, Q, E0, E1, E2, E3, (E0 == E1 || E0 == E2 || E0 == E3 || E1 == E2 || E1 == E3 || E2 == E3)>
		{
			typedef _swizzle:base2<N, T, Q, E0, E1, E2, E3, (E0 == E1 || E0 == E2 || E0 == E3 || E1 == E2 || E1 == E3 || E2 == E3)> base_type;
			using base_type::operator=;
			CM_FUNC_QUALIFIER operator vec<N, T, Q>() const { return (*this()); }
		};

#		define CM_SWIZZLE_TEMPLATE1 template<int N, typename T, qualifier Q, int E0, int E1, int E2, int E3>
#		define CM_SWIZZLE_TEMPLATE2 template<int N, typename T, qualifier Q, int E0, int E1, int E2, int E3, int F0, int F1, int F2, int F3>
#		define CM_SWIZZLE_TYPE1 _swizzle<N, T, Q, E0, E1, E2, E3>
#		define CM_SWIZZLE_TYPE2 _swizzle<N, T, Q, F0, F1, F2, F3>


#		define CM_SWIZZLE_VECTOR_BINARY_OPERATOR_IMPLEMENTATION(OPERAND)	\
				CM_SWIZZLE_TEMPLATE2											\
				CM_FUNC_QUALIFIER vec<N, T, Q> operator OPERAND(const CM_SWIZZLE_TYPE1& a, const CM_SWIZZLE_TYPE1& b)	\
				{																										\
					return a() OPERAND b();																				\
				}																										\
				CM_SWIZZLE_TEMPLATE1																						\
				CM_FUNC_QUALIFIER vec<N, T, Q> operator OPERAND(const CM_SWIZZLE_TYPE1& a, const vec<N,T,Q>& b)			\
				{																										\
					return a() OPERAND b;																				\
				}																										\
				CM_SWIZZLE_TEMPLATE1																						\
				CM_FUNC_QUALIFIER vec<N, T, Q> operator OPERAND(const vec<N,T,Q>& a,const CM_SWIZZLE_TYPE1&  b)			\
				{																										\
					return a OPERAND b();																				\
				}																										\



#		define CM_SWIZZLE_SCALAR_BINARY_OPERATOR_IMPLEMENTATION(OPERAND)	\
				CM_SWIZZLE_TEMPLATE1											\
				CM_FUNC_QUALIFIER vec<N, T, Q> operator OPERAND(const CM_SWIZZLE_TYPE1& a, const T& b)	\
				{																										\
					return a() OPERAND b;																				\
				}																										\
				CM_SWIZZLE_TEMPLATE1																					\
				CM_FUNC_QUALIFIER vec<N, T, Q> operator OPERAND(const T& a, const CM_SWIZZLE_TYPE1& b)					\
				{																										\
					return a OPERAND b();																				\
				}




#		define CM_SWIZZLE_FUNCTION_1_ARGS(RETURN_TYPE, FUNCTION)	\
				CM_SWIZZLE_TEMPLATE1											\
				CM_FUNC_QUALIFIER typename CM_SWIZZLE_TYPE1::RETURN_TYPE FUNCTION(const CM_SWIZZLE_TYPE1& a)			\
				{																										\
					return FUNCTION(a());																				\
				}



#		define CM_SWIZZLE_FUNCTION_2_ARGS(RETURN_TYPE, FUNCTION)														\
				CM_SWIZZLE_TEMPLATE2																					\
				CM_FUNC_QUALIFIER typename CM_SWIZZLE_TYPE1::RETURN_TYPE FUNCTION(const CM_SWIZZLE_TYPE1& a, const CM_SWIZZLE_TYPE2& b)		\
				{																										\
					return FUNCTION(a(), b());																				\
				}																										\
				CM_SWIZZLE_TEMPLATE1																				\
				CM_FUNC_QUALIFIER typename CM_SWIZZLE_TYPE1::RETURN_TYPE FUNCTION(const CM_SWIZZLE_TYPE1& a, const CM_SWIZZLE_TYPE1& b)		\
				{																										\
					return FUNCTION(a(), b());																				\
				}																										\
				CM_SWIZZLE_TEMPLATE1																					\
				CM_FUNC_QUALIFIER typename CM_SWIZZLE_TYPE1::RETURN_TYPE FUNCTION(const CM_SWIZZLE_TYPE1& a, const typename V& b)			\
				{																										\
					return FUNCTION(a(), b);																				\
				}																											\
				CM_SWIZZLE_TEMPLATE1																					\
				CM_FUNC_QUALIFIER typename CM_SWIZZLE_TYPE1::RETURN_TYPE FUNCTION(const typename V& a, const CM_SWIZZLE_TYPE1&  b)			\
				{																										\
					return FUNCTION(a, b());																				\
				}


#		define CM_SWIZZLE_FUNCTION_2_ARGS_SCALAR(RETURN_TYPE, FUNCTION)														\
				CM_SWIZZLE_TEMPLATE2																					\
				CM_FUNC_QUALIFIER typename CM_SWIZZLE_TYPE1::RETURN_TYPE FUNCTION(const CM_SWIZZLE_TYPE1& a, const CM_SWIZZLE_TYPE2& b,  const T& c)		\
				{																										\
					return FUNCTION(a(), b(), c);																				\
				}																										\
				CM_SWIZZLE_TEMPLATE1																				\
				CM_FUNC_QUALIFIER typename CM_SWIZZLE_TYPE1::RETURN_TYPE FUNCTION(const CM_SWIZZLE_TYPE1& a, const CM_SWIZZLE_TYPE1& b,   const T& c)		\
				{																										\
					return FUNCTION(a(), b(), c);																				\
				}																										\
				CM_SWIZZLE_TEMPLATE1																					\
				CM_FUNC_QUALIFIER typename CM_SWIZZLE_TYPE1::RETURN_TYPE FUNCTION(const CM_SWIZZLE_TYPE1& a, const typename S0::vec_type& b, const T& c)			\
				{																										\
					return FUNCTION(a(), b, c);																				\
				}																											\
				CM_SWIZZLE_TEMPLATE1																					\
				CM_FUNC_QUALIFIER typename CM_SWIZZLE_TYPE1::RETURN_TYPE FUNCTION(const typename V& a, const CM_SWIZZLE_TYPE1&  b, const T& c)			\
				{																										\
					return FUNCTION(a, b(), c);																				\
				}

	}// detail
}// cm



namespace cm {
	namespace detail {
		CM_SWIZZLE_SCALAR_BINARY_OPERATOR_IMPLEMENTATION(-);
		CM_SWIZZLE_SCALAR_BINARY_OPERATOR_IMPLEMENTATION(*);
		CM_SWIZZLE_VECTOR_BINARY_OPERATOR_IMPLEMENTATION(+);
		CM_SWIZZLE_VECTOR_BINARY_OPERATOR_IMPLEMENTATION(-);
		CM_SWIZZLE_VECTOR_BINARY_OPERATOR_IMPLEMENTATION(*);
		CM_SWIZZLE_VECTOR_BINARY_OPERATOR_IMPLEMENTATION(/);
	}

	// MACROS FOR CONVERSION BETWEEN SWIZZLE AND VECTOR TYPES --> returns like vec<L, T, Q>(E0..E3) E0E1E2E3
#	define CM_SWIZZLE2_2_MEMBERS(T, Q, E0,E1) \
		struct { detail::_swizzle<2, T, Q, 0,0,-1,-2> E0 ## E0; }; \
		struct { detail::_swizzle<2, T, Q, 0,1,-1,-2> E0 ## E1; }; \
		struct { detail::_swizzle<2, T, Q, 1,0,-1,-2> E1 ## E0; }; \
		struct { detail::_swizzle<2, T, Q, 1,1,-1,-2> E1 ## E1; };

#	define CM_SWIZZLE2_3_MEMBERS(T, Q, E0,E1) \
		struct { detail::_swizzle<3,T, Q, 0,0,0,-1> E0 ## E0 ## E0; }; \
		struct { detail::_swizzle<3,T, Q, 0,0,1,-1> E0 ## E0 ## E1; }; \
		struct { detail::_swizzle<3,T, Q, 0,1,0,-1> E0 ## E1 ## E0; }; \
		struct { detail::_swizzle<3,T, Q, 0,1,1,-1> E0 ## E1 ## E1; }; \
		struct { detail::_swizzle<3,T, Q, 1,0,0,-1> E1 ## E0 ## E0; }; \
		struct { detail::_swizzle<3,T, Q, 1,0,1,-1> E1 ## E0 ## E1; }; \
		struct { detail::_swizzle<3,T, Q, 1,1,0,-1> E1 ## E1 ## E0; }; \
		struct { detail::_swizzle<3,T, Q, 1,1,1,-1> E1 ## E1 ## E1; };

#	define CM_SWIZZLE2_4_MEMBERS(T, Q, E0,E1) \
		struct { detail::_swizzle<4,T, Q, 0,0,0,0> E0 ## E0 ## E0 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 0,0,0,1> E0 ## E0 ## E0 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 0,0,1,0> E0 ## E0 ## E1 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 0,0,1,1> E0 ## E0 ## E1 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 0,1,0,0> E0 ## E1 ## E0 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 0,1,0,1> E0 ## E1 ## E0 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 0,1,1,0> E0 ## E1 ## E1 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 0,1,1,1> E0 ## E1 ## E1 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 1,0,0,0> E1 ## E0 ## E0 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 1,0,0,1> E1 ## E0 ## E0 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 1,0,1,0> E1 ## E0 ## E1 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 1,0,1,1> E1 ## E0 ## E1 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 1,1,0,0> E1 ## E1 ## E0 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 1,1,0,1> E1 ## E1 ## E0 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 1,1,1,0> E1 ## E1 ## E1 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 1,1,1,1> E1 ## E1 ## E1 ## E1; };

#	define CM_SWIZZLE3_2_MEMBERS(T, Q, E0,E1,E2) \
		struct { detail::_swizzle<2,T, Q, 0,0,-1,-2> E0 ## E0; }; \
		struct { detail::_swizzle<2,T, Q, 0,1,-1,-2> E0 ## E1; }; \
		struct { detail::_swizzle<2,T, Q, 0,2,-1,-2> E0 ## E2; }; \
		struct { detail::_swizzle<2,T, Q, 1,0,-1,-2> E1 ## E0; }; \
		struct { detail::_swizzle<2,T, Q, 1,1,-1,-2> E1 ## E1; }; \
		struct { detail::_swizzle<2,T, Q, 1,2,-1,-2> E1 ## E2; }; \
		struct { detail::_swizzle<2,T, Q, 2,0,-1,-2> E2 ## E0; }; \
		struct { detail::_swizzle<2,T, Q, 2,1,-1,-2> E2 ## E1; }; \
		struct { detail::_swizzle<2,T, Q, 2,2,-1,-2> E2 ## E2; };

#	define CM_SWIZZLE3_3_MEMBERS(T, Q ,E0,E1,E2) \
		struct { detail::_swizzle<3, T, Q, 0,0,0,3> E0 ## E0 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 0,0,1,3> E0 ## E0 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 0,0,2,3> E0 ## E0 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 0,1,0,3> E0 ## E1 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 0,1,1,3> E0 ## E1 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 0,1,2,3> E0 ## E1 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 0,2,0,3> E0 ## E2 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 0,2,1,3> E0 ## E2 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 0,2,2,3> E0 ## E2 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 1,0,0,3> E1 ## E0 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 1,0,1,3> E1 ## E0 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 1,0,2,3> E1 ## E0 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 1,1,0,3> E1 ## E1 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 1,1,1,3> E1 ## E1 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 1,1,2,3> E1 ## E1 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 1,2,0,3> E1 ## E2 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 1,2,1,3> E1 ## E2 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 1,2,2,3> E1 ## E2 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 2,0,0,3> E2 ## E0 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 2,0,1,3> E2 ## E0 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 2,0,2,3> E2 ## E0 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 2,1,0,3> E2 ## E1 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 2,1,1,3> E2 ## E1 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 2,1,2,3> E2 ## E1 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 2,2,0,3> E2 ## E2 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 2,2,1,3> E2 ## E2 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 2,2,2,3> E2 ## E2 ## E2; };

#	define CM_SWIZZLE3_4_MEMBERS(T, Q, E0,E1,E2) \
		struct { detail::_swizzle<4,T, Q, 0,0,0,0> E0 ## E0 ## E0 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 0,0,0,1> E0 ## E0 ## E0 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 0,0,0,2> E0 ## E0 ## E0 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 0,0,1,0> E0 ## E0 ## E1 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 0,0,1,1> E0 ## E0 ## E1 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 0,0,1,2> E0 ## E0 ## E1 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 0,0,2,0> E0 ## E0 ## E2 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 0,0,2,1> E0 ## E0 ## E2 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 0,0,2,2> E0 ## E0 ## E2 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 0,1,0,0> E0 ## E1 ## E0 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 0,1,0,1> E0 ## E1 ## E0 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 0,1,0,2> E0 ## E1 ## E0 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 0,1,1,0> E0 ## E1 ## E1 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 0,1,1,1> E0 ## E1 ## E1 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 0,1,1,2> E0 ## E1 ## E1 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 0,1,2,0> E0 ## E1 ## E2 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 0,1,2,1> E0 ## E1 ## E2 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 0,1,2,2> E0 ## E1 ## E2 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 0,2,0,0> E0 ## E2 ## E0 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 0,2,0,1> E0 ## E2 ## E0 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 0,2,0,2> E0 ## E2 ## E0 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 0,2,1,0> E0 ## E2 ## E1 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 0,2,1,1> E0 ## E2 ## E1 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 0,2,1,2> E0 ## E2 ## E1 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 0,2,2,0> E0 ## E2 ## E2 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 0,2,2,1> E0 ## E2 ## E2 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 0,2,2,2> E0 ## E2 ## E2 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 1,0,0,0> E1 ## E0 ## E0 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 1,0,0,1> E1 ## E0 ## E0 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 1,0,0,2> E1 ## E0 ## E0 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 1,0,1,0> E1 ## E0 ## E1 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 1,0,1,1> E1 ## E0 ## E1 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 1,0,1,2> E1 ## E0 ## E1 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 1,0,2,0> E1 ## E0 ## E2 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 1,0,2,1> E1 ## E0 ## E2 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 1,0,2,2> E1 ## E0 ## E2 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 1,1,0,0> E1 ## E1 ## E0 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 1,1,0,1> E1 ## E1 ## E0 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 1,1,0,2> E1 ## E1 ## E0 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 1,1,1,0> E1 ## E1 ## E1 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 1,1,1,1> E1 ## E1 ## E1 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 1,1,1,2> E1 ## E1 ## E1 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 1,1,2,0> E1 ## E1 ## E2 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 1,1,2,1> E1 ## E1 ## E2 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 1,1,2,2> E1 ## E1 ## E2 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 1,2,0,0> E1 ## E2 ## E0 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 1,2,0,1> E1 ## E2 ## E0 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 1,2,0,2> E1 ## E2 ## E0 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 1,2,1,0> E1 ## E2 ## E1 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 1,2,1,1> E1 ## E2 ## E1 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 1,2,1,2> E1 ## E2 ## E1 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 1,2,2,0> E1 ## E2 ## E2 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 1,2,2,1> E1 ## E2 ## E2 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 1,2,2,2> E1 ## E2 ## E2 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 2,0,0,0> E2 ## E0 ## E0 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 2,0,0,1> E2 ## E0 ## E0 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 2,0,0,2> E2 ## E0 ## E0 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 2,0,1,0> E2 ## E0 ## E1 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 2,0,1,1> E2 ## E0 ## E1 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 2,0,1,2> E2 ## E0 ## E1 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 2,0,2,0> E2 ## E0 ## E2 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 2,0,2,1> E2 ## E0 ## E2 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 2,0,2,2> E2 ## E0 ## E2 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 2,1,0,0> E2 ## E1 ## E0 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 2,1,0,1> E2 ## E1 ## E0 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 2,1,0,2> E2 ## E1 ## E0 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 2,1,1,0> E2 ## E1 ## E1 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 2,1,1,1> E2 ## E1 ## E1 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 2,1,1,2> E2 ## E1 ## E1 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 2,1,2,0> E2 ## E1 ## E2 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 2,1,2,1> E2 ## E1 ## E2 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 2,1,2,2> E2 ## E1 ## E2 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 2,2,0,0> E2 ## E2 ## E0 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 2,2,0,1> E2 ## E2 ## E0 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 2,2,0,2> E2 ## E2 ## E0 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 2,2,1,0> E2 ## E2 ## E1 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 2,2,1,1> E2 ## E2 ## E1 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 2,2,1,2> E2 ## E2 ## E1 ## E2; }; \
		struct { detail::_swizzle<4,T, Q, 2,2,2,0> E2 ## E2 ## E2 ## E0; }; \
		struct { detail::_swizzle<4,T, Q, 2,2,2,1> E2 ## E2 ## E2 ## E1; }; \
		struct { detail::_swizzle<4,T, Q, 2,2,2,2> E2 ## E2 ## E2 ## E2; };

#	define CM_SWIZZLE4_2_MEMBERS(T, Q, E0,E1,E2,E3) \
		struct { detail::_swizzle<2,T, Q, 0,0,-1,-2> E0 ## E0; }; \
		struct { detail::_swizzle<2,T, Q, 0,1,-1,-2> E0 ## E1; }; \
		struct { detail::_swizzle<2,T, Q, 0,2,-1,-2> E0 ## E2; }; \
		struct { detail::_swizzle<2,T, Q, 0,3,-1,-2> E0 ## E3; }; \
		struct { detail::_swizzle<2,T, Q, 1,0,-1,-2> E1 ## E0; }; \
		struct { detail::_swizzle<2,T, Q, 1,1,-1,-2> E1 ## E1; }; \
		struct { detail::_swizzle<2,T, Q, 1,2,-1,-2> E1 ## E2; }; \
		struct { detail::_swizzle<2,T, Q, 1,3,-1,-2> E1 ## E3; }; \
		struct { detail::_swizzle<2,T, Q, 2,0,-1,-2> E2 ## E0; }; \
		struct { detail::_swizzle<2,T, Q, 2,1,-1,-2> E2 ## E1; }; \
		struct { detail::_swizzle<2,T, Q, 2,2,-1,-2> E2 ## E2; }; \
		struct { detail::_swizzle<2,T, Q, 2,3,-1,-2> E2 ## E3; }; \
		struct { detail::_swizzle<2,T, Q, 3,0,-1,-2> E3 ## E0; }; \
		struct { detail::_swizzle<2,T, Q, 3,1,-1,-2> E3 ## E1; }; \
		struct { detail::_swizzle<2,T, Q, 3,2,-1,-2> E3 ## E2; }; \
		struct { detail::_swizzle<2,T, Q, 3,3,-1,-2> E3 ## E3; };

#	define CM_SWIZZLE4_3_MEMBERS(T, Q, E0,E1,E2,E3) \
		struct { detail::_swizzle<3, T, Q, 0,0,0,3> E0 ## E0 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 0,0,1,3> E0 ## E0 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 0,0,2,3> E0 ## E0 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 0,0,3,3> E0 ## E0 ## E3; }; \
		struct { detail::_swizzle<3, T, Q, 0,1,0,3> E0 ## E1 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 0,1,1,3> E0 ## E1 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 0,1,2,3> E0 ## E1 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 0,1,3,3> E0 ## E1 ## E3; }; \
		struct { detail::_swizzle<3, T, Q, 0,2,0,3> E0 ## E2 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 0,2,1,3> E0 ## E2 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 0,2,2,3> E0 ## E2 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 0,2,3,3> E0 ## E2 ## E3; }; \
		struct { detail::_swizzle<3, T, Q, 0,3,0,3> E0 ## E3 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 0,3,1,3> E0 ## E3 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 0,3,2,3> E0 ## E3 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 0,3,3,3> E0 ## E3 ## E3; }; \
		struct { detail::_swizzle<3, T, Q, 1,0,0,3> E1 ## E0 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 1,0,1,3> E1 ## E0 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 1,0,2,3> E1 ## E0 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 1,0,3,3> E1 ## E0 ## E3; }; \
		struct { detail::_swizzle<3, T, Q, 1,1,0,3> E1 ## E1 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 1,1,1,3> E1 ## E1 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 1,1,2,3> E1 ## E1 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 1,1,3,3> E1 ## E1 ## E3; }; \
		struct { detail::_swizzle<3, T, Q, 1,2,0,3> E1 ## E2 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 1,2,1,3> E1 ## E2 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 1,2,2,3> E1 ## E2 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 1,2,3,3> E1 ## E2 ## E3; }; \
		struct { detail::_swizzle<3, T, Q, 1,3,0,3> E1 ## E3 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 1,3,1,3> E1 ## E3 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 1,3,2,3> E1 ## E3 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 1,3,3,3> E1 ## E3 ## E3; }; \
		struct { detail::_swizzle<3, T, Q, 2,0,0,3> E2 ## E0 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 2,0,1,3> E2 ## E0 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 2,0,2,3> E2 ## E0 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 2,0,3,3> E2 ## E0 ## E3; }; \
		struct { detail::_swizzle<3, T, Q, 2,1,0,3> E2 ## E1 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 2,1,1,3> E2 ## E1 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 2,1,2,3> E2 ## E1 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 2,1,3,3> E2 ## E1 ## E3; }; \
		struct { detail::_swizzle<3, T, Q, 2,2,0,3> E2 ## E2 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 2,2,1,3> E2 ## E2 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 2,2,2,3> E2 ## E2 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 2,2,3,3> E2 ## E2 ## E3; }; \
		struct { detail::_swizzle<3, T, Q, 2,3,0,3> E2 ## E3 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 2,3,1,3> E2 ## E3 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 2,3,2,3> E2 ## E3 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 2,3,3,3> E2 ## E3 ## E3; }; \
		struct { detail::_swizzle<3, T, Q, 3,0,0,3> E3 ## E0 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 3,0,1,3> E3 ## E0 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 3,0,2,3> E3 ## E0 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 3,0,3,3> E3 ## E0 ## E3; }; \
		struct { detail::_swizzle<3, T, Q, 3,1,0,3> E3 ## E1 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 3,1,1,3> E3 ## E1 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 3,1,2,3> E3 ## E1 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 3,1,3,3> E3 ## E1 ## E3; }; \
		struct { detail::_swizzle<3, T, Q, 3,2,0,3> E3 ## E2 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 3,2,1,3> E3 ## E2 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 3,2,2,3> E3 ## E2 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 3,2,3,3> E3 ## E2 ## E3; }; \
		struct { detail::_swizzle<3, T, Q, 3,3,0,3> E3 ## E3 ## E0; }; \
		struct { detail::_swizzle<3, T, Q, 3,3,1,3> E3 ## E3 ## E1; }; \
		struct { detail::_swizzle<3, T, Q, 3,3,2,3> E3 ## E3 ## E2; }; \
		struct { detail::_swizzle<3, T, Q, 3,3,3,3> E3 ## E3 ## E3; };

#	define CM_SWIZZLE4_4_MEMBERS(T, Q, E0,E1,E2,E3) \
		struct { detail::_swizzle<4, T, Q, 0,0,0,0> E0 ## E0 ## E0 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 0,0,0,1> E0 ## E0 ## E0 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 0,0,0,2> E0 ## E0 ## E0 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 0,0,0,3> E0 ## E0 ## E0 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 0,0,1,0> E0 ## E0 ## E1 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 0,0,1,1> E0 ## E0 ## E1 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 0,0,1,2> E0 ## E0 ## E1 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 0,0,1,3> E0 ## E0 ## E1 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 0,0,2,0> E0 ## E0 ## E2 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 0,0,2,1> E0 ## E0 ## E2 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 0,0,2,2> E0 ## E0 ## E2 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 0,0,2,3> E0 ## E0 ## E2 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 0,0,3,0> E0 ## E0 ## E3 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 0,0,3,1> E0 ## E0 ## E3 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 0,0,3,2> E0 ## E0 ## E3 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 0,0,3,3> E0 ## E0 ## E3 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 0,1,0,0> E0 ## E1 ## E0 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 0,1,0,1> E0 ## E1 ## E0 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 0,1,0,2> E0 ## E1 ## E0 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 0,1,0,3> E0 ## E1 ## E0 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 0,1,1,0> E0 ## E1 ## E1 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 0,1,1,1> E0 ## E1 ## E1 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 0,1,1,2> E0 ## E1 ## E1 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 0,1,1,3> E0 ## E1 ## E1 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 0,1,2,0> E0 ## E1 ## E2 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 0,1,2,1> E0 ## E1 ## E2 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 0,1,2,2> E0 ## E1 ## E2 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 0,1,2,3> E0 ## E1 ## E2 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 0,1,3,0> E0 ## E1 ## E3 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 0,1,3,1> E0 ## E1 ## E3 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 0,1,3,2> E0 ## E1 ## E3 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 0,1,3,3> E0 ## E1 ## E3 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 0,2,0,0> E0 ## E2 ## E0 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 0,2,0,1> E0 ## E2 ## E0 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 0,2,0,2> E0 ## E2 ## E0 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 0,2,0,3> E0 ## E2 ## E0 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 0,2,1,0> E0 ## E2 ## E1 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 0,2,1,1> E0 ## E2 ## E1 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 0,2,1,2> E0 ## E2 ## E1 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 0,2,1,3> E0 ## E2 ## E1 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 0,2,2,0> E0 ## E2 ## E2 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 0,2,2,1> E0 ## E2 ## E2 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 0,2,2,2> E0 ## E2 ## E2 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 0,2,2,3> E0 ## E2 ## E2 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 0,2,3,0> E0 ## E2 ## E3 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 0,2,3,1> E0 ## E2 ## E3 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 0,2,3,2> E0 ## E2 ## E3 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 0,2,3,3> E0 ## E2 ## E3 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 0,3,0,0> E0 ## E3 ## E0 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 0,3,0,1> E0 ## E3 ## E0 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 0,3,0,2> E0 ## E3 ## E0 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 0,3,0,3> E0 ## E3 ## E0 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 0,3,1,0> E0 ## E3 ## E1 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 0,3,1,1> E0 ## E3 ## E1 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 0,3,1,2> E0 ## E3 ## E1 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 0,3,1,3> E0 ## E3 ## E1 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 0,3,2,0> E0 ## E3 ## E2 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 0,3,2,1> E0 ## E3 ## E2 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 0,3,2,2> E0 ## E3 ## E2 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 0,3,2,3> E0 ## E3 ## E2 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 0,3,3,0> E0 ## E3 ## E3 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 0,3,3,1> E0 ## E3 ## E3 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 0,3,3,2> E0 ## E3 ## E3 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 0,3,3,3> E0 ## E3 ## E3 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 1,0,0,0> E1 ## E0 ## E0 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 1,0,0,1> E1 ## E0 ## E0 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 1,0,0,2> E1 ## E0 ## E0 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 1,0,0,3> E1 ## E0 ## E0 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 1,0,1,0> E1 ## E0 ## E1 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 1,0,1,1> E1 ## E0 ## E1 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 1,0,1,2> E1 ## E0 ## E1 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 1,0,1,3> E1 ## E0 ## E1 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 1,0,2,0> E1 ## E0 ## E2 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 1,0,2,1> E1 ## E0 ## E2 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 1,0,2,2> E1 ## E0 ## E2 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 1,0,2,3> E1 ## E0 ## E2 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 1,0,3,0> E1 ## E0 ## E3 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 1,0,3,1> E1 ## E0 ## E3 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 1,0,3,2> E1 ## E0 ## E3 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 1,0,3,3> E1 ## E0 ## E3 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 1,1,0,0> E1 ## E1 ## E0 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 1,1,0,1> E1 ## E1 ## E0 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 1,1,0,2> E1 ## E1 ## E0 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 1,1,0,3> E1 ## E1 ## E0 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 1,1,1,0> E1 ## E1 ## E1 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 1,1,1,1> E1 ## E1 ## E1 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 1,1,1,2> E1 ## E1 ## E1 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 1,1,1,3> E1 ## E1 ## E1 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 1,1,2,0> E1 ## E1 ## E2 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 1,1,2,1> E1 ## E1 ## E2 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 1,1,2,2> E1 ## E1 ## E2 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 1,1,2,3> E1 ## E1 ## E2 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 1,1,3,0> E1 ## E1 ## E3 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 1,1,3,1> E1 ## E1 ## E3 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 1,1,3,2> E1 ## E1 ## E3 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 1,1,3,3> E1 ## E1 ## E3 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 1,2,0,0> E1 ## E2 ## E0 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 1,2,0,1> E1 ## E2 ## E0 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 1,2,0,2> E1 ## E2 ## E0 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 1,2,0,3> E1 ## E2 ## E0 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 1,2,1,0> E1 ## E2 ## E1 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 1,2,1,1> E1 ## E2 ## E1 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 1,2,1,2> E1 ## E2 ## E1 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 1,2,1,3> E1 ## E2 ## E1 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 1,2,2,0> E1 ## E2 ## E2 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 1,2,2,1> E1 ## E2 ## E2 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 1,2,2,2> E1 ## E2 ## E2 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 1,2,2,3> E1 ## E2 ## E2 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 1,2,3,0> E1 ## E2 ## E3 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 1,2,3,1> E1 ## E2 ## E3 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 1,2,3,2> E1 ## E2 ## E3 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 1,2,3,3> E1 ## E2 ## E3 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 1,3,0,0> E1 ## E3 ## E0 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 1,3,0,1> E1 ## E3 ## E0 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 1,3,0,2> E1 ## E3 ## E0 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 1,3,0,3> E1 ## E3 ## E0 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 1,3,1,0> E1 ## E3 ## E1 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 1,3,1,1> E1 ## E3 ## E1 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 1,3,1,2> E1 ## E3 ## E1 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 1,3,1,3> E1 ## E3 ## E1 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 1,3,2,0> E1 ## E3 ## E2 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 1,3,2,1> E1 ## E3 ## E2 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 1,3,2,2> E1 ## E3 ## E2 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 1,3,2,3> E1 ## E3 ## E2 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 1,3,3,0> E1 ## E3 ## E3 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 1,3,3,1> E1 ## E3 ## E3 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 1,3,3,2> E1 ## E3 ## E3 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 1,3,3,3> E1 ## E3 ## E3 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 2,0,0,0> E2 ## E0 ## E0 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 2,0,0,1> E2 ## E0 ## E0 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 2,0,0,2> E2 ## E0 ## E0 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 2,0,0,3> E2 ## E0 ## E0 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 2,0,1,0> E2 ## E0 ## E1 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 2,0,1,1> E2 ## E0 ## E1 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 2,0,1,2> E2 ## E0 ## E1 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 2,0,1,3> E2 ## E0 ## E1 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 2,0,2,0> E2 ## E0 ## E2 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 2,0,2,1> E2 ## E0 ## E2 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 2,0,2,2> E2 ## E0 ## E2 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 2,0,2,3> E2 ## E0 ## E2 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 2,0,3,0> E2 ## E0 ## E3 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 2,0,3,1> E2 ## E0 ## E3 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 2,0,3,2> E2 ## E0 ## E3 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 2,0,3,3> E2 ## E0 ## E3 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 2,1,0,0> E2 ## E1 ## E0 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 2,1,0,1> E2 ## E1 ## E0 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 2,1,0,2> E2 ## E1 ## E0 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 2,1,0,3> E2 ## E1 ## E0 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 2,1,1,0> E2 ## E1 ## E1 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 2,1,1,1> E2 ## E1 ## E1 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 2,1,1,2> E2 ## E1 ## E1 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 2,1,1,3> E2 ## E1 ## E1 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 2,1,2,0> E2 ## E1 ## E2 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 2,1,2,1> E2 ## E1 ## E2 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 2,1,2,2> E2 ## E1 ## E2 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 2,1,2,3> E2 ## E1 ## E2 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 2,1,3,0> E2 ## E1 ## E3 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 2,1,3,1> E2 ## E1 ## E3 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 2,1,3,2> E2 ## E1 ## E3 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 2,1,3,3> E2 ## E1 ## E3 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 2,2,0,0> E2 ## E2 ## E0 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 2,2,0,1> E2 ## E2 ## E0 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 2,2,0,2> E2 ## E2 ## E0 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 2,2,0,3> E2 ## E2 ## E0 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 2,2,1,0> E2 ## E2 ## E1 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 2,2,1,1> E2 ## E2 ## E1 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 2,2,1,2> E2 ## E2 ## E1 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 2,2,1,3> E2 ## E2 ## E1 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 2,2,2,0> E2 ## E2 ## E2 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 2,2,2,1> E2 ## E2 ## E2 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 2,2,2,2> E2 ## E2 ## E2 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 2,2,2,3> E2 ## E2 ## E2 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 2,2,3,0> E2 ## E2 ## E3 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 2,2,3,1> E2 ## E2 ## E3 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 2,2,3,2> E2 ## E2 ## E3 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 2,2,3,3> E2 ## E2 ## E3 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 2,3,0,0> E2 ## E3 ## E0 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 2,3,0,1> E2 ## E3 ## E0 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 2,3,0,2> E2 ## E3 ## E0 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 2,3,0,3> E2 ## E3 ## E0 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 2,3,1,0> E2 ## E3 ## E1 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 2,3,1,1> E2 ## E3 ## E1 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 2,3,1,2> E2 ## E3 ## E1 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 2,3,1,3> E2 ## E3 ## E1 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 2,3,2,0> E2 ## E3 ## E2 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 2,3,2,1> E2 ## E3 ## E2 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 2,3,2,2> E2 ## E3 ## E2 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 2,3,2,3> E2 ## E3 ## E2 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 2,3,3,0> E2 ## E3 ## E3 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 2,3,3,1> E2 ## E3 ## E3 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 2,3,3,2> E2 ## E3 ## E3 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 2,3,3,3> E2 ## E3 ## E3 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 3,0,0,0> E3 ## E0 ## E0 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 3,0,0,1> E3 ## E0 ## E0 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 3,0,0,2> E3 ## E0 ## E0 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 3,0,0,3> E3 ## E0 ## E0 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 3,0,1,0> E3 ## E0 ## E1 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 3,0,1,1> E3 ## E0 ## E1 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 3,0,1,2> E3 ## E0 ## E1 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 3,0,1,3> E3 ## E0 ## E1 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 3,0,2,0> E3 ## E0 ## E2 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 3,0,2,1> E3 ## E0 ## E2 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 3,0,2,2> E3 ## E0 ## E2 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 3,0,2,3> E3 ## E0 ## E2 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 3,0,3,0> E3 ## E0 ## E3 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 3,0,3,1> E3 ## E0 ## E3 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 3,0,3,2> E3 ## E0 ## E3 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 3,0,3,3> E3 ## E0 ## E3 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 3,1,0,0> E3 ## E1 ## E0 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 3,1,0,1> E3 ## E1 ## E0 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 3,1,0,2> E3 ## E1 ## E0 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 3,1,0,3> E3 ## E1 ## E0 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 3,1,1,0> E3 ## E1 ## E1 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 3,1,1,1> E3 ## E1 ## E1 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 3,1,1,2> E3 ## E1 ## E1 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 3,1,1,3> E3 ## E1 ## E1 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 3,1,2,0> E3 ## E1 ## E2 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 3,1,2,1> E3 ## E1 ## E2 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 3,1,2,2> E3 ## E1 ## E2 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 3,1,2,3> E3 ## E1 ## E2 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 3,1,3,0> E3 ## E1 ## E3 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 3,1,3,1> E3 ## E1 ## E3 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 3,1,3,2> E3 ## E1 ## E3 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 3,1,3,3> E3 ## E1 ## E3 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 3,2,0,0> E3 ## E2 ## E0 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 3,2,0,1> E3 ## E2 ## E0 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 3,2,0,2> E3 ## E2 ## E0 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 3,2,0,3> E3 ## E2 ## E0 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 3,2,1,0> E3 ## E2 ## E1 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 3,2,1,1> E3 ## E2 ## E1 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 3,2,1,2> E3 ## E2 ## E1 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 3,2,1,3> E3 ## E2 ## E1 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 3,2,2,0> E3 ## E2 ## E2 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 3,2,2,1> E3 ## E2 ## E2 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 3,2,2,2> E3 ## E2 ## E2 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 3,2,2,3> E3 ## E2 ## E2 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 3,2,3,0> E3 ## E2 ## E3 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 3,2,3,1> E3 ## E2 ## E3 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 3,2,3,2> E3 ## E2 ## E3 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 3,2,3,3> E3 ## E2 ## E3 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 3,3,0,0> E3 ## E3 ## E0 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 3,3,0,1> E3 ## E3 ## E0 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 3,3,0,2> E3 ## E3 ## E0 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 3,3,0,3> E3 ## E3 ## E0 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 3,3,1,0> E3 ## E3 ## E1 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 3,3,1,1> E3 ## E3 ## E1 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 3,3,1,2> E3 ## E3 ## E1 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 3,3,1,3> E3 ## E3 ## E1 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 3,3,2,0> E3 ## E3 ## E2 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 3,3,2,1> E3 ## E3 ## E2 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 3,3,2,2> E3 ## E3 ## E2 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 3,3,2,3> E3 ## E3 ## E2 ## E3; }; \
		struct { detail::_swizzle<4, T, Q, 3,3,3,0> E3 ## E3 ## E3 ## E0; }; \
		struct { detail::_swizzle<4, T, Q, 3,3,3,1> E3 ## E3 ## E3 ## E1; }; \
		struct { detail::_swizzle<4, T, Q, 3,3,3,2> E3 ## E3 ## E3 ## E2; }; \
		struct { detail::_swizzle<4, T, Q, 3,3,3,3> E3 ## E3 ## E3 ## E3; };
}
