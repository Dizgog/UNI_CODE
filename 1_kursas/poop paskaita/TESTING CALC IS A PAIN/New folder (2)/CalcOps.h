//#ifndef CALCOPS_HEADER
//#define CALCOPS_HEADER
#pragma once

namespace CalcFunctions {

	class CalcOpsSingle
	{
	public:
		CalcOpsSingle(double x);

		double Negate();

		~CalcOpsSingle();

	private:
		double singleElement;
	};

	class CalcOps
	{
	public:

		CalcOps(double x, double y);

		double Add();
		double Substract();
		double Multiply();
		double Divide();
		double Modulus();

		~CalcOps();

	private:
		double firstElement;
		double secondElement;
	};
}

//#endif // !CALCOPS_HEADER


	