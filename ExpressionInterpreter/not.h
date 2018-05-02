#pragma once
class Not : public SubExpression
{
public:
	Not(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return !(left->evaluate());
	}
};