//
//  Composite.h
//  CS371Spring2014DesignPatterns
//
//  Created by Chris Hartman on 4/28/14.
//  Copyright (c) 2014 Chris Hartman. All rights reserved.
//

#ifndef __CS371Spring2014DesignPatterns__Composite__
#define __CS371Spring2014DesignPatterns__Composite__

#include <iostream>
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <memory>
using std::shared_ptr;

class Visitor;

class Composite
{
public:
    virtual ~Composite()
    {}
    virtual int size() = 0;
    virtual string name() = 0;
    virtual void visit(Visitor *)=0;
private:
};

class Folder : public Composite
{
public:
    Folder(const string &name) :_name(name)
    {
    }
    
    virtual void visit(Visitor *) override;
    
    virtual string name() override
    {
        return _name;
    }
    
    virtual int size() override
    {
        int total=0;
        for(auto i : _items)
            total += i->size();
        return total;
    }
    
    void add_item(shared_ptr<Composite> i)
    {
        _items.push_back(i);
    }
    
private:
    string _name;
public: //TODO fix access
    vector<shared_ptr<Composite>> _items;
};


class File : public Composite
{
public:
    File(const string &name, int size) :_name(name),_size(size)
    {
    }
    
    virtual void visit(Visitor *) override;
    virtual string name() override
    {
        return _name;
    }
    
    virtual int size() override
    {
        return _size;
    }
    
private:
    string _name;
    int _size;
};

#endif /* defined(__CS371Spring2014DesignPatterns__Composite__) */
