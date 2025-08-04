#pragma once


#include<cassert>
#include<cstddef>

#define STRINGIFY(x) #x
#define TOSTRING(x) STRINGIFY(x)

#if CM_MESSAGES
#define CM_LOG_MESSAGE(m) _Pragma(STRINGIFY(message(m)))
#define CM_LOG_MACRO_VALUE(name) _Pragma(TOSTRING(message(#name " = " TOSTRING(name))))
#else
#define CM_LOG_MESSAGE(m)
#define CM_LOG_MACRO_VALUE(name)
#endif

#define CM_ENABLE 1
CM_LOG_MACRO_VALUE(CM_ENABLE)
#define CM_DISABLE 0
CM_LOG_MACRO_VALUE(CM_DISABLE)

#if defined(CM_FORCE_MESSAGE)
#		define CM_MESSAGES CM_ENABLE
#else
#		define CM_MESSAGES CM_DISABLE
#endif
CM_LOG_MESSAGE("Use CM_FORCE_MESSAGE to define CM_MESSAGES")
CM_LOG_MACRO_VALUE(CM_MESSAGES)


#define CM_VERSION_MAJOR 1
CM_LOG_MACRO_VALUE(CM_VERSION_MAJOR)
#define CM_VERSION_MINOR 0
CM_LOG_MACRO_VALUE(CM_VERSION_MINOR)
#define CM_VERSION_PATCH 0
CM_LOG_MACRO_VALUE(CM_VERSION_PATCH)
#define CM_VERSION_REVISION 0 // deprecated
CM_LOG_MACRO_VALUE(CM_VERSION_REVISION)
CM_LOG_MESSAGE("CM_VERSION_REVISION has been deprecated")
#define CM_VERSION 1000 //deprecated
CM_LOG_MACRO_VALUE(CM_VERSION)
CM_LOG_MESSAGE("CM_VERSION has been deprecated")
#define CM_VERSION_MESSAGE "CM: version 1.0.0"
CM_LOG_MACRO_VALUE(CM_VERSION_MESSAGE)

#define CM_MAKE_API_VERSION(variant, major, minor, patch) \
	((((uint32_t)(variant)) << 29U) | (((uint32_t)(major)) << 22U) | (((uint32_t)(minor)) << 12U) | ((uint32_t)(patch)))
CM_LOG_MESSAGE("CM_MAKE_API_VERSION(variant, major, minor, patch) defined")

#define CM__VERSION_COMPLETE CM_MAKE_API_VERSION(0, CM_VERSION_MAJOR, CM_VERSION_MINOR, CM_VERSION_PATCH)
CM_LOG_MACRO_VALUE(CM__VERSION_COMPLETE)

#define CM_SETUP_INCLUDED CM_VERSION
CM_LOG_MACRO_VALUE(CM_SETUP_INCLUDED)

#define CM_GET_VERSION_VARIANT(version) ((uint32_t)(version) >> 29U)
CM_LOG_MESSAGE("CM_GET_VERSION_VARIANT(version) defined")
#define CM_GET_VERSION_MAJOR(version)  (((uint32_t)(version) >> 22U) & 0x7FU)
CM_LOG_MESSAGE("CM_GET_VERSION_MAJOR(version) defined")
#define CM_GET_VERSION_MINOR(version)  (((uint32_t)(version) >> 12U) & 0x3FFU)
CM_LOG_MESSAGE("CM_GET_VERSION_MINOR(version) defined")
#define CM_GET_VERSION_PATCH(version)  (((uint32_t)(version)) & 0xFFFU)
CM_LOG_MESSAGE("CM_GET_VERSION_PATCH(version) defined")


#include "../SIMD/platform.hpp"
CM_LOG_MESSAGE("platform.hpp included")

#if defined(_M_ARM64) || defined(__LP64__) || defined(_M_X64) || defined(__ppc64__) || defined(__x86_64__)
#		define CM_MODEL CM_MODEL_64
#elif defined(__i386__) || defined(__ppc__) || defined(__ILP32__) || defined(_M_ARM)
#		define CM_MODEL CM_MODEL_32
#else
#		define CM_MODEL CM_MODEL_32
#endif
CM_LOG_MACRO_VALUE(CM_MODEL)

// User defines: CM_FORCE_CXX98, CM_FORCE_CXX03, CM_FORCE_CXX11, CM_FORCE_CXX14, CM_FORCE_CXX17, CM_FORCE_CXX20
#define CM_LANG_CXX98_FLAG			(1 << 1)
CM_LOG_MACRO_VALUE(CM_LANG_CXX98_FLAG)
#define CM_LANG_CXX03_FLAG			(1 << 2)
CM_LOG_MACRO_VALUE(CM_LANG_CXX03_FLAG)
#define CM_LANG_CXX0X_FLAG			(1 << 3)
CM_LOG_MACRO_VALUE(CM_LANG_CXX0X_FLAG)
#define CM_LANG_CXX11_FLAG			(1 << 4)
CM_LOG_MACRO_VALUE(CM_LANG_CXX11_FLAG)
#define CM_LANG_CXX14_FLAG			(1 << 5)
CM_LOG_MACRO_VALUE(CM_LANG_CXX14_FLAG)
#define CM_LANG_CXX17_FLAG			(1 << 6)
CM_LOG_MACRO_VALUE(CM_LANG_CXX17_FLAG)
#define CM_LANG_CXX20_FLAG			(1 << 7)
CM_LOG_MACRO_VALUE(CM_LANG_CXX20_FLAG)
#define CM_LANG_CXXMS_FLAG			(1 << 8)
CM_LOG_MACRO_VALUE(CM_LANG_CXXMS_FLAG)
#define CM_LANG_CXXGNU_FLAG			(1 << 9)
CM_LOG_MACRO_VALUE(CM_LANG_CXXGNU_FLAG)

