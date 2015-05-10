#include <iostream>
#include <cmath>
#include <memory>

#include "diffclock.h"

#include <algorithm>

#include "simd/simd.h"

#include "test_cache_miss.hpp"
#include "test_pointer_alias/test_pointer_alias.h"
#include "test_SoA.hpp"
#include "test_inline/test_inline.h"
#include "test_data_oriented_design.hpp"
#include "test_float_double.hpp"

#include "test_virtual/test_virtual.h"


void testSSE() {
    using namespace embree;
    size_t testSize = 1 << 15;
    
    std::unique_ptr<float[]> floats(new float[testSize]);
    
    std::generate(floats.get(),
                  floats.get() + testSize,
                  []{ return randomFloat();});
    
    auto sseSize = testSize/ssef::size;
    std::unique_ptr<ssef[]> sseFloats(new ssef[sseSize]);
    
    int floatIter = 0;
    for (int i = 0; i < sseSize; ++i) {
        sseFloats[i].load(floats.get() + floatIter);
        floatIter += 4;
    }
    
    auto time0 = getTime();
    std::for_each(floats.get(),
                  floats.get() + testSize,
                  [](float x) { return sqrtf(x); });
    auto time1 = getTime();
    std::cout << diffclock(time1, time0) << std::endl;
    auto time2 = getTime();
    std::for_each(sseFloats.get(),
                  sseFloats.get() + sseSize,
                  [](const ssef& f) { return sqrt(f); });
    auto time3 = getTime();

    std::cout << diffclock(time3, time2) << std::endl;

}

int main(int argc, const char * argv[]) {
    //t/estSSE();
    //return 0;
    std::cout << "Starting tests ...\n" << std::endl;
    Virtual::test();
    FloatDouble::test();
    DataOrientedDesign::test();
    SoA::test();
    Inline::test();
    PointerAlias::test();
    CacheMiss::test();
    std::cout << "Tests completed."  << std::endl;
    return 0;
}


