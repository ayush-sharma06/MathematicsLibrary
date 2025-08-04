#pragma once


// Platform definitions

#define CM_PLATFORM_UNKNOWN		0x00000000
#define CM_PLATFORM_WINDOWS		0x00010000
#define CM_PLATFORM_LINUX			0x00020000
#define CM_PLATFORM_APPLE			0x00040000
//#define CM_PLATFORM_IOS			0x00080000
#define CM_PLATFORM_ANDROID		0x00100000
#define CM_PLATFORM_CHROME_NACL	0x00200000
#define CM_PLATFORM_UNIX			0x00400000
#define CM_PLATFORM_QNXNTO			0x00800000
#define CM_PLATFORM_WINCE			0x01000000
#define CM_PLATFORM_CYGWIN			0x02000000


#ifdef CM_FORCE_PLATFORM_UNKNOWN
#	define CM_PLATFORM CM_PLATFORM_UNKNOWN
#elif defined(_WIN32)
#	define CM_PLATFORM CM_PLATFORM_WINDOWS
#elif defined(__linux)
#	define CM_PLATFORM CM_PLATFORM_LINUX
#elif defined(__APPLE__)
#	define CM_PLATFORM CM_PLATFORM_APPLE
#elif defined(__ANDROID__)
#	define CM_PLATFORM CM_PLATFORM_ANDROID
#elif defined(__native_client__)
#	define CM_PLATFORM CM_PLATFORM_CHROME_NACL
#elif defined(__unix)
#	define CM_PLATFORM CM_PLATFORM_UNIX
#elif defined(__QNXNTO__)
#	define CM_PLATFORM CM_PLATFORM_QNXNTO
#elif defined(WINCE)
#	define CM_PLATFORM CM_PLATFORM_WINCE
#elif defined(__CYGWIN__)
#	define CM_PLATFORM CM_PLATFORM_CYGWIN
#else
#	define CM_PLATFORM CM_PLATFORM_UNKNOWN
#endif
////////////////////////////////////////////////////////////////////////////////////////









// Compiler

#define CM_COMPILER_UNKNOWN		0x00000000

// Intel
#define CM_COMPILER_INTEL			0x00100000
#define CM_COMPILER_INTEL14		0x00100040
#define CM_COMPILER_INTEL15		0x00100050
#define CM_COMPILER_INTEL16		0x00100060
#define CM_COMPILER_INTEL17		0x00100070
#define CM_COMPILER_INTEL18		0x00100080
#define CM_COMPILER_INTEL19		0x00100090
#define CM_COMPILER_INTEL21		0x001000A0

// Visual C++ defines
#define CM_COMPILER_VC				0x01000000
#define CM_COMPILER_VC12			0x01000001 // Visual Studio 2013
#define CM_COMPILER_VC14			0x01000002 // Visual Studio 2015
#define CM_COMPILER_VC15			0x01000003 // Visual Studio 2017
#define CM_COMPILER_VC15_3			0x01000004
#define CM_COMPILER_VC15_5			0x01000005
#define CM_COMPILER_VC15_6			0x01000006
#define CM_COMPILER_VC15_7			0x01000007
#define CM_COMPILER_VC15_8			0x01000008
#define CM_COMPILER_VC15_9			0x01000009
#define CM_COMPILER_VC16			0x0100000A // Visual Studio 2019
#define CM_COMPILER_VC17			0x0100000B // Visual Studio 2022

// GCC defines
#define CM_COMPILER_GCC			0x02000000
#define CM_COMPILER_GCC46			0x020000D0
#define CM_COMPILER_GCC47			0x020000E0
#define CM_COMPILER_GCC48			0x020000F0
#define CM_COMPILER_GCC49			0x02000100
#define CM_COMPILER_GCC5			0x02000200
#define CM_COMPILER_GCC6			0x02000300
#define CM_COMPILER_GCC61			0x02000800
#define CM_COMPILER_GCC7			0x02000400
#define CM_COMPILER_GCC8			0x02000500
#define CM_COMPILER_GCC9			0x02000600
#define CM_COMPILER_GCC10			0x02000700
#define CM_COMPILER_GCC11			0x02000800
#define CM_COMPILER_GCC12			0x02000900
#define CM_COMPILER_GCC13			0x02000A00
#define CM_COMPILER_GCC14			0x02000B00

