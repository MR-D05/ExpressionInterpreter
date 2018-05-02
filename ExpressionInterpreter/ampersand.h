#pragma once
class Ampersand : public SubExpression
{
public:
	Ampersand(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return left->evaluate() && right->evaluate();
	}
};