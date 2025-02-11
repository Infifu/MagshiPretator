#pragma once
#include "Type.h"

class Void : public Type
{
public:
	Void(void);
	bool isPrintable();
	std::string toString();
private:

};