// CUDA
#define CM_COMPILER_CUDA			0x10000000
#define CM_COMPILER_CUDA75			0x10000001
#define CM_COMPILER_CUDA80			0x10000002
#define CM_COMPILER_CUDA90			0x10000004
#define CM_COMPILER_CUDA_RTC		0x10000100

// Clang
#define CM_COMPILER_CLANG			0x20000000
#define CM_COMPILER_CLANG34		0x20000050
#define CM_COMPILER_CLANG35		0x20000060
#define CM_COMPILER_CLANG36		0x20000070
#define CM_COMPILER_CLANG37		0x20000080
#define CM_COMPILER_CLANG38		0x20000090
#define CM_COMPILER_CLANG39		0x200000A0
#define CM_COMPILER_CLANG4			0x200000B0
#define CM_COMPILER_CLANG5			0x200000C0
#define CM_COMPILER_CLANG6			0x200000D0
#define CM_COMPILER_CLANG7			0x200000E0
#define CM_COMPILER_CLANG8			0x200000F0
#define CM_COMPILER_CLANG9			0x20000100
#define CM_COMPILER_CLANG10		0x20000200
#define CM_COMPILER_CLANG11		0x20000300
#define CM_COMPILER_CLANG12		0x20000400
#define CM_COMPILER_CLANG13		0x20000500
#define CM_COMPILER_CLANG14		0x20000600
#define CM_COMPILER_CLANG15		0x20000700
#define CM_COMPILER_CLANG16		0x20000800
#define CM_COMPILER_CLANG17		0x20000900
#define CM_COMPILER_CLANG18		0x20000A00
#define CM_COMPILER_CLANG19		0x20000B00

// HIP
#define CM_COMPILER_HIP			0x40000000

// Build model
#define CM_MODEL_32				0x00000010
#define CM_MODEL_64				0x00000020



#ifdef CM_FORCE_COMPILER_UNKNOWN
#	define CM_COMPILER CM_COMPILER_UNKNOWN

#elif defined(__INTEL_COMPILER)
#	if __INTEL_COMPILER >= 2021
#		define CM_COMPILER CM_COMPILER_INTEL21
#	elif __INTEL_COMPILER >= 1900
#		define CM_COMPILER CM_COMPILER_INTEL19
#	elif __INTEL_COMPILER >= 1800
#		define CM_COMPILER CM_COMPILER_INTEL18
#	elif __INTEL_COMPILER >= 1700
#		define CM_COMPILER CM_COMPILER_INTEL17
#	elif __INTEL_COMPILER >= 1600
#		define CM_COMPILER CM_COMPILER_INTEL16
#	elif __INTEL_COMPILER >= 1500
#		define CM_COMPILER CM_COMPILER_INTEL15
#	elif __INTEL_COMPILER >= 1400
#		define CM_COMPILER CM_COMPILER_INTEL14
#	elif __INTEL_COMPILER < 1400
#		error "CM requires ICC 2013 SP1 or newer"
#	endif

// CUDA
#elif defined(__CUDACC__)
#	if !defined(CUDA_VERSION) && !defined(CM_FORCE_CUDA)
#		include <cuda.h>  // make sure version is defined since nvcc does not define it itself!
#	endif
#	if defined(__CUDACC_RTC__)
#		define CM_COMPILER CM_COMPILER_CUDA_RTC
#	elif CUDA_VERSION >= 8000
#		define CM_COMPILER CM_COMPILER_CUDA80
#	elif CUDA_VERSION >= 7500
#		define CM_COMPILER CM_COMPILER_CUDA75
#	elif CUDA_VERSION >= 7000
#		define CM_COMPILER CM_COMPILER_CUDA70
#	elif CUDA_VERSION < 7000
#		error "CM requires CUDA 7.0 or higher"
#	endif

