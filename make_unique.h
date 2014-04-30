//
//  make_unique.h
//  CS394State
//
//  Created by Chris Hartman on 4/5/13.
//  Copyright (c) 2013 Chris Hartman. All rights reserved.
//

#ifndef CS394State_make_unique_h
#define CS394State_make_unique_h

#include <memory>

template<typename T, typename ...Args>
std::unique_ptr<T> make_unique( Args&& ...args )
{
    return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
}

#endif
