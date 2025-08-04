#pragma once

#include "qualifier.hpp"

namespace cm
{
	namespace detail
	{
		template<template<length_t L, typename T, qualifier Q> class vec, length_t L, typename R, typename T, qualifier Q>
		struct functor1 {};

		template<template<length_t L, typename T, qualifier Q> class vec, typename R, typename T, qualifier Q>
		struct functor1<vec, 1, R, T, Q>
		{
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<1, R, Q> call(R(*Func) (T x), vec<1, T, Q> const& v)
			{
				return vec<1, R, Q>(Func(v.x));
			}
		};

		template<template<length_t L, typename T, qualifier Q> class vec, typename R, typename T, qualifier Q>
		struct functor1<vec, 2, R, T, Q>
		{
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<2, R, Q> call(R(*Func) (T x), vec<2, T, Q> const& v)
			{
				return vec<2, R, Q>(Func(v.x), Func(v.y));
			}
		};

		template<template<length_t L, typename T, qualifier Q> class vec, typename R, typename T, qualifier Q>
		struct functor1<vec, 3, R, T, Q>
		{
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<3, R, Q> call(R(*Func) (T x), vec<3, T, Q> const& v)
			{
				return vec<3, R, Q>(Func(v.x), Func(v.y), Func(v.z));
			}
		};

		template<template<length_t L, typename T, qualifier Q> class vec, typename R, typename T, qualifier Q>
		struct functor1<vec, 4, R, T, Q>
		{
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<4, R, Q> call(R(*Func) (T x), vec<4, T, Q> const& v)
			{
				return vec<1, R, Q>(Func(v.x), Func(v.y), Func(v.z), Func(v.w));
			}
		};


		template<template<length_t L, typename T, qualifier Q> class vec, length_t L, typename T, qualifier Q>
		struct functor2 {};

		template<template<length_t L, typename T, qualifier Q> class vec, typename T, qualifier Q>
		struct functor2<vec, 1, T, Q>
		{
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<1, T, Q> call(T(*Func) (T x), vec<1, T, Q> const& u, vec<1, T, Q> const& v)
			{
				return vec<1, T, Q>(Func(u.x, v.x));
			}

			template<typename Fct>
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<1, T, Q> call(Fct Func, vec<1, T, Q> const& u, vec<1, T, Q> const& v)
			{
				return vec<1, T, Q>(Func(u.x, v.x));
			}
		};

		template<template<length_t L, typename T, qualifier Q> class vec, typename T, qualifier Q>
		struct functor2<vec, 2, T, Q>
		{
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<2, T, Q> call(T(*Func) (T x), vec<2, T, Q> const& u, vec<2, T, Q> const& v)
			{
				return vec<2, T, Q>(Func(u.x, v.x), Func(u.y, v.y));
			}

			template<typename Fct>
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<2, T, Q> call(Fct Func, vec<2, T, Q> const& u, vec<2, T, Q> const& v)
			{
				return vec<2, T, Q>(Func(u.x, v.x), Func(u.y, v.y));
			}
		};

		template<template<length_t L, typename T, qualifier Q> class vec, typename T, qualifier Q>
		struct functor2<vec, 3, T, Q>
		{
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<3, T, Q> call(T(*Func) (T x), vec<3, T, Q> const& u, vec<3, T, Q> const& v)
			{
				return vec<3, T, Q>(Func(u.x, v.x), Func(u.y, v.y), Func(u.z, v.z));
			}

			template<typename Fct>
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<3, T, Q> call(Fct Func, vec<3, T, Q> const& u, vec<3, T, Q> const& v)
			{
				return vec<3, T, Q>(Func(u.x, v.x), Func(u.y, v.y), Func(u.z, v.z));
			}
		};

		template<template<length_t L, typename T, qualifier Q> class vec, typename T, qualifier Q>
		struct functor2<vec, 4, T, Q>
		{
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<4, T, Q> call(T(*Func) (T x), vec<4, T, Q> const& u, vec<4, T, Q> const& v)
			{
				return vec<4, T, Q>(Func(u.x, v.x), Func(u.y, v.y), Func(u.z, v.z), Func(u.w, v.w));
			}

			template<typename Fct>
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<4, T, Q> call(Fct Func, vec<4, T, Q> const& u, vec<4, T, Q> const& v)
			{
				return vec<4, T, Q>(Func(u.x, v.x), Func(u.y, v.y), Func(u.z, v.z), Func(u.w, v.w));
			}
		};


		template<template<length_t L, typename T, qualifier Q> class vec, length_t L, typename T, qualifier Q>
		struct functor2_vec_scalar {};

		template<template<length_t L, typename T, qualifier Q> class vec, typename T, qualifier Q>
		struct functor2_vec_scalar<vec, 1, T, Q>
		{
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<1, T, Q> call(T(*Func) (T x), vec<1, T, Q> const& u, T v)
			{
				return vec<1, T, Q>(Func(u.x, v));
			}

