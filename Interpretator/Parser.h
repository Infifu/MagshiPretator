#pragma once
#include "InterpreterException.h"
#include "Type.h"
#include "Helper.h"
#include <string>
#include <unordered_map>
#include <iostream>
#include <sstream>
#include "String.h"
#include "Void.h"
#include "Integer.h"
#include "Boolean.h"


class Parser
{
public:
    static Type* parseString(std::string str);
    static Type* getType(std::string &str);

private:

};