#define CM_LANG_CXX98			CM_LANG_CXX98_FLAG
CM_LOG_MACRO_VALUE(CM_LANG_CXX98)
#define CM_LANG_CXX03			(CM_LANG_CXX98 | CM_LANG_CXX03_FLAG)
CM_LOG_MACRO_VALUE(CM_LANG_CXX03)
#define CM_LANG_CXX0X			(CM_LANG_CXX03 | CM_LANG_CXX0X_FLAG)
CM_LOG_MACRO_VALUE(CM_LANG_CXX0X)
#define CM_LANG_CXX11			(CM_LANG_CXX0X | CM_LANG_CXX11_FLAG)
CM_LOG_MACRO_VALUE(CM_LANG_CXX11)
#define CM_LANG_CXX14			(CM_LANG_CXX11 | CM_LANG_CXX14_FLAG)
CM_LOG_MACRO_VALUE(CM_LANG_CXX14)
#define CM_LANG_CXX17			(CM_LANG_CXX14 | CM_LANG_CXX17_FLAG)
CM_LOG_MACRO_VALUE(CM_LANG_CXX17)
#define CM_LANG_CXX20			(CM_LANG_CXX17 | CM_LANG_CXX20_FLAG)
CM_LOG_MACRO_VALUE(CM_LANG_CXX20)
#define CM_LANG_CXXMS			CM_LANG_CXXMS_FLAG
CM_LOG_MACRO_VALUE(CM_LANG_CXXMS)
#define CM_LANG_CXXGNU			CM_LANG_CXXGNU_FLAG
CM_LOG_MACRO_VALUE(CM_LANG_CXXGNU)

#if (defined(__MSC_EXTENSIONS))
#		define CM_LANG_EXT CM_LANG_CXXMS_FLAG
#elif ((CM_COMPILER & (CM_COMPILER_GCC | CM_COMPILER_CLANG)) && (CM_ARCH & CM_ARCH_SIMD_BIT))
#		define CM_LANG_EXT CM_LANG_CXXMS_FLAG
#else
#		define CM_LANG_EXT 0
#endif
CM_LOG_MACRO_VALUE(CM_LANG_EXT)


#if (defined(CM_FORCE_CXX_UNKNOWN))
#		define CM_LANG 0
#elif defined(CM_FORCE_CXX20)
#		define CM_LANG (CM_LANG_EXT | CM_LANG_CXX20)
#		define CM_LANG_STL11_FORCED
#elif defined(CM_FORCE_CXX17)
#		define CM_LANG (CM_LANG_EXT | CM_LANG_CXX17)
#		define CM_LANG_STL11_FORCED
#elif defined(CM_FORCE_CXX14)
#		define CM_LANG (CM_LANG_EXT | CM_LANG_CXX14)
#		define CM_LANG_STL11_FORCED
#elif defined(CM_FORCE_CXX11)
#		define CM_LANG (CM_LANG_EXT | CM_LANG_CXX11)
#		define CM_LANG_STL11_FORCED
#elif defined(CM_FORCE_CXX03)
#		define CM_LANG (CM_LANG_EXT | CM_LANG_CXX03)
#elif defined(CM_FORCE_CXX98)
#		define CM_LANG (CM_LANG_EXT | CM_LANG_CXX98)
#else
#	if CM_COMPILER & CM_COMPILER_VC && defined(_MSVC_LANG)
#		if CM_COMPILER >= CM_COMPILER_VC15_7
#			define CM_LANG_PLATFORM _MSVC_LANG
#		elif CM_COMPILER >= CM_COMPILER_VC15
#			if _MSVC_LANG > 201402L
#				define CM_LANG_PLATFORM 201402L
#			else
#				define CM_LANG_PLATFORM _MSVC_LANG
#			endif
#		else
#			define CM_LANG_PLATFORM 0
#		endif
#	else
#		define CM_LANG_PLATFORM 0
#	endif
CM_LOG_MACRO_VALUE(CM_LANG_PLATFORM)
#	if __cplusplus > 201703L || CM_LANG_PLATFORM > 201703L
#		define CM_LANG (CM_LANG_EXT | CM_LANG_CXX20)
#	elif __cplusplus == 201703L || CM_LANG_PLATFORM == 201703L
#		define CM_LANG (CM_LANG_EXT | CM_LANG_CXX17)
#	elif __cplusplus == 201402L || __cplusplus == 201406L || __cplusplus == 201500L || CM_LANG_PLATFORM == 201402L
#		define CM_LANG (CM_LANG_EXT | CM_LANG_CXX14)
#	elif __cplusplus == 201103L || CM_LANG_PLATFORM == 201103L
#		define CM_LANG (CM_LANG_EXT | CM_LANG_CXX11)
#	elif defined(__INTEL_CXX11_MODE__) || defined(_MSC_VER) || defined(__CXX_EXPERIMENTAL_CXX0X__)
#		define CM_LANG (CM_LANG_EXT | CM_LANG_CXX0X)
#	elif __cplusplus == 199711L
#		define CM_LANG (CM_LANG_CXX98 | CM_LANG_EXT)
#	else
#		define CM_LANG (0 | CM_LANG_EXT)
#	endif
#endif
CM_LOG_MESSAGE("Use CM_FORCE_CXX_UNKNOWN, CM_FORCE_CXX20, CM_FORCE_CXX17, CM_FORCE_CXX14, CM_FORCE_CXX11, CM_FORCE_CXX03, CM_FORCE_CXX98 to define CM_LANG")
CM_LOG_MACRO_VALUE(CM_LANG)


