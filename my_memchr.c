#include "my_libc.h"

void *
my_memchr(const void *b, int c, size_t len)
{
	const unsigned char *p;
	size_t i;

	p = b;
	i = 0;
	while (i < len) {
		if (p[i] == (unsigned char)c)
			return ((void *)&p[i]);
		i++;
	}
	return (NULL);
}
