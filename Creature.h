//
//  Creature.h
//  CS371Spring2014DesignPatterns
//
//  Created by Chris Hartman on 3/31/14.
//  Copyright (c) 2014 Chris Hartman. All rights reserved.
//

#ifndef CS371Spring2014DesignPatterns_Creature_h
#define CS371Spring2014DesignPatterns_Creature_h

#include <string>
using std::string;
#include <iostream>
using std::cout;
using std::endl;
#include <memory>
using std::make_shared;
using std::shared_ptr;

class Creature;

class FoodBehavior
{
public:
    virtual ~FoodBehavior() = default;
    virtual void lookForFood(Creature *) = 0;
protected:
    void setMyHealth(Creature *c, int delta);
};

class Creature
{
    friend class FoodBehavior;
public:
    Creature(shared_ptr<FoodBehavior> fb):_foodBehavior(fb)
    {}
    
    virtual ~Creature() = default;
    void lookForFood()
    {
        _foodBehavior->lookForFood(this);
    }
    void setFoodBehavior(shared_ptr<FoodBehavior> fb)
    {
        _foodBehavior= fb;
    }
    virtual void jump() = 0;
private:
    shared_ptr<FoodBehavior> _foodBehavior;
    int _health;
};

void FoodBehavior::setMyHealth(Creature *c, int delta)
{
    c->_health += delta;
}

class LookForGrass : public FoodBehavior
{
public:
    virtual void lookForFood(Creature *me) override
    {
        cout << "Looking for grass." << endl;
        setMyHealth(me,1);
    }
};

class LookForCows : public FoodBehavior
{
public:
    virtual void lookForFood(Creature *me) override
    {
        cout << "Looking for cows." << endl;
        setMyHealth(me,10);
    }
};

class Cow : public Creature
{
public:
    using Creature::Creature;
    virtual void jump() override
    {}
};

class Goat : public Creature
{
public:
    using Creature::Creature;
    virtual void jump() override
    {
        cout << "boing" << endl;
    }

};

class Troll : public Creature
{
public:
    using Creature::Creature;
    
    virtual void jump() override
    {
        cout << "SHOCKWAVE!!!" << endl;
    }

};


#endif
