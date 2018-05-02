#include <iostream>
#include <sstream>
using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "addition.h"
#include "subtraction.h"
#include "multiplication.h"
#include "divide.h"
#include "pipe.h"
#include "ampersand.h"
#include "equals.h"
#include "greater.h"
#include "less.h"
#include "conditional.h"
#include "not.h"

SubExpression::SubExpression(Expression* left, Expression* right)
{
	this->left = left;
	this->right = right;
}

Expression* SubExpression::parse(stringstream& in)
{
	Expression* left;
	Expression* right;
	Expression* condition;
	char operation, paren;

	left = Operand::parse(in);

	in >> operation;

	if (operation == '!') {
		in >> paren;
		return new Not(left, nullptr);

	}
	else if (operation == ':') {
		right = Operand::parse(in);
		in >> paren;
		condition = Operand::parse(in);
		in >> paren;
		return new Conditional(left, right, condition);

	}
	else {

		right = Operand::parse(in);
		in >> paren;

		switch (operation)
		{
		case '+': return new Addition(left, right);
		case '-': return new Subtraction(left, right);
		case '*': return new Multiplication(left, right);
		case '/': return new Divide(left, right);
		case '>': return new Greater(left, right);
		case '<': return new Less(left, right);
		case '=': return new Equals(left, right);
		case '|': return new Pipe(left, right);
		case '&': return new Ampersand(left, right);
		}
	}
	return nullptr;
}
