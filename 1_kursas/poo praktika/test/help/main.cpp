#include <iostream>
#include <vector>
using namespace std;

struct MyException : public std::exception
{
	const char * what () const throw ()
    {
    	return "C++ Exception";
    }
};

int main()
{
	try
    {
    	throw MyException();
    }
    catch (MyException& e)
    {
    	std::cout << "MyException caught" << std::endl;
        std::cout << e.what() << std::endl;
    }
    catch (std::exception& e)
    {
    	// Other errors
    }
}
