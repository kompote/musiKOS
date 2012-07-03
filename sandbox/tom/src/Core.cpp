#include "Core.hpp"

Core::Core() : hbox(false,10),menu(true,5),label("Accueil")
{
	set_default_size(1024,600);
	set_border_width(20);
	set_decorated(false);
	set_has_resize_grip(false);

	label.set_size_request(900,600);

	LoadModules();
	cout << "Modules loaded" << endl;

	LoadMenu();
	cout << "Menu loaded" << endl;

	hbox.pack_start(menu);
	hbox.pack_start(label);

	add(hbox);

	show_all_children();
}

void Core::LoadModules()
{
	ifstream liste("modules.list",ios::in);

	if(liste) {
		string moduleName;
		Module* newModule;
		while(getline(liste,moduleName)) {
			newModule = ModuleFactory::Create(moduleName);
			if(newModule)
				modules.insert(pair<string,Module*>(moduleName,newModule));
			else
				cout << "Impossible de charger le module " << moduleName << endl;
		}
		liste.close();
	}
	else {
		cout << "Impossible de charger les modules\n" << endl;
		exit(EXIT_FAILURE);
	}
}

void Core::LoadMenu()
{
	std::map<string,Module*>::iterator it = modules.begin();
	Gtk::Button* button;

	while(it != modules.end()) {
		button = new Gtk::Button(it->first);
		button->signal_clicked().connect(sigc::bind<Glib::ustring>(sigc::mem_fun(*this,&Core::SetModule),it->first));
		menu.pack_start(*button,Gtk::PACK_EXPAND_PADDING);
		it++;
	}
}

void Core::SetModule(Glib::ustring data)
{
	
	hbox.remove(*(hbox.get_children()[1]));

	if(hbox.get_children().size()==1) {
		hbox.pack_start(*modules[data]);
	}

	show_all_children();
}

Core::~Core()
{
}
