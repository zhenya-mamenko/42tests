/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 20:53:48 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/18 16:02:19 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdarg.h>
#include "libtest.h"

int		g_test_level = -1;

static char *replace_word(const char *s, const char *oldW, const char *newW)
{
	char *result;
	int i, cnt = 0;
	int newWlen = strlen(newW);
	int oldWlen = strlen(oldW);

	for (i = 0; s[i] != '\0'; i++)
	{
		if (strstr(&s[i], oldW) == &s[i])
		{
			cnt++;
			i += oldWlen - 1;
		}
	}
	result = (char *)malloc(i + cnt * (newWlen - oldWlen) + 1);
	i = 0;
	while (*s)
	{
		if (strstr(s, oldW) == s)
		{
			strcpy(&result[i], newW);
			i += newWlen;
			s += oldWlen;
		}
		else
			result[i++] = *s++;
	}
	result[i] = '\0';
	return (result);
}

static char *escape_sym(char *s)
{
	return (replace_word(replace_word(s, "\n", "\\n"), "\t", "\\t"));
}

static void	r_itoa(long nb, char *s, int *index)
{
	if (nb < 0)
	{
		s[(*index)++] = '-';
		r_itoa(-nb, s, index);
	}
	else if (nb > 9)
	{
		r_itoa(nb / 10, s, index);
		r_itoa(nb % 10, s, index);
	}
	else
	{
		s[(*index)++] = nb + '0';
	}
	s[*index] = '\0';
}

static char		*itoa(long n)
{
	char	*s;
	int		i;

	i = 0;
	s = make_buf(12, '\0');
	if (s != NULL)
		r_itoa(n, s, &i);
	return (s);
}

char	*flatten_array_char(char **a)
{
	int		i;
	int		len;
	char	*s;

	i = 0;
	len = 0;
	while (a[i])
	{
		len += strlen(a[i]) + 1;
		i += 1;
	}
	len++;
	s = malloc(sizeof(char) * len);
	i = 0;
	len = 0;
	while (a[i])
	{
		strcpy(&s[len], a[i]);
		len += strlen(a[i]);
		s[len++] = '\n';
		i += 1;
	}
	s[len] = '\0';
	return (s);
}

char	*flatten_array_int(int *a, size_t n)
{
	size_t	i;
	int		len;
	char	*s, *e;

	s = make_buf(n * 12 + 1, '\0');
	i = 0;
	len = 0;
	while (i < n)
	{
		e = itoa(a[i]);
		strcpy(&s[len], e);
		len += strlen(e);
		free(e);
		s[len++] = '\t';
		i += 1;
	}
	s[len--] = '\0';
	e = strdup(s);
	free(s);
	return (e);
}

char	*flatten_array_uint(unsigned int *a, size_t n)
{
	size_t	i;
	int		len;
	char	*s, *e;

	s = make_buf(n * 12 + 1, '\0');
	i = 0;
	len = 0;
	while (i < n)
	{
		e = itoa(a[i]);
		strcpy(&s[len], e);
		len += strlen(e);
		free(e);
		s[len++] = '\t';
		i += 1;
	}
	s[len--] = '\0';
	e = strdup(s);
	free(s);
	return (e);
}

char	*flatten_array_uchar(unsigned char *a, size_t n)
{
	size_t	i;
	int		len;
	char	*s, *e;

	s = make_buf(n * 3 + 1, '\0');
	i = 0;
	len = 0;
	while (i < n)
	{
		e = itoa(a[i]);
		strcpy(&s[len], e);
		len += strlen(e);
		free(e);
		s[len++] = '\t';
		i += 1;
	}
	s[len--] = '\0';
	e = strdup(s);
	free(s);
	return (e);
}

void	margin(void)
{
	int	i;

	i = 0;
	while (i < g_test_level)
	{
		printf("\t");
		i += 1;
	}
}

