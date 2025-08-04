#include "qualifier.hpp"
#include "compute_vec_decl.hpp"

namespace cm
{
	namespace detail
	{
		template<length_t L, typename T, qualifier Q, int IsInt, std::size_t Size>
		struct compute_vec_and<L, T, Q, IsInt, Size, true> : public compute_vec_and<L, T, Q, IsInt, Size, false>
		{ };

		template<length_t L, typename T, qualifier Q, int IsInt, std::size_t Size>
		struct compute_vec_or<L, T, Q, IsInt, Size, true> : public compute_vec_or<L, T, Q, IsInt, Size, false>
		{
		};

		template<length_t L, typename T, qualifier Q, int IsInt, std::size_t Size>
		struct compute_vec_xor<L, T, Q, IsInt, Size, true> : public compute_vec_xor<L, T, Q, IsInt, Size, false>
		{
		};

		template<length_t L, typename T, qualifier Q, int IsInt, std::size_t Size>
		struct compute_vec_shift_left<L, T, Q, IsInt, Size, true> : public compute_vec_shift_left<L, T, Q, IsInt, Size, false>
		{
		};

		template<length_t L, typename T, qualifier Q, int IsInt, std::size_t Size>
		struct compute_vec_shift_right<L, T, Q, IsInt, Size, true> : public compute_vec_shift_right<L, T, Q, IsInt, Size, false>
		{
		};

		template<length_t L, typename T, qualifier Q, int IsInt, std::size_t Size>
		struct compute_vec_bitwise_not<L, T, Q, IsInt, Size, true> : public compute_vec_bitwise_not<L, T, Q, IsInt, Size, false>
		{
		};

		template<length_t L, typename T, qualifier Q, int IsInt, std::size_t Size>
		struct compute_vec_equal<L, T, Q, IsInt, Size, true> : public compute_vec_equal<L, T, Q, IsInt, Size, false>
		{
		};

		template<length_t L, typename T, qualifier Q, int IsInt, std::size_t Size>
		struct compute_vec_nequal<L, T, Q, IsInt, Size, true> : public compute_vec_nequal<L, T, Q, IsInt, Size, false>
		{
		};

		template<length_t L, typename T, qualifier Q>
		struct compute_vec_mod<L, T, Q, true> : public compute_vec_mod<L, T, Q, false>
		{};

		template<length_t L, typename T, qualifier Q>
		struct compute_vec_add<L, T, Q, true> : public compute_vec_add<L, T, Q, false>
		{};

		template<length_t L, typename T, qualifier Q>
		struct compute_vec_sub<L, T, Q, true> : public compute_vec_sub<L, T, Q, false>
		{};

		template<length_t L, typename T, qualifier Q>
		struct compute_vec_mul<L, T, Q, true> : public compute_vec_mul<L, T, Q, false>
		{};

		template<length_t L, typename T, qualifier Q>
		struct compute_vec_div<L, T, Q, true> : public compute_vec_div<L, T, Q, false>
		{};

#		if CM_ARCH & CM_ARCH_SSE2_BIT
#			if CM_CONFIG_SWIZZLE == CM_SWIZZLE_OPERATOR

			#endif//CM_ARCH & CM_ARCH_SSE2_BIT
		#endif//CM_CONFIG_SWIZZLE == CM_CONFIG_SWIZZLE_OPERATOR

	}
}