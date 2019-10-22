#include <iostream>

enum ProductType
{
    PT_A,
    PT_B,
    PT_C
};

class IProduce
{
public:
    virtual ~IProduce() {};
    virtual void show() = 0;
};

class ProductA : public IProduce
{
public:
    void show()
    {
        ::std::cout << "show A" << ::std::endl;
    }
};

class ProductB : public IProduce
{
public:
    void show()
    {
        ::std::cout << "show B" << ::std::endl;
    }
};

class ProductC : public IProduce
{
public:
    void show()
    {
        ::std::cout << "show C" << ::std::endl;
    }
};

class Factory final
{
public:
    Factory() {}
    ~Factory() {}

    IProduce* create( ProductType pt )
    {
        switch( pt )
        {
        case PT_A:
            return new ProductA();
        case PT_B:
            return new ProductB();
        case PT_C:
            return new ProductC();
        }
    }
};

int main(int argc, char const *argv[])
{
    Factory ft;

    IProduce* ptA = ft.create( PT_A );
    IProduce* ptB = ft.create( PT_B );
    IProduce* ptC = ft.create( PT_C );

    if ( ptA ) {
         ptA->show();
         delete ptA;
    }

    if ( ptB ) {
         ptB->show();
         delete ptB;
    }

    if ( ptC ) {
         ptC->show();
         delete ptC;
    }

    return 0;
}


