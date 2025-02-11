#include "Integer.h"

Integer::Integer(int value) : _value(value)
{
}

bool Integer::isPrintable()
{
	return true;
}

std::string Integer::toString()
{
	return std::to_string(_value);
}
