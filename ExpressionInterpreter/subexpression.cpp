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

Expression* SubExpression::parse(stringstream& file)
{
	Expression* charFromLeft;
	Expression* charFromRight;
	Expression* conditionalOperator;
	char operation;
	char closeParenthesis;
	char questionMark;

	charFromLeft = Operand::parse(file);

	file >> operation;

	if (inputIsNotOperator(operation)) {
		file >> closeParenthesis;
		return new NotOperator(charFromLeft, nullptr);

	}
	else if (inputIsConditionalOperator(operation)) {
		charFromRight = Operand::parse(file); file >> questionMark; conditionalOperator = Operand::parse(file); file >> closeParenthesis;
		return new ConditionalOperator(charFromLeft, charFromRight, conditionalOperator);

	}
	else {
		charFromRight = Operand::parse(file);
		file >> closeParenthesis;

		switch (operation)
		{
		case '+': return new AdditionOperator(charFromLeft, charFromRight);
		case '-': return new SubtractionOperator(charFromLeft, charFromRight);
		case '*': return new MultiplicationOperator(charFromLeft, charFromRight);
		case '/': return new DivisionOperator(charFromLeft, charFromRight);
		case '>': return new GreaterOperator(charFromLeft, charFromRight);
		case '<': return new LessOperator(charFromLeft, charFromRight);
		case '=': return new EqualsOperator(charFromLeft, charFromRight);
		case '|': return new PipeOperator(charFromLeft, charFromRight);
		case '&': return new AmpersandOperator(charFromLeft, charFromRight);
		}
	}
	return nullptr;
}
