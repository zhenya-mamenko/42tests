#include "libft.h"
#include "libtest.h"
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char	*a1, *a2;
	int		count, all;

	count = 0;
	all = 0;

	all++;
	count += run_test(test_description("memset"), 1,
		expect("10:\t\t", 3, ft_memset(make_string("ABCDEABCDE"), 'x', 10), memset(make_string("ABCDEABCDE"), 'x', 10))
		);

	a1 = make_buf(10, 'A'); ft_bzero(a1, 10);
	a2 = make_buf(10, 'A'); bzero(a2, 10);
	all++;
	count += run_test(test_description("bzero"), 1,
		expect("10:\t\t", 4, 10, a1, a2)
		);

	ft_memcpy(a1, "1234567890", 10);
	memcpy(a2, "1234567890", 10);
	all++;
	count += run_test(test_description("memcpy"), 1,
		expect("10:\t\t", 4, 10, a1, a2)
		);

	bzero(a1, 10); bzero(a2, 10);
	ft_memccpy(a1, "1234567890", '3', 10);
	memccpy(a2, "1234567890", '3', 10);
	all++;
	count += run_test(test_description("memccpy"), 1,
		expect("10:\t\t", 4, 10, a1, a2)
		);

	memcpy(a1, "1234567890", 10);
	memcpy(a2, "1234567890", 10);
	all++;
	count += run_test(test_description("memmove"), 2,
		expect("diff strs:\t", 4, 10, ft_memmove(a1, "ABCDE", 4), memmove(a2, "ABCDE", 4)),
		expect("same strs:\t", 4, 10, ft_memmove(a1, a1 + 2, 4), memmove(a2, a2 + 2, 4))
		);

	all++;
	count += run_test(test_description("memchr"), 2,
		expect("none:\t\t", 3, ft_memchr(make_string("ABCDEABCDE"), 'x', 10), memchr(make_string("ABCDEABCDE"), 'x', 10)),
		expect("E:\t\t", 3, ft_memchr(make_string("ABCDEABCDE"), 'E', 10), memchr(make_string("ABCDEABCDE"), 'E', 10))
		);

	all++;
	count += run_test(test_description("memcmp"), 2,
		expect("same:\t\t", 1, ft_memcmp("ABCDEABCDE", "ABCDEABCDE", 10), memcmp("ABCDEABCDE", "ABCDEABCDE", 10)),
		expect("diff:\t\t", 1, ft_memcmp("ABCDEABCDE", "ABCDE1BCDE", 10), memcmp("ABCDEABCDE", "ABCDE1BCDE", 10)),
		expect("empty:\t", 1, ft_memcmp("", "", 0), memcmp("", "", 0))
		);

	all++;
	count += run_test(test_description("strlen"), 2,
		expect("10:\t\t", 1, ft_strlen("ABCDEABCDE"), strlen("ABCDEABCDE")),
		expect("empty:\t", 1, ft_strlen(""), strlen(""))
		);

	all++;
	count += run_test(test_description("strdup"), 1,
		expect("10:\t\t", 3, ft_strdup("ABCDEABCDE"), strdup("ABCDEABCDE"))
		);

	all++;
	count += run_test(test_description("strcpy"), 2,
		expect("12345:\t", 3, ft_strcpy(make_string("ABCDEABCDE"), "12345"), strcpy(make_string("ABCDEABCDE"), "12345")),
		expect("empty:\t", 3, ft_strcpy(make_string("ABCDEABCDE"), ""), strcpy(make_string("ABCDEABCDE"), ""))
		);

	all++;
	count += run_test(test_description("strncpy"), 3,
		expect("3:\t\t", 3, ft_strncpy(make_string("ABCDEABCDE"), "12345", 3), strncpy(make_string("ABCDEABCDE"), "12345", 3)),
		expect("6:\t\t", 3, ft_strncpy(make_string("ABCDEABCDE"), "12345", 6), strncpy(make_string("ABCDEABCDE"), "12345", 6)),
		expect("0:\t\t", 3, ft_strncpy(make_string("ABCDEABCDE"), "12345", 0), strncpy(make_string("ABCDEABCDE"), "12345", 0))
		);

	memcpy(a1, "123\0", 10);
	memcpy(a2, "123\0", 10);
	ft_strcat(a1, "456");
	strcat(a2, "456");
	all++;
	count += run_test(test_description("strcat"), 1,
		expect("123456:\t", 3, a1, a2)
		);

	memcpy(a1, "123\0", 10);
	memcpy(a2, "123\0", 10);
	ft_strcat(a1, "456789");
	strcat(a2, "456789");
	all++;
	count += run_test(test_description("strncat"), 3,
		expect("1234:\t\t", 3, a1, a2),
		expect("1234:\t\t", 3, a1, a2),
		expect("123456:\t", 3, a1, a2)
		);

	all++;
	count += run_test(test_description("isalpha"), 3,
		expect("1:\t\t", 1, ft_isalpha('1'), isalpha('1')),
		expect("f:\t\t", 1, ft_isalpha('f'), isalpha('f')),
		expect("' ':\t\t", 1, ft_isalpha(' '), isalpha(' '))
		);

	all++;
	count += run_test(test_description("isalnum"), 3,
		expect("1:\t\t", 1, ft_isalnum('1'), isalnum('1')),
		expect("f:\t\t", 1, ft_isalnum('f'), isalnum('f')),
		expect("' ':\t\t", 1, ft_isalnum(' '), isalnum(' '))
		);

	all++;
	count += run_test(test_description("isdigit"), 2,
		expect("1:\t\t", 1, ft_isdigit('1'), isdigit('1')),
		expect("f:\t\t", 1, ft_isdigit('f'), isdigit('f'))
		);

	all++;
	count += run_test(test_description("isascii"), 2,
		expect("'1':\t\t", 1, ft_isascii('1'), isascii('1')),
		expect("180:\t\t", 1, ft_isascii(180), isascii(180))
		);

	all++;
	count += run_test(test_description("isprint"), 3,
		expect("'1':\t\t", 1, ft_isprint('1'), isprint('1')),
		expect("127:\t\t", 1, ft_isprint(127), isprint(127)),
		expect("126:\t\t", 1, ft_isprint(126), isprint(126))
		);

	all++;
	count += run_test(test_description("toupper"), 2,
		expect("f:\t\t", 1, ft_toupper('f'), toupper('f')),
		expect("A:\t\t", 1, ft_toupper('A'), toupper('A'))
		);

	all++;
	count += run_test(test_description("tolower"), 2,
		expect("f:\t\t", 1, ft_tolower('f'), tolower('f')),
		expect("A:\t\t", 1, ft_tolower('A'), tolower('A'))
		);

	printf("---------\n\n");
	if (count == all)
		printf("\x1b[92;1mOK \x1b[39m%d/%d\x1b[0m\n", count, all);
	else
		printf("\x1b[91;1mFAIL \x1b[39m%d/%d\x1b[0m\n", count, all);

	return (0);
}
