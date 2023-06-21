#include <iostream>
#include <functional>
#include "CalcOps.h"

namespace CalcFunctions {

	CalcOps::CalcOps(double x, double y) :
		firstElement(x), secondElement(y) {

	}
	CalcOps::~CalcOps()
	{
	}

	CalcOpsSingle::CalcOpsSingle(double x) :
		singleElement(x) {

	}

	double CalcOps::Add()
	{
		return firstElement + secondElement;
	}

	double CalcOps::Substract()
	{
		return firstElement - secondElement;
	}

	double CalcOps::Multiply()
	{
		return firstElement * secondElement;
	}

	double CalcOps::Divide()
	{
		return firstElement / secondElement;
	}

	double CalcOps::Modulus()
	{
		int _firstElement = firstElement;
		int _secondElement = secondElement;
		return _firstElement % _secondElement;
	}

	double CalcOpsSingle::Negate()
	{
		return singleElement * (-1);
	}

	CalcOpsSingle::~CalcOpsSingle()
	{
	}
}

