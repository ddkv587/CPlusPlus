#include <iostream>

class Base
{
    virtual void show()
    {
        ::std::cout << "show in Base" << ::std::endl;
    }
};

class Derived : public Base
{
    void show()
    {
        ::std::cout << "show in Derived" << ::std::endl;
    }
};

int main(int argc, char const *argv[])
{
    system( "cat /proc/self/maps" );
    Base* a     = new Base();
    Base* b     = new Derived();
    Derived* c  = new Derived();

    printf( " a: %p\n b: %p\n c: %p\n", a, b, c );

    return 0;
}
