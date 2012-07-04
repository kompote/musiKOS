#include "Player.hpp"
#include <iostream>


libvlc_instance_t *inst;
libvlc_media_player_t *mp;
libvlc_media_list_player_t *mlp;
libvlc_media_list_t *playlist;
libvlc_media_t *m; 


Player::Player() : Module(), button5("Play"), artist_lbl("None"), album_lbl("None"), title_lbl("None"), button1("Stop"), button2("Next")
{
  current_idx = 0;

  button5.signal_clicked().connect(sigc::mem_fun(*this,&Player::on_click));
  button1.signal_clicked().connect(sigc::mem_fun(*this,&Player::stop));
  button2.signal_clicked().connect(sigc::mem_fun(*this,&Player::next));
  
  pixbuf = Gdk::Pixbuf::create_from_file("images/gorillaz.jpg",300,300,true);
  image.set(pixbuf);
  add(grid);

  artist_lbl.set_size_request(624,-1);

  grid.attach(artist_lbl,0,0,2,1);
  grid.attach(album_lbl,0,1,2,1);
  grid.attach(title_lbl,0,2,2,1);
  grid.attach(image,2,0,3,3);
  grid.attach(button5,0,3,5,1);
  grid.attach(button1,0,4,5,1);
  grid.attach(button2,0,5,5,1);


  show_all_children();


  /* VLC init */

  inst = libvlc_new (0, NULL);
  mlp = libvlc_media_list_player_new(inst);
  createPlaylist();
  addMedia("test.mp3");
  addMedia("rhcp_st.mp3");
}

void Player::next() {

 libvlc_media_list_player_next(mlp);
 current_idx++;
 getCurrentMeta();
 showMeta();

}

void Player::getCurrentMeta() {
  printf("getCurrentMeta in\n");
  libvlc_media_t *mm; 

  mm = libvlc_media_list_item_at_index(playlist,current_idx);
  //  printf("getCurrentMeta 2: %s\n", mm);

  libvlc_media_parse(mm);
  metaTitle       = libvlc_media_get_meta(mm, libvlc_meta_Title      );
  metaArtist      = libvlc_media_get_meta(mm, libvlc_meta_Artist     );
  metaAlbum      = libvlc_media_get_meta(mm, libvlc_meta_Album     );
  libvlc_media_release (mm);
  printf("getCurrentMeta: %s  -> %s - %s ----- index %d\n",metaTitle,metaAlbum, metaArtist,current_idx);
  printf("getCurrentMeta out\n");
}

void Player::showMeta() {
  printf("showMeta\n");
  if ( !metaArtist)
    artist_lbl.set_text("Inconnu");
  else
    artist_lbl.set_text(metaArtist);
  if (!metaAlbum)
    album_lbl.set_text("Inconnu");
  else
    album_lbl.set_text(metaAlbum);
  if (!metaTitle)
    title_lbl.set_text("Inconnu");
  else
    title_lbl.set_text(metaTitle);

}

void Player::addMedia(const char *s) {

  m=libvlc_media_new_path (inst,s );

  libvlc_media_parse(m);
  char * t       = libvlc_media_get_meta(m, libvlc_meta_Title      );
  char * ar     = libvlc_media_get_meta(m, libvlc_meta_Artist     );
  char * al      = libvlc_media_get_meta(m, libvlc_meta_Album     );

  printf("Add: %s  -> %s - %s\n",ar,al,t);

  libvlc_media_list_add_media(playlist,m);
  libvlc_media_release (m);
}

void Player::createPlaylist(const char *) {

  playlist = libvlc_media_list_new(inst);


  libvlc_media_list_player_set_media_list(mlp,playlist);


}

void Player::on_click()
{

  libvlc_media_list_player_play (mlp);
  getCurrentMeta();
  showMeta();
    
}

void Player::stop() {

 libvlc_media_list_player_stop(mlp);

}


Player::~Player()
{

  //   libvlc_media_player_release (mp);
  //  libvlc_release (inst);

}
