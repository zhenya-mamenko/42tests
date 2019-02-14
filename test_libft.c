#include <stdio.h>
#include <ctype.h>
#include "test_libft_1.c"
#include "test_libft_2.c"

int main(void)
{
	run_test(test_description("\x1b[95mlibft"), 2,
		test_part1(),
		test_part2()
		);

	return (0);
}
