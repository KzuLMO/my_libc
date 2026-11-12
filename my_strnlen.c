#include "my_libc.h"

size_t
my_strnlen(const char *s, size_t maxlen)
{
	size_t i;

	i = 0;
	while (i < maxlen && s[i] != '\0')
		i++;
	return (i);
}
