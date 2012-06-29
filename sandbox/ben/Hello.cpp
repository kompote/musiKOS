#include "Hello.hpp"
#include <iostream>

Hello::Hello() : button("Hello world !")
{
  button.signal_clicked().connect(sigc::mem_fun(*this,&Hello::on_click));

	add(button);

  button.show();
}

void Hello::on_click()
{
  std::cout << "Hello world !" << std::endl;
}

Hello::~Hello()
{
}
