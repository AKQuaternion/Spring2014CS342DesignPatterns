//
//  MP3Player.h
//  CS394State
//
//  Created by Chris Hartman on 4/1/13.
//  Copyright (c) 2013 Chris Hartman. All rights reserved.
//

#ifndef __CS394State__MP3Player__
#define __CS394State__MP3Player__

#include "MP3PlayerState.h"
#include <memory>
using std::unique_ptr;

class MP3Player
{
    friend class MP3PlayerState;
    
public:

    MP3Player(unique_ptr<MP3PlayerState> state);
    void pushPlayButton();
    void pushSourceButton();

private:
    void setState(unique_ptr<MP3PlayerState> );
    void changeRadioStation();
    void playMP3();
    void stopMP3();
    
    unique_ptr<MP3PlayerState> _state;
};
#endif /* defined(__CS394State__MP3Player__) */
