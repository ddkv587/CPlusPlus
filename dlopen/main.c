#include <dlfcn.h>
#include <assert.h>
#include <stdio.h>
#include "Interface.h"

typedef Interface* (*GETINSTANCE)();
typedef void (*DELINSTANCE)();
typedef void (*FOO)();

int main()
{	
	void* pHandle = NULL;

	FOO pFoo = NULL;
	//pFoo = (FOO)dlsym( NULL, "foo2" );
	if ( pFoo ) {
		printf("in main\n");
		assert(pFoo);
		pFoo();
	} else {
		printf("in dlopen\n");
		pHandle = dlopen( "./libfoo.so", RTLD_LAZY );
		assert( NULL != pHandle );

		pFoo = (FOO)dlsym( pHandle, "foo2" );
		assert(pFoo);
		pFoo();
	}

	if ( !pHandle ) {
		pHandle = dlopen( "./libfoo.so", RTLD_LAZY );
		assert( NULL != pHandle );
	}

	GETINSTANCE getInstance = (GETINSTANCE)dlsym( pHandle, "getInstance" );
	DELINSTANCE delInstance = (DELINSTANCE)dlsym( pHandle, "delInstance" );
	assert( NULL != getInstance && NULL != delInstance );

	Interface* ins = getInstance();
	ins->test();
	delInstance();
	ins = NULL;

	if ( NULL != pHandle )
		dlclose(pHandle);

	return 0;
}
