#include <iostream>

#define SAFE_DELETE( p ) do { if ( (p) ) { delete (p); (p) = nullptr; } } while( 0 )

class IProxy
{
public:
    virtual void show() = 0;
};

class Real : public IProxy
{
public:
    void show()
    {
        ::std::cout << "show in real\n";
    }
};


class Proxy final : public IProxy
{
public:
    Proxy()
        : m_pReal( NULL )
    {
        m_pReal = new Real();
    }

    ~Proxy()
    {
        SAFE_DELETE(m_pReal);
    }

    void show()
    {
        if ( m_pReal ) m_pReal->show();
    }

private:
    Real* m_pReal;
};

int main(int argc, char const *argv[])
{
    Proxy* pProxy = new Proxy();

    pProxy->show();

    SAFE_DELETE( pProxy );

    return 0;
}
