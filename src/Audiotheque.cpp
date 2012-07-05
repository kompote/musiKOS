#include "Audiotheque.hpp"

/*****************************************/
/***					CONSTRUCTEUR             ***/
/*****************************************/
Audiotheque::Audiotheque() : hbox(false,2)
{
	dirpath = "/home/k/Musique";
	currentDepth = ALBUM;

	GetArtists();
	hbox.pack_start(*vbox,Gtk::PACK_SHRINK);

	add(hbox);

	hbox.show();
}

/*****************************************/
/***				METHODE GetArtists       	 ***/
/*****************************************/
void Audiotheque::GetArtists()
{
	vbox = Gtk::manage(new Gtk::VBox(false,2));
	vbox->set_size_request(300,0);

	Gtk::Button* button;
	DIR* rep = opendir(dirpath.c_str());

	button = Gtk::manage(new Gtk::Button("Tous les artistes"));
	button->signal_clicked().connect(sigc::mem_fun(*this,&Audiotheque::GetAllAlbums));
	vbox->pack_start(*button,Gtk::PACK_SHRINK);

	if(rep!=NULL) {
		struct dirent* ent;
		std::string here = ".";
		std::string parent = "..";
		while((ent=readdir(rep))!=NULL) {
			if(here.compare(ent->d_name)!=0 && parent.compare(ent->d_name)!=0) {
				button = Gtk::manage(new Gtk::Button(ent->d_name));
				button->signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this,&Audiotheque::GetAlbums),ent->d_name));
				vbox->pack_start(*button,Gtk::PACK_SHRINK);
			}
		}
		closedir(rep);
	}
}


/*****************************************/
/***				METHODE GetAlbums       	 ***/
/*****************************************/
void Audiotheque::GetAlbums(Glib::ustring artist)
{
	std::vector<Gtk::Widget*> children = hbox.get_children();
	for(std::vector<Gtk::Widget*>::iterator it=children.begin()+1; it!=children.end(); it++)
		hbox.remove(**it);

	vbox = Gtk::manage(new Gtk::VBox(false,2));
	vbox->set_size_request(300,0);

	Gtk::Button* button;
	std::string path = dirpath+"/"+artist;
	DIR* rep = opendir(path.c_str());

	button = Gtk::manage(new Gtk::Button("Tous les albums"));
	button->signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this,&Audiotheque::GetAllSongsBy),artist));
	vbox->pack_start(*button,Gtk::PACK_SHRINK);

	if(rep!=NULL) {
		struct dirent* ent;
		std::string here = ".";
		std::string parent = "..";
		while((ent=readdir(rep))!=NULL) {
			if(here.compare(ent->d_name)!=0 && parent.compare(ent->d_name)!=0) {
				button = Gtk::manage(new Gtk::Button(ent->d_name));
				button->signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this,&Audiotheque::GetSongs),artist+"/"+ent->d_name));
				vbox->pack_start(*button,Gtk::PACK_SHRINK);
			}
		}
		closedir(rep);
	}	

	hbox.pack_start(*vbox,Gtk::PACK_SHRINK);

	hbox.show_all_children();
}


/*****************************************/
/***				METHODE GetAllAlbums    	 ***/
/*****************************************/
void Audiotheque::GetAllAlbums()
{
	std::vector<Gtk::Widget*> children = hbox.get_children();
	for(std::vector<Gtk::Widget*>::iterator it=children.begin()+1; it!=children.end(); it++)
		hbox.remove(**it);

	vbox = Gtk::manage(new Gtk::VBox(false,2));
	vbox->set_size_request(300,0);

	Gtk::Button* button;
	button = Gtk::manage(new Gtk::Button("Tous les albums"));
	button->signal_clicked().connect(sigc::mem_fun(*this,&Audiotheque::GetAllSongs));
	vbox->pack_start(*button,Gtk::PACK_SHRINK);

	DIR* rep = opendir(dirpath.c_str());

	if(rep!=NULL) {
		struct dirent* ent;
		std::string here = ".";
		std::string parent = "..";
		while((ent=readdir(rep))!=NULL) {
			if(here.compare(ent->d_name)!=0 && parent.compare(ent->d_name)!=0) {
				std::string subdirpath = dirpath+"/"+ent->d_name;
				DIR* subdir = opendir(subdirpath.c_str());
				if(subdir!=NULL) {
					struct dirent* subent;
					while((subent=readdir(subdir))!=NULL) {
						if(here.compare(subent->d_name)!=0 && parent.compare(subent->d_name)!=0) {
							button = Gtk::manage(new Gtk::Button(subent->d_name));
							std::string albumpath = ent->d_name;
							albumpath += "/";
							albumpath += subent->d_name;
							button->signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this,&Audiotheque::GetSongs),albumpath));
							vbox->pack_start(*button,Gtk::PACK_SHRINK);
						}
					}
					closedir(subdir);
				}
			}
		}
		closedir(rep);
	}	

	hbox.pack_start(*vbox,Gtk::PACK_SHRINK);

	hbox.show_all_children();
}

