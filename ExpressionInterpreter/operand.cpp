#include <cctype>
#include <iostream>
#include <sstream>
#include <list>
#include <string>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h"
#include "parse.h"
#include "pipe.h"
#include "ampersand.h"
#include "equals.h"
#include "greater.h"
#include "less.h"
#include "conditional.h"
#include "not.h"

Expression* Operand::parse(stringstream& file)
{
	char paren;
	int value;

	file >> ws;
	if (isdigit(file.peek()))
	{
		file >> value;
		Expression* literal = new Literal(value);
		return literal;
	}
	if (file.peek() == '(')
	{
		file >> paren;
		return SubExpression::parse(file);
	}
	else
		return new Variable(parseName(file));
	return nullptr;
}