#ifndef COUCOU_H
#define COUCOU_H

#include <gtkmm/button.h>
#include "Module.hpp"

class Coucou : public Module
{
  public:
    Coucou();
    ~Coucou();

  protected:
    // Gestionnaire de signal : clic
    void on_click();
    
    // Widgets membres
    Gtk::Button button;
};    

#endif
