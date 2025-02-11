#pragma once
#include "Sequence.h"
#include <iostream>

class String : public Sequence
{
public:
	String(std::string);
	bool isPrintable();
	std::string toString();
private:
	std::string _value;
};
