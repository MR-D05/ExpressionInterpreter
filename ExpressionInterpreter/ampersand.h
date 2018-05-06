#pragma once
class AmpersandOperator : public SubExpression
{
public:
	AmpersandOperator(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return left->evaluate() && right->evaluate();
	}
};