#if CM_PLATFORM == CM_PLATFORM_ANDROID && !defined(CXX_LANG_STL11_FORCED)
#	define CM_HAS_STL11 0
#elif (CM_COMPILER & CM_COMPILER_CUDA_RTC) == CM_COMPILER_CUDA_RTC
#	define CM_HAS_STL11 0
#elif (CM_COMPILER & CM_COMPILER_HIP)
#	define CM_HAS_STL11 0
#elif (CM_COMPILER & CM_COMPILER_HIP)
#	if (defined(_LIBCPP_VERSION) || (CM_LANG & CM_LANG_CXX11_FLAG) || defined(CM_LANG_STL11_FORCED))
#		define CM_HAS_STL11 1
#	else
#		define CM_HAS_STL11 0
#	endif
#elif CM_LANG & CM_LANG_CXX11_FLAG
#	define CM_HAS_STL11 1
#else
#	define CM_HAS_STL11 ((CM_LANG & CM_LANG_CXX0X_FLAG)	&& (\
						((CM_COMPILER & CM_COMPILER_GCC) && (CM_COMPILER >= CM_COMPILER_GCC48)) || \
						((CM_COMPILER & CM_COMPILER_VC) && (CM_COMPILER >= CM_COMPILER_VC12)) || \
						((CM_PLATFORM != CM_PLATFORM_WINDOWS) && (CM_COMPILER & CM_COMPILER_INTEL) && (CM_COMPILER >= CM_COMPILER_INTEL15))))
#endif // CM_PLATFORM == CM_PLATFORM_ANDROID && !defined(CXX_LANG_STL11_FORCED)
CM_LOG_MESSAGE("Use CM_FORCED_STL11 to define CM_HAS_STL")
CM_LOG_MACRO_VALUE(CM_HAS_STL)


// N1720
#if CM_COMPILER & CM_COMPILER_CLANG
#	define CM_HAS_STATIC_ASSERT __has_feature(cxx_static_assert)
#elif CM_LANG & CM_LANG_CXX11_FLAG
#	define CM_HAS_STATIC_ASSERT 1
#else
#	define CM_HAS_STATIC_ASSERT ((CM_LANG & CM_LANG_CXX0X_FLAG) && (\
		((CM_COMPILER & CM_COMPILER_CUDA)) || \
		((CM_COMPILER & CM_COMPILER_VC)) || \
		((CM_COMPILER & CM_COMPILER_HIP))))
#endif
CM_LOG_MACRO_VALUE(CM_HAS_STATIC_ASSERT)

// N2672 Initializer lists http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2672.htm
#if CM_COMPILER & CM_COMPILER_CLANG
#	define CM_HAS_INITIALIZER_LISTS __has_feature(cxx_generalized_initializers)
#elif CM_LANG & CM_LANG_CXX11_FLAG
#	define CM_HAS_INITIALIZER_LISTS 1
#else
#	define CM_HAS_INITIALIZER_LISTS ((CM_LANG & CM_LANG_CXX0X_FLAG) && (\
		((CM_COMPILER & CM_COMPILER_VC) && (CM_COMPILER >= CM_COMPILER_VC15)) || \
		((CM_COMPILER & CM_COMPILER_INTEL) && (CM_COMPILER >= CM_COMPILER_INTEL14)) || \
		((CM_COMPILER & CM_COMPILER_CUDA)) || \
		((CM_COMPILER & CM_COMPILER_HIP))))
#endif
CM_LOG_MACRO_VALUE(CM_HAS_INITIALIZER_LISTS)

// N2544 Unrestricted unions http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2008/n2544.pdf
#if CM_COMPILER & CM_COMPILER_CLANG
#	define CM_HAS_UNRESTRICTED_UNIONS __has_feature(cxx_unrestricted_unions)
#elif CM_LANG & CM_LANG_CXX11_FLAG
#	define CM_HAS_UNRESTRICTED_UNIONS 1
#else
#	define CM_HAS_UNRESTRICTED_UNIONS (CM_LANG & CM_LANG_CXX0X_FLAG) && (\
		(CM_COMPILER & CM_COMPILER_VC) || \
		((CM_COMPILER & CM_COMPILER_CUDA)) || \
		((CM_COMPILER & CM_COMPILER_HIP)))
