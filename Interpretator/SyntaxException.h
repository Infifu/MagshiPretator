#include "InterpreterException.h"
#pragma once


class SyntaxException : public InterpreterException
{
public:
	virtual const char* what() const noexcept;
};
