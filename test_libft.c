#include "/nfs/2018/e/emamenko/projects/libft/libft.h"
#include "libtest.h"
#include <stdio.h>
#include <ctype.h>

int main(void)
{
	printf("\x1b[1mStart testing: \x1b[4;96mlibft\x1b[0m\n\n");

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
	/*
	printf("isalpha=%d -- ft_isalpha=%d\n", isalpha('f'), ft_isalpha('f'));
	printf("isalpha=%d -- ft_isalpha=%d\n", isalpha(33), ft_isalpha(33));
	printf("isdigit=%d -- ft_isdigit=%d\n", isdigit('0'), ft_isdigit('0'));
	printf("isdigit=%d -- ft_isdigit=%d\n", isdigit(33), ft_isdigit(33));
	printf("isalnum=%d -- ft_isalnum=%d\n", isalnum('f'), ft_isalnum('f'));
	printf("isalnum=%d -- ft_isalnum=%d\n", isalnum('0'), ft_isalnum('0'));
	printf("isalnum=%d -- ft_isalnum=%d\n", isalnum(33), ft_isalnum(33));
	printf("isascii=%d -- ft_isascii=%d\n", isascii('0'), ft_isascii('0'));
	printf("isascii=%d -- ft_isascii=%d\n", isascii(180), ft_isascii(180));
	printf("isprint=%d -- ft_isprint=%d\n", isprint('0'), ft_isprint('0'));
	printf("isprint=%d -- ft_isprint=%d\n", isprint(127), ft_isprint(127));
	printf("isprint=%d -- ft_isprint=%d\n", isprint(15), ft_isprint(15));
	printf("toupper=%c -- ft_toupper=%c\n", toupper('a'), ft_toupper('a'));
	printf("toupper=%c -- ft_toupper=%c\n", toupper('F'), ft_toupper('F'));
	printf("tolower=%c -- ft_tolower=%c\n", tolower('a'), ft_tolower('a'));
	printf("tolower=%c -- ft_tolower=%c\n", tolower('F'), ft_tolower('F'));
	printf("memset=%s -- ft_memset=%s\n", (char*)memset(b1, 'x', 10), (char*)ft_memset(b2, 'x', 10));*/
	return 0;
}