/*****************************************/
/***				METHODE GetSongs        	 ***/
/*****************************************/
void Audiotheque::GetSongs(Glib::ustring album)
{
	std::vector<Gtk::Widget*> children = hbox.get_children();
	for(std::vector<Gtk::Widget*>::iterator it=children.begin()+2; it!=children.end(); it++)
		hbox.remove(**it);
	
	libvlc_instance_t *inst;
	inst = libvlc_new (0, NULL);
	libvlc_media_t *media;

	vbox = Gtk::manage(new Gtk::VBox(false,2));
	vbox->set_size_request(300,0);

	Gtk::Button* button;
	std::string path = dirpath+"/"+album;
	DIR* rep = opendir(path.c_str());

	button = Gtk::manage(new Gtk::Button("Tout l'album"));
	vbox->pack_start(*button,Gtk::PACK_SHRINK);

	if(rep!=NULL) {
		struct dirent* ent;
		std::string here = ".";
		std::string parent = "..";
		while((ent=readdir(rep))!=NULL) {
			if(here.compare(ent->d_name)!=0 && parent.compare(ent->d_name)!=0) {
				std::string songpath = path+"/";
				songpath += ent->d_name;
				media = libvlc_media_new_path(inst,songpath.c_str());
  			libvlc_media_parse(media);
  			char* title = libvlc_media_get_meta(media,libvlc_meta_Title);
				button = Gtk::manage(new Gtk::Button(title));
				vbox->pack_start(*button,Gtk::PACK_SHRINK);
			}
		}
		closedir(rep);
	}	

	hbox.pack_start(*vbox,Gtk::PACK_SHRINK);

	hbox.show_all_children();
	
	free(media);
	free(inst);
}

/*****************************************/
/***		METHODE GetAllSongsBy       	 ***/
/*****************************************/
void Audiotheque::GetAllSongsBy(Glib::ustring artist)
{
	std::vector<Gtk::Widget*> children = hbox.get_children();
	for(std::vector<Gtk::Widget*>::iterator it=children.begin()+2; it!=children.end(); it++)
		hbox.remove(**it);
		
	libvlc_instance_t *inst;
	inst = libvlc_new (0, NULL);
	libvlc_media_t *media;

	vbox = Gtk::manage(new Gtk::VBox(false,2));
	vbox->set_size_request(300,0);

	Gtk::Button* button;
	std::string path = dirpath+"/"+artist;
	DIR* rep = opendir(path.c_str());

	button = Gtk::manage(new Gtk::Button("Tous les titres"));
	vbox->pack_start(*button,Gtk::PACK_SHRINK);

	if(rep!=NULL) {
		struct dirent* ent;
		std::string here = ".";
		std::string parent = "..";
		while((ent=readdir(rep))!=NULL) {
			if(here.compare(ent->d_name)!=0 && parent.compare(ent->d_name)!=0) {
				std::string subdirpath = path+"/"+ent->d_name;
				DIR* subdir = opendir(subdirpath.c_str());
				if(subdir!=NULL) {
					struct dirent* subent;
					while((subent=readdir(subdir))!=NULL) {
						if(here.compare(subent->d_name)!=0 && parent.compare(subent->d_name)!=0) {
							std::string songpath = subdirpath+"/";
							songpath += subent->d_name;
							media = libvlc_media_new_path(inst,songpath.c_str());
							libvlc_media_parse(media);
							char* title = libvlc_media_get_meta(media,libvlc_meta_Title);
							button = Gtk::manage(new Gtk::Button(title));
							vbox->pack_start(*button,Gtk::PACK_SHRINK);
						}
					}
					closedir(subdir);
				}
			}
		}
		closedir(rep);
	}	

	hbox.pack_start(*vbox,Gtk::PACK_SHRINK);

	hbox.show_all_children();
}


/*****************************************/
/***				METHODE GetAllSongs      	 ***/
/*****************************************/
void Audiotheque::GetAllSongs()
{
	std::vector<Gtk::Widget*> children = hbox.get_children();
	for(std::vector<Gtk::Widget*>::iterator it=children.begin()+2; it!=children.end(); it++)
		hbox.remove(**it);

	libvlc_instance_t *inst;
	inst = libvlc_new (0, NULL);
	libvlc_media_t *media;

	vbox = Gtk::manage(new Gtk::VBox(false,2));
	vbox->set_size_request(300,0);

	Gtk::Button* button;
	DIR* rep = opendir(dirpath.c_str());

	button = Gtk::manage(new Gtk::Button("Tous les titres"));
	vbox->pack_start(*button,Gtk::PACK_SHRINK);

	if(rep!=NULL) {
		struct dirent* ent;
		std::string here = ".";
		std::string parent = "..";
		while((ent=readdir(rep))!=NULL) 
		{
			if(here.compare(ent->d_name)!=0 && parent.compare(ent->d_name)!=0) 
			{
				std::string subdirpath = dirpath+"/"+ent->d_name;
				DIR* subdir = opendir(subdirpath.c_str());
				if(subdir!=NULL) 
				{
					struct dirent* subent;
					while((subent=readdir(subdir))!=NULL) 
					{
						if(here.compare(subent->d_name)!=0 && parent.compare(subent->d_name)!=0) 
						{
							std::string subsubdirpath = subdirpath+"/"+subent->d_name;
							DIR* subsubdir = opendir(subsubdirpath.c_str());
							if(subsubdir!=NULL) 
							{
								struct dirent* subsubent;
								while((subsubent=readdir(subsubdir))!=NULL) 
								{
									if(here.compare(subsubent->d_name)!=0 && parent.compare(subsubent->d_name)!=0) 
									{
										std::string songpath = subsubdirpath+"/";
										songpath += subsubent->d_name;
										media = libvlc_media_new_path(inst,songpath.c_str());
										libvlc_media_parse(media);
										char* title = libvlc_media_get_meta(media,libvlc_meta_Title);
										button = Gtk::manage(new Gtk::Button(title));
										vbox->pack_start(*button,Gtk::PACK_SHRINK);
									}		
								}
								closedir(subsubdir);
							}
						}
					}
					closedir(subdir);
				}
			}
		}
		closedir(rep);
	}	

	hbox.pack_start(*vbox,Gtk::PACK_SHRINK);

	hbox.show_all_children();
}

/*****************************************/
/***				DESTRUCTEUR				       	 ***/
/*****************************************/
Audiotheque::~Audiotheque()
{
}
