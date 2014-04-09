//
//  main.cpp
//  CS371Spring2014DesignPatterns
//
//  Created by Chris Hartman on 3/31/14.
//  Copyright (c) 2014 Chris Hartman. All rights reserved.
//

#include <iostream>
#include <map>
using std::map;

#include "Creature.h"
#include "Expression.h"
#include "Observer.h"
#include "Decorator.h"

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

int main(int argc, const char * argv[])
{
    unique_ptr<Armor> p = make_unique<Plate>();
    cout << p->name() << endl;
    
    unique_ptr<Armor> mp = make_unique<MagicDecorator>(std::move(p));
    cout << mp->name() << endl;
    
    unique_ptr<Armor> rmp = make_unique<RustyDecorator>(std::move(mp));
    cout << rmp->name() << endl;
    
    return 0;
}



