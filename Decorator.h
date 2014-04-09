//
//  Decorator.h
//  CS371Spring2014DesignPatterns
//
//  Created by Chris Hartman on 4/9/14.
//  Copyright (c) 2014 Chris Hartman. All rights reserved.
//

#ifndef __CS371Spring2014DesignPatterns__Decorator__
#define __CS371Spring2014DesignPatterns__Decorator__

#include <iostream>
#include <memory>
using std::unique_ptr;

#include <string>
using std::string;

class Armor
{
public:
    virtual ~Armor()
    {}
    
    virtual string name()const=0;
private:
};

class Plate : public Armor
{
public:
    virtual string name() const override
    {
        return "Plate";
    }
};

class Decorator : public Armor
{
public:
    Decorator(unique_ptr<Armor> armor) : _armor(std::move(armor))
    {}
    
    virtual string name() const override
    {
        return _armor->name();
    }
private:
    unique_ptr<Armor> _armor;
};

class MagicDecorator : public Decorator
{
public:
    using Decorator::Decorator;
    virtual string name() const override
    {
        return "Magic " + Decorator::name();
    }
private:
};

class RustyDecorator : public Decorator
{
public:
    using Decorator::Decorator;
    virtual string name() const override
    {
        return "Rusty " + Decorator::name();
    }
private:
};
#endif /* defined(__CS371Spring2014DesignPatterns__Decorator__) */
