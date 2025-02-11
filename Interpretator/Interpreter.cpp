#include "Type.h"
#include "InterpreterException.h"
#include "NameErrorException.h"
#include "Parser.h"
#include <iostream>

#define WELCOME "Welcome to Magshimim Python Interperter version 1.0 by "
#define YOUR_NAME "Ilya"


int main(int argc,char **argv)
{
	try
	{
		std::cout << WELCOME << YOUR_NAME << std::endl;

		std::string input_string;

		// get new command from user
		std::cout << ">>> ";
		std::getline(std::cin, input_string);

		while (input_string != "quit()")
		{
			// parsing command
			Parser::parseString(input_string);


			// get new command from user
			std::cout << ">>> ";
			std::getline(std::cin, input_string);
		}

		return 0;
	}
	catch (NameErrorException& exception)
	{
		std::cout << exception.what();
	}

}