// HIP
#elif defined(__HIP__)
#	define CM_COMPILER CM_COMPILER_HIP

// Clang
#elif defined(__clang__)
#	if defined(__apple_build_version__)
#		if (__clang_major__ < 6)
#			error "CM requires Clang 3.4 / Apple Clang 6.0 or higher"
#		elif __clang_major__ == 6 && __clang_minor__ == 0
#			define CM_COMPILER CM_COMPILER_CLANG35
#		elif __clang_major__ == 6 && __clang_minor__ >= 1
#			define CM_COMPILER CM_COMPILER_CLANG36
#		elif __clang_major__ >= 7
#			define CM_COMPILER CM_COMPILER_CLANG37
#		endif
#	else
#		if ((__clang_major__ == 3) && (__clang_minor__ < 4)) || (__clang_major__ < 3)
#			error "CM requires Clang 3.4 or higher"
#		elif __clang_major__ == 3 && __clang_minor__ == 4
#			define CM_COMPILER CM_COMPILER_CLANG34
#		elif __clang_major__ == 3 && __clang_minor__ == 5
#			define CM_COMPILER CM_COMPILER_CLANG35
#		elif __clang_major__ == 3 && __clang_minor__ == 6
#			define CM_COMPILER CM_COMPILER_CLANG36
#		elif __clang_major__ == 3 && __clang_minor__ == 7
#			define CM_COMPILER CM_COMPILER_CLANG37
#		elif __clang_major__ == 3 && __clang_minor__ == 8
#			define CM_COMPILER CM_COMPILER_CLANG38
#		elif __clang_major__ == 3 && __clang_minor__ >= 9
#			define CM_COMPILER CM_COMPILER_CLANG39
#		elif __clang_major__ == 4 && __clang_minor__ == 0
#			define CM_COMPILER CM_COMPILER_CLANG4
#		elif __clang_major__ == 5
#			define CM_COMPILER CM_COMPILER_CLANG5
#		elif __clang_major__ == 6
#			define CM_COMPILER CM_COMPILER_CLANG6
#		elif __clang_major__ == 7
#			define CM_COMPILER CM_COMPILER_CLANG7
#		elif __clang_major__ == 8
#			define CM_COMPILER CM_COMPILER_CLANG8
#		elif __clang_major__ == 9
#			define CM_COMPILER CM_COMPILER_CLANG9
#		elif __clang_major__ == 10
#			define CM_COMPILER CM_COMPILER_CLANG10
#		elif __clang_major__ == 11
#			define CM_COMPILER CM_COMPILER_CLANG11
#		elif __clang_major__ == 12
#			define CM_COMPILER CM_COMPILER_CLANG12
#		elif __clang_major__ == 13
#			define CM_COMPILER CM_COMPILER_CLANG13
#		elif __clang_major__ == 14
#			define CM_COMPILER CM_COMPILER_CLANG14
#		elif __clang_major__ == 15
#			define CM_COMPILER CM_COMPILER_CLANG15
#		elif __clang_major__ == 16
#			define CM_COMPILER CM_COMPILER_CLANG16
#		elif __clang_major__ == 17
#			define CM_COMPILER CM_COMPILER_CLANG17
#		elif __clang_major__ == 18
#			define CM_COMPILER CM_COMPILER_CLANG18
#		elif __clang_major__ >= 19
#			define CM_COMPILER CM_COMPILER_CLANG19
#		endif
#	endif