static void	print_result(result)
{
	margin();
	if (result == 1)
		printf("\x1b[92;1mOK\x1b[0m");
	else if (result == 0)
		printf("\x1b[91;1mFAIL\x1b[0m");
	else if (result == 2)
		printf("\x1b[93mSKIP\x1b[0m");
}

char		*make_buf(size_t len, char c)
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

char		*make_string(char *src)
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

char		*wrapper_char_1(int argc, ...)
{
	va_list	arg_ptr;
	int		i;
	char	*value;

	va_start(arg_ptr, argc);
	i = 0;
	while (i < argc -1)
	{
		va_arg(arg_ptr, int);
		i += 1;
	}
	value = va_arg(arg_ptr, char *);
	va_end(arg_ptr);
	return (value);
}

int		skip_run_test_1(char *description, int *count, int argc)
{
	if (description) {};
	margin();
	printf("--\n");
	print_result(2);
	printf(" \x1b[39;1m%d/%d\x1b[0m\n\n", argc, argc);
	g_test_level--;
	*count += argc;
	g_all_tests_count += argc;
	return (argc);
}

int		run_test_1(char *description, int *count, int argc, ...)
{
	va_list	arg_ptr;
	int		i, result;

	if (description) {};
	va_start(arg_ptr, argc);
	i = 0;
	result = 0;
	while (i < argc)
	{
		result += va_arg(arg_ptr, int);
		i += 1;
	}
	va_end(arg_ptr);
	margin();
	printf("--\n");
	print_result(result == argc ? 1 : 0);
	printf(" \x1b[39;1m%d/%d\x1b[0m\n\n", result, argc);
	g_test_level--;
	*count += result;
	g_all_tests_count += argc;
	return (argc);
}

int		run_test_global_1(char *description, int *count, int argc, ...)
{
	va_list	arg_ptr;
	int		i, result;

	if (description) {};
	va_start(arg_ptr, argc);
	i = 0;
	result = 0;
	while (i < argc)
	{
		result += va_arg(arg_ptr, int);
		i += 1;
	}
	va_end(arg_ptr);
	margin();
	printf("--\n");
	*count += result;
	print_result(*count == g_all_tests_count ? 1 : 0);
	printf(" \x1b[39;1m%d/%d\x1b[0m\n\n", *count, g_all_tests_count);
	g_test_level--;
	return (g_all_tests_count);
}


char		*test_description(char *description)
{
	g_test_level++;
	margin();
	printf("\x1b[94;1m%s\x1b[0m\n", description);
	return (description);
}

int			expect_1(char *name, int type, ...)
{
	int		result, l, i_a1, i_a2;
	char	*b, *s_a1, *s_a2;
	va_list	arg_ptr;

	b = malloc(sizeof(char) * 1000);
	margin();
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
	else if (type == 2) // string
	{
		s_a1 = va_arg(arg_ptr, char*);
		s_a2 = va_arg(arg_ptr, char*);
		if (s_a1 == NULL || s_a2 == NULL)
			result = (s_a1 == s_a2) ? 1 : 0;
		else
			result = strcmp(s_a1, s_a2) == 0 ? 1 : 0;
		print_result(result);
		if (result == 0)
			printf(". Value: \x1b[1m%s\x1b[0m Expected: \x1b[1m%s\x1b[0m\n",
				escape_sym(s_a1), escape_sym(s_a2));
		else
			printf(".\n");
	}
	else if (type == 3) // void*
	{
		s_a1 = va_arg(arg_ptr, void*);
		s_a2 = va_arg(arg_ptr, void*);
		l = va_arg(arg_ptr, int);
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

void finish_test_block(int const count, int const all)
{
	margin();
	printf("    --\n");
	margin();
	if (count == all)
		printf("    \x1b[92;1mOK \x1b[39m%d/%d\x1b[0m\n\n", count, all);
	else
		printf("    \x1b[91;1mFAIL \x1b[39m%d/%d\x1b[0m\n\n", count, all);
}
