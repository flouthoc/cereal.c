#include "cereal.h"
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>



struct book{

	int a;
	char q[3];
	
};


int main(){

	int status, iterator;

	struct iovec *vector;
	struct iovec *readVector;

		/*--test for disk-io -- */
	{

		int file;
		uint32_t ui32_dest_array[10];
		uint32_t ui32_source_array[10];
		uint32_t ui32_buffer[10];

		for(iterator = 0; iterator<10; iterator++){
			//ui32_source_array[iterator] = rand();
			//ui32_source_array[iterator] %= 10;
			ui32_source_array[iterator] = 3;
		}

		vector = NULL;
		status = cereal(&vector, 1, "ui32[10]", ui32_source_array);

		file = open("data", O_RDWR | O_CREAT);

		if(file < 0)
			perror("File");

		if((writev(file, vector, 1)) == -1)
			perror("Vector write");

		close(file);

		decereal_read_struct(&readVector, 1, "ui32[10]", ui32_dest_array);

		file = open("data", O_RDONLY);

		if(file < 0)
			perror("File");

		if((readv(file, readVector, 1)) == -1)
			perror("Vector read only");

		close(file);





		//decereal(&vector, 1, "ui32[10]", &ui32_dest_array);

		//printf("%lu\n", (unsigned long)f[0]);
		
		/*b = (uint32_t *)(vector[0].iov_base);
		printf("%lu", (unsigned long)b[1]);

		f = *(uint32_t *)(vector[1].iov_base);
		printf("%lu", (unsigned long)f);*/

		//printf("%lu\n", (unsigned long)f[0]);
		//printf("%lu\n", (unsigned long)f[1]);

		for(iterator = 0; iterator<10; iterator++)
			assert( ui32_dest_array[iterator] == ui32_source_array[iterator]);

		printf("Disk IO array test passed for array size 10 and datatype uint32_t\n");

	}
	/*----end test for disk-io---*/


	/*--test for uint32 array -- */
	{

		int file;
		uint32_t ui32_dest_array[10];
		uint32_t ui32_source_array[10];
		uint32_t ui32_buffer[10];

		for(iterator = 0; iterator<10; iterator++){
			ui32_source_array[iterator] = rand();
			//ui32_source_array[iterator] %= 10;
			//ui32_source_array[iterator] = 3;
		}

		//readVector[0].iov_base = ui32_buffer;
		//readVector[0].iov_len = 10 * sizeof(uint32_t);

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

		for(iterator = 0; iterator<10; iterator++)
			assert( ui32_dest_array[iterator] == ui32_source_array[iterator]);

		printf("uint32 array test passed for array size 10\n");

	}
	/*----end test for uint32 array---*/



	/*--test for uint32-- */
	{

		uint32_t ui32_dest;
		uint32_t ui32_source;
		
		ui32_source = rand();

		vector = NULL;
		status = cereal(&vector, 1, "ui32", ui32_source);
		decereal(&vector, 1, "ui32", &ui32_dest);

		assert( ui32_dest == ui32_source);

		printf("uint32 test passed\n");

	}
	/*----end test for uint32--*/

	/*--test for uint64 array -- */
	{

		uint64_t ui64_dest_array[10];
		uint64_t ui64_source_array[10];

		for(iterator = 0; iterator<10; iterator++)
			ui64_source_array[iterator] = rand();

		vector = NULL;
		status = cereal(&vector, 1, "ui64[10]", ui64_source_array);
		decereal(&vector, 1, "ui64[10]", &ui64_dest_array);

		//printf("%lu\n", (unsigned long)f[0]);
		
		/*b = (uint32_t *)(vector[0].iov_base);
		printf("%lu", (unsigned long)b[1]);

		f = *(uint32_t *)(vector[1].iov_base);
		printf("%lu", (unsigned long)f);*/

		//printf("%lu\n", (unsigned long)f[0]);
		//printf("%lu\n", (unsigned long)f[1]);

		for(iterator = 0; iterator<10; iterator++)
			assert( ui64_dest_array[iterator] == ui64_source_array[iterator]);

		printf("uint64 array test passed for array size 10\n");

	}
	/*----end test for uint64 array---*/

	/*--test for uint64-- */
	{

		uint64_t ui64_dest;
		uint64_t ui64_source;
		
		ui64_source = rand();

		vector = NULL;
		status = cereal(&vector, 1, "ui64", ui64_source);
		decereal(&vector, 1, "ui64", &ui64_dest);

		assert( ui64_dest == ui64_source);

		printf("uint64 test passed\n");

	}
	/*----end test for uint64--*/


	/*--test for uint8 array -- */
	{

		uint8_t ui8_dest_array[10];
		uint8_t ui8_source_array[10];

		for(iterator = 0; iterator<10; iterator++)
			ui8_source_array[iterator] = rand();

		vector = NULL;
		status = cereal(&vector, 1, "ui8[10]", ui8_source_array);
		decereal(&vector, 1, "ui8[10]", &ui8_dest_array);

		//printf("%lu\n", (unsigned long)f[0]);
		
		/*b = (uint32_t *)(vector[0].iov_base);
		printf("%lu", (unsigned long)b[1]);

		f = *(uint32_t *)(vector[1].iov_base);
		printf("%lu", (unsigned long)f);*/

		//printf("%lu\n", (unsigned long)f[0]);
		//printf("%lu\n", (unsigned long)f[1]);

		for(iterator = 0; iterator<10; iterator++)
			assert( ui8_dest_array[iterator] == ui8_source_array[iterator]);

		printf("uint8 array test passed for array size 10\n");

	}
	/*----end test for uin8 array---*/

	/*--test for uint8-- */
	{

		uint8_t ui8_dest;
		uint8_t ui8_source;
		
		ui8_source = rand();

		vector = NULL;
		status = cereal(&vector, 1, "ui8", ui8_source);
		decereal(&vector, 1, "ui8", &ui8_dest);

		assert( ui8_dest == ui8_source);

		printf("uint8 test passed\n");

	}
	/*----end test for uint8--*/

	/*--test for char array (string) -- */
	{

		char char_dest_array[10];
		char char_source_array[10] = "hello";


		vector = NULL;
		status = cereal(&vector, 1, "char[10]", char_source_array);
		decereal(&vector, 1, "char[10]", &char_dest_array);

		//printf("%lu\n", (unsigned long)f[0]);
		
		/*b = (uint32_t *)(vector[0].iov_base);
		printf("%lu", (unsigned long)b[1]);

		f = *(uint32_t *)(vector[1].iov_base);
		printf("%lu", (unsigned long)f);*/

		//printf("%lu\n", (unsigned long)f[0]);
		//printf("%lu\n", (unsigned long)f[1]);

		for(iterator = 0; iterator<10; iterator++)
			assert( char_dest_array[iterator] == char_source_array[iterator]);

		assert(strcmp(char_source_array, char_dest_array) == 0);

		printf("char array/string array test passed for array size 10\n");

	}
	/*----end test for char array---*/

	/*--test for char-- */
	{

		char char_dest;
		char char_source;
		
		char_source = rand();

		vector = NULL;
		status = cereal(&vector, 1, "char", char_source);
		decereal(&vector, 1, "char", &char_dest);

		assert( char_dest == char_source);

		printf("char test passed\n");

	}
	/*----end test for uint8--*/






	return 0;

}