#ifndef PLAYER_H
#define PLAYER_H


#include <gtkmm.h>
#include "Module.hpp"
#include "PlayerPlaylist.hpp"
#include <vlc/vlc.h>

class Player : public Module
{
  public:
    Player();
    ~Player();

  void addMedia(const char*);
  void createPlaylist(const char * = NULL);
  int current_idx;
  int playlist_size;
  static void vlcEvent(const libvlc_event_t* event, Player* miaou);

protected:
  // Gestionnaire de signal : clic
  void play();
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

  PlayerPlaylist playlist_view;

  //  Gtk::Label test1,test2,test3,test4,test5,test6,test7,test8,test9,test10;


  Gtk::Button button1, button2, button3;
  
  //  Gtk::TreeViewColumn tvc;
  // Gtk::CellRendererText crt;

  //  Gtk::Layout layout;

  Glib::RefPtr<Gdk::Pixbuf> pixbuf;
  Gtk::Image image;
  Gtk::Grid grid;
  

  char* metaTitle;
  char* metaArtist;
  char* metaAlbum;
};    

#endif
