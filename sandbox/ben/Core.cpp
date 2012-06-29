#include "Core.hpp"

Core::Core() : hbox(false,10),menu(true,5),button1("Hello"),button2("Coucou"),hello(),coucou(),label("Accueil")
{
	set_default_size(300,512);
	set_border_width(20);
	set_decorated(false);
	set_has_resize_grip(false);

	button1.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this,&Core::set_module),"hello"));
	button2.signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this,&Core::set_module),"coucou"));

	menu.pack_start(button1);
	menu.pack_start(button2);

	hbox.pack_start(menu);
	hbox.pack_start(label);

	add(hbox);

	show_all_children();
}

void Core::set_module(Glib::ustring data)
{
	
	hbox.remove(*(hbox.get_children()[1]));

	if(hbox.get_children().size()==1) {

		if(data == "hello") {
			hbox.pack_start(hello);
		}
		else if(data == "coucou") {
			hbox.pack_start(coucou);
		}

	}

	show_all_children();
}

Core::~Core()
{
}
