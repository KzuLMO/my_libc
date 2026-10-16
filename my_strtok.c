#include "my_libc.h"

static int
is_delim(char c, const char *delim)
{
	size_t i;

	i = 0;
	while (delim[i] != '\0') {
		if (delim[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char *
my_strtok(char *str, const char *delim)
{
	static char *next = NULL;
	char *token;

	if (str != NULL)
		next = str;
	if (next == NULL)
		return (NULL);
	while (*next != '\0' && is_delim(*next, delim))
		next++;
	if (*next == '\0') {
		next = NULL;
		return (NULL);
	}
	token = next;
	while (*next != '\0' && !is_delim(*next, delim))
		next++;
	if (*next != '\0') {
		*next = '\0';
		next++;
	} else
		next = NULL;
	return (token);
}
