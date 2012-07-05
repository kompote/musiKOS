#include "Player.hpp"
#include <iostream>


Player::Player() : Module()
{
  add(pm);
  show_all_children();

}



Player::~Player()
{

}
