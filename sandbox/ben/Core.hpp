#include <gtkmm/window.h>
#include <gtkmm/hvbox.h>
#include <gtkmm/button.h>
#include <gtkmm/label.h>

#include "Hello.hpp"
#include "Coucou.hpp"

class Core : public Gtk::Window
{
  public:

    Core();
		~Core();

  protected:

		void set_module(Glib::ustring data);

		Gtk::HBox hbox;
		Gtk::VBox menu;
		Gtk::Button button1;
		Gtk::Button button2;
		Gtk::Label label;
		Hello hello;
		Coucou coucou;
};
