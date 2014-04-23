//
//  main.cpp
//  CS371Spring2014DesignPatterns
//
//  Created by Chris Hartman on 3/31/14.
//  Copyright (c) 2014 Chris Hartman. All rights reserved.
//

#include <iostream>
using std::cin;

#include <map>
using std::map;

#include "Creature.h"
#include "Expression.h"
#include "Observer.h"
#include "Decorator.h"
#include "Command.h"
#include "Handler.h"

template<typename T, typename FB>
void testCreature()
{
    shared_ptr<Creature> name = make_shared<T>(make_shared<FB>());
    name->lookForFood();
    name->jump();
}

void doCreatures()
{
    testCreature<Cow,LookForGrass>();
    testCreature<Goat,LookForGrass>();
    testCreature<Troll,LookForCows>();
    
    shared_ptr<Creature> funnyTroll = make_shared<Troll>(make_shared<LookForCows>());
    funnyTroll->lookForFood();
    funnyTroll->setFoodBehavior(make_shared<LookForGrass>());
    funnyTroll->lookForFood();
    funnyTroll->jump();
}

void testExpression()
{
    
    /*
     E : E + T | E – T | T
     T : T * P | T / P | P
     P : (E) | -P | [number] | [variable]
     */
    
    auto n1 = make_shared<Number>(17.3);
    auto n2 = make_shared<Number>(4.3);
    
    
    shared_ptr<Term> prod = make_shared<ProdTerm>(n1,n1);
    
    
    shared_ptr<Primary> pp=make_shared<ParenthesizedPrimary>(prod);
    shared_ptr<Primary> mpp = make_shared<NegativePrimary>(pp);
    shared_ptr<Expression> sum = make_shared<SumExpression>(n2,mpp);
    
    cout << sum->print() << "=" << sum->eval(map<string,double>()) << endl;
    
    auto z = make_shared<Variable>("z");
    
    shared_ptr<Expression> big = make_shared<DifferenceExpression>(sum,z);
    
    map<string,double> values;
    values["z"] = -294.99;
    cout << big->print() << "=" << big->eval(values) << endl;
    
    values["z"] = 1000000;
    cout << big->print() << "=" << big->eval(values) << endl;
}

void testObserver()
{
    Thermometer t;
    // Observer * obs = getObserver();
    BarGraph bStar('*');
    BarGraph bCarat('^');
    
    Announcer a;
    
    t.attach(&a);
    t.attach(&bStar);
    
    t.temperatureHasChanged(13.3);
    
    cout << endl;
    t.attach(&bCarat);
    t.detach(&bStar);
    t.temperatureHasChanged(300.2);
}

template<typename T, typename ...Args>
std::unique_ptr<T> make_unique( Args&& ...args )
{
    return std::unique_ptr<T>( new T( std::forward<Args>(args)... ) );
}

void testDecorator()
{
    unique_ptr<Armor> p = make_unique<Plate>();
    cout << p->name() << endl;
    
    unique_ptr<Armor> mp = make_unique<MagicDecorator>(std::move(p));
    cout << mp->name() << endl;
    
    unique_ptr<Armor> rmp = make_unique<RustyDecorator>(std::move(mp));
    cout << rmp->name() << endl;
    

}

void testCommand()
{
    Fan f;
    Light l;
    
    Switched * tv = new SwitchedTV;
    
    tv->on();
    
    map<int,shared_ptr<Command>> remote;
    
    remote[0] = make_shared<HelloCommand>();
    remote[1] = make_shared<ToggleSwitchCommand>(f);
    remote[2] = make_shared<ToggleSwitchCommand>(l);
    remote[3] =
    make_shared<MacroCommand>(
                    std::initializer_list<shared_ptr<Command>>{remote[0],remote[1],remote[2]});
    remote[4] =
    make_shared<MacroCommand>(
                              std::initializer_list<shared_ptr<Command>>{remote[3],remote[0],remote[0]});

    
    // remote[5] = make_shared<AnyCommand>(&f.off());
    
    remote[5] = make_shared<AnyCommand>([](){cout << "Goodbye\n";});
    
    int choice;
    cout << "Push a button: ";
    while(cin >> choice)
    {
        remote.at(choice)->execute();
        cout << "Push a button: ";
    }
}

int main(int argc, const char * argv[])
{
    unique_ptr<Handler> fb = make_unique<FizzBuzz>();
    unique_ptr<Handler> f = make_unique<Fizz>();
    unique_ptr<Handler> b = make_unique<Buzz>();
    unique_ptr<Handler> n = make_unique<FizzyNumber>();
    
    b->setNextHandler(move(n));
    f->setNextHandler(move(b));
    fb->setNextHandler(move(f));
    
    for(int ii=0;ii<50;++ii)
        fb->printNumber(ii);
    return 0;
}

