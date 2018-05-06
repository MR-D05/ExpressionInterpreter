#pragma once
class GreaterOperator : public SubExpression
{
public:
	GreaterOperator(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return left->evaluate() > right->evaluate();
	}
};