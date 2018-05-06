#pragma once
class SymbolTable
{
public:
	SymbolTable() {}
	void insert(string variable, int value);

	int lookUp(string variable) const
	{
		for (const auto & element : elements)
			if (element.variable == variable)
				return element.value;
		return -1;
	}

	void iterate();

	int decrement(int &i)
	{
		return i--;
	}

private:
	struct Symbol
	{
		Symbol(string variable, int value)
		{
			this->variable = variable;
			this->value = value;
		}
		string variable;
		int value;
	};
	vector<Symbol> elements;
};


