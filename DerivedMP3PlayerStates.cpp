//
//  DerivedMP3PlayerStates.cpp
//  CS394State
//
//  Created by Chris Hartman on 4/5/13.
//  Copyright (c) 2013 Chris Hartman. All rights reserved.
//

#include "DerivedMP3PlayerStates.h"
#include "MP3Player.h"
#include "make_unique.h"

void StandByState::pushPlay(MP3Player * context){
    // Do nothing
}

void StandByState::pushSource(MP3Player * context){
    playMP3(context);
    setState(context, make_unique<PlayingState>());
}

void PlayingState::pushPlay(MP3Player * context){
    stopMP3(context);
    setState(context,make_unique<PausedState>());
}

void PlayingState::pushSource(MP3Player * context){
    stopMP3(context);
    setState(context,make_unique<RadioState>());
}

void PausedState::pushPlay(MP3Player * context){
    playMP3(context);
    setState(context,make_unique<PlayingState>());
}

void PausedState::pushSource(MP3Player * context){
    setState(context,make_unique<RadioState>());
}

void RadioState::pushPlay(MP3Player * context){
    changeRadioStation(context);
}

void RadioState::pushSource(MP3Player * context){
    setState(context,make_unique<StandByState>());
}