#pragma once
class Multiplication : public SubExpression
{
public:
	Multiplication(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return left->evaluate() * right->evaluate();
	}
};