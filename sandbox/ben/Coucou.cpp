#include "Coucou.hpp"
#include <iostream>

Coucou::Coucou() : Module(), button("Coucou les gens !")
{
  button.signal_clicked().connect(sigc::mem_fun(*this,&Coucou::on_click));

	add(button);

  button.show();
}

void Coucou::on_click()
{
  std::cout << "Coucou les gens !" << std::endl;
}

Coucou::~Coucou()
{
}
