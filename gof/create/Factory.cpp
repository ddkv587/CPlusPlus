#include <iostream>

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

class IFactory
{
public:
    virtual ~IFactory() {}

    virtual IProduce* create() = 0;
};

class FactoryA : public IFactory
{
public:
    IProduce* create()
    {
        return new ProductA();
    }
};

class FactoryB : public IFactory
{
public:
    IProduce* create()
    {
        return new ProductB();
    }
};

class FactoryC : public IFactory
{
public:
    IProduce* create()
    {
        return new ProductC();
    }
};

int main(int argc, char const *argv[])
{
    FactoryA fa;
    FactoryB fb;
    FactoryC fc;

    IProduce* ptA = fa.create();
    IProduce* ptB = fb.create();
    IProduce* ptC = fc.create();

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