// Visual C++
#elif defined(_MSC_VER)
#   if _MSC_VER >= 1930
#		define CM_COMPILER CM_COMPILER_VC17
#	elif _MSC_VER >= 1920
#		define CM_COMPILER CM_COMPILER_VC16
#	elif _MSC_VER >= 1916
#		define CM_COMPILER CM_COMPILER_VC15_9
#	elif _MSC_VER >= 1915
#		define CM_COMPILER CM_COMPILER_VC15_8
#	elif _MSC_VER >= 1914
#		define CM_COMPILER CM_COMPILER_VC15_7
#	elif _MSC_VER >= 1913
#		define CM_COMPILER CM_COMPILER_VC15_6
#	elif _MSC_VER >= 1912
#		define CM_COMPILER CM_COMPILER_VC15_5
#	elif _MSC_VER >= 1911
#		define CM_COMPILER CM_COMPILER_VC15_3
#	elif _MSC_VER >= 1910
#		define CM_COMPILER CM_COMPILER_VC15
#	elif _MSC_VER >= 1900
#		define CM_COMPILER CM_COMPILER_VC14
#	elif _MSC_VER >= 1800
#		define CM_COMPILER CM_COMPILER_VC12
#	elif _MSC_VER < 1800
#		error "CM requires Visual C++ 12 - 2013 or higher"
#	endif//_MSC_VER

// G++
#elif defined(__GNUC__) || defined(__MINGW32__)
#	if __GNUC__ >= 14
#		define CM_COMPILER CM_COMPILER_GCC14
#	elif __GNUC__ >= 13
#		define CM_COMPILER CM_COMPILER_GCC13
#	elif __GNUC__ >= 12
#		define CM_COMPILER CM_COMPILER_GCC12
#	elif __GNUC__ >= 11
#		define CM_COMPILER CM_COMPILER_GCC11
#	elif __GNUC__ >= 10
#		define CM_COMPILER CM_COMPILER_GCC10
#	elif __GNUC__ >= 9
#		define CM_COMPILER CM_COMPILER_GCC9
#	elif __GNUC__ >= 8
#		define CM_COMPILER CM_COMPILER_GCC8
#	elif __GNUC__ >= 7
#		define CM_COMPILER CM_COMPILER_GCC7
#	elif __GNUC__ >= 6
#		define CM_COMPILER CM_COMPILER_GCC6
#	elif __GNUC__ >= 5
#		define CM_COMPILER CM_COMPILER_GCC5
#	elif __GNUC__ == 4 && __GNUC_MINOR__ >= 9
#		define CM_COMPILER CM_COMPILER_GCC49
#	elif __GNUC__ == 4 && __GNUC_MINOR__ >= 8
#		define CM_COMPILER CM_COMPILER_GCC48
#	elif __GNUC__ == 4 && __GNUC_MINOR__ >= 7
#		define CM_COMPILER CM_COMPILER_GCC47
#	elif __GNUC__ == 4 && __GNUC_MINOR__ >= 6
#		define CM_COMPILER CM_COMPILER_GCC46
#	elif ((__GNUC__ == 4) && (__GNUC_MINOR__ < 6)) || (__GNUC__ < 4)
#		error "CM requires GCC 4.6 or higher"
#	endif

#else
#	define CM_COMPILER CM_COMPILER_UNKNOWN
#endif

#ifndef CM_COMPILER
#	error "CM_COMPILER undefined, your compiler may not be supported by CM. Add #define CM_COMPILER 0 to ignore this message."
#endif//CM_COMPILER




///////////////////////////////////////////////////////////////////////////////////
// Instruction sets

// User defines: CM_FORCE_PURE CM_FORCE_INTRINSICS CM_FORCE_SSE2 CM_FORCE_SSE3 CM_FORCE_AVX CM_FORCE_AVX2 CM_FORCE_AVX2

#define CM_ARCH_MIPS_BIT	  (0x10000000)
#define CM_ARCH_PPC_BIT	  (0x20000000)
#define CM_ARCH_ARM_BIT	  (0x40000000)
#define CM_ARCH_ARMV8_BIT  (0x01000000)
#define CM_ARCH_X86_BIT	  (0x80000000)

#define CM_ARCH_SIMD_BIT	(0x00001000)

#define CM_ARCH_NEON_BIT	(0x00000001)
#define CM_ARCH_SSE_BIT	(0x00000002)
#define CM_ARCH_SSE2_BIT	(0x00000004)
#define CM_ARCH_SSE3_BIT	(0x00000008)
#define CM_ARCH_SSSE3_BIT	(0x00000010)
#define CM_ARCH_SSE41_BIT	(0x00000020)
#define CM_ARCH_SSE42_BIT	(0x00000040)
#define CM_ARCH_AVX_BIT	(0x00000080)
#define CM_ARCH_AVX2_BIT	(0x00000100)

