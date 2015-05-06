//
//  pointer_alias.h
//  GPAPI
//
//  Created by savage309 on 6.05.15.
//  Copyright (c) 2015 г. savage309. All rights reserved.
//

#ifndef GPAPI_pointer_alias_h
#define GPAPI_pointer_alias_h

namespace PointerAlias {
    struct A{};
    struct B{};
    
void pointerAliasSameType(float* a, float* b, float* res, size_t size);
void pointerAliasDifferentType(float* a, A* b, B* res, size_t size);
void pointerAliasDifferentTypeNoCast(float* a, A* b, B* res, size_t size) ;
    void pointerAliasSameTypeRestrict( float* __restrict__ a,  float*  __restrict__ b,  float* __restrict__ res, size_t size);
} //namespace PointerAlias


#endif
