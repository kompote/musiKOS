#ifndef PLAYER_H
#define PLAYER_H


#include <gtkmm.h>
#include "Module.hpp"
#include "PlayerMain.hpp"
//#include <vlc/vlc.h>

class Player : public Module
{
  public:
    Player();
    ~Player();

protected:
  PlayerMain pm;
private:

};    

#endif
