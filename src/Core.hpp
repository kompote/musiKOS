#include <gtkmm/window.h>
#include <gtkmm/hvbox.h>
#include <gtkmm/fixed.h>
#include <gtkmm/button.h>
#include <gtkmm/label.h>
#include <string>
#include <fstream>
#include <iostream>
#include <cstdlib>
#include <map>

#include "ModuleFactory.hpp"

using namespace std;

class Core : public Gtk::Window
{
  public:

    Core();
		~Core();

  protected:

		void SetModule(Glib::ustring data);
		void LoadModules(void);
		void LoadMenu(void);

		Gtk::Fixed container;
		Gtk::VBox menu;
		Gtk::Label label;
		std::map<string,Module*> modules;
		Module* currentModule;
};