#endif
CM_LOG_MACRO_VALUE(CM_HAS_UNRESTRICTED_UNIONS)

// N2346
#if CM_COMPILER & CM_COMPILER_CLANG
#	define CM_HAS_DEFAULTED_FUNCTIONS __has_feature(cxx_defaulted_functions)
#elif CM_LANG & CM_LANG_CXX11_FLAG
#	define CM_HAS_DEFAULTED_FUNCTIONS 1
#else
#	define CM_HAS_DEFAULTED_FUNCTIONS ((CM_LANG & CM_LANG_CXX0X_FLAG) && (\
		((CM_COMPILER & CM_COMPILER_VC) && (CM_COMPILER >= CM_COMPILER_VC12)) || \
		((CM_COMPILER & CM_COMPILER_INTEL)) || \
		(CM_COMPILER & CM_COMPILER_CUDA)) || \
		((CM_COMPILER & CM_COMPILER_HIP)))
#endif
CM_LOG_MACRO_VALUE(CM_HAS_DEFAULTED_FUNCTIONS)

// N2118
#if CM_COMPILER & CM_COMPILER_CLANG
#	define CM_HAS_RVALUE_REFERENCES __has_feature(cxx_rvalue_references)
#elif CM_LANG & CM_LANG_CXX11_FLAG
#	define CM_HAS_RVALUE_REFERENCES 1
#else
#	define CM_HAS_RVALUE_REFERENCES ((CM_LANG & CM_LANG_CXX0X_FLAG) && (\
		((CM_COMPILER & CM_COMPILER_VC)) || \
		((CM_COMPILER & CM_COMPILER_CUDA)) || \
		((CM_COMPILER & CM_COMPILER_HIP))))
#endif
CM_LOG_MACRO_VALUE(CM_HAS_RVALUE_REFERENCES)

// N2437 http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2437.pdf
#if CM_COMPILER & CM_COMPILER_CLANG
#	define CM_HAS_EXPLICIT_CONVERSION_OPERATORS __has_feature(cxx_explicit_conversions)
#elif CM_LANG & CM_LANG_CXX11_FLAG
#	define CM_HAS_EXPLICIT_CONVERSION_OPERATORS 1
#else
#	define CM_HAS_EXPLICIT_CONVERSION_OPERATORS ((CM_LANG & CM_LANG_CXX0X_FLAG) && (\
		((CM_COMPILER & CM_COMPILER_INTEL) && (CM_COMPILER >= CM_COMPILER_INTEL14)) || \
		((CM_COMPILER & CM_COMPILER_VC) && (CM_COMPILER >= CM_COMPILER_VC12)) || \
		((CM_COMPILER & CM_COMPILER_CUDA)) || \
		((CM_COMPILER & CM_COMPILER_HIP))))
#endif
CM_LOG_MACRO_VALUE(CM_HAS_EXPLICIT_CONVERSION_OPERATORS)

// N2258 http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2258.pdf
#if CM_COMPILER & CM_COMPILER_CLANG
#	define CM_HAS_TEMPLATE_ALIASES __has_feature(cxx_alias_templates)
#elif CM_LANG & CM_LANG_CXX11_FLAG
#	define CM_HAS_TEMPLATE_ALIASES 1
#else
#	define CM_HAS_TEMPLATE_ALIASES ((CM_LANG & CM_LANG_CXX0X_FLAG) && (\
		((CM_COMPILER & CM_COMPILER_INTEL)) || \
		((CM_COMPILER & CM_COMPILER_VC) && (CM_COMPILER >= CM_COMPILER_VC12)) || \
		((CM_COMPILER & CM_COMPILER_CUDA)) || \
		((CM_COMPILER & CM_COMPILER_HIP))))
#endif
CM_LOG_MACRO_VALUE(CM_HAS_TEMPLATE_ALIASES)

// N2930 http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2009/n2930.html
#if CM_COMPILER & CM_COMPILER_CLANG
#	define CM_HAS_RANGE_FOR __has_feature(cxx_range_for)
#elif CM_LANG & CM_LANG_CXX11_FLAG
#	define CM_HAS_RANGE_FOR 1
#else
#	define CM_HAS_RANGE_FOR ((CM_LANG & CM_LANG_CXX0X_FLAG) && (\
		((CM_COMPILER & CM_COMPILER_INTEL)) || \
		((CM_COMPILER & CM_COMPILER_VC)) || \
		((CM_COMPILER & CM_COMPILER_CUDA)) || \
		((CM_COMPILER & CM_COMPILER_HIP))))
#endif
CM_LOG_MACRO_VALUE(CM_HAS_RANGE_FOR)

// N2341 http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2341.pdf
#if CM_COMPILER & CM_COMPILER_CLANG
#	define CM_HAS_ALIGNOF __has_feature(cxx_alignas)
#elif CM_LANG & CM_LANG_CXX11_FLAG
#	define CM_HAS_ALIGNOF 1
#else
#	define CM_HAS_ALIGNOF ((CM_LANG & CM_LANG_CXX0X_FLAG) && (\
		((CM_COMPILER & CM_COMPILER_INTEL) && (CM_COMPILER >= CM_COMPILER_INTEL15)) || \
		((CM_COMPILER & CM_COMPILER_VC) && (CM_COMPILER >= CM_COMPILER_VC14)) || \
		((CM_COMPILER & CM_COMPILER_CUDA)) || \
		((CM_COMPILER & CM_COMPILER_HIP))))
