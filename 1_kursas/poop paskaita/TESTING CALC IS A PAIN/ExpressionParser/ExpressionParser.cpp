#include "ExpressionParser.h"

ExpressionParser::ExpressionParser(std::string expr) {
	operators = {
		{ "*", 2},
        { "/", 2},
        { "%", 2},
        { "+", 1},
        { "-", 1},
        { "(", -1},
        { ")", -1},
		
	};
	
	std::vector<std::string> tokens = Tokenize(expr, operators);
	std::vector<std::string> expression = simplifyExpression(tokens, operators);
	
	result = calculateExpression(expression, operators);
}

ExpressionParser::~ExpressionParser() {
}

std::vector<std::string> ExpressionParser::Tokenize(std::string &expr, std::unordered_map<std::string, int> &operators) {
	std::vector<std::string> tokens;
	std::string number = "";
	for (char c : expr) {
		if (c == ' ') {
			continue;
		}
		//Jeigu randa operatoriu
		else if (operators.find(std::string(1, c)) != operators.end()) {
			if (number != "")
				tokens.push_back(number);
			number = "";
			tokens.push_back(std::string(1, c));
		}
		else
			number += c;
	}
	if (number != "")
		tokens.push_back(number);

	return tokens;
}

std::vector<std::string> ExpressionParser::simplifyExpression(std::vector<std::string> &tokenizedExpr,
															  std::unordered_map<std::string, int> &operators) {
	std::vector<std::string> simplifiedExpr;
	std::vector<std::string> stack = { "(" };

	tokenizedExpr.push_back(")");
	for (std::string token : tokenizedExpr) {
		if (operators.find(token) == operators.end()) {
			simplifiedExpr.push_back(token);
		}
		else if (token == "(") {
			stack.push_back(token);
		}
		else if (token == ")") {
			while(stack.back() != "(") {
				simplifiedExpr.push_back(stack.back() );
				stack.pop_back();
			}
			stack.pop_back();
		}
		else {
			while (!stack.empty() && operators[token] <= operators[stack.back()]) {
				simplifiedExpr.push_back(stack.back());
				stack.pop_back();
			}
			stack.push_back(token);
		}

	}

	return simplifiedExpr;
}

double ExpressionParser::calculateExpression(std::vector<std::string> &simplifiedExpr, std::unordered_map<std::string, int> &operators) {
	std::vector<double> evaluationStack;

	for (std::string token : simplifiedExpr) {
		if (operators.find(token) != operators.end()) {
			double a = evaluationStack[evaluationStack.size() - 1];
			double b = evaluationStack[evaluationStack.size() - 2];

			switch(token[0]) {
				case '+':
					b = b + a;
					break;
				case '-':
					b = b - a;
					break;
				case '*':
					b = b * a;
					break;
				case '/':
					b = b / a;
				case '%':
					while (b > a) {
						b = b - a;
					}
					break;
				default:
					break;
			}
			evaluationStack.pop_back();
			evaluationStack.pop_back();
			evaluationStack.push_back(b);

		}
		else {
			evaluationStack.push_back(atof(token.c_str()));
		}
	}
	return evaluationStack[0];

}

void ExpressionParser::print() {
	std::cout << result << std::endl;
}

