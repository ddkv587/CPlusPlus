#include <iostream>

class IProduce1
{
public:
    virtual ~IProduce1() {};
    virtual void show() = 0;
};

class IProduce2
{
public:
    virtual ~IProduce2() {};
    virtual void show() = 0;
};

class ProductA : public IProduce1
{
public:
    void show()
    {
        ::std::cout << "show A produce1" << ::std::endl;
    }
};

class ProductB : public IProduce1
{
public:
    void show()
    {
        ::std::cout << "show B produce1" << ::std::endl;
    }
};

class ProductC : public IProduce2
{
public:
    void show()
    {
        ::std::cout << "show C produce2" << ::std::endl;
    }
};

class ProductD : public IProduce2
{
public:
    void show()
    {
        ::std::cout << "show D produce2" << ::std::endl;
    }
};

class IFactory
{
public:
    virtual ~IFactory() {}

    virtual IProduce1* createProduct1() = 0;
    virtual IProduce2* createProduct2() = 0;
};

class FactoryA : public IFactory
{
public:
    IProduce1* createProduct1()
    {
        return new ProductA();
    }

    IProduce2* createProduct2()
    {
        return new ProductC();
    }
};

class FactoryB : public IFactory
{
public:
    IProduce1* createProduct1()
    {
        return new ProductB();
    }

    IProduce2* createProduct2()
    {
        return new ProductD();
    }
};

int main(int argc, char const *argv[])
{
    FactoryA fa;
    FactoryB fb;

    IProduce1* ptA = fa.createProduct1();
    IProduce1* ptB = fb.createProduct1();

    IProduce2* ptC = fa.createProduct2();
    IProduce2* ptD = fb.createProduct2();

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

    if ( ptD ) {
         ptD->show();
         delete ptD;
    }
    
    return 0;
}
