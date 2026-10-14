#include "my_libc.h"

char *
my_strrchr(const char *s, int c)
{
	char *last;
	size_t i;

	last = NULL;
	i = 0;
	while (s[i] != '\0') {
		if (s[i] == (char)c)
			last = (char *)&s[i];
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&s[i]);
	return (last);
}
