#include <stdio.h>
#include "lib.h"
#include "test.h"

Deliver* Deliver::pInstance = NULL;

Deliver* Deliver::getInstance()
{
	if ( NULL == pInstance ) {
		pInstance = new Deliver();
	}

	return pInstance;
}

void Deliver::delInstance()
{
	if ( NULL != pInstance ) {
		delete pInstance;
		pInstance = NULL;
	}
}

void Deliver::test()
{
	foo();
}
