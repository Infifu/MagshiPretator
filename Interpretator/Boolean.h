#pragma once
#include "Type.h"

class Boolean : public Type
{
public:
	Boolean(bool value);
	bool isPrintable();
	std::string toString();
private:
	bool _value;
};