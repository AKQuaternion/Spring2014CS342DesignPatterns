//
//  Visitor.h
//  CS371Spring2014DesignPatterns
//   
//  Created by Chris Hartman on 4/28/14.
//  Copyright (c) 2014 Chris Hartman. All rights reserved.
//

#ifndef __CS371Spring2014DesignPatterns__Visitor__
#define __CS371Spring2014DesignPatterns__Visitor__

#include <iostream>
using std::cout;
using std::endl;
#include "Composite.h"

class Visitor
{
public:
    virtual ~Visitor() {}
    virtual void accept(File * fp) = 0;
    virtual void accept(Folder * fp) = 0;
private:
};

class Printer : public Visitor
{
public:
    Printer():_depth(0)
    {}
    
    virtual void accept(File * fp)
    {
        tab();
        cout << fp->name() << endl;
    }
    
    virtual void accept(Folder * fp)
    {
        tab();
        cout << fp->name() << endl;
        ++_depth;
        for (auto i : fp->_items)
            i->visit(this);
        --_depth;
    }
private:
    int _depth;

    void tab()
    {
        for(int ii=0;ii<_depth;++ii)
            cout << "    ";
    }
};
#endif /* defined(__CS371Spring2014DesignPatterns__Visitor__) */
