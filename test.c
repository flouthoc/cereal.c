#include "cereal.h"
#include <stdio.h>


struct book{

	int a;
	char q[3];
	
};


int main(){

	int status;
	int e = 42;
	uint32_t f[2];
	uint32_t b[2];
	b[0] = 32;
	b[1] = 54;
	struct iovec *vector;
	status = cereal(&vector, 1, "ui32[2]", b);
	decereal(&vector, 1, "ui32[2]", &f);

	printf("%lu\n", (unsigned long)f[0]);
	
	/*b = (uint32_t *)(vector[0].iov_base);
	printf("%lu", (unsigned long)b[1]);

	f = *(uint32_t *)(vector[1].iov_base);
	printf("%lu", (unsigned long)f);*/





	return 0;

}