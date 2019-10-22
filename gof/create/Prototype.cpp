#include <iostream>

#define SAFE_DELETE( p ) do { if ( (p) ) { delete (p); (p) = nullptr; } } while( 0 )

class IBase
{
public:
    virtual ~IBase()    {}
    virtual IBase* clone() = 0;
};

class PrototypeA final : public IBase
{
public:
    IBase* clone()
    {
        PrototypeA* a = new PrototypeA();
        a->setA( m_a );

        return a;
    }

    void    setA( int a )   { m_a = a; }
    int     getA()          { return m_a; }

private:
    int m_a;
};

class PrototypeB final : public IBase
{
public:
    IBase* clone()
    {
        PrototypeB* b = new PrototypeB();
        b->setB( m_b );

        return b;
    }

    void    setB( int b )   { m_b = b; }
    int     getB()          { return m_b; }

private:
    int m_b;
};

class Product final : public IBase
{
public:
    Product()
        : m_a ( nullptr )
        , m_b ( nullptr )
    {
        m_a = new PrototypeA();
        m_a->setA( 10 );

        m_b = new PrototypeB();
        m_b->setB( 10 );
    }

    ~Product()
    {
        SAFE_DELETE( m_a );
        SAFE_DELETE( m_b );
    }

    PrototypeA*     getPrototypeA()  { return m_a; }
    void            setPrototypeA( PrototypeA*  pa )
    {
        if ( m_a ) SAFE_DELETE( m_a );

        m_a = pa;
    }

    PrototypeB*     getPrototypeB()  { return m_b; }
    void            setPrototypeB( PrototypeB*  pb )
    {
        if ( m_b ) SAFE_DELETE( m_b );

        m_b = pb;
    }

    void show()
    { 
        ::std::cout << "a: " << m_a->getA() << ", b: " << m_b->getB() << ::std::endl; 
    }

    IBase* clone()
    {
        Product* p = new Product();

        p->setPrototypeA( static_cast< PrototypeA* >( m_a->clone() ) );
        p->setPrototypeB( static_cast< PrototypeB* >( m_b->clone() ) );
    };

private:
    PrototypeA*  m_a;
    PrototypeB*  m_b;
};

int main(int argc, char const *argv[])
{
    Product a;

    Product* b = static_cast< Product* >( a.clone() );

    a.show();
    b->show();

    SAFE_DELETE( b );

    return 0;
}