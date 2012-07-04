#include "ModuleFactory.hpp"

ModuleFactory::ModuleFactory() {}

Module* ModuleFactory::Create(std::string name)
{
	if(name.compare("hello")==0)
		return new Hello();

	if(name.compare("coucou")==0)
		return new Coucou();

	if(name.compare("Audiotheque")==0)
		return new Audiotheque();

	return NULL;
}

ModuleFactory::~ModuleFactory() {}
