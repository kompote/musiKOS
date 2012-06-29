#include "Core.hpp"
#include <gtkmm/application.h>

int main(int argc, char* argv[])
{
  Glib::RefPtr<Gtk::Application> app = Gtk::Application::create(argc, argv,"org.gtkmm.examples.hello");

  Core core;

  return app->run(core);
}
