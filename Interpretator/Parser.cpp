#include "Parser.h"
#include <iostream>
#include "IndentationException.h"
#include "SyntaxException.h"
#include "NameErrorException.h"

std::unordered_map<std::string, Type*> Parser::_variables;

Type* Parser::parseString(std::string str)
{
    try
    {
        Helper helper;
        Type* variable;

        if (str.length() > 0)
        {
            if (str[0] == '\t' || str[0] == ' ')
            {
                throw IndentationException();
            }
        }

        helper.trim(str);
        helper.removeLeadingZeros(str);

        if (Parser::makeAssignment(str) == false)
        {
            
        }

        variable = getType(str);

if (variable == nullptr || variable->isPrintable() == false || variable->isTemp() == true)
{
    throw SyntaxException();
}

    }
    catch (const IndentationException& exception)
    {
        std::cout << exception.what();
    }
    catch (const SyntaxException& exception)
    {
        std::cout << exception.what();
    }

    return nullptr;
}

Type* Parser::getType(std::string& str)
{
    Helper helper;

    if (str.size() <= 0)
    {
        return nullptr;
    }

    if (helper.isInteger(str))
    {
        helper.removeLeadingZeros(str);
        Type* integer = new Integer(std::stoi(str));
        return integer;
    }

    if (helper.isBoolean(str))
    {
        Type* boolean = new Boolean(str == "true" ? true : false);
        return boolean;
    }

    if (helper.isString(str))
    {
        Type* string = new String(str);
        return string;
    }
    return nullptr;
}

void Parser::memoryCleaner()
{
    for (auto& pair : _variables)
    {
        delete(pair.second);
    }
}

void Parser::copyVariable(std::string& str)
{

}

bool Parser::isLegalVarName(std::string str)
{
    Helper helper;
    if (helper.isDigit(str[0]) || str.length() <= 0)
    {
        return false;
    }

    for (int i = 0; i < str.length(); i++)
    {
        if (helper.isDigit(str[i]) || helper.isUnderscore(str[i]) || helper.isLetter(str[i]))
        {
            continue;
        }
        else
        {
            return false;
        }
    }
    return true;
}

bool Parser::makeAssignment(std::string str)
{
    char del = '=';
    std::stringstream ss(str);
    std::string varname;
    std::string value;

    auto pos = str.find(del);
    if (str.find(del) == str.npos)
    {
        return false;
    }

    while (!ss.eof())
    {
        std::getline(ss, varname, del);
        std::getline(ss, value, del);
    }

    if (!isLegalVarName(varname))
    {
        throw NameErrorException();
    }

    Type* variable = getType(value);
    if (variable == nullptr)
    {
        throw SyntaxException();
    }

    std::pair<std::string, Type*> variableandname(varname, variable);
    _variables.insert(variableandname);
    return true;

}

Type* Parser::getVariableValue(std::string str)
{
    return nullptr;
}
