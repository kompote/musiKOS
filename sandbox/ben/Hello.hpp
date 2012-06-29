#ifndef HELLOWORLD_H
#define HELLOWORLD_H

#include <gtkmm/frame.h>
#include <gtkmm/button.h>

class Hello : public Gtk::Frame
{
  public:
    Hello();
    virtual ~Hello();

  protected:
    // Gestionnaire de signal : clic
    void on_click();
    
    // Widgets membres
    Gtk::Button button;
};    

#endif
