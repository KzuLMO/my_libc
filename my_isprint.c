#include "my_libc.h"

int
my_isprint(int c)
{
	if (c >= 32 && c <= 126)
		return (1);
	return (0);
}
