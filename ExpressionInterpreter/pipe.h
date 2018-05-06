#pragma once
class PipeOperator : public SubExpression
{
public:
	PipeOperator(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return left->evaluate() || right->evaluate();
	}
};