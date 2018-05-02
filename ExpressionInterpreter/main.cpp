using namespace std;
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"
#include <istream>
#include <iosfwd>

SymbolTable symbolTable;

void parseAssignments(stringstream& in);

int main()
{
	const int chunk = 128;
	Expression* expression;
	char paren, comma, temp[chunk];

	ifstream fin("expressions.txt");

	while (true)
	{
		symbolTable.iterate();
		fin.getline(temp, chunk);
		if (!fin) break;

		stringstream in(temp, ios_base::in);

		in >> paren;
		cout << temp << " ";

		try
		{
			expression = SubExpression::parse(in);
			in >> comma;
			parseAssignments(in);
			cout << "Value = " << expression->evaluate() << endl;
		}
		catch (exception) {
			return EXIT_FAILURE;
		}
	}
	std::system("pause");
	return 0;
}

void parseAssignments(stringstream& in)
{
	char assignop, delimiter;
	string variable;
	int value;
	do
	{
		variable = parseName(in);
		in >> ws >> assignop >> value >> delimiter;
		symbolTable.insert(variable, value);
	} while (delimiter == ',');
}