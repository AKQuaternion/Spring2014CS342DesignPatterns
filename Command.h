//
//  Command.h
//  CS371Spring2014DesignPatterns
//
//  Created by Chris Hartman on 4/16/14.
//  Copyright (c) 2014 Chris Hartman. All rights reserved.
//

#ifndef __CS371Spring2014DesignPatterns__Command__
#define __CS371Spring2014DesignPatterns__Command__

#include <iostream>
using std::cout;
#include <vector>
using std::vector;
#include <memory>
using std::shared_ptr;
#include <functional>
using std::function;

class Command
{
public:
    virtual ~Command(){}
    virtual void execute()=0;
private:
};

class HelloCommand : public Command
{
public:
    virtual void execute() override
    {
        cout << "Hello!\n";
    }
};

class Switched
{
public:
    virtual ~Switched(){};
    virtual void on() = 0;
    virtual void off() = 0;
};

class SwitchOnCommand : public Command
{
public:
    SwitchOnCommand(Switched &appliance):_appliance(appliance)
    {}
    
    virtual void execute() override
    {
        _appliance.on();
    }
private:
    Switched & _appliance;
};

class SwitchOffCommand : public Command
{
public:
    SwitchOffCommand(Switched &appliance):_appliance(appliance)
    {}
    
    virtual void execute() override
    {
        _appliance.off();
    }
private:
    Switched & _appliance;
};

class ToggleSwitchCommand : public Command
{
public:
    ToggleSwitchCommand(Switched &appliance):_isOn(false),_appliance(appliance)
    {}
    virtual void execute() override
    {
        if(_isOn)
        {
            _appliance.off();
            _isOn = false;
        }
        else
        {
            _appliance.on();
            _isOn = true;
        }
    }

private:
    bool _isOn;
    Switched & _appliance;
};

class Fan : public Switched
{
public:
    virtual void on() override
    {
        cout << "Fan is on\n";
    }
    virtual void off() override
    {
        cout << "Fan is off\n";
    }
};

class Light : public Switched
{
public:
    virtual void on() override
    {
        cout << "Light is on\n";
    }
    virtual void off() override
    {
        cout << "Light is off\n";
    }
};

class MacroCommand : public Command
{
public:
    MacroCommand(std::vector<shared_ptr<Command>> commands)
       :_commands(commands)
    {}
    virtual void execute() override
    {
        for(auto c : _commands)
            c->execute();
    }
    
private:
    vector<shared_ptr<Command>> _commands;
};

class AnyCommand : public Command
{
public:
    AnyCommand(function<void ()> f):_f(f)
    {}
    
    virtual void execute() override
    {
        _f();
    }

private:
    function<void ()> _f;
};


class TV
{
public:
    void start()
    {
        cout << "TV turning on\n";
    }
    void stop()
    {
        cout << "TV turning off\n";
    }
};

class SwitchedTV: public Switched
{
public:
    virtual void on() override
    {
        _tv.start();
    }
    virtual void off() override
    {
        _tv.stop();
    }
private:
    TV _tv;
};

#endif /* defined(__CS371Spring2014DesignPatterns__Command__) */
