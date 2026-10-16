#include "my_libc.h"

size_t
my_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t dlen;
	size_t slen;
	size_t i;

	dlen = 0;
	while (dlen < dstsize && dst[dlen] != '\0')
		dlen++;
	slen = my_strlen(src);
	if (dlen == dstsize)
		return (dstsize + slen);
	i = 0;
	while (src[i] != '\0' && dlen + i < dstsize - 1) {
		dst[dlen + i] = src[i];
		i++;
	}
	dst[dlen + i] = '\0';
	return (dlen + slen);
}
