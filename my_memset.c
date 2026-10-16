#include "my_libc.h"

void *
my_memset(void *b, int c, size_t len)
{
	unsigned char *p;
	size_t i;

	p = b;
	i = 0;
	while (i < len) {
		p[i] = (unsigned char)c;
		i++;
	}
	return (b);
}
