//#ifndef OPERATIONTYPE_HEADER
//#define OPERATIONTYPE_HEADER
#pragma once

#include <iostream>
#include <string>

enum SelectOperation
{
	Menu = 0,
	Single = 1,
	Double = 2,
	Sequence = 3
};

enum SelectAction
{
	Add			= 1,
	Substract	= 2,
	Multiply	= 3,
	Divide		= 4,
	Modulus		= 5,
	Negate		= 6
};

//std::istream& operator>>(std::istream& is, SelectOperation& op)
//{
//	int o;
//	is >> o;
//	op = static_cast<SelectOperation>(o);
//	return is;
//}

extern SelectOperation COperantion;

//#endif // !OPERATIONTYPE_HEADER

