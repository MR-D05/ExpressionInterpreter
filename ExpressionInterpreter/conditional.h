#pragma once
class ConditionalOperator : public SubExpression
{
public:
	ConditionalOperator(Expression* left, Expression* right, Expression* condition) : SubExpression(left, right)
	{
		this->condition = condition;
	}
	int evaluate()
	{
		return condition->evaluate() ? left->evaluate() : right->evaluate();
	}

private:
	Expression * condition;
};