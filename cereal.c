#include "cereal.h"

#include <stdio.h>

static int _cereal_core(struct iovec *, size_t items, char *format, va_list);
static size_t _cereal_parse_arraysize(char *format);
static char * _cereal_utils_leftTrim(char *str);
static char * _cereal_utils_rightTrim(char *str);
static int _de_cereal_core(struct iovec **user_vector, size_t items, char *format, va_list);


int decereal(struct iovec **user_vector, size_t items, char *format, ...){

	int status;
	va_list ap;
	va_start(ap, format);
	status = _de_cereal_core(user_vector, items, format, ap);
	va_end(ap);
	//*user_vector = iov;
	return status;

}

static int _de_cereal_core(struct iovec **user_vector, size_t items, char *format, va_list ap){

	size_t i;
	size_t j;
	size_t k;
	size_t m;
	char *buf;
	char *buf_head;
	size_t length = strlen(format);
	buf_head = malloc(100);
	buf = buf_head;
	memset(buf, 0, 100);
	//uint32_t buf_uint32;
	//buf_uint32 = va_arg(ap, uint32_t);
	//printf("%lu", (unsigned long)buf_uint32);	
	j=0;
	for(i=0; i<items; i++){

		m = 0;
		buf = buf_head;
		while(j < length && format[j] != ','){

			buf[m] = format[j];
			m++;
			j++;
		}

		if(format[j] == ',')
			j++;

		buf[m] = '\0';
		buf = _cereal_utils_leftTrim(buf);
		buf = _cereal_utils_rightTrim(buf);


		if(strstr(buf, "ui32")){

			printf("here\n");

			//if((*user_vector)[i].iov_len == sizeof(unsigned long)){
				uint32_t f;
				f = *(uint32_t *)((*user_vector)[i].iov_base);
				printf("%lu\n", (unsigned long)f);
			//}



		}



	}

}

int cereal(struct iovec **user_vector, size_t items, char *format, ...){

	int status;
	struct iovec *iov;
	va_list ap;
	iov = malloc(items * sizeof(struct iovec));
	va_start(ap, format);
	status = _cereal_core(iov, items, format, ap);
	va_end(ap);
	*user_vector = iov;
	return status;
}


