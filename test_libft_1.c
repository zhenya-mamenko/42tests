#include "libft/libft.h"
#include "libtest.h"
#include <stdio.h>
#include <ctype.h>

int	test_part1(void)
{
	char	*a1, *a2;
	int		count, all;

	margin();
	printf("    \x1b[1;39mpart 1\x1b[0m\n");

	count = 0;
	all = 0;

	all += run_test(test_description("memset"), &count,
		expect("10:\t", ft_memset(make_string("ABCDEABCDE"), 'x', 10), memset(make_string("ABCDEABCDE"), 'x', 10), 10)
		);

	a1 = make_buf(10, 'A'); ft_bzero(a1, 10);
	a2 = make_buf(10, 'A'); bzero(a2, 10);
	all += run_test(test_description("bzero"), &count,
		expect("10:\t", (void *)a1, (void *)a2, 10)
		);

	ft_memcpy(a1, "1234567890", 10);
	memcpy(a2, "1234567890", 10);
	all += run_test(test_description("memcpy"), &count,
		expect("10:\t", (void *)a1, (void *)a2, 10)
		);

	bzero(a1, 10); bzero(a2, 10);
	ft_memccpy(a1, "1234567890", '3', 10);
	memccpy(a2, "1234567890", '3', 10);
	all += run_test(test_description("memccpy"), &count,
		expect("10:\t", (void *)a1, (void *)a2, 10)
		);

	memcpy(a1, "1234567890", 10);
	memcpy(a2, "1234567890", 10);
	all += run_test(test_description("memmove"), &count,
		expect("diff strs:", ft_memmove(a1, "ABCDE", 4), memmove(a2, "ABCDE", 4), 10),
		expect("same strs:", ft_memmove(a1, a1 + 2, 4), memmove(a2, a2 + 2, 4), 10)
		);

	all += run_test(test_description("memchr"), &count,
		expect("none:\t", (char *)ft_memchr(make_string("ABCDEABCDE"), 'x', 10), (char *)memchr(make_string("ABCDEABCDE"), 'x', 10)),
		expect("E:\t", (char *)ft_memchr(make_string("ABCDEABCDE"), 'E', 10), (char *)memchr(make_string("ABCDEABCDE"), 'E', 10))
		);

	all += skip_run_test(test_description("memcmp"), &count,
		expect("same:\t", ft_memcmp("ABCDEABCDE", "ABCDEABCDE", 10), memcmp("ABCDEABCDE", "ABCDEABCDE", 10)),
		expect("diff:\t", ft_memcmp("ABCDEABCDE", "ABCDE1BCDE", 10), memcmp("ABCDEABCDE", "ABCDE1BCDE", 10)),
		expect("bin:\t", ft_memcmp("\xff\xaa\xde\xffMACOSX\xff", "\xff\xaa\xde\x02", 10),
			memcmp("\xff\xaa\xde\xffMACOSX\xff", "\xff\xaa\xde\x02", 10)),
		expect("empty:", ft_memcmp("", "", 0), memcmp("", "", 0))
		);

	all += run_test(test_description("strlen"), &count,
		expect("10:\t", ft_strlen("ABCDEABCDE"), strlen("ABCDEABCDE")),
		expect("empty:", ft_strlen(""), strlen(""))
		);

	all += run_test(test_description("strdup"), &count,
		expect("10:\t", ft_strdup("ABCDEABCDE"), strdup("ABCDEABCDE"))
		);

	all += run_test(test_description("strcpy"), &count,
		expect("12345:", ft_strcpy(make_string("ABCDEABCDE"), "12345"), strcpy(make_string("ABCDEABCDE"), "12345")),
		expect("empty:", ft_strcpy(make_string("ABCDEABCDE"), ""), strcpy(make_string("ABCDEABCDE"), ""))
		);

	all += run_test(test_description("strncpy"), &count,
		expect("3:\t", ft_strncpy(make_string("ABCDEABCDE"), "12345", 3), strncpy(make_string("ABCDEABCDE"), "12345", 3)),
		expect("6:\t", ft_strncpy(make_string("ABCDEABCDE"), "12345", 6), strncpy(make_string("ABCDEABCDE"), "12345", 6)),
		expect("0:\t", ft_strncpy(make_string("ABCDEABCDE"), "12345", 0), strncpy(make_string("ABCDEABCDE"), "12345", 0))
		);

	bzero(a1, 10); bzero(a2, 10);
	memcpy(a1, "123", 3);
	memcpy(a2, "123", 3);
	ft_strcat(a1, "456");
	strcat(a2, "456");
	all += run_test(test_description("strcat"), &count,
		expect("123456:", a1, a2)
		);

	memcpy(a1, "123\0", 4);
	memcpy(a2, "123\0", 4);
	all += run_test(test_description("strncat"), &count,
		expect("1:\t", wrapper_char(ft_strncat(a1, "456789", 1), a1), wrapper_char(strncat(a2, "456789", 1), a2)),
		expect("0:\t", wrapper_char(ft_strncat(a1, "456789", 0), a1), wrapper_char(strncat(a2, "456789", 0), a2)),
		expect("10:\t", wrapper_char(ft_strncat(a1, "56789", 10), a1), wrapper_char(strncat(a2, "56789", 10), a2))
		);

	bzero(a1, 10); bzero(a2, 10);
	memcpy(a1, "123", 3);
	memcpy(a2, "123", 3);
	all += run_test(test_description("strlcat"), &count,
		expect("0:\t", ft_strlcat(a1, "Z", 0), strlcat(a2, "Z", 0)),
		expect("0=:\t", a1, a2),
		expect("5:\t", ft_strlcat(a1, "X", 5), strlcat(a2, "X", 5)),
		expect("5=:\t", a1, a2),
		expect("8:\t", ft_strlcat(a1, "qwerty", 8), strlcat(a2, "qwerty", 8)),
		expect("8=:\t", a1, a2),
		expect("10:\t", ft_strlcat(a1, "qwerty", 10), strlcat(a2, "qwerty", 10)),
		expect("10=:\t", a1, a2)
		);

	all += run_test(test_description("strchr"), &count,
		expect("found:", ft_strchr("123456789", '4'), strchr("123456789", '4')),
		expect("none:\t", ft_strchr("123456789", '0'), strchr("123456789", '0')),
		expect("empty:", ft_strchr("", '1'), strchr("", '1')),
		expect("0:\t", ft_strchr("123456789", '\0'), strchr("123456789", '\0'))
		);

	all += run_test(test_description("strrchr"), &count,
		expect("found:", ft_strrchr("1234564789", '4'), strrchr("1234564789", '4')),
		expect("none:\t", ft_strrchr("123456789", '0'), strrchr("123456789", '0')),
		expect("empty:", ft_strrchr("", '1'), strrchr("", '1')),
		expect("0:\t", ft_strrchr("123456789", '\0'), strrchr("123456789", '\0'))
		);

	all += run_test(test_description("strstr"), &count,
		expect("found:", ft_strstr("1234564789", "47"), strstr("1234564789", "47")),
		expect("none:\t", ft_strstr("123456789", "80"), strstr("123456789", "80")),
		expect("empty:", ft_strstr("123456789", ""), strstr("123456789", ""))
		);

	all += run_test(test_description("strnstr"), &count,
		expect("found:", ft_strnstr("1234564789", "23", 5), strnstr("1234564789", "23", 5)),
		expect("none:\t", ft_strnstr("123456789", "78", 5), strnstr("123456789", "78", 5)),
		expect("empty:", ft_strnstr("123456789", "", 5), strnstr("123456789", "", 5))
		);

	all += run_test(test_description("strcmp"), &count,
		expect("less:\t", ft_strcmp("1234", "1235"), strcmp("1234", "1235")),
		expect("equal:", ft_strcmp("1234", "1234"), strcmp("1234", "1234")),
		expect("greater:", ft_strcmp("12369", "1234"), strcmp("12369", "1234")),
		expect("a - ab:", ft_strcmp("a", "ab"), strcmp("a", "ab"))
		);

	all += run_test(test_description("strncmp"), &count,
		expect("less:\t", ft_strncmp("1234564789", "12346", 5), strncmp("1234564789", "12346", 5)),
		expect("equal:", ft_strncmp("123456", "123457", 5), strncmp("123456", "123457", 5)),
		expect("greater:", ft_strncmp("123456789", "12344", 5), strncmp("123456789", "12344", 5)),
		expect("empty:", ft_strncmp("1234", "", 5), strncmp("1234", "", 5)),
		expect("zero:\t", ft_strncmp("123456789", "12344", 0), strncmp("123456789", "12344", 0))
		);

	all += run_test(test_description("atoi"), &count,
		expect("0:\t", ft_atoi("0"), atoi("0")),
		expect("-42:\t", ft_atoi("-42"), atoi("-42")),
		expect("  1:\t", ft_atoi("  1"), atoi("  1")),
		expect("10pp:\t", ft_atoi("10pp"), atoi("10pp")),
		expect("- 10:\t", ft_atoi("- 10"), atoi("- 10")),
		expect("+10:\t", ft_atoi("+10"), atoi("+10")),
		expect("+-10:\t", ft_atoi("+-10"), atoi("+-10")),
		expect("00010:", ft_atoi("00010"), atoi("00010")),
		expect("-2^31:", ft_atoi("-2147483648"), atoi("-2147483648")),
		expect("2^31-1:", ft_atoi("2147483647"), atoi("2147483647")),
		expect("-overflow:", ft_atoi("-214748364899"), atoi("-214748364899")),
		expect("overflow:", ft_atoi("214748364799"), atoi("214748364799")),
		expect("-long over:", ft_atoi("-9999999999999999999999999999999"), atoi("-9999999999999999999999999999999")),
		expect("long over:", ft_atoi("9999999999999999999999999999999"), atoi("9999999999999999999999999999999")),
		expect("spaces:", ft_atoi("\t\v\f\r\n \f- \f\t\n\r    06050"),
			atoi("\t\v\f\r\n \f- \f\t\n\r    06050"))
		);

	all += run_test(test_description("isalpha"), &count,
		expect("1:\t", ft_isalpha('1'), isalpha('1')),
		expect("f:\t", ft_isalpha('f'), isalpha('f')),
		expect("' ':\t", ft_isalpha(' '), isalpha(' '))
		);

	all += run_test(test_description("isalnum"), &count,
		expect("1:\t", ft_isalnum('1'), isalnum('1')),
		expect("f:\t", ft_isalnum('f'), isalnum('f')),
		expect("' ':\t", ft_isalnum(' '), isalnum(' '))
		);

	all += run_test(test_description("isdigit"), &count,
		expect("1:\t", ft_isdigit('1'), isdigit('1')),
		expect("f:\t", ft_isdigit('f'), isdigit('f'))
		);

	all += run_test(test_description("isascii"), &count,
		expect("'1':\t", ft_isascii('1'), isascii('1')),
		expect("180:\t", ft_isascii(180), isascii(180))
		);

	all += run_test(test_description("isprint"), &count,
		expect("'1':\t", ft_isprint('1'), isprint('1')),
		expect("127:\t", ft_isprint(127), isprint(127)),
		expect("126:\t", ft_isprint(126), isprint(126))
		);

	all += run_test(test_description("toupper"), &count,
		expect("f:\t", ft_toupper('f'), toupper('f')),
		expect("A:\t", ft_toupper('A'), toupper('A'))
		);

	all += run_test(test_description("tolower"), &count,
		expect("f:\t", ft_tolower('f'), tolower('f')),
		expect("A:\t", ft_tolower('A'), tolower('A'))
		);

	finish_test_block(count, all);
	g_all_tests_count += all;
	return (count);
}
