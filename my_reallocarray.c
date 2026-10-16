#include <errno.h>
#include <stdlib.h>
#include "my_libc.h"

void *
my_reallocarray(void *ptr, size_t nmemb, size_t size)
{
	if (nmemb != 0 && size > (size_t)-1 / nmemb) {
		errno = ENOMEM;
		return (NULL);
	}
	return (realloc(ptr, nmemb * size));
}
