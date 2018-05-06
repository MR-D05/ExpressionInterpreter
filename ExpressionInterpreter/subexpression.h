class SubExpression : public Expression
{
public:
	SubExpression(Expression* left, Expression* right);
	static Expression* parse(stringstream& file);

	static bool inputIsConditionalOperator(char operation)
	{
		return operation == ':';
	}

	static bool inputIsNotOperator(char operation)
	{
		return operation == '!';
	}

protected:
	Expression * left;
	Expression* right;
};