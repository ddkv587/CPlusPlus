#include <iostream>

#define SAFE_DELETE( p ) do { if ( (p) ) { delete (p); (p) = nullptr; } } while( 0 )

class Product final
{
public:
    Product()   {}
    ~Product()  {}

    int     getA()          { return m_a; }
    void    setA( int a )   { m_a = a; }

    int     getB()          { return m_b; }
    void    setB( int b )   { m_b = b; }

private:
    int m_a;
    int m_b;
};

class IBuilder
{
public:
    virtual ~IBuilder() {}

    virtual void buildA() = 0;
    virtual void buildB() = 0;
};

class Builder1 : public IBuilder
{
public:
    Builder1() : m_product( nullptr ) { m_product = new Product(); }
    ~Builder1() { SAFE_DELETE( m_product ); }

    void buildA()   { m_product->setA(10); }
    void buildB()   { m_product->setB(10); }

    void show()
    { 
        ::std::cout << "a: " << m_product->getA() << ", b: " << m_product->getB() << ::std::endl; 
    }

private:
    Product*    m_product;
};

class Builder2 : public IBuilder
{
public:
    Builder2() : m_product( nullptr ) { m_product = new Product(); }
    ~Builder2() { SAFE_DELETE( m_product ); }

    void buildA()   { m_product->setA(100); }
    void buildB()   { m_product->setB(100); }

    void show()     
    {
         ::std::cout << "a: " << m_product->getA() << ", b: " << m_product->getB() << ::std::endl; 
    }

private:
    Product*    m_product;
};

class Director final
{
public:
    void create( IBuilder* builder )
    {
        if ( !builder ) return;

        builder->buildA();
        builder->buildB();
    }
};

int main(int argc, char const *argv[])
{
    Director di;
    Builder1* b1 = new Builder1();
    Builder2* b2 = new Builder2();

    di.create( b1 );
    di.create( b2 );

    b1->show();
    b2->show();

    SAFE_DELETE( b1 );
    SAFE_DELETE( b2 );

    return 0;
}
