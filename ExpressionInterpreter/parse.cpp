#include <cctype>
#include <iostream>
#include <sstream>
#include <string>
using namespace std;
#include "parse.h"

string parseName(stringstream& file)
{
	char alnum;
	string name = "";

	file >> ws;
	while (isalnum(file.peek()))
	{
		file >> alnum;
		name += alnum;
	}
	return name;
}