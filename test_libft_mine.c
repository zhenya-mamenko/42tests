#include "libft/libft.h"
#include "libtest.h"
#include <stdio.h>
#include <stdlib.h>
#include <malloc/malloc.h>

int			test_mine(void)
{
	int		count, all;
	int		a[4] = {1, 23, 456, 7890};
	char	*s;
	t_list	*el1;
	t_list	*el2;


	count = 0;
	all = 0;
	s = NULL;

	margin();
	printf("    \x1b[1;39madditional\x1b[0m\n");

	all += run_test(test_description("ft_word_count"), &count,
		expect("1:\t", ft_word_count("123", ' '), 1),
		expect("1-:\t", ft_word_count("12 34", '-'), 1),
		expect("2:\t", ft_word_count("12 34", ' '), 2),
		expect("4:\t", ft_word_count("   12 34  qw   wer   ", ' '), 4)
		);

	all += run_test(test_description("ft_extract_word"), &count,
		expect("123:\t", ft_extract_word("123", ' ', 1), "123"),
		expect("12 34:", ft_extract_word("12 34", '-', 1), "12 34"),
		expect("34:\t", ft_extract_word("12 34", ' ', 2), "34"),
		expect("qwdsa7:", ft_extract_word("   12 34  qwdsa7  wer   ", ' ', 3), "qwdsa7")
		);

	s = make_buf(1000, '\0');
	strcpy(s, "123456789");
	all += run_test(test_description("ft_strshrink"), &count,
		expect("shrink:", malloc_size(ft_strshrink(&s)), 16)
		);
	free(s);

	all += run_test(test_description("ft_flatten_charr"), &count,
		expect("flat:\t", ft_flatten_charr(ft_strsplit("  1 23 456  7890", ' ')), "1\n23\n456\n7890\n")
		);

	all += run_test(test_description("ft_flatten_int_array"), &count,
		expect("flat:\t", ft_flatten_intarr(a, 4), "1\t23\t456\t7890")
		);

	el1 = ft_lstnew("Test list", 10);
	el2 = ft_lstnew("Begin of list", 14);
	ft_lstadd(&el1, el2);
	all += run_test(test_description("ft_flatten_tlist"), &count,
		expect("flat:\t", ft_flatten_tlist(el2), "Begin of list\nTest list\n")
		);

	all += run_test(test_description("ft_strchri"), &count,
		expect("start:", ft_strchri("123", '1'), 0),
		expect("end:\t", ft_strchri("12 34", '4'), 4),
		expect("middle:", ft_strchri("hsjdhf shjdsf", 'd'), 3),
		expect("zero:\t", ft_strchri("12 34", '\0'), 5),
		expect("none:\t", ft_strchri("   12 34  qw   wer   ", 'X'), -1)
		);

	all += run_test(test_description("ft_freeret"), &count,
		expect("free:", ft_freeret(NULL, 1), 1)
		);

	finish_test_block(count, all);
	g_all_tests_count += all;
	return (count);
}
