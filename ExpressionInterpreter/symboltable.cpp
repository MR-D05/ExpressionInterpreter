#include <string>
#include <vector>
using namespace std;

#include "symboltable.h"


void SymbolTable::insert(string variable, int value)
{
	const Symbol& symbol = Symbol(variable, value);
	elements.push_back(symbol);
}

int SymbolTable::lookUp(string variable) const
{
	for (const auto & element : elements)
		if (element.variable == variable)
			return element.value;
	return -1;
}

void SymbolTable::iterate()
{
	if (!elements.empty())
		for (int i = elements.size(); i > 0; i--) {
			elements.pop_back();
		}
}