#endif
CM_LOG_MACRO_VALUE(CM_HAS_ALIGNOF)

// N2235 Generalized Constant Expressions http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2007/n2235.pdf
// N3652 Extended Constant Expressions http://www.open-std.org/jtc1/sc22/wg21/docs/papers/2013/n3652.html
#if (CM_ARCH & CM_ARCH_SIMD_BIT) // Compiler SIMD intrinsics don't support constexpr...
#	define CM_HAS_CONSTEXPR 0
#elif (CM_COMPILER & CM_COMPILER_CLANG)
#	define CM_HAS_CONSTEXPR __has_feature(cxx_relaxed_constexpr)
#elif (CM_LANG & CM_LANG_CXX14_FLAG)
#	define CM_HAS_CONSTEXPR 1
#else
#	define CM_HAS_CONSTEXPR ((CM_LANG & CM_LANG_CXX0X_FLAG) && CM_HAS_INITIALIZER_LISTS && (\
		((CM_COMPILER & CM_COMPILER_INTEL) && (CM_COMPILER >= CM_COMPILER_INTEL17)) || \
		((CM_COMPILER & CM_COMPILER_VC) && (CM_COMPILER >= CM_COMPILER_VC15))))
#endif
CM_LOG_MACRO_VALUE(CM_HAS_CONSTEXPR)

#if CM_HAS_CONSTEXPR
#	define CM_CONSTEXPR constexpr
#else
#	define CM_CONSTEXPR
#endif
CM_LOG_MACRO_VALUE(CM_CONSTEXPR)

//
#if CM_HAS_CONSTEXPR
# if (CM_COMPILER & CM_COMPILER_CLANG)
#	if __has_feature(cxx_if_constexpr)
#		define CM_HAS_IF_CONSTEXPR 1
#	else
# 		define CM_HAS_IF_CONSTEXPR 0
#	endif
# elif (CM_LANG & CM_LANG_CXX17_FLAG)
# 	define CM_HAS_IF_CONSTEXPR 1
# else
# 	define CM_HAS_IF_CONSTEXPR 0
# endif
#else
#	define CM_HAS_IF_CONSTEXPR 0
#endif
CM_LOG_MACRO_VALUE(CM_HAS_IF_CONSTEXPR)

#if CM_HAS_IF_CONSTEXPR
# 	define CM_IF_CONSTEXPR if constexpr
#else
#	define CM_IF_CONSTEXPR if
#endif
CM_LOG_MACRO_VALUE(CM_IF_CONSTEXPR)

//
#if CM_LANG & CM_LANG_CXX11_FLAG
#	define CM_HAS_ASSIGNABLE 1
#else
#	define CM_HAS_ASSIGNABLE ((CM_LANG & CM_LANG_CXX0X_FLAG) && (\
		((CM_COMPILER & CM_COMPILER_VC) && (CM_COMPILER >= CM_COMPILER_VC15)) || \
		((CM_COMPILER & CM_COMPILER_GCC) && (CM_COMPILER >= CM_COMPILER_GCC49))))
#endif
CM_LOG_MACRO_VALUE(CM_HAS_ASSIGNABLE)

//
#define CM_HAS_TRIVIAL_QUERIES 0
CM_LOG_MACRO_VALUE(CM_HAS_TRIVIAL_QUERIES)

//
#if CM_LANG & CM_LANG_CXX11_FLAG
#	define CM_HAS_MAKE_SIGNED 1
#else
#	define CM_HAS_MAKE_SIGNED ((CM_LANG & CM_LANG_CXX0X_FLAG) && (\
		((CM_COMPILER & CM_COMPILER_VC) && (CM_COMPILER >= CM_COMPILER_VC12)) || \
		((CM_COMPILER & CM_COMPILER_CUDA)) || \
		((CM_COMPILER & CM_COMPILER_HIP))))
#endif
CM_LOG_MACRO_VALUE(CM_HAS_MAKE_SIGNED)

//
#if defined(CM_FORCE_INTRINSICS)
#	define CM_HAS_BITSCAN_WINDOWS ((CM_PLATFORM & CM_PLATFORM_WINDOWS) && (\
		((CM_COMPILER & CM_COMPILER_INTEL)) || \
		((CM_COMPILER & CM_COMPILER_VC) && (CM_COMPILER >= CM_COMPILER_VC14) && (CM_ARCH & CM_ARCH_X86_BIT))))
#else
#	define CM_HAS_BITSCAN_WINDOWS 0
#endif
CM_LOG_MESSAGE("Use CM_FORCE_INTRINSICS to define CM_HAS_BITSCAN_WINDOWS")
CM_LOG_MACRO_VALUE(CM_HAS_BITSCAN_WINDOWS)

#if CM_LANG & CM_LANG_CXX11_FLAG
#	define CM_HAS_NOEXCEPT 1
#else
#	define CM_HAS_NOEXCEPT 0
#endif
CM_LOG_MACRO_VALUE(CM_HAS_NOEXCEPT)

