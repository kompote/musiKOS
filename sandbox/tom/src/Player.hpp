#ifndef PLAYER_H
#define PLAYER_H

#include <gtkmm/button.h>
#include "Module.hpp"
#include <vlc/vlc.h>

class Player : public Module
{
  public:
    Player();
    ~Player();

  protected:
    // Gestionnaire de signal : clic
    void on_click();
    
    // Widgets membres
    Gtk::Button button;

private:

  
  //

};    

#endif
