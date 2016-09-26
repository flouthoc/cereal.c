#include "cereal.h"
#include <stdio.h>


struct book{

	int a;
	char q[3];
	
};


int main(){

	int status;
	int e = 42;
	uint32_t f;
	uint32_t *b;
	struct iovec *vector;
	status = cereal(&vector, 1, "ui32", e);
	decereal(&vector, 1, "ui32", &f);
	
	/*b = (uint32_t *)(vector[0].iov_base);
	printf("%lu", (unsigned long)b[1]);

	f = *(uint32_t *)(vector[1].iov_base);
	printf("%lu", (unsigned long)f);*/





	return 0;

}