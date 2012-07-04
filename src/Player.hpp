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

  void addMedia(const char*);
  void createPlaylist(const char * = NULL);
  int current_idx;

protected:
  // Gestionnaire de signal : clic
  void on_click();
  void next();
  void stop();
  
private:
  void getCurrentMeta();
  void showMeta();

  // Widgets membres

  Gtk::Button button5;
  //Gtk::Button button3, button4, button5;

  Gtk::Label artist_lbl;
  Gtk::Label album_lbl;
  Gtk::Label title_lbl;

  Gtk::Button button1, button2, button3;
  Glib::RefPtr<Gdk::Pixbuf> pixbuf;
  Gtk::Image image;
  Gtk::Grid grid;

  char* metaTitle;
  char* metaArtist;
  char* metaAlbum;
};    

#endif
