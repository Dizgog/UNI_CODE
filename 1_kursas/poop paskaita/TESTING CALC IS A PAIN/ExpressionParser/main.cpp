#include "ExpressionParser.h"

using namespace std;

int main() {
	string expr;
	getline(cin, expr);
	
	ExpressionParser a(expr);
	
	
	a.print();
	
}
	
