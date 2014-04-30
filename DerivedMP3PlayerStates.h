//
//  DerivedMP3PlayerStates.h
//  CS394State
//
//  Created by Chris Hartman on 4/5/13.
//  Copyright (c) 2013 Chris Hartman. All rights reserved.
//

#ifndef __CS394State__DerivedMP3PlayerStates__
#define __CS394State__DerivedMP3PlayerStates__

#include "MP3PlayerState.h"

class StandByState : public MP3PlayerState
{
public:
    void pushPlay(MP3Player * _context) override;
    void pushSource(MP3Player * _context) override;
};

class PlayingState : public MP3PlayerState
{
public:
    void pushPlay(MP3Player * _context) override;
    void pushSource(MP3Player * _context) override;
};

class PausedState : public MP3PlayerState
{
public:
    void pushPlay(MP3Player * _context) override;
    void pushSource(MP3Player * _context) override;
};

class RadioState : public MP3PlayerState
{
public:
    void pushPlay(MP3Player * _context) override;
    void pushSource(MP3Player * _context) override;
};
#endif /* defined(__CS394State__DerivedMP3PlayerStates__) */
