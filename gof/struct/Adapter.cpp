#include <iostream>

#define SAFE_DELETE( p ) do { if ( (p) ) { delete (p); (p) = nullptr; } } while( 0 )

class Real
{
public:
    void func()
    {
        ::std::cout << "func in real\n";
    }
};

class IAdapterInterface
{
public:
    virtual void call() = 0;
};

class Adapter final : public IAdapterInterface
{
public:
    Adapter()
        : m_pReal( NULL )
    {
        m_pReal = new Real();
    }

    ~Adapter()
    {
        SAFE_DELETE(m_pReal);
    }

    void call()
    {
        if ( m_pReal ) m_pReal->func();
    }

private:
    Real* m_pReal;
};

int main(int argc, char const *argv[])
{
    Adapter* pAdapter = new Adapter();

    pAdapter->call();

    SAFE_DELETE( pAdapter );

    return 0;
}
