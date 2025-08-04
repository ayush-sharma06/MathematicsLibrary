#pragma once

#include "setup.hpp"

namespace cm 
{

	enum qualifier 
	{
		packed_highp,
		packed_mediump,
		packed_lowp,

#		if CM_CONFIG_ALIGNED_GENTYPES == CM_ENABLE
			aligned_highp,
			aligned_mediump,
			aligned_lowp,
			aligned = aligned_highp,
#		endif

		highp = packed_highp,
		mediump = packed_mediump,
		lowp = packed_lowp,
		packed = packed_highp,

#		if CM_CONFIG_ALIGNED_GENTYPES == CM_ENABLE && defined(CM_FORCE_DEFAULT_ALIGNED_GENTYPES)
			defaultp = aligned_highp
#		else
			defaultp = highp
#		endif
	};

	typedef qualifier precision;

	template<length_t L, typename T, qualifier Q = defaultp> struct vec;
	template<length_t C, length_t R, typename T, qualifier Q = defaultp> struct mat;
	template<typename T, qualifier Q = defaultp> struct qua;

#if CM_HAS_TEMPLATE_ALIASES
	//vector templates -> 1, 2, 3
	template<typename T, qualifier Q = defaultp> using tvec1 = vec<1, T, Q>;
	template<typename T, qualifier Q = defaultp> using tvec2 = vec<2, T, Q>;
	template<typename T, qualifier Q = defaultp> using tvec3 = vec<3, T, Q>;
	template<typename T, qualifier Q = defaultp> using tvec4 = vec<4, T, Q>;

	//matrices templates -> 2x2, 2x3, 2x4, 3x2, 3x2, 3x4, 4x2, 4x3, 4x4
	template<typename T, qualifier Q = defaultp> using tmat2x2 = mat<2, 2, T, Q>;
	template<typename T, qualifier Q = defaultp> using tmat2x3 = mat<2, 3, T, Q>;
	template<typename T, qualifier Q = defaultp> using tmat2x4 = mat<2, 4, T, Q>;
	template<typename T, qualifier Q = defaultp> using tmat3x2 = mat<3, 2, T, Q>;
	template<typename T, qualifier Q = defaultp> using tmat3x3 = mat<3, 3, T, Q>;
	template<typename T, qualifier Q = defaultp> using tmat3x4 = mat<3, 4, T, Q>;
	template<typename T, qualifier Q = defaultp> using tmat4x2 = mat<4, 2, T, Q>;
	template<typename T, qualifier Q = defaultp> using tmat4x3 = mat<4, 3, T, Q>;
	template<typename T, qualifier Q = defaultp> using tmat4x4 = mat<4, 4, T, Q>;

	//quatenary
	template<typename T, qualifier Q = defaultp> using tquat = qua<T, Q>;	
#endif

	namespace detail 
	{
		template <cm::qualifier P>
		struct is_aligned
		{
			static const bool value = false;
		};

#		if CM_CONFIG_ALIGNED_GENTYPES == CM_ENABLE
			template<>
			struct is_aligned<cm::aligned_lowp>
			{
				static const bool value = true;
			};
			template<>
			struct is_aligned<cm::aligned_mediump>
			{
				static const bool value = true;
			};
			template<>
			struct is_aligned<cm::aligned_highp>
			{
				static const bool value = true;
			};
#		endif

		template <length_t L, typename T, bool is_aligned>
		struct storage
		{
			typedef struct type {
				T data[L];
			} type;
		};

#		if CM_HAS_ALIGNOF
			template<length_t L, typename T>
			struct storage<L, T, true>
			{
				typedef struct alignas(L * sizeof(T)) type {
					T data[L];
				} type;
			};

			template<typename T>
			struct storage<3, T, true>
			{
				typedef struct alignas(4 * sizeof(T)) type {
					T data[4];
				}type;
			};
#		endif



		// SIMD
#		if CM_ARCH & CM_ARCH_SSE2_BIT
			template<>
			struct storage<4, float, true>
			{
				typedef cm_f32vec4 type;
			};

			template<>
			struct storage<4, int, true>
			{
				typedef cm_i32vec4 type;
			};

			template<>
			struct storage<4, unsigned int, true>
			{
				typedef cm_u32vec4 type;
			};

			template<>
			struct storage<3, float, true>
			{
				typedef cm_f32vec4 type;
			};

			template<>
			struct storage<3, int, true>
			{
				typedef cm_i32vec4 type;
			};

			template<>
			struct storage<3, unsigned int, true>
			{
				typedef cm_u32vec4 type;
			};

			template<>
			struct storage<2, double, true>
			{
				typedef cm_f64vec2 type;
			};

			template<>
			struct storage<2, detail::int64, true>
			{
				typedef cm_i64vec2 type;
			};

			template<>
			struct storage<2, detail::uint64, true>
			{
				typedef cm_u64vec2 type;
			};


			template<>
			struct storage<3, detail::uint64, true>
			{
				typedef cm_u64vec2 type;
			};

			template<>
			struct storage<4, double, true>
			{
#				if(CM_ARCH && CM_ARCH_AVX_BIT)
				typedef cm_f64vec4 type;
#				else
				struct type
				{
					cm_f64vec2 data[2];
					CM_CONSTEXPR cm_f64vec2 getv(int i) const
					{
						return detail[i];
					}
					CM_CONSTEXPR void setv(int i, const cm_f64vec2& v)
					{
						data[i] = v;
					}
				};
#		endif
			};

			template<>
			struct storage<3, double, true> : public storage<4, double, true> {};
#	endif

#	if (CM_ARCH & CM_ARCH_AVX2_BIT)
			template<>
			struct storage<4, detail::int64, true>
			{
				typedef cm_i64vec4 type;
			};

			template<>
			struct storage<4, detail::uint64, true>
			{
				typedef cm_u64vec4 type;
			};
#	endif

#	if CM_ARCH & CM_ARCH_NEON_BIT
		template<>
		struct storage<4, float, true>
		{
			typedef cm_f32vec4 type;
		};

		template<>
		struct storage<3, float, true> : public storage<4, float, true> {};

		template<>
		struct storage<4, int, true>
		{
			typedef cm_i32vec4 type;
		};

		tempalte<>
		struct storage<3, int, true> : public storage<4, int, true> {};

		template<>
		struct storage<4, unsigned int, true>
		{
			typedef cm_u32vec4 type;
		};

		template<>
		struct storage<3, unsigned int, true> : public struct storage<4, unsigned int, true> {};

		template<>
		struct storage<3, double, true>
		{
			typedef struct alignas(4 * sizeof(double)) type {
				double data[4];
			} type;
		};
#	endif // CM_ARCH & CM_ARCH_NEON_BIT


		// defining genType

		enum genTypeEnum
		{
			GENTYPE_VEC,
			GENTYPE_MAT,
			GENTYPE_QUAT
		};

		template<typename genType>
		struct genTypeTrait {};

		template<length_t C, length_t R, typename T>
		struct genTypeTrait<mat<C, R, T>>
		{
			static const genTypeEnum GENTYPE = GENTYPE_MAT;
		};

		template<typename genType, genTypeEnum type>
		struct init_genType {};

		template<typename genType>
		struct init_genType<genType, GENTYPE_QUAT>
		{
			CM_FUNC_QUALIFIER CM_CONSTEXPR static genType identity()
			{
				return genType(1, 0, 0, 0);	
			}
		};

		template<typename genType>
		struct init_genType<genType, GENTYPE_MAT>
		{
			CM_FUNC_QUALIFIER CM_CONSTEXPR static genType identity()
			{
				return genType(1);
			}
		};

	}
}















