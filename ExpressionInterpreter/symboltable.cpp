#include <string>
#include <vector>
using namespace std;

#include "symboltable.h"


void SymbolTable::insert(string variable, int value)
{
	const Symbol& symbol = Symbol(variable, value);
	elements.push_back(symbol);
}

void SymbolTable::iterate()
{
	if (!elements.empty())
		for (int i = elements.size(); i > 0; decrement(i))
			elements.pop_back();
}