#include "libft.h"
#include "libtest.h"
#include <stdio.h>

int test_part2(void)
{
	char	*a1, *a2;
	int		count, all;

	margin();
	printf("    \x1b[1;39mpart 2\x1b[0m\n");

	count = 0;
	all = 0;

	all++;
	a1 = ft_memalloc(1000);
	count += run_test(test_description("ft_memalloc"), 1,
		expect("allocate:", 1, a1 != NULL ? 1 : 0, 1)
		);

	all++;
	ft_memdel((void **)(&a1));
	count += run_test(test_description("ft_memdel"), 1,
		expect("free:\t", 1, a1 == NULL ? 1 : 0, 1)
		);

	all++;
	a1 = ft_strnew(1000);
	count += run_test(test_description("ft_strnew"), 1,
		expect("allocate:", 1, a1 != NULL ? 1 : 0, 1)
		);

	all++;
	ft_strdel((void **)(&a1));
	count += run_test(test_description("ft_strdel"), 1,
		expect("free:\t", 1, a1 == NULL ? 1 : 0, 1)
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
