#pragma once
class EqualsOperator : public SubExpression
{
public:
	EqualsOperator(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return left->evaluate() == right->evaluate();
	}
};