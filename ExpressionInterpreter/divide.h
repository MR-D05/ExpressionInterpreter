#pragma once
class DivisionOperator : public SubExpression
{
public:
	DivisionOperator(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return left->evaluate() / right->evaluate();
	}
};