#pragma once
class Subtraction : public SubExpression
{
public:
	Subtraction(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return left->evaluate() - right->evaluate();
	}
};