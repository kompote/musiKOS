#ifndef COUCOU_H
#define COUCOU_H

#include <gtkmm/frame.h>
#include <gtkmm/button.h>

class Coucou : public Gtk::Frame
{
  public:
    Coucou();
    virtual ~Coucou();

  protected:
    // Gestionnaire de signal : clic
    void on_click();
    
    // Widgets membres
    Gtk::Button button;
};    

#endif
