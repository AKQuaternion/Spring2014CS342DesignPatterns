//
//  Observer.h
//  CS371Spring2014DesignPatterns
//
//  Created by Chris Hartman on 4/7/14.
//  Copyright (c) 2014 Chris Hartman. All rights reserved.
//

#ifndef __CS371Spring2014DesignPatterns__Observer__
#define __CS371Spring2014DesignPatterns__Observer__

#include <iostream>
using std::cout;
using std::endl;

#include <vector>
using std::vector;

#include <algorithm>
using std::remove;

class Observer
{
public:
    virtual ~Observer()
    {}
    virtual void update(double d)=0;
private:
};


class BarGraph : public Observer
{
public:
    BarGraph(char c):_c(c)
    {}
    
    virtual void update(double d)
    {
        for(int ii=0;ii<d;++ii)
            cout << _c;
        cout << endl;
    }
private:
    char _c;
};

class Announcer : public Observer
{
public:
    virtual void update(double d)
    {
        cout << "The new value is " << d << "!!!!" << endl;
    }
};

class Subject
{
public:
    virtual ~Subject()
    {}
    void attach(Observer *o)
    {
        _observers.push_back(o);
    }
    void detach(Observer *o)
    {
        _observers.erase(remove(_observers.begin(),_observers.end(),o));
    }
    //double getState();
    void setState(double d)
    {
        for(auto o : _observers)
            o->update(d);
    }
    
private:
    vector<Observer *> _observers;
    
};

class Thermometer : public Subject
{
public:
    void temperatureHasChanged(double d)
    {
        _currentTemperature = d;
        setState(d);
    }
private:
    double _currentTemperature;
};


#endif /* defined(__CS371Spring2014DesignPatterns__Observer__) */
