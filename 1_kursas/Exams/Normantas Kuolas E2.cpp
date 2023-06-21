// your are allowed to modify the code inside the class,
// you are NOT allowed to change anything outside of it

#include <algorithm>

class Object {
public:
int a;
Object()
    {
    a = 0;
    }
Object operator+(int i)
{
    return *this;
}

Object operator++()
    {
        ++this->a;
        return *this;
    }

    Object operator++(int)
    {
        Object old =*this;
        operator++();
        return old;
    }
Object operator()()
{
        return *this;
}

struct st{
    int y()
{
    return 2;
}
};
st x;


int y()
{
    return 2;
}

Object& operator=(const Object& SA)
    {
        return *this;
    }
bool operator<(Object&)
{
    return true;
}
};

template <typename Object>

void test(){
	Object x[5], y = x[0]() + x[1]++.y();	
	std::sort(x, x+5);
	if (y.x.y() == 2){
		return;
	}
}

int main(int argc, char** argv) {
    test<Object>(); 
    return 0;
}