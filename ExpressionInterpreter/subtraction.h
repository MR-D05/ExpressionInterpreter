#pragma once
class SubtractionOperator : public SubExpression
{
public:
	SubtractionOperator(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return left->evaluate() - right->evaluate();
	}
};