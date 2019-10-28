#include <iostream>

class IProduct
{
public:
    virtual void showA() = 0;
    virtual void showB() = 0;
};

class ProductA : public IProduct
{
public:
    void showA()
    {
        ::std::cout << "show A in ProductA" << ::std::endl;
    }

    void showB()
    {
        ::std::cout << "show B in ProductA" << ::std::endl;
    }
};

class ProductB : public IProduct
{
public:
    void showA()
    {
        ::std::cout << "show A in ProductB" << ::std::endl;
    }

    void showB()
    {
        ::std::cout << "show B in ProductB" << ::std::endl;
    }
};

class IControl
{
public:
    IControl( IProduct* p ) :m_pProduct(p) {}
    virtual ~IControl() { }

    virtual void controlA() = 0;
    virtual void controlB() = 0;

protected:
    IProduct* m_pProduct;
};

class ControlA : IControl
{
public:
    ControlA( IProduct* p ) : IControl(p) {}
    ~ControlA(){}

    void controlA()
    {
        ::std::cout<< "in ControlA" << ::std::endl;
        m_pProduct->showA();
    }

    void controlB()
    {
        ::std::cout<< "in ControlA" << ::std::endl;
        m_pProduct->showB();
    }
};

class ControlB : IControl
{
public:
    ControlB( IProduct* p ) : IControl(p) {}
    ~ControlB(){}

    void controlA()
    {
        ::std::cout<< "in ControlB" << ::std::endl;
        m_pProduct->showA();
    }

    void controlB()
    {
        ::std::cout<< "in ControlB" << ::std::endl;
        m_pProduct->showB();
    }
};

int main(int argc, char const *argv[])
{
    ProductA* pa = new ProductA();
    ProductB* pb = new ProductB();

    ControlA* ca1 = new ControlA( pa );
    ControlA* ca2 = new ControlA( pb );

    ControlB* cb1 = new ControlB( pa );
    ControlB* cb2 = new ControlB( pb );

    ca1->controlA();
    ca1->controlB();

    ca2->controlA();
    ca2->controlB();

    cb1->controlA();
    cb1->controlB();

    cb2->controlA();
    cb2->controlB();

    return 0;
}
