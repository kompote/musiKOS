#include "Player.hpp"
#include <iostream>


// libvlc_instance_t *inst;
// libvlc_media_player_t *mp;
// libvlc_media_t *m; 


Player::Player() : Module(), button1("artist"), button2("album"), button3("titre"), button4("image"), button5("Playlist")
{


  add(grid);
  grid.attach(button1,0,0,2,1);
  grid.attach(button2,0,1,2,1);
  grid.attach(button3,0,2,2,1);
  grid.attach(button4,2,0,3,3);
  grid.attach(button5,0,3,5,5);
  show_all_children();


  // inst = libvlc_new (0, NULL);
  // m=libvlc_media_new_path (inst, "test.mp3");
  // mp = libvlc_media_player_new_from_media (m);
  // libvlc_media_release (m);
}


void Player::on_click()
{

  std::cout << "Player les gens !" << std::endl;
  
  
  //libvlc_media_player_play (mp);
    
  //  sleep (10); 

  // libvlc_media_player_stop (mp);
 

}

Player::~Player()
{

  //   libvlc_media_player_release (mp);
  //  libvlc_release (inst);

}
