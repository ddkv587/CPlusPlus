#ifndef __LIB_H__
#define __LIB_H__

#include "Interface.h"

class Deliver : public Interface
{
public:
	static Deliver* getInstance();
	static void delInstance();

	Deliver() {}
	virtual ~Deliver() {}

	void test();

private:
	static Deliver* pInstance;
};

extern "C" {
	Interface* getInstance() {
		return Deliver::getInstance();
	}	

	void delInstance() {
		return Deliver::delInstance();
	}	

	void foo2() {
		printf("call foo2 in lib\n");
	}
}
#endif
