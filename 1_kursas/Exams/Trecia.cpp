// your are allowed to modify the code inside the class,
// you are NOT allowed to change anything outside of it

#include <algorithm>

class Object {
private:
int arr[10];
int a;
public:
Object()
{
    arr;
}
int f()
{
      return a;
}
int operator+(int i)
{
    return i;
}
};

template <typename Object>
void test(){
	Object o;
	std::transform(o, o+5, o, &Object::f);
}

int main(int argc, char** argv) {
    test<Object>(); 
    return 0;
}