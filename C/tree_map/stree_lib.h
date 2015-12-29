#ifndef stblib.h
#include<stdlib.h>
#endif

#ifdef string.h
#include<string.h>
#endif


#ifndef MEM_FAILURE()

#define MEM_FAILURE()							\
	do{								\
		printf("\n Memory failure in function "			\
			   "%s at %d line \n", __FUNCTION__, __LINE__);	\
		exit(0);						\
	} while(0);
#endif
