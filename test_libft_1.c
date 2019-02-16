#include "libft.h"
#include "libtest.h"
#include <stdio.h>
#include <ctype.h>

int test_part1(void)
{
	char	*a1, *a2;
	int		count, all;

	margin();
	printf("    \x1b[1;39mpart 1\x1b[0m\n");

	count = 0;
	all = 0;

	all++;
	count += run_test(test_description("memset"), 1,
		expect("10:\t", 3, ft_memset(make_string("ABCDEABCDE"), 'x', 10), memset(make_string("ABCDEABCDE"), 'x', 10))
		);

	a1 = make_buf(10, 'A'); ft_bzero(a1, 10);
	a2 = make_buf(10, 'A'); bzero(a2, 10);
	all++;
	count += run_test(test_description("bzero"), 1,
		expect("10:\t", 4, 10, a1, a2)
		);

	ft_memcpy(a1, "1234567890", 10);
	memcpy(a2, "1234567890", 10);
	all++;
	count += run_test(test_description("memcpy"), 1,
		expect("10:\t", 4, 10, a1, a2)
		);

	bzero(a1, 10); bzero(a2, 10);
	ft_memccpy(a1, "1234567890", '3', 10);
	memccpy(a2, "1234567890", '3', 10);
	all++;
	count += run_test(test_description("memccpy"), 1,
		expect("10:\t", 4, 10, a1, a2)
		);

	memcpy(a1, "1234567890", 10);
	memcpy(a2, "1234567890", 10);
	all++;
	count += run_test(test_description("memmove"), 2,
		expect("diff strs:", 4, 10, ft_memmove(a1, "ABCDE", 4), memmove(a2, "ABCDE", 4)),
		expect("same strs:", 4, 10, ft_memmove(a1, a1 + 2, 4), memmove(a2, a2 + 2, 4))
		);

	all++;
	count += run_test(test_description("memchr"), 2,
		expect("none:\t", 3, ft_memchr(make_string("ABCDEABCDE"), 'x', 10), memchr(make_string("ABCDEABCDE"), 'x', 10)),
		expect("E:\t", 3, ft_memchr(make_string("ABCDEABCDE"), 'E', 10), memchr(make_string("ABCDEABCDE"), 'E', 10))
		);

	all++;
	count += run_test(test_description("memcmp"), 4,
		expect("same:\t", 1, ft_memcmp("ABCDEABCDE", "ABCDEABCDE", 10), memcmp("ABCDEABCDE", "ABCDEABCDE", 10)),
		expect("diff:\t", 1, ft_memcmp("ABCDEABCDE", "ABCDE1BCDE", 10), memcmp("ABCDEABCDE", "ABCDE1BCDE", 10)),
		expect("bin:\t", 1, ft_memcmp("\xff\xaa\xde\xffMACOSX\xff", "\xff\xaa\xde\x02", 10),
			memcmp("\xff\xaa\xde\xffMACOSX\xff", "\xff\xaa\xde\x02", 10)),
		expect("empty:", 1, ft_memcmp("", "", 0), memcmp("", "", 0))
		);

	all++;
	count += run_test(test_description("strlen"), 2,
		expect("10:\t", 1, ft_strlen("ABCDEABCDE"), strlen("ABCDEABCDE")),
		expect("empty:", 1, ft_strlen(""), strlen(""))
		);

	all++;
	count += run_test(test_description("strdup"), 1,
		expect("10:\t", 3, ft_strdup("ABCDEABCDE"), strdup("ABCDEABCDE"))
		);

	all++;
	count += run_test(test_description("strcpy"), 2,
		expect("12345:", 3, ft_strcpy(make_string("ABCDEABCDE"), "12345"), strcpy(make_string("ABCDEABCDE"), "12345")),
		expect("empty:", 3, ft_strcpy(make_string("ABCDEABCDE"), ""), strcpy(make_string("ABCDEABCDE"), ""))
		);

	all++;
	count += run_test(test_description("strncpy"), 3,
		expect("3:\t", 3, ft_strncpy(make_string("ABCDEABCDE"), "12345", 3), strncpy(make_string("ABCDEABCDE"), "12345", 3)),
		expect("6:\t", 3, ft_strncpy(make_string("ABCDEABCDE"), "12345", 6), strncpy(make_string("ABCDEABCDE"), "12345", 6)),
		expect("0:\t", 3, ft_strncpy(make_string("ABCDEABCDE"), "12345", 0), strncpy(make_string("ABCDEABCDE"), "12345", 0))
		);

	memcpy(a1, "123\0", 10);
	memcpy(a2, "123\0", 10);
	ft_strcat(a1, "456");
	strcat(a2, "456");
	all++;
	count += run_test(test_description("strcat"), 1,
		expect("123456:", 3, a1, a2)
		);

	memcpy(a1, "123\0", 4);
	memcpy(a2, "123\0", 4);
	all++;
	count += run_test(test_description("strncat"), 3,
		expect("1:\t", 3, wrapper_char(ft_strncat(a1, "456789", 1), a1), wrapper_char(strncat(a2, "456789", 1), a2)),
		expect("0:\t", 3, wrapper_char(ft_strncat(a1, "456789", 0), a1), wrapper_char(strncat(a2, "456789", 0), a2)),
		expect("10:\t", 3, wrapper_char(ft_strncat(a1, "56789", 10), a1), wrapper_char(strncat(a2, "56789", 10), a2))
		);

	memcpy(a1, "ABC\0", 4);
	memcpy(a2, "ABC\0", 4);
	all++;
	count += run_test(test_description("strlcat"), 5,
		expect("0:\t", 1, ft_strlcat(a1, "Z", 0), strlcat(a2, "Z", 0)),
		expect("0=:\t", 3, a1, a2),
		expect("0v:\t", 3, wrapper_char(ft_strlcat(a1, "X", 0), a1),
			wrapper_char(strlcat(a2, "X", 0), a2)),
		expect("5:\t", 1, ft_strlcat(a1, "qwerty", 8), strlcat(a2, "qwerty", 8)),
		expect("5v:\t", 3, wrapper_char(ft_strlcat(a1, "poi", 10), a1),
			wrapper_char(strlcat(a2, "poi", 10), a2))
		);

	all++;
	count += run_test(test_description("strchr"), 4,
		expect("found:", 3, ft_strchr("123456789", '4'), strchr("123456789", '4')),
		expect("none:\t", 3, ft_strchr("123456789", '0'), strchr("123456789", '0')),
		expect("empty:", 3, ft_strchr("", '1'), strchr("", '1')),
		expect("0:\t", 3, ft_strchr("123456789", '\0'), strchr("123456789", '\0'))
		);

	all++;
	count += run_test(test_description("strrchr"), 4,
		expect("found:", 3, ft_strrchr("1234564789", '4'), strrchr("1234564789", '4')),
		expect("none:\t", 3, ft_strrchr("123456789", '0'), strrchr("123456789", '0')),
		expect("empty:", 3, ft_strrchr("", '1'), strrchr("", '1')),
		expect("0:\t", 3, ft_strrchr("123456789", '\0'), strrchr("123456789", '\0'))
		);

	all++;
	count += run_test(test_description("strstr"), 3,
		expect("found:", 3, ft_strstr("1234564789", "47"), strstr("1234564789", "47")),
		expect("none:\t", 3, ft_strstr("123456789", "80"), strstr("123456789", "80")),
		expect("empty:", 3, ft_strstr("123456789", ""), strstr("123456789", ""))
		);

	all++;
	count += run_test(test_description("strnstr"), 3,
		expect("found:", 3, ft_strnstr("1234564789", "23", 5), strnstr("1234564789", "23", 5)),
		expect("none:\t", 3, ft_strnstr("123456789", "78", 5), strnstr("123456789", "78", 5)),
		expect("empty:", 3, ft_strnstr("123456789", "", 5), strnstr("123456789", "", 5))
		);

	all++;
	count += run_test(test_description("strcmp"), 4,
		expect("less:\t", 1, ft_strcmp("1234", "1235"), strcmp("1234", "1235")),
		expect("equal:", 1, ft_strcmp("1234", "1234"), strcmp("1234", "1234")),
		expect("greater:", 1, ft_strcmp("12369", "1234"), strcmp("12369", "1234")),
		expect("a - ab:", 1, ft_strcmp("a", "ab"), strcmp("a", "ab"))
		);

	all++;
	count += run_test(test_description("strncmp"), 5,
		expect("less:\t", 1, ft_strncmp("1234564789", "12346", 5), strncmp("1234564789", "12346", 5)),
		expect("equal:", 1, ft_strncmp("123456", "123457", 5), strncmp("123456", "123457", 5)),
		expect("greater:", 1, ft_strncmp("123456789", "12344", 5), strncmp("123456789", "12344", 5)),
		expect("empty:", 1, ft_strncmp("1234", "", 5), strncmp("1234", "", 5)),
		expect("zero:\t", 1, ft_strncmp("123456789", "12344", 0), strncmp("123456789", "12344", 0))
		);

	all++;
	count += run_test(test_description("atoi"), 11,
		expect("0:\t", 1, ft_atoi("0"), atoi("0")),
		expect("-42:\t", 1, ft_atoi("-42"), atoi("-42")),
		expect("  1:\t", 1, ft_atoi("  1"), atoi("  1")),
		expect("10pp:\t", 1, ft_atoi("10pp"), atoi("10pp")),
		expect("- 10:\t", 1, ft_atoi("- 10"), atoi("- 10")),
		expect("+10:\t", 1, ft_atoi("+10"), atoi("+10")),
		expect("+-10:\t", 1, ft_atoi("+-10"), atoi("+-10")),
		expect("00010:", 1, ft_atoi("00010"), atoi("00010")),
		expect("-2^31:", 1, ft_atoi("-2147483648"), atoi("-2147483648")),
		expect("2^31-1:", 1, ft_atoi("2147483647"), atoi("2147483647")),
		expect("big value:", 1, ft_atoi("99999999999999999999999999"), atoi("99999999999999999999999999")),
		expect("big neg:", 1, ft_atoi("-99999999999999999999999999"), atoi("-99999999999999999999999999 ")),
		expect("spaces:", 1, ft_atoi("\t\v\f\r\n \f- \f\t\n\r    06050"),
			atoi("\t\v\f\r\n \f- \f\t\n\r    06050"))
		);

	all++;
	count += run_test(test_description("isalpha"), 3,
		expect("1:\t", 1, ft_isalpha('1'), isalpha('1')),
		expect("f:\t", 1, ft_isalpha('f'), isalpha('f')),
		expect("' ':\t", 1, ft_isalpha(' '), isalpha(' '))
		);

	all++;
	count += run_test(test_description("isalnum"), 3,
		expect("1:\t", 1, ft_isalnum('1'), isalnum('1')),
		expect("f:\t", 1, ft_isalnum('f'), isalnum('f')),
		expect("' ':\t", 1, ft_isalnum(' '), isalnum(' '))
		);

	all++;
	count += run_test(test_description("isdigit"), 2,
		expect("1:\t", 1, ft_isdigit('1'), isdigit('1')),
		expect("f:\t", 1, ft_isdigit('f'), isdigit('f'))
		);

	all++;
	count += run_test(test_description("isascii"), 2,
		expect("'1':\t", 1, ft_isascii('1'), isascii('1')),
		expect("180:\t", 1, ft_isascii(180), isascii(180))
		);

	all++;
	count += run_test(test_description("isprint"), 3,
		expect("'1':\t", 1, ft_isprint('1'), isprint('1')),
		expect("127:\t", 1, ft_isprint(127), isprint(127)),
		expect("126:\t", 1, ft_isprint(126), isprint(126))
		);

	all++;
	count += run_test(test_description("toupper"), 2,
		expect("f:\t", 1, ft_toupper('f'), toupper('f')),
		expect("A:\t", 1, ft_toupper('A'), toupper('A'))
		);

	all++;
	count += run_test(test_description("tolower"), 2,
		expect("f:\t", 1, ft_tolower('f'), tolower('f')),
		expect("A:\t", 1, ft_tolower('A'), tolower('A'))
		);

	margin();
	printf("    --\n");
	margin();
	if (count == all)
		printf("    \x1b[92;1mOK \x1b[39m%d/%d\x1b[0m\n\n", count, all);
	else
		printf("    \x1b[91;1mFAIL \x1b[39m%d/%d\x1b[0m\n\n", count, all);
	
	return (count == all ? 1 : 0);
}
