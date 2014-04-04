//
//  Expression.h
//  CS371Spring2014DesignPatterns
//
//  Created by Chris Hartman on 4/2/14.
//  Copyright (c) 2014 Chris Hartman. All rights reserved.
//

#ifndef __CS371Spring2014DesignPatterns__Expression__
#define __CS371Spring2014DesignPatterns__Expression__

#include <iostream>
#include <memory>
using std::shared_ptr;
using std::make_shared;

/*
 E : E + T | E – T | T
 T : T * P | T / P | P
 P : (E) | -P | [number]
 */
#include <string>
using std::string;

class Expression
{
public:
    virtual ~Expression() = default;
    virtual double eval() const = 0;
    virtual string print() const = 0;
private:
};

class Term : public Expression
{
};

class SumExpression : public Expression
{
public:
    SumExpression(shared_ptr<Expression> e,shared_ptr<Term> t):_e(e),_t(t)
    {}
    
    virtual double eval() const override
    {
        return _e->eval() + _t->eval();
    }
    
    virtual string print() const override
    {
        return _e->print() + "+" + _t->print();
    }
    
private:
    shared_ptr<Expression> _e;
    shared_ptr<Term> _t;
};

class DifferenceExpression : public Expression
{
public:
    DifferenceExpression(shared_ptr<Expression> e,shared_ptr<Term> t):_e(e),_t(t)
    {}
    
    virtual double eval() const override
    {
        return _e->eval() - _t->eval();
    }
    
    virtual string print() const override
    {
        return _e->print() + "-" + _t->print();
    }
    
private:
    shared_ptr<Expression> _e;
    shared_ptr<Term> _t;
};

class Primary : public Term
{
};

class ProdTerm : public Term
{
public:
    ProdTerm(shared_ptr<Term> t,shared_ptr<Primary> p):_t(t),_p(p)
    {}
    
    virtual double eval() const override
    {
        return _t->eval() * _p->eval();
    }
    virtual string print() const override
    {
        return _t->print() + "*" + _p->print();
    }
    
private:
    shared_ptr<Term> _t;
    shared_ptr<Primary> _p;
};

class DivTerm : public Term
{
public:
    DivTerm(shared_ptr<Term> t,shared_ptr<Primary> p):_t(t),_p(p)
    {}
    
    virtual double eval() const override
    {
        return _t->eval() * _p->eval();
    }
    virtual string print() const override
    {
        return _t->print() + "*" + _p->print();
    }
    
private:
    shared_ptr<Term> _t;
    shared_ptr<Primary> _p;
};

class Number : public Primary
{
public:
    Number(double v):_val(v)
    {}
    
    virtual double eval() const override
    {
        return _val;
    }
 
    virtual string print() const override
    {
        return std::to_string(_val);
    }

private:
    double _val;
};

class ParenthesizedPrimary : public Primary
{
public:
    ParenthesizedPrimary(shared_ptr<Expression> e):_e(e)
    {}
    
    virtual double eval() const override
    {
        return _e->eval();
    }
    
    virtual string print() const override
    {
        return "(" + _e->print() + ")";
    }
    
private:
    shared_ptr<Expression> _e;
};

class NegativePrimary : public Primary
{
public:
    NegativePrimary(shared_ptr<Primary> p):_p(p)
    {}
    
    virtual double eval() const override
    {
        return -_p->eval();
    }
    
    virtual string print() const override
    {
        return "-" + _p->print();
    }
    
private:
    shared_ptr<Primary> _p;
};

#endif /* defined(__CS371Spring2014DesignPatterns__Expression__) */
