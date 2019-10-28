#include <iostream>

class Real
{
public:
    void func()
    {
        :;std::cout << "func in real";
    }
};

class Adapter final 
{
public:
    Adapter()
        : m_pReal( NULL )
    {
        m_pReal = new Real();
    }

    ~Adapter()
    {
        if ()
    }

private:
    Real* m_pReal;
}