#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>

static void print_result(result)
{
	if (result == 1)
		printf("\x1b[92;1mOK\x1b[0m");
	else
		printf("\x1b[91;1mFAIL\x1b[0m");
}

char	*make_buf(size_t len, char c)
{
	char	*b;
	size_t	i;

	b = malloc(sizeof(char) * len);
	i = 0;
	while (i < len)
	{
		b[i] = c;
		i += 1;
	}
	return(b);
}

char	*make_string(char *src)
{
	char	*dest;
	int		i;

	dest = malloc(sizeof(char) * (strlen(src)+1));
	i = 0;
	while (src[i])
	{
		dest[i] = src[i];
		i += 1;
	}
	return (dest);
}

int	run_test(char *description, int count, ...)
{
	va_list	arg_ptr;
	int		i, result;
	
	if (description) {};
	va_start(arg_ptr, count);
	i = 0;
	result = 0;
	while (i < count)
	{
		result += va_arg(arg_ptr, int);
		i += 1;
	}
	va_end(arg_ptr);
	printf("  --\n  ");
	print_result(result == count ? 1 : 0);
	printf(" \x1b[39;1m%d/%d\x1b[0m\n\n", result, count);
	return (result == count ? 1 : 0);
}

char	*test_description(char *description)
{
	printf("\x1b[94;1m%s\x1b[0m\n", description);
	return (description);
}

int	expect(char *name, int type, ...)
{
	int		result, l, i_a1, i_a2;
	char	*b, c_a1, c_a2, *s_a1, *s_a2;
	va_list	arg_ptr;

	b = malloc(sizeof(char) * 1000);
	printf("  %s", name);
	va_start(arg_ptr, type);
	result = 0;
	if (type == 1) // int
	{
		i_a1 = va_arg(arg_ptr, int);
		i_a2 = va_arg(arg_ptr, int);
		result = i_a1 == i_a2 ? 1 : 0;
		print_result(result);
		if (result == 0)
			printf(". Value: \x1b[1m%d\x1b[0m Expected: \x1b[1m%d\x1b[0m\n", i_a1, i_a2);
		else
			printf(".\n");
	}
	else if (type == 2) // char
	{
		c_a1 = va_arg(arg_ptr, int);
		c_a2 = va_arg(arg_ptr, int);
		result = c_a1 == c_a2 ? 1 : 0;
		print_result(result);
		if (result == 0)
			printf(". Value: \x1b[1m%c\x1b[0m Expected: \x1b[1m%c\x1b[0m\n", c_a1, c_a2);
		else
			printf(".\n");
	}
	else if (type == 3) // string
	{
		s_a1 = va_arg(arg_ptr, char*);
		s_a2 = va_arg(arg_ptr, char*);
		if (s_a1 == NULL || s_a2 == NULL)
			result = (s_a1 == s_a2) ? 1 : 0;
		else
			result = strcmp(s_a1, s_a2) == 0 ? 1 : 0;
		print_result(result);
		if (result == 0)
			printf(". Value: \x1b[1m%s\x1b[0m Expected: \x1b[1m%s\x1b[0m\n", s_a1, s_a2);
		else
			printf(".\n");
	}
	else if (type == 4) // char*
	{
		l = va_arg(arg_ptr, int);
		s_a1 = va_arg(arg_ptr, char*);
		s_a2 = va_arg(arg_ptr, char*);
		if (s_a1 == NULL || s_a2 == NULL)
			result = (s_a1 == s_a2) ? 1 : 0;
		else
			result = memcmp(s_a1, s_a2, l) == 0 ? 1 : 0;
		print_result(result);
		printf(".\n");
	}
	
	va_end(arg_ptr);
	return (result);
}