#include <stdio.h>
#include <ctype.h>
#include "libtest.h"

#include "test_libft_1.c"
#include "test_libft_2.c"
#include "test_libft_bonus.c"
#include "test_libft_mine.c"

int main(void)
{
	int count;

	g_all_tests_count = 0;
	count = 0;
	run_test_global(test_description("\x1b[95mlibft\x1b[0m"), &count,
		test_part1(),
		test_part2(),
		test_bonus(),
		test_mine()
		);

	return (0);
}