#define CM_ARCH_UNKNOWN	(0)
#define CM_ARCH_X86		(CM_ARCH_X86_BIT)
#define CM_ARCH_SSE		(CM_ARCH_SSE_BIT | CM_ARCH_SIMD_BIT | CM_ARCH_X86)
#define CM_ARCH_SSE2		(CM_ARCH_SSE2_BIT | CM_ARCH_SSE)
#define CM_ARCH_SSE3		(CM_ARCH_SSE3_BIT | CM_ARCH_SSE2)
#define CM_ARCH_SSSE3		(CM_ARCH_SSSE3_BIT | CM_ARCH_SSE3)
#define CM_ARCH_SSE41		(CM_ARCH_SSE41_BIT | CM_ARCH_SSSE3)
#define CM_ARCH_SSE42		(CM_ARCH_SSE42_BIT | CM_ARCH_SSE41)
#define CM_ARCH_AVX		(CM_ARCH_AVX_BIT | CM_ARCH_SSE42)
#define CM_ARCH_AVX2		(CM_ARCH_AVX2_BIT | CM_ARCH_AVX)
#define CM_ARCH_ARM		(CM_ARCH_ARM_BIT)
#define CM_ARCH_ARMV8		(CM_ARCH_NEON_BIT | CM_ARCH_SIMD_BIT | CM_ARCH_ARM | CM_ARCH_ARMV8_BIT)
#define CM_ARCH_NEON		(CM_ARCH_NEON_BIT | CM_ARCH_SIMD_BIT | CM_ARCH_ARM)
#define CM_ARCH_MIPS		(CM_ARCH_MIPS_BIT)
#define CM_ARCH_PPC		(CM_ARCH_PPC_BIT)

#if defined(CM_FORCE_ARCH_UNKNOWN) || defined(CM_FORCE_PURE)
#	define CM_ARCH CM_ARCH_UNKNOWN
#elif defined(CM_FORCE_NEON)
#	if __ARM_ARCH >= 8
#		define CM_ARCH (CM_ARCH_ARMV8)
#	else
#		define CM_ARCH (CM_ARCH_NEON)
#	endif
#	define CM_FORCE_INTRINSICS
#elif defined(CM_FORCE_AVX2)
#	define CM_ARCH (CM_ARCH_AVX2)
#	define CM_FORCE_INTRINSICS
#elif defined(CM_FORCE_AVX)
#	define CM_ARCH (CM_ARCH_AVX)
#	define CM_FORCE_INTRINSICS
#elif defined(CM_FORCE_SSE42)
#	define CM_ARCH (CM_ARCH_SSE42)
#	define CM_FORCE_INTRINSICS
#elif defined(CM_FORCE_SSE41)
#	define CM_ARCH (CM_ARCH_SSE41)
#	define CM_FORCE_INTRINSICS
#elif defined(CM_FORCE_SSSE3)
#	define CM_ARCH (CM_ARCH_SSSE3)
#	define CM_FORCE_INTRINSICS
#elif defined(CM_FORCE_SSE3)
#	define CM_ARCH (CM_ARCH_SSE3)
#	define CM_FORCE_INTRINSICS
#elif defined(CM_FORCE_SSE2)
#	define CM_ARCH (CM_ARCH_SSE2)
#	define CM_FORCE_INTRINSICS
#elif defined(CM_FORCE_SSE)
#	define CM_ARCH (CM_ARCH_SSE)
#	define CM_FORCE_INTRINSICS
#elif defined(CM_FORCE_INTRINSICS) && !defined(CM_FORCE_XYZW_ONLY)
#	if defined(__AVX2__)
#		define CM_ARCH (CM_ARCH_AVX2)
#	elif defined(__AVX__)
#		define CM_ARCH (CM_ARCH_AVX)
#	elif defined(__SSE4_2__)
#		define CM_ARCH (CM_ARCH_SSE42)
#	elif defined(__SSE4_1__)
#		define CM_ARCH (CM_ARCH_SSE41)
#	elif defined(__SSSE3__)
#		define CM_ARCH (CM_ARCH_SSSE3)
#	elif defined(__SSE3__)
#		define CM_ARCH (CM_ARCH_SSE3)
#	elif defined(__SSE2__) || defined(__x86_64__) || defined(_M_X64) || defined(_M_IX86_FP)
#		define CM_ARCH (CM_ARCH_SSE2)
#	elif defined(__i386__)
#		define CM_ARCH (CM_ARCH_X86)
#	elif defined(__ARM_ARCH) && (__ARM_ARCH >= 8)
#		define CM_ARCH (CM_ARCH_ARMV8)
#	elif defined(__ARM_NEON)
#		define CM_ARCH (CM_ARCH_ARM | CM_ARCH_NEON)
#	elif defined(__arm__ ) || defined(_M_ARM)
#		define CM_ARCH (CM_ARCH_ARM)
#	elif defined(__mips__ )
#		define CM_ARCH (CM_ARCH_MIPS)
#	elif defined(__powerpc__ ) || defined(_M_PPC)
#		define CM_ARCH (CM_ARCH_PPC)
#	else
#		define CM_ARCH (CM_ARCH_UNKNOWN)
#	endif
#else
#	if defined(__x86_64__) || defined(_M_X64) || defined(_M_IX86) || defined(__i386__)
#		define CM_ARCH (CM_ARCH_X86)
#	elif defined(__arm__) || defined(_M_ARM)
#		define CM_ARCH (CM_ARCH_ARM)
#	elif defined(__powerpc__) || defined(_M_PPC)
#		define CM_ARCH (CM_ARCH_PPC)
#	elif defined(__mips__)
#		define CM_ARCH (CM_ARCH_MIPS)
#	else
#		define CM_ARCH (CM_ARCH_UNKNOWN)
#	endif
#endif

