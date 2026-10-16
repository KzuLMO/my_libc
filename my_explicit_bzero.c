#include "my_libc.h"

void
my_explicit_bzero(void *buf, size_t len)
{
	volatile unsigned char *p;
	size_t i;

	p = buf;
	i = 0;
	while (i < len) {
		p[i] = 0;
		i++;
	}
}
