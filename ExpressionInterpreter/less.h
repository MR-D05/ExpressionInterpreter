#pragma once
class LessOperator : public SubExpression
{
public:
	LessOperator(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return left->evaluate() < right->evaluate();
	}
};