// your are allowed to modify the code inside the class,
// you are NOT allowed to change anything outside of it

class Object {
private:
    double num;
public:
Object()
{
    num = 0;
}

Object(double num)
    :num(num)
{};

static double a()
{
    return 1;
}
static double  c()
{
    return 1;
}
static double b()
{
    return 1;
}


};

template <typename Object>
void test(){
	Object a(2.1), b;
	if (b.a() == b.c()){
		const Object c;
		if (c.b() == Object::a())
			return;
	}
}

int main(int argc, char** argv) {
    test<Object>();
    return 0;
}
