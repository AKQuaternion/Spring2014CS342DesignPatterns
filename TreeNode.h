//
//  TreeNode.h
//  CS371Spring2014DesignPatterns
//
//  Created by Chris Hartman on 4/30/14.
//  Copyright (c) 2014 Chris Hartman. All rights reserved.
//

#ifndef __CS371Spring2014DesignPatterns__TreeNode__
#define __CS371Spring2014DesignPatterns__TreeNode__


#include <iostream>
using std::cout;
using std::endl;

class AbstractNode
{
public:
    virtual int size() const= 0;
    virtual AbstractNode * getLeft() =0;
    virtual AbstractNode * getRight() =0;
    virtual ~AbstractNode()
    {}
};

class NullNode : public AbstractNode
{
public:
    virtual int size() const override
    {
        return 0;
    }
    
    virtual AbstractNode * getLeft() override
    {
        return this;
    }
    
    virtual AbstractNode * getRight() override
    {
        return this;
    }
};

class Node : public AbstractNode
{
public:
    Node(int data, AbstractNode *left=new NullNode, AbstractNode *right=new NullNode):_data(data),_left(left),_right(right)
    {}
    
    virtual int size() const override
    {
        return 1+_left->size()+_right->size();
    }
    
    virtual AbstractNode * getLeft() override
    {
        return _left;
    }
    
    virtual AbstractNode * getRight() override
    {
        return _right;
    }
    
    virtual ~Node()
    {
        delete _left;
        delete _right;
    }
    
private:
    int _data;
    AbstractNode * _left;
    AbstractNode * _right;
};

#endif /* defined(__CS371Spring2014DesignPatterns__TreeNode__) */
