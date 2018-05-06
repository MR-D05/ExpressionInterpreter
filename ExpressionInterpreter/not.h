#pragma once
class NotOperator : public SubExpression
{
public:
	NotOperator(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return (left->evaluate() == 0);
	}
};