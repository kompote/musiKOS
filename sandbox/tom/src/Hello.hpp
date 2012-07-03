#ifndef HELLOWORLD_H
#define HELLOWORLD_H

#include <gtkmm/button.h>
#include "Module.hpp"

class Hello : public Module
{
  public:
    Hello();
    ~Hello();

  protected:
    // Gestionnaire de signal : clic
    void on_click();
    
    // Widgets membres
    Gtk::Button button;
};    

#endif
