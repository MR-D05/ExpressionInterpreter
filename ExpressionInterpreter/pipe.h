#pragma once
class Pipe : public SubExpression
{
public:
	Pipe(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return left->evaluate() || right->evaluate();
	}
};