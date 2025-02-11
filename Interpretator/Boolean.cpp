#include "Boolean.h"

Boolean::Boolean(bool value) : _value(value)
{
}

bool Boolean::isPrintable()
{
	return true;
}

std::string Boolean::toString()
{
	return _value == true ? "true" : "false";
}
