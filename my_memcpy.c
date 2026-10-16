#include "my_libc.h"

void *
my_memcpy(void *dst, const void *src, size_t len)
{
	unsigned char *d;
	const unsigned char *s;
	size_t i;

	d = dst;
	s = src;
	i = 0;
	while (i < len) {
		d[i] = s[i];
		i++;
	}
	return (dst);
}
