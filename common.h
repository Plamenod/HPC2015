#pragma once

#define RESTRICT __restrict__
#define NO_INLINE __attribute__ ((noinline))
#define INLINE __inline__ __attribute__((always_inline))

#if __cplusplus >= 201103L
#   define CPP11
#endif

#if defined(CPP11) && (defined __clang__)
#   define DISABLE_SIMD_UNROLL _Pragma("clang loop vectorize(disable) interleave(disable)")
#else
#   define DISABLE_SIMD_UNROLL
#endif

#if defined(CPP11) && (defined __clang__)
#   define DISABLE_SIMD _Pragma("clang loop vectorize(disable)")
#else
#   define DISABLE_SIMD
#endif

#if defined(CPP11) && (defined __clang__)
#   define UNROLL _Pragma("unroll")
#else
#   define UNROLL
#endif

#include <cmath>
#include <cstdlib>

#define DISABLE_REDUNDANT_CODE_OPT() { asm(""); }

#include "benchpress/benchpress.hpp"

#define ADD_BENCHMARK(name, function) { BENCHMARK(name, [&](benchpress::context* ctx) { for (size_t i = 0; i < ctx->num_iterations(); ++i) { function(); } });}

inline float randomFloat() {
    return float(rand())/RAND_MAX;
}
inline int randomInt(int min, int max) {
    return min + (max - min) * randomFloat();
}


constexpr
unsigned long long operator"" _million ( unsigned long long v ) {
    return v*1000000ULL;
}