static int _cereal_core(struct iovec *iov, size_t items, char *format, va_list ap){

		size_t i;
		size_t j;
		size_t k;
		size_t m;
		char *buf;
		char *buf_head;
		size_t length = strlen(format);
		buf_head = malloc(100);
		buf = buf_head;
		memset(buf, 0, 100);
		//uint32_t buf_uint32;
		//buf_uint32 = va_arg(ap, uint32_t);
		//printf("%lu", (unsigned long)buf_uint32);	
		j=0;
		for(i=0; i<items; i++){

				m = 0;
				buf = buf_head;
				while(j < length && format[j] != ','){

					buf[m] = format[j];
					m++;
					j++;
				}

				if(format[j] == ',')
					j++;

				buf[m] = '\0';
				buf = _cereal_utils_leftTrim(buf);
				buf = _cereal_utils_rightTrim(buf);


				/*write the f(kin) parser*/ 
				if(strstr(buf, "ui32[")){

					printf("Just parsed a ui32[\n");


					int j;
					uint32_t *buf_array, *store_array;
					size_t arraysize = _cereal_parse_arraysize(buf);
					store_array = va_arg(ap, uint32_t *);
					buf_array = (uint32_t *)calloc(arraysize, sizeof(uint32_t));


					for(j=0; j<arraysize; j++)
						buf_array[j] = store_array[j];

					//printf("%lu", (unsigned long)buf_array[0]);

					iov[i].iov_base = buf_array;
					iov[i].iov_len = arraysize*sizeof(uint32_t);

					//store_array = (uint32_t *)(iov[i].iov_base);					
					//printf("%lu\n", (unsigned long)store_array[0]);

					//printf("%s", buf);
					/*uint32_t *buf_uint32 = malloc(sizeof(uint32_t)); 
					*buf_uint32 = va_arg(ap, uint32_t);
					iov[i].iov_base = buf_uint32;
					iov[i].iov_len = sizeof(uint32_t);*/
					//printf("%lu", (unsigned long)(*buf_uint32));		

				}
				else if(!strcmp(buf, "ui32")){

					printf("Just parsed a ui32\n");

					uint32_t *buf_uint32 = malloc(sizeof(uint32_t)); 
					*buf_uint32 = va_arg(ap, uint32_t);
					//printf("%lu", (unsigned long)(*buf_uint32));
					iov[i].iov_base = buf_uint32;
					iov[i].iov_len = sizeof(uint32_t);

				}else if(strstr(buf, "ui64[")){

					printf("Just parsed a ui64[\n");


					int j;
					uint64_t *buf_array, *store_array;
					size_t arraysize = _cereal_parse_arraysize(buf);
					store_array = va_arg(ap, uint64_t *);
					buf_array = (uint64_t *)calloc(arraysize, sizeof(uint64_t));


					for(j=0; j<arraysize; j++)
						buf_array[j] = store_array[j];

					//printf("%lu", (unsigned long)buf_array[0]);

					iov[i].iov_base = buf_array;
					iov[i].iov_len = arraysize*sizeof(uint64_t);

					//store_array = (uint32_t *)(iov[i].iov_base);					
					//printf("%lu\n", (unsigned long)store_array[0]);

					//printf("%s", buf);
					/*uint32_t *buf_uint32 = malloc(sizeof(uint32_t)); 
					*buf_uint32 = va_arg(ap, uint32_t);
					iov[i].iov_base = buf_uint32;
					iov[i].iov_len = sizeof(uint32_t);*/
					//printf("%lu", (unsigned long)(*buf_uint32));		

				}
				else if(!strcmp(buf, "ui64")){

					printf("Just parsed a ui64\n");

					uint32_t *buf_uint64 = malloc(sizeof(uint64_t)); 
					*buf_uint64 = va_arg(ap, uint64_t);
					//printf("%lu", (unsigned long)(*buf_uint32));
					iov[i].iov_base = buf_uint64;
					iov[i].iov_len = sizeof(uint64_t);

				}else if(strstr(buf, "ui16[")){

					printf("Just parsed a ui16[\n");


					int j;
					uint16_t *buf_array, *store_array;
					size_t arraysize = _cereal_parse_arraysize(buf);
					store_array = va_arg(ap, uint16_t *);
					buf_array = (uint16_t *)calloc(arraysize, sizeof(uint16_t));


					for(j=0; j<arraysize; j++)
						buf_array[j] = store_array[j];

					//printf("%lu", (unsigned long)buf_array[0]);

					iov[i].iov_base = buf_array;
					iov[i].iov_len = arraysize*sizeof(uint16_t);

					//store_array = (uint32_t *)(iov[i].iov_base);					
					//printf("%lu\n", (unsigned long)store_array[0]);

					//printf("%s", buf);
					/*uint32_t *buf_uint32 = malloc(sizeof(uint32_t)); 
					*buf_uint32 = va_arg(ap, uint32_t);
					iov[i].iov_base = buf_uint32;
					iov[i].iov_len = sizeof(uint32_t);*/
					//printf("%lu", (unsigned long)(*buf_uint32));		

				}
				else if(!strcmp(buf, "ui16")){

					printf("Just parsed a ui16\n");

					uint32_t *buf_uint16 = malloc(sizeof(uint16_t)); 
					*buf_uint16 = (uint16_t)va_arg(ap, int);
					//printf("%lu", (unsigned long)(*buf_uint32));
					iov[i].iov_base = buf_uint16;
					iov[i].iov_len = sizeof(uint16_t);

				}else if(strstr(buf, "ui8[")){

					printf("Just parsed a ui8[\n");


					int j;
					uint8_t *buf_array, *store_array;
					size_t arraysize = _cereal_parse_arraysize(buf);
					store_array = va_arg(ap, uint8_t *);
					buf_array = (uint8_t *)calloc(arraysize, sizeof(uint8_t));


					for(j=0; j<arraysize; j++)
						buf_array[j] = store_array[j];

					//printf("%lu", (unsigned long)buf_array[0]);

					iov[i].iov_base = buf_array;
					iov[i].iov_len = arraysize*sizeof(uint8_t);

					//store_array = (uint32_t *)(iov[i].iov_base);					
					//printf("%lu\n", (unsigned long)store_array[0]);

					//printf("%s", buf);
					/*uint32_t *buf_uint32 = malloc(sizeof(uint32_t)); 
					*buf_uint32 = va_arg(ap, uint32_t);
					iov[i].iov_base = buf_uint32;
					iov[i].iov_len = sizeof(uint32_t);*/
					//printf("%lu", (unsigned long)(*buf_uint32));		

				}
				else if(!strcmp(buf, "ui8")){

					printf("Just parsed a ui8\n");

					uint8_t *buf_uint8 = malloc(sizeof(uint8_t)); 
					*buf_uint8 = (uint8_t)va_arg(ap, int);
					//printf("%lu", (unsigned long)(*buf_uint32));
					iov[i].iov_base = buf_uint8;
					iov[i].iov_len = sizeof(uint8_t);

				}else if(strstr(buf, "char[")){

					printf("Just parsed a char[\n");


					int j;
					char *buf_array, *store_array;
					size_t arraysize = _cereal_parse_arraysize(buf);
					store_array = va_arg(ap, char *);
					buf_array = (char *)calloc(arraysize, sizeof(char));


					for(j=0; j<arraysize; j++)
						buf_array[j] = store_array[j];

					//printf("%lu", (unsigned long)buf_array[0]);

					iov[i].iov_base = buf_array;
					iov[i].iov_len = arraysize*sizeof(char);

					//store_array = (uint32_t *)(iov[i].iov_base);					
					//printf("%lu\n", (unsigned long)store_array[0]);

					//printf("%s", buf);
					/*uint32_t *buf_uint32 = malloc(sizeof(uint32_t)); 
					*buf_uint32 = va_arg(ap, uint32_t);
					iov[i].iov_base = buf_uint32;
					iov[i].iov_len = sizeof(uint32_t);*/
					//printf("%lu", (unsigned long)(*buf_uint32));		

				}
				else if(!strcmp(buf, "char")){

					printf("Just parsed a char\n");

					char *buf_char = malloc(sizeof(char)); 
					*buf_char = (char)va_arg(ap, int);
					//printf("%lu", (unsigned long)(*buf_uint32));
					iov[i].iov_base = buf_char;
					iov[i].iov_len = sizeof(char);
				}


		}

		free(buf_head);


}



static size_t _cereal_parse_arraysize(char *format){

	int j;
	char size_buf[10000];
	char *ptr = format;
	j=0;

	while(*ptr != '[')
		ptr++;
	ptr++;
	while(*ptr != ']'){

		size_buf[j] = *ptr;
		j++;
		ptr++;
	}

	size_buf[j] = '\0';
	return (size_t)atoi(size_buf);

}


static char *_cereal_utils_leftTrim(char *str){

	while(*str == ' ')
		str++;
	return str;
}

char *_cereal_utils_rightTrim(char *str){

	char *buf = str;
	while(*buf != '\0')
		buf++;

	buf--;
	while(*(buf) == ' '){
		*(buf) = '\0';
		buf--;
	}
	return str;
}