#include "Core.hpp"

Core::Core() : menu(true,5),label("Accueil")
{
	set_default_size(1024,600);
	set_border_width(0);
	set_decorated(false);
	set_has_resize_grip(false);

	label.set_size_request(950,600);

	LoadModules();
	cout << "Modules loaded" << endl;

	LoadMenu();
	cout << "Menu loaded" << endl;

	container.put(label,74,0);
	container.put(menu,0,100);

	add(container);

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
	menu.set_size_request(120,400);

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
	std::vector<Gtk::Widget*> children = container.get_children();
	for(std::vector<Gtk::Widget*>::iterator it=children.begin(); it!=children.end(); it++)
		container.remove(**it);

	container.put(*modules[data],74,0);
	container.put(menu,0,100);

	show_all_children();
	menu.show_all_children();
}

Core::~Core()
{
}
