#include "libft.h"
#include "libtest.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>

int			test_mine(void)
{
	int		count, all;
	char	*s;

	count = 0;
	all = 0;
	s = NULL;

	margin();
	printf("    \x1b[1;39madditional\x1b[0m\n");

	all += run_test(test_description("ft_word_count"), &count,
		expect("1:\t", 1, ft_word_count("123", ' '), 1),
		expect("1-:\t", 1, ft_word_count("12 34", '-'), 1),
		expect("2:\t", 1, ft_word_count("12 34", ' '), 2),
		expect("4:\t", 1, ft_word_count("   12 34  qw   wer   ", ' '), 4)
		);

	all += run_test(test_description("ft_extract_word"), &count,
		expect("123:\t", 3, ft_extract_word("123", ' ', 1), "123"),
		expect("12 34:", 3, ft_extract_word("12 34", '-', 1), "12 34"),
		expect("34:\t", 3, ft_extract_word("12 34", ' ', 2), "34"),
		expect("qwdsa7:", 3, ft_extract_word("   12 34  qwdsa7  wer   ", ' ', 3), "qwdsa7")
		);

	s = make_buf(1000, '\0');
	strcpy(s, "123456789");
	all += run_test(test_description("ft_strshrink"), &count,
		expect("shrink:", 1, malloc_size(ft_strshrink(&s)), 16)
		);
	free(s);

	margin();
	printf("    --\n");
	margin();
	if (count == all)
		printf("    \x1b[92;1mOK \x1b[39m%d/%d\x1b[0m\n\n", count, all);
	else
		printf("    \x1b[91;1mFAIL \x1b[39m%d/%d\x1b[0m\n\n", count, all);
	g_all_tests_count += all;
	return (count);
}
