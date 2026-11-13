#include "my_libc.h"

int
my_atoi(const char *nptr)
{
	long res;
	int sign;
	size_t i;

	res = 0;
	sign = 1;
	i = 0;
	while (my_isspace(nptr[i]))
		i++;
	if (nptr[i] == '+' || nptr[i] == '-') {
		if (nptr[i] == '-')
			sign = -1;
		i++;
	}
	while (my_isdigit(nptr[i])) {
		res = res * 10 + (nptr[i] - '0');
		i++;
	}
	return ((int)(res * sign));
}
