#pragma once
#include "InterpreterException.h"
#include <iostream>
#include <string>


class NameErrorException : public InterpreterException
{
private:
	std::string _name;
	std::string* _msg;
public:
	virtual const char* what() const noexcept;
};
