#include "NameErrorException.h"


const char* NameErrorException::what() const noexcept
{
	std::string name = "NameError: name ";
	name.append(_name);
	name.append(" is not defined\n");
	//_msg = name;

	return "name is not defined\n";
}