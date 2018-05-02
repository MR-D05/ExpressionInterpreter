class Addition : public SubExpression
{
public:
	Addition(Expression* left, Expression* right) : SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return left->evaluate() + right->evaluate();
	}
};