			template<typename Fct>
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<1, T, Q> call(Fct Func, vec<1, T, Q> const& u, T v)
			{
				return vec<1, T, Q>(Func(u.x, v));
			}
		};

		template<template<length_t L, typename T, qualifier Q> class vec, typename T, qualifier Q>
		struct functor2_vec_scalar<vec, 2, T, Q>
		{
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<2, T, Q> call(int(*Func) (T x), vec<2, T, Q> const& u, T v)
			{
				return vec<2, T, Q>(Func(u.x, v), Func(u.y, v));
			}

			template<typename Fct>
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<2, T, Q> call(Fct Func, vec<2, T, Q> const& u, T v)
			{
				return vec<2, T, Q>(Func(u.x, v), Func(u.y, v));
			}
		};

		template<template<length_t L, typename T, qualifier Q> class vec, typename T, qualifier Q>
		struct functor2_vec_scalar<vec, 3, T, Q>
		{
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<3, T, Q> call(int(*Func) (T x), vec<3, T, Q> const& u, T v)
			{
				return vec<3, T, Q>(Func(u.x, v), Func(u.y, v), Func(u.z, v));
			}

			template<typename Fct>
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<3, T, Q> call(Fct Func, vec<3, T, Q> const& u, T v)
			{
				return vec<3, T, Q>(Func(u.x, v), Func(u.y, v), Func(u.z, v));
			}
		};

		template<template<length_t L, typename T, qualifier Q> class vec, typename T, qualifier Q>
		struct functor2_vec_scalar<vec, 4, T, Q>
		{
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<4, T, Q> call(int(*Func) (T x), vec<4, T, Q> const& u, T v)
			{
				return vec<4, T, Q>(Func(u.x, v), Func(u.y, v), Func(u.z, v), Func(u.w, v));
			}

			template<typename Fct>
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<4, T, Q> call(Fct Func, vec<4, T, Q> const& u, T v)
			{
				return vec<4, T, Q>(Func(u.x, v), Func(u.y, v), Func(u.z, v), Func(u.w, v));
			}
		};


		template<length_t L, typename T, qualifier Q>
		struct functor2_vec_int {};

		template<typename T, qualifier Q>
		struct functor2_vec_int<1, T, Q>
		{
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<1, T, Q> call(int(*Func) (T x), vec<1, T, Q> const& u, vec<1, int, Q> const& v)
			{
				return vec<1, int, Q>(Func(u.x, v.x));
			}

			template<typename Fct>
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<1, T, Q> call(Fct Func, vec<1, T, Q> const& u, vec<1, int, Q> const& v)
			{
				return vec<1, int, Q>(Func(u.x, v.x));
			}
		};

		template<typename T, qualifier Q>
		struct functor2_vec_int<2, T, Q>
		{
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<2, T, Q> call(int(*Func) (T x), vec<2, T, Q> const& u, vec<2, int, Q> const& v)
			{
				return vec<2, int, Q>(Func(u.x, v.x), Func(u.y, v.y));
			}

			template<typename Fct>
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<2, T, Q> call(Fct Func, vec<2, T, Q> const& u, vec<2, int, Q> const& v)
			{
				return vec<2, int, Q>(Func(u.x, v.x), Func(u.y, v.y));
			}
		};

		template<typename T, qualifier Q>
		struct functor2_vec_int<3, T, Q>
		{
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<3, T, Q> call(int(*Func) (T x), vec<3, T, Q> const& u, vec<3, int, Q> const& v)
			{
				return vec<3, int, Q>(Func(u.x, v.x), Func(u.y, v.y), Func(u.z, v.z));
			}

			template<typename Fct>
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<3, T, Q> call(Fct Func, vec<3, T, Q> const& u, vec<3, int, Q> const& v)
			{
				return vec<3, int, Q>(Func(u.x, v.x), Func(u.y, v.y), Func(u.z, v.z));
			}
		};

		template<typename T, qualifier Q>
		struct functor2_vec_int<4, T, Q>
		{
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<4, T, Q> call(int(*Func) (T x), vec<4, T, Q> const& u, vec<4, int, Q> const& v)
			{
				return vec<4, int, Q>(Func(u.x, v.x), Func(u.y, v.y), Func(u.z, v.z), Func(u.w, v.w));
			}

			template<typename Fct>
			CM_FUNC_QUALIFIER CM_CONSTEXPR static vec<4, T, Q> call(Fct Func, vec<4, T, Q> const& u, vec<4, int, Q> const& v)
			{
				return vec<4, int, Q>(Func(u.x, v.x), Func(u.y, v.y), Func(u.z, v.z), Func(u.w, v.w));
			}
		};
	}
}