#if CM_HAS_NOEXCEPT
#	define CM_NOEXCEPT noexcept
#else
#	define CM_NOEXCEPT
#endif
CM_LOG_MACRO_VALUE(CM_NOEXCEPT)

///////////////////////////////////////////////////////////////////////////////////
// OpenMP
#ifdef _OPENMP
#	if CM_COMPILER & CM_COMPILER_GCC
#		if CM_COMPILER >= CM_COMPILER_GCC61
#			define CM_HAS_OPENMP 45
#		elif CM_COMPILER >= CM_COMPILER_GCC49
#			define CM_HAS_OPENMP 40
#		elif CM_COMPILER >= CM_COMPILER_GCC47
#			define CM_HAS_OPENMP 31
#		else
#			define CM_HAS_OPENMP 0
#		endif
#	elif CM_COMPILER & CM_COMPILER_CLANG
#		if CM_COMPILER >= CM_COMPILER_CLANG38
#			define CM_HAS_OPENMP 31
#		else
#			define CM_HAS_OPENMP 0
#		endif
#	elif CM_COMPILER & CM_COMPILER_VC
#		define CM_HAS_OPENMP 20
#	elif CM_COMPILER & CM_COMPILER_INTEL
#		if CM_COMPILER >= CM_COMPILER_INTEL16
#			define CM_HAS_OPENMP 40
#		else
#			define CM_HAS_OPENMP 0
#		endif
#	else
#		define CM_HAS_OPENMP 0
#	endif
#else
#	define CM_HAS_OPENMP 0
#endif
CM_LOG_MACRO_VALUE(CM_HAS_OPENMP)

///////////////////////////////////////////////////////////////////////////////////
// nullptr

#if CM_LANG & CM_LANG_CXX0X_FLAG
#	define CM_CONFIG_NULLPTR CM_ENABLE
#else
#	define CM_CONFIG_NULLPTR CM_DISABLE
#endif
CM_LOG_MACRO_VALUE(CM_CONFIG_NULLPTR)

#if CM_CONFIG_NULLPTR == CM_ENABLE
#	define CM_NULLPTR nullptr
#else
#	define CM_NULLPTR 0
#endif
CM_LOG_MACRO_VALUE(CM_NULLPTR)

///////////////////////////////////////////////////////////////////////////////////
// Static assert

#if CM_HAS_STATIC_ASSERT
#	define CM_STATIC_ASSERT(x, message) static_assert(x, message)
#elif CM_COMPILER & CM_COMPILER_VC
#	define CM_STATIC_ASSERT(x, message) typedef char __CASSERT__##__LINE__[(x) ? 1 : -1]
#else
#	define CM_STATIC_ASSERT(x, message) assert(x)
#endif//CM_LANG
CM_LOG_MESSAGE("Use CM_HAS_STATIC_ASSERT to define CM_STATIC_ASSERT(x, message")
CM_LOG_MESSAGE("CM_HAS_STATIC_ASSERT(x, message) defined")


// USing SIMD instruction set
#if CM_HAS_ALIGNOF && (CM_LANG & CM_LANG_CXXMS_FLAG) && (CM_ARCH & CM_ARCH_SIMD_BIT)
#	define	CM_CONFIG_SIMD CM_ENABLE
#else
#	define CM_CONFIG_SIMD CM_DISABLE
#endif


// User defines: CM_CUDA_FORCE_DEVICE_FUNC, CM_CUDA_FORCE_HOST_FUNC

#if (CM_COMPILER & CM_COMPILER_CUDA) || (CM_COMPILER & CM_COMPILER_HIP)
#	if defined(CM_CUDA_FORCE_DEVICE_FUNC) && defined(CM_CUDA_FORCE_HOST_FUNC)
#		error "CM error: CM_CUDA_FORCE_DEVICE_FUNC and CM_CUDA_FORCE_HOST_FUNC should not be defined at the same time, CM by default generates both device and host code for CUDA compiler."
#	endif//defined(CM_CUDA_FORCE_DEVICE_FUNC) && defined(CM_CUDA_FORCE_HOST_FUNC)

#	if defined(CM_CUDA_FORCE_DEVICE_FUNC)
#		define CM_CUDA_FUNC_DEF __device__
#		define CM_CUDA_FUNC_DECL __device__
#	elif defined(CM_CUDA_FORCE_HOST_FUNC)
#		define CM_CUDA_FUNC_DEF __host__
#		define CM_CUDA_FUNC_DECL __host__
#	else
#		define CM_CUDA_FUNC_DEF __device__ __host__
#		define CM_CUDA_FUNC_DECL __device__ __host__
#	endif//defined(CM_CUDA_FORCE_XXXX_FUNC)
#else
#	define CM_CUDA_FUNC_DEF
#	define CM_CUDA_FUNC_DECL
#endif
CM_LOG_MESSAGE("Use CM_CUDA_FORCE_DEVICE_FUNC or CM_CUDA_FORCE_HOST_FUNC to define CM_CUDA_FUNC_DEF and CM_CUDA_FUNC_DECL")
CM_LOG_MACRO_VALUE(CM_CUDA_FUNC_DEF)
CM_LOG_MACRO_VALUE(CM_CUDA_FUNC_DECL)


