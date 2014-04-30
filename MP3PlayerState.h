//
//  MP3PlayerState.h
//  CS394State
//
//  Created by Chris Hartman on 4/1/13.
//  Copyright (c) 2013 Chris Hartman. All rights reserved.
//

#ifndef __CS394State__MP3PlayerState__
#define __CS394State__MP3PlayerState__

#include <memory>
using std::unique_ptr;

class MP3Player;

class MP3PlayerState
{
public:
    virtual ~MP3PlayerState()
    {}
    virtual void pushPlay(MP3Player * _context)=0;
    virtual void pushSource(MP3Player * _context)=0;
protected:
    void setState(MP3Player *player, unique_ptr<MP3PlayerState> &&s);    
    void changeRadioStation(MP3Player *player );
    void playMP3(MP3Player *player );
    void stopMP3(MP3Player *player );

private:
};


#endif /* defined(__CS394State__MP3PlayerState__) */
