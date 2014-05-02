//
//  Handler.h
//  CS371Spring2014DesignPatterns
//
//  Created by Chris Hartman on 4/21/14.
//  Copyright (c) 2014 Chris Hartman. All rights reserved.
//

#ifndef __CS371Spring2014DesignPatterns__Handler__
#define __CS371Spring2014DesignPatterns__Handler__

#include <iostream>
using std::cout;
#include <memory>
using std::unique_ptr;
using std::move;

class Handler
{
public:
    virtual ~Handler()
    {}
    virtual void printNumber(int n) = 0;
    void setNextHandler(unique_ptr<Handler> nh)
    {
        _nextHandler = move(nh);
    }
    void passItOn(int n)
    {
        if(_nextHandler)
            _nextHandler->printNumber(n);
    }
private:
    unique_ptr<Handler> _nextHandler;
};

class FizzBuzz : public Handler
{
    virtual void printNumber(int n)
    {
    if(n%15==0)
        cout << "FizzBuzz\n";
    else
        passItOn(n);
    }
};

class Fizz : public Handler
{
    virtual void printNumber(int n)
    {
        if(n%3==0)
            cout << "Fizz\n";
        else
            passItOn(n);
    }
};

class Buzz : public Handler
{
    virtual void printNumber(int n)
    {
        if(n%5==0)
            cout << "Buzz\n";
        else
            passItOn(n);
    }
};

class FizzyNumber : public Handler
{
    virtual void printNumber(int n)
    {
        cout << n << "\n";
    }
};
#endif /* defined(__CS371Spring2014DesignPatterns__Handler__) */
