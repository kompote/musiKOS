#include "Audiotheque.hpp"

Audiotheque::Audiotheque() : hbox(true,2)
{
	dirpath = "/home/k/Musique";
	currentDepth = ALBUM;

	GetArtists();
	hbox.pack_start(*vbox);

	vbox = Gtk::manage(new Gtk::VBox(2,true));
	vbox->set_size_request(300,-1);
	hbox.pack_start(*vbox);

	vbox = Gtk::manage(new Gtk::VBox(2,true));
	vbox->set_size_request(300,-1);
	hbox.pack_start(*vbox);

	add(hbox);

	hbox.show();
}

void Audiotheque::GetArtists()
{
	vbox = Gtk::manage(new Gtk::VBox(2,true));
	vbox->set_size_request(300,-1);

	Gtk::Button* button;
	DIR* rep = opendir(dirpath.c_str());

	button = Gtk::manage(new Gtk::Button("Tous"));
	vbox->add(*button);

	if(rep!=NULL) {
		struct dirent* ent;
		std::string here = ".";
		std::string parent = "..";
		while((ent=readdir(rep))!=NULL) {
			if(here.compare(ent->d_name)!=0 && parent.compare(ent->d_name)!=0) {
				button = Gtk::manage(new Gtk::Button(ent->d_name));
				button->signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this,&Audiotheque::GetAlbums),ent->d_name));
				vbox->add(*button);
			}
		}
		closedir(rep);
	}
}

void Audiotheque::GetAlbums(Glib::ustring artist)
{
	std::vector<Gtk::Widget*> children = hbox.get_children();
	for(std::vector<Gtk::Widget*>::iterator it=children.begin()+1; it!=children.end(); it++)
		hbox.remove(**it);

	vbox = Gtk::manage(new Gtk::VBox(2,true));
	vbox->set_size_request(300,-1);

	Gtk::Button* button;
	std::string path = dirpath+"/"+artist;
	DIR* rep = opendir(path.c_str());

	button = Gtk::manage(new Gtk::Button("Tous"));
	vbox->add(*button);

	if(rep!=NULL) {
		struct dirent* ent;
		std::string here = ".";
		std::string parent = "..";
		while((ent=readdir(rep))!=NULL) {
			if(here.compare(ent->d_name)!=0 && parent.compare(ent->d_name)!=0) {
				button = Gtk::manage(new Gtk::Button(ent->d_name));
				button->signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this,&Audiotheque::GetSongs),artist+"/"+ent->d_name));
				vbox->add(*button);
			}
		}
		closedir(rep);
	}	

	hbox.pack_start(*vbox);

	vbox = Gtk::manage(new Gtk::VBox(2,true));
	vbox->set_size_request(300,-1);
	hbox.pack_start(*vbox);

	hbox.show_all_children();
}

void Audiotheque::GetSongs(Glib::ustring album)
{
	std::vector<Gtk::Widget*> children = hbox.get_children();
	for(std::vector<Gtk::Widget*>::iterator it=children.begin()+2; it!=children.end(); it++)
		hbox.remove(**it);

	vbox = Gtk::manage(new Gtk::VBox(2,true));
	vbox->set_size_request(300,-1);

	Gtk::Button* button;
	std::string path = dirpath+"/"+album;
	DIR* rep = opendir(path.c_str());

	button = Gtk::manage(new Gtk::Button("Tous"));
	vbox->add(*button);

	if(rep!=NULL) {
		struct dirent* ent;
		std::string here = ".";
		std::string parent = "..";
		while((ent=readdir(rep))!=NULL) {
			if(here.compare(ent->d_name)!=0 && parent.compare(ent->d_name)!=0) {
				button = Gtk::manage(new Gtk::Button(ent->d_name));
				//button->signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this,&Audiotheque::GetSongs),artist+"/"+ent->d_name));
				vbox->add(*button);
			}
		}
		closedir(rep);
	}	

	hbox.pack_start(*vbox);

	hbox.show_all_children();
}

Audiotheque::~Audiotheque()
{
}
