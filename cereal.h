#include <string.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>

/* ui8 - unsigned 8 bit int
   ui32 - unsigned 32 bit int
   ui16 - unsigned 16 bit int
   ui64 - unsigned 64 bit int
   char - char

   ui32[<size>] - array
   ui16[<size>] - array
   ui64[<size>] - array
   char[<size>] - array
*/

//int cereal_write(struct iovec **, size_t , char *, ...);
int decereal_read_struct(struct iovec **, size_t, char *, ...);
int cereal(struct iovec **, size_t , char *, ...);
int decereal(struct iovec **, size_t , char *, ...);
//int cereal_write()
