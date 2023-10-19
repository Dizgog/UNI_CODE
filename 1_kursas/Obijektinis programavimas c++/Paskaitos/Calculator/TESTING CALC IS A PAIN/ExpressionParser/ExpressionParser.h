#ifndef EXPRESSIONPARSER_H_
#define EXPRESSIONPARSER_H_

#include <vector>
#include <string>
#include <unordered_map>
#include <cstdlib>
#include <iostream>

class ExpressionParser {
private:
	std::unordered_map<std::string, int> operators;
	float result;

public:
	ExpressionParser(std::string expr);
	virtual ~ExpressionParser();

	std::vector<std::string> Tokenize(std::string &expr, std::unordered_map<std::string, int> &operators);
	std::vector<std::string> simplifyExpression(std::vector<std::string> &tokenizedExpr, std::unordered_map<std::string, int> &operators);
	double calculateExpression(std::vector<std::string> &simplifiedExpr, std::unordered_map<std::string, int> &operators);
	void print();

};

#endif /* EXPRESSIONPARSER_H_ */
