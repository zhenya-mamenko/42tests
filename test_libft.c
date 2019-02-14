#include "/nfs/2018/e/emamenko/projects/libft/libft.h"
#include "libtest.h"
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	char	*a1, *a2;

	run_test(test_description("isalpha"), 3,
		expect("1:\t", 1, ft_isalpha('1'), isalpha('1')),
		expect("f:\t", 1, ft_isalpha('f'), isalpha('f')),
		expect("' ':\t", 1, ft_isalpha(' '), isalpha(' '))
		);

	run_test(test_description("isalnum"), 3,
		expect("1:\t", 1, ft_isalnum('1'), isalnum('1')),
		expect("f:\t", 1, ft_isalnum('f'), isalnum('f')),
		expect("' ':\t", 1, ft_isalnum(' '), isalnum(' '))
		);

	run_test(test_description("isdigit"), 2,
		expect("1:\t", 1, ft_isdigit('1'), isdigit('1')),
		expect("f:\t", 1, ft_isdigit('f'), isdigit('f'))
		);

	run_test(test_description("isascii"), 2,
		expect("'1':\t", 1, ft_isascii('1'), isascii('1')),
		expect("180:\t", 1, ft_isascii(180), isascii(180))
		);

	run_test(test_description("isprint"), 3,
		expect("'1':\t", 1, ft_isprint('1'), isprint('1')),
		expect("127:\t", 1, ft_isprint(127), isprint(127)),
		expect("126:\t", 1, ft_isprint(126), isprint(126))
		);

	run_test(test_description("toupper"), 2,
		expect("f:\t", 1, ft_toupper('f'), toupper('f')),
		expect("A:\t", 1, ft_toupper('A'), toupper('A'))
		);

	run_test(test_description("tolower"), 2,
		expect("f:\t", 1, ft_tolower('f'), tolower('f')),
		expect("A:\t", 1, ft_tolower('A'), tolower('A'))
		);

	run_test(test_description("memset"), 1,
		expect("10:\t", 3, ft_memset(make_string("ABCDEABCDE"), 'x', 10), ft_memset(make_string("ABCDEABCDE"), 'x', 10))
		);

	a1 = make_buf(10, 'A'); ft_bzero(a1, 10);
	a2 = make_buf(10, 'A'); bzero(a2, 10);
	run_test(test_description("bzero"), 1,
		expect("10:\t", 4, 10, a1, a2)
		);

	ft_memcpy(a1, "1234567890", 10);
	memcpy(a2, "1234567890", 10);
	run_test(test_description("memcpy"), 1,
		expect("10:\t", 4, 10, a1, a2)
		);

	bzero(a1, 10); bzero(a2, 10);
	ft_memccpy(a1, "123456789\0", '7', 10);
	memccpy(a2, "123456789\0", '7', 10);
	run_test(test_description("memccpy"), 1,
		expect("10:\t", 4, 10, a1, a2)
		);

	return (0);
}
