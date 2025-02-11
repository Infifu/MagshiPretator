#include "String.h"
#include "Void.h"

String::String(std::string value) : _value(value)
{
}

bool String::isPrintable()
{
	return true;
}

std::string String::toString()
{
	return _value;
}
