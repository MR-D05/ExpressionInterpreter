class AdditionOperator : public SubExpression
{
public:
	AdditionOperator(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return left->evaluate() + right->evaluate();
	}
};