//
//  MP3Player.cpp
//  CS394State
//
//  Created by Chris Hartman on 4/1/13.
//  Copyright (c) 2013 Chris Hartman. All rights reserved.
//

#include "MP3Player.h"
#include <iostream>
using std::cout;

MP3Player::MP3Player(unique_ptr<MP3PlayerState> state):_state(std::move(state))
{}

void MP3Player::pushPlayButton()
{
    _state->pushPlay(this);
}

void MP3Player::pushSourceButton()
{
    _state->pushSource(this);
}

void MP3Player::setState(unique_ptr<MP3PlayerState> s)
{
    _state = std::move(s);
}

void MP3Player::changeRadioStation()
{
    cout << "Changing radio station\n";
}

void MP3Player::playMP3()
{
    cout << "Playing MP3\n";
}

void MP3Player::stopMP3()
{
    cout << "Stopping MP3\n";
}
