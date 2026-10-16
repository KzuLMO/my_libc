#include "my_libc.h"

size_t
my_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t len;
	size_t i;

	len = my_strlen(src);
	if (dstsize == 0)
		return (len);
	i = 0;
	while (i < dstsize - 1 && src[i] != '\0') {
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (len);
}
