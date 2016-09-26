#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>


int cereal(struct iovec **, size_t , char *, ...);
int decereal(struct iovec **, size_t , char *, ...);
//int cereal_write()
