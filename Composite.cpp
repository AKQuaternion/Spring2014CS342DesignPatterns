//
//  Composite.cpp
//  CS371Spring2014DesignPatterns
//
//  Created by Chris Hartman on 4/28/14.
//  Copyright (c) 2014 Chris Hartman. All rights reserved.
//

#include "Composite.h"
#include "Visitor.h"

void Folder::visit(Visitor *vp)
{
    vp->accept(this);
}

void File::visit(Visitor *vp)
{
    vp->accept(this);
}