#if CM_ARCH & CM_ARCH_AVX2_BIT
#	include <immintrin.h>
#elif CM_ARCH & CM_ARCH_AVX_BIT
#	include <immintrin.h>
#elif CM_ARCH & CM_ARCH_SSE42_BIT
#	if CM_COMPILER & CM_COMPILER_CLANG
#		include <popcntintrin.h>
#	endif
#	include <nmmintrin.h>
#elif CM_ARCH & CM_ARCH_SSE41_BIT
#	include <smmintrin.h>
#elif CM_ARCH & CM_ARCH_SSSE3_BIT
#	include <tmmintrin.h>
#elif CM_ARCH & CM_ARCH_SSE3_BIT
#	include <pmmintrin.h>
#elif CM_ARCH & CM_ARCH_SSE2_BIT
#	include <emmintrin.h>
#elif CM_ARCH & CM_ARCH_NEON_BIT
#	include "neon.h"
#endif//CM_ARCH

#if CM_ARCH & CM_ARCH_SSE2_BIT
typedef __m128			cm_f32vec4;
typedef __m128i			cm_i32vec4;
typedef __m128i			cm_u32vec4;
typedef __m128d			cm_f64vec2;
typedef __m128i			cm_i64vec2;
typedef __m128i			cm_u64vec2;

typedef cm_f32vec4		cm_vec4;
typedef cm_i32vec4		cm_ivec4;
typedef cm_u32vec4		cm_uvec4;
typedef cm_f64vec2		cm_dvec2;
#endif

#if CM_ARCH & CM_ARCH_AVX_BIT
typedef __m256d			cm_f64vec4;
typedef cm_f64vec4		cm_dvec4;
#endif

#if CM_ARCH & CM_ARCH_AVX2_BIT
typedef __m256i			cm_i64vec4;
typedef __m256i			cm_u64vec4;
#endif

#if CM_ARCH & CM_ARCH_NEON_BIT
typedef float32x4_t			cm_f32vec4;
typedef int32x4_t			cm_i32vec4;
typedef uint32x4_t			cm_u32vec4;
#endif