#include "cereal.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


struct book{

	int a;
	char q[3];
	
};


int main(){

	int status, iterator;
	uint32_t ui32_dest_array[10];
	uint32_t ui32_source_array[10];
	struct iovec *vector;

	/*--test for uint32 array -- */

	for(iterator = 0; iterator<10; iterator++)
		ui32_source_array[iterator] = rand();

	vector = NULL;
	status = cereal(&vector, 1, "ui32[10]", ui32_source_array);
	decereal(&vector, 1, "ui32[10]", &ui32_dest_array);

	//printf("%lu\n", (unsigned long)f[0]);
	
	/*b = (uint32_t *)(vector[0].iov_base);
	printf("%lu", (unsigned long)b[1]);

	f = *(uint32_t *)(vector[1].iov_base);
	printf("%lu", (unsigned long)f);*/

	//printf("%lu\n", (unsigned long)f[0]);
	//printf("%lu\n", (unsigned long)f[1]);
	ui32_dest_array[8] = 32;

	for(iterator = 0; iterator<10; iterator++)
		assert( ui32_dest_array[iterator] == ui32_source_array[iterator]);

	printf("uint32 array test passed for array size 10\n");


	/*----end test for uint32 array---*/





	return 0;

}