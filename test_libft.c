#include <stdio.h>
#include <ctype.h>
#include "test_libft_1.c"
#include "test_libft_2.c"
#include "test_libft_bonus.c"
#include "test_libft_mine.c"

int main(void)
{

	run_test(test_description("\x1b[95mlibft"), 2,
		test_part1(),
		test_part2(),
		test_bonus(),
		test_mine()
		);

	return (0);
}