#if defined(CM_FORCE_INLINE)
#	if CM_COMPILER & CM_COMPILER_VC
#		define CM_INLINE __forceinline
#		define CM_NEVER_INLINE __declspec(noinline)
#	elif CM_COMPILER & (CM_COMPILER_GCC | CM_COMPILER_CLANG)
#		define CM_INLINE inline __attribute__((__always_inline__))
#		define CM_NEVER_INLINE __attribute__((__noinline__))
#	elif (CM_COMPILER & CM_COMPILER_CUDA) || (CM_COMPILER & CM_COMPILER_HIP)
#		define CM_INLINE __forceinline__
#		define CM_NEVER_INLINE __noinline__
#	else
#		define CM_INLINE inline
#		define CM_NEVER_INLINE
#	endif//CM_COMPILER
#else
#	define CM_INLINE inline
#	define CM_NEVER_INLINE
#endif//defined(CM_FORCE_INLINE)
CM_LOG_MESSAGE("Use CM_FORCE_INLINE to define CM_INLINE or CM_NEVER_INLINE")
CM_LOG_MACRO_VALUE(CM_INLINE)
CM_LOG_MACRO_VALUE(CM_NEVER_INLINE)


#define CM_FUNC_DECL CM_CUDA_FUNC_DECL
CM_LOG_MACRO_VALUE(CM_FUNC_DECL)
#define CM_FUNC_QUALIFIER CM_CUDA_FUNC_DEF CM_INLINE
CM_LOG_MACRO_VALUE(CM_FUNC_QUALIFIER)

// Do not use CUDA function qualifiers on CUDA compiler when functions are made default
#if CM_HAS_DEFAULTED_FUNCTIONS
#	define CM_DEFAULTED_FUNC_DECL
#	define CM_DEFAULTED_FUNC_QUALIFIER CM_INLINE
#else
#	define CM_DEFAULTED_FUNC_DECL CM_FUNC_DECL
#	define CM_DEFAULTED_FUNC_QUALIFIER CM_FUNC_QUALIFIER
#endif//CM_HAS_DEFAULTED_FUNCTIONS
CM_LOG_MACRO_VALUE(CM_DEFAULTED_FUNC_DECL)
CM_LOG_MACRO_VALUE(CM_DEFAULTED_FUNC_QUALIFIER)


#if !defined(CM_FORCE_CTOR_INIT)
#	define CM_DEFAULTED_DEFAULT_CTOR_DECL CM_DEFAULTED_FUNC_DECL
#	define CM_DEFAULTED_DEFAULT_CTOR_QUALIFIER CM_DEFAULTED_FUNC_QUALIFIER
#else
#	define CM_DEFAULTED_DEFAULT_CTOR_DECL CM_FUNC_DECL
#	define CM_DEFAULTED_DEFAULT_CTOR_QUALIFIER CM_FUNC_QUALIFIER
#endif//CM_FORCE_CTOR_INIT
CM_LOG_MACRO_VALUE(CM_DEFAULTED_DEFAULT_CTOR_DECL)
CM_LOG_MACRO_VALUE(CM_DEFAULTED_DEFAULT_CTOR_DECL)




// N1988
#if CM_LANG & CM_LANG_CXX11_FLAG
#	define CM_HAS_EXTENDED_INTEGER_TYPE 1
#else
#	define CM_HAS_EXTENDED_INTEGER_TYPE (\
		((CM_LANG & CM_LANG_CXX0X_FLAG) && (CM_COMPILER & CM_COMPILER_VC)) || \
		((CM_LANG & CM_LANG_CXX0X_FLAG) && (CM_COMPILER & CM_COMPILER_CUDA)) || \
		((CM_LANG & CM_LANG_CXX0X_FLAG) && (CM_COMPILER & CM_COMPILER_CLANG)) || \
		((CM_COMPILER & CM_COMPILER_HIP)))
#endif
CM_LOG_MACRO_VALUE(CM_HAS_EXTENDED_INTEGER_TYPE)


// Adding compatibility for align objects in memory
// Based on preprocessor CM_FORCE_ALIGNED
#ifdef CM_FORCE_ALIGNED
#	define CM_FORCE_DEFAULT_ALIGNED_GENTYPES
#endif
#ifdef CM_FORCE_DEFAULT_ALIGNED_GENTYPES
#	define CM_FORCE_ALIGNED_GENTYPES
#endif
#if CM_HAS_ALIGNOF && (CM_LANG & CM_LANG_CXXMS_FLAG) && defined(CM_FORCE_ALIGNED_GENTYPES) || (CM_CONFIG_SIMD == CM_ENABLE)
#	define CM_CONFIG_ALIGNED_GENTYPES CM_ENABLE
#else
#	define CM_CONFIG_ALIGNED_GENTYPES CM_DISABLE
#endif

#if CM_HAS_EXTENDED_INTEGER_TYPE
#	include <cstdint>
#endif

