#include "libtest.h"
#include <stdio.h>
#include <stdlib.h>

int			test_files(void)
{
	int		count, all;

	count = 0;
	all = 0;

	margin();
	printf("    \x1b[1;39mread from file\x1b[0m\n");

	all += run_test(test_description("test1.txt"), &count,
		expect("1:\t", 1, 1)
		);

	finish_test_block(count, all);
	g_all_tests_count += all;

	return (count);
}
