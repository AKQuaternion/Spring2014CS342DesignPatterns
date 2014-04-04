//
//  main.cpp
//  CS371Spring2014DesignPatterns
//
//  Created by Chris Hartman on 3/31/14.
//  Copyright (c) 2014 Chris Hartman. All rights reserved.
//

#include <iostream>
#include "Creature.h"
#include "Expression.h"

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

int main(int argc, const char * argv[])
{
    auto n1 = make_shared<Number>(17.3);
    auto n2 = make_shared<Number>(4.3);
    
    cout << n1->eval() << endl;
    
    shared_ptr<Term> prod = make_shared<ProdTerm>(n1,n1);

    cout << prod->eval() << endl;

    shared_ptr<Primary> pp=make_shared<ParenthesizedPrimary>(prod);
    shared_ptr<Primary> mpp = make_shared<NegativePrimary>(pp);
    shared_ptr<Expression> sum = make_shared<SumExpression>(n2,mpp);
    
    cout << sum->print() << "=" << sum->eval() << endl;
    
    return 0;
}


/*
 E : E + T | E – T | T
 T : T * P | T / P | P
 P : (E) | -P | [number] | [variable]
 */


