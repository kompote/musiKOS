#include "Player.hpp"
#include <iostream>


libvlc_instance_t *inst;
libvlc_media_player_t *mp;
libvlc_media_t *m; 


Player::Player() : Module(), button("Player les gens !")
{
  button.signal_clicked().connect(sigc::mem_fun(*this,&Player::on_click));

  add(button);

  button.show();

  inst = libvlc_new (0, NULL);
  m=libvlc_media_new_path (inst, "test.mp3");
  mp = libvlc_media_player_new_from_media (m);
  libvlc_media_release (m);
}


void Player::on_click()
{

  std::cout << "Player les gens !" << std::endl;
  
  
  libvlc_media_player_play (mp);
    
  sleep (10); 

  libvlc_media_player_stop (mp);
 

}

Player::~Player()
{

  libvlc_media_player_release (mp);
  libvlc_release (inst);

}
