#include <errno.h>
#include <limits.h>

#include "my_libc.h"

static int
digit_value(char c)
{
	if (c >= '0' && c <= '9')
		return (c - '0');
	if (c >= 'a' && c <= 'z')
		return (c - 'a' + 10);
	if (c >= 'A' && c <= 'Z')
		return (c - 'A' + 10);
	return (36);
}

static const char *
skip_prefix(const char *s, int *base)
{
	if ((*base == 0 || *base == 16) && s[0] == '0' &&
	    (s[1] == 'x' || s[1] == 'X') && digit_value(s[2]) < 16) {
		*base = 16;
		return (s + 2);
	}
	if (*base == 0) {
		if (s[0] == '0')
			*base = 8;
		else
			*base = 10;
	}
	return (s);
}

long
my_strtol(const char *nptr, char **endptr, int base)
{
	const char *s;
	unsigned long res;
	unsigned long limit;
	int neg;
	int over;

	if (endptr != NULL)
		*endptr = (char *)nptr;
	if (base < 0 || base == 1 || base > 36) {
		errno = EINVAL;
		return (0);
	}
	s = nptr;
	while (my_isspace(*s))
		s++;
	neg = 0;
	if (*s == '+' || *s == '-') {
		if (*s == '-')
			neg = 1;
		s++;
	}
	s = skip_prefix(s, &base);
	if (digit_value(*s) >= base)
		return (0);
	limit = LONG_MAX;
	if (neg)
		limit = (unsigned long)LONG_MAX + 1;
	res = 0;
	over = 0;
	while (digit_value(*s) < base) {
		if (res > (limit - digit_value(*s)) / base)
			over = 1;
		else
			res = res * base + digit_value(*s);
		s++;
	}
	if (endptr != NULL)
		*endptr = (char *)s;
	if (over) {
		errno = ERANGE;
		if (neg)
			return (LONG_MIN);
		return (LONG_MAX);
	}
	if (neg && res != 0)
		return (-(long)(res - 1) - 1);
	return ((long)res);
}
