#pragma once
#include "Type.h"

class Integer : public Type
{
public:
	Integer(int value);
	bool isPrintable();
	std::string toString();
private:
	int _value;
};