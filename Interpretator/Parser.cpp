#include "Parser.h"
#include <iostream>
#include "IndentationException.h"
#include "SyntaxException.h"

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
    catch (...)
    {

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
        Integer integer(std::stoi(str));
        return &integer;
    }

    if (helper.isBoolean(str))
    {
        Boolean boolean(str == "true" ? true : false);
        return &boolean;
    }

    if (helper.isString(str))
    {
        String string(str);
        return &string;
    }
    return nullptr;
}