namespace cm {
	namespace detail
	{
#	if CM_HAS_EXTENDED_INTEGER_TYPE
		typedef std::uint64_t						uint64;
		typedef std::int64_t						int64;
#	elif (defined(__STDC_VERSION__) && (__STDC_VERSION__ >= 199901L)) // C99 detected, 64 bit types available
		typedef uint64_t							uint64;
		typedef int64_t								int64;
#	elif CM_COMPILER & CM_COMPILER_VC
		typedef unsigned __int64					uint64;
		typedef signed __int64						int64;
#	elif CM_COMPILER & CM_COMPILER_GCC
#		pragma GCC diagnostic ignored "-Wlong-long"
		__extension__ typedef unsigned long long	uint64;
		__extension__ typedef signed long long		int64;
#	elif (CM_COMPILER & CM_COMPILER_CLANG)
#		pragma clang diagnostic ignored "-Wc++11-long-long"
		typedef unsigned long long					uint64;
		typedef signed long long					int64;
#	else//unknown compiler
		typedef unsigned long long					uint64;
		typedef signed long long					int64;
#	endif
	}
}



// Adding compatibility to allow functions to return length as a size_t type(unsigned type) or by default as int
// Use CM_FORCE_SIZE_T_LENGTH
#define CM_LENGTH_INT	1
#define CM_LENGTH_SIZE_T	2

#ifdef CM_FORCE_SIZE_T_LENGTH
#	define CM_CONFIG_LENGTH_TYPE	CM_LENGTH_SIZE_T
#	define CM_ASSERT_LENGTH(l, max)	(assert((l) < (max)))
#else
#	define CM_CONFIG_LENGTH_TYPE CM_LENGTH_INT
#	define CM_ASSERT_LENGTH(l, max)	(assert((l >= 0) && (l) < (max)))
#endif

namespace cm {
	using std::size_t;
#	if CM_CONFIG_LENGTH_TYPE == CM_LENGTH_SIZE_T
		typedef size_t length_t;
#	else
		typedef int length_t;
#	endif
}


#define CM_SWIZZLE_DISABLED		0
#define CM_SWIZZLE_OPERATOR		1
#define CM_SWIZZLE_FUNCTION		2

#if defined(CM_SWIZZLE)
#	pragma message("CM: CM_SWIZZLE is deprecated, use CM_FORCE_SWIZZLE instead.")
#	define CM_FORCE_SWIZZLE
#endif

#if defined(CM_FORCE_SWIZZLE) && (CM_LANG & CM_LANG_CXXMS_FLAG) && !defined(CM_FORCE_XYZW_ONLY)
#	define CM_CONFIG_SWIZZLE CM_SWIZZLE_OPERATOR
#elif defined(CM_FORCE_SWIZZLE)
#	define CM_CONFIG_SWIZZLE CM_SWIZZLE_FUNCTION
#else
#	define CM_CONFIG_SWIZZLE CM_SWIZZLE_DISABLED
#endif


#if ((CM_CONFIG_SIMD == CM_ENABLE) || (CM_CONFIG_SWIZZLE == CM_SWIZZLE_OPERATOR) || (CM_CONFIG_ALIGNED_GENTYPES == CM_ENABLE))
#	define CM_CONFIG_ANONYMOUS_STRUCT CM_ENABLE
#else
#	define CM_CONFIG_ANONYMOUS_STRUCT CM_DISABLE
#endif


#if CM_FORCE_XYZW_ONLY
#	define CM_CONFIG_XYZW_ONLY CM_ENABLE
#else
#	define CM_CONFIG_XYZW_ONLY CM_DISABLE
#endif


#if CM_FORCE_WARNINGS
#	define CM_SILENT_WARNINGS CM_DISABLE
#else
#	define CM_SILENT_WARNINGS CM_ENABLE
#endif

#if CM_HAS_DEFAULTED_FUNCTIONS
#	define CM_CONFIG_DEFAULTED_FUNCTIONS CM_ENABLE
#	define CM_DEFAULT =default
#else
#	define CM_CONFIG_DEFAULTED_FUNCTIONS CM_DISABLE
#	define CM_DEFAULT
#endif

#define CM_CTOR_INIT_DISABLE 0
#define CM_CTOR_INITIALIZER_LIST 1
#define CM_CTOR_INITIALIZATION 2

#if defined(CTOR_FORCE_CTOR_INIT) && CM_HAS_INITIALIZER_LISTS
#	define CM_CONFIG_CTOR_INIT CM_CTOR_INITIALIZER_LIST
#elif defined(CTOR_FORCE_CTOR_INIT) && !CM_HAS_INITIALIZER_LISTS
#	define CM_CONFIG_CTOR_INIT CM_CTOR_INITIALIZATION
#else
#	define CM_CONFIG_CTOR_INIT CM_CTOR_INIT_DISABLE
#endif

#ifdef CM_FORCE_EXPLICIT_CTOR
#	define CM_EXPLICIT explicit
#else
#	define CM_EXPLICIT
#endif



#if CM_CONFIG_CTOR_INIT == CM_CTOR_INIT_DISABLE && CM_CONFIG_DEFAULTED_FUNCTIONS == CM_ENABLE
#	define CM_CONFIG_DEFAULTED_DEFAULT_CTOR CM_ENABLE
#	define CM_DEFAULT_CTOR CM_DEFAULT
#else
#	define CM_CONFIG_DEFAULTED_DEFAULT_CTOR CM_DISABLE
#	define CM_DEFAULT_CTOR
#endif








// MODIFICATIONS:
// Add more platform support for "cuda" capabilities like Apple, OpenCL, SYCL.






