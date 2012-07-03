#ifndef PLAYER_H
#define PLAYER_H


#include <gtkmm.h>
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
  
private:
  // Widgets membres
  Gtk::Button button1;
  Gtk::Button button2;
  Gtk::Button button3, button4, button5;
  Gtk::Grid grid;


};    

#endif
