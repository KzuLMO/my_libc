#include "my_libc.h"

int
my_isalnum(int c)
{
	if (my_isalpha(c) || my_isdigit(c))
		return (1);
	return (0);
}
