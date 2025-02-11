#pragma once
#include <iostream>
#include <String>
#include "Helper.h"

class Type
{
public:
	bool isTemp() const;
	virtual bool isPrintable() = 0;
private:
	bool _isTemp = false;
};
