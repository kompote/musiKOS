#include "modules.hpp"
#include <string>

class ModuleFactory
{
	public:
		ModuleFactory(); 
		static Module* Create(std::string);
		~ModuleFactory();
};
