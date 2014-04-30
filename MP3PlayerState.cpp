//
//  MP3PlayerState.cpp
//  CS394State
//
//  Created by Chris Hartman on 4/5/13.
//  Copyright (c) 2013 Chris Hartman. All rights reserved.
//

#include "MP3Player.h"
#include <utility>

void MP3PlayerState::setState(MP3Player *player, unique_ptr<MP3PlayerState> &&s)
{
    player->setState(std::move(s));
}

void MP3PlayerState::changeRadioStation(MP3Player *player )
{
    player->changeRadioStation();   
}

void MP3PlayerState::playMP3(MP3Player *player )
{
    player->playMP3();
}

void MP3PlayerState::stopMP3(MP3Player *player )
{
    player->stopMP3();
}
