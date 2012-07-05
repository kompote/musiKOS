#include "Core.hpp"
#include <gtkmm/application.h>
#include <gtkmm/stylecontext.h>
#include <gtkmm/cssprovider.h>

int main(int argc, char* argv[])
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv, "org.musikos");

	/*Glib::RefPtr<Gtk::CssProvider> css = Gtk::CssProvider::create();
	if(!css->load_from_path("/home/k/.themes/Mint-Z Improved/gtk-3.0/gtk-widgets.css"))
		std::cout << "Erreur de chargement du CSS" << std::endl;*/

  Core core;

	/*Glib::RefPtr<Gtk::StyleContext> cxt = core.get_style_context();
	cxt->add_provider(css,0);

	core.reset_style();*/

	std::cout << "Core OK" << std::endl;

	return app->run(core);
}
