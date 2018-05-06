#pragma once
class MultiplicationOperator : public SubExpression
{
public:
	MultiplicationOperator(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return left->evaluate() * right->evaluate();
	}
};