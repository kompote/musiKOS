#include "Module.hpp"
#include <gtkmm/scrolledwindow.h>
#include <gtkmm/hvbox.h>
#include <gtkmm/button.h>
#include <dirent.h>
#include <string>
#include <iostream>

class Audiotheque : public Module
{
	public:
		Audiotheque();
		~Audiotheque();
		enum depth{ARTIST,ALBUM,SONG};

	protected:
		Gtk::HBox hbox;
		Gtk::VBox* vbox;
		std::string dirpath;
		int currentDepth;

		void GetArtists();
		void GetAlbums(Glib::ustring artist);
		void GetSongs(Glib::ustring album);
};
