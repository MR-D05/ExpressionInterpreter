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

void parseAssignments(stringstream& file);

std::ostream &output(std::ostream &os, int v) 
{ 
	switch (v) 
	{ 
	case 0: return os << "False"; 
	case 1: return os << "True"; 
	default: return os << v; 
	}; 
} 

int main()
{
	fstream fin("expressions.txt");
	const int chunk = 128;
	char start;
	char comma;
	char temp[chunk];


	Expression* expression;



	while (true)
	{
		symbolTable.iterate();
		fin.getline(temp, chunk);
		if (fin.fail()) break;
		stringstream file(temp, ios_base::in);
		file >> start;
		cout << temp;
		cout << " ";
		expression = SubExpression::parse(file);
		file >> comma;
		parseAssignments(file);
		cout << "Value = ";
		output(cout, (expression->evaluate()));
		cout << endl;
	}
	std::system("pause");
	return 0;
}

void parseAssignments(stringstream& file)
{
	char assignop, delimiter;
	string variable;
	int value;
	do
	{
		variable = parseName(file);
		file >> ws >> assignop >> value >> delimiter;
		symbolTable.insert(variable, value);
	} while (delimiter == ',');
}