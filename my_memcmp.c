#include "my_libc.h"

int
my_memcmp(const void *b1, const void *b2, size_t len)
{
	const unsigned char *p1;
	const unsigned char *p2;
	size_t i;

	p1 = b1;
	p2 = b2;
	i = 0;
	while (i < len) {
		if (p1[i] != p2[i])
			return (p1[i] - p2[i]);
		i++;
	}
	return (0);
}
