#include <iostream>

class A
{ 
public:
    static A*       getInstance();
    static void     delInstance();

protected:
    A() 
    {
        ::std::cout << "A construct" << ::std::endl;
    }

    virtual ~A()
    {
        ::std::cout << "A desconstruct" << ::std::endl;
    }

protected:
    void operator delete(void* p) { ::operator delete(p); }
    void operator delete[](void* p) { ::operator delete(p); }

private:
    static A* s_pInstance;
};

A* A::s_pInstance = nullptr;

A* A::getInstance()
{
    if ( !s_pInstance ) {
        s_pInstance = new A();
    }

    return s_pInstance;
}

void A::delInstance()
{
    if ( s_pInstance ) {
        delete s_pInstance;
    }
}

int main(int argc, char const *argv[])
{
    A* ptr = A::getInstance();
    A::delInstance();

    return 0;
}

