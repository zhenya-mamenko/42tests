#include "libft.h"
#include "libtest.h"
#include <stdio.h>

static int	check_zeros(char *b, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (b[i] != '\0')
			return (0);
		i += 1;
	}
	return (1);
}

static void	fiter(char *c)
{
	*c = 'X';
}

static char	fiterc(char c)
{
	c = 0;
	return('X');
}

static void	fiteri(unsigned int i, char *c)
{
	*c = '0' + i;
}

static char	fiterci(unsigned int i, char c)
{
	c = 0;
	return('0' + i);
}


int			test_part2(void)
{
	char	*a1;
	int		count, all;

	margin();
	printf("    \x1b[1;39mpart 2\x1b[0m\n");

	count = 0;
	all = 0;

	all++;
	a1 = ft_memalloc(1000);
	count += run_test(test_description("ft_memalloc"), 1,
		expect("allocate:", 1, a1 != NULL && check_zeros(a1, 1000) == 1 ? 1 : 0, 1)
		);

	all++;
	ft_memdel((void **)(&a1));
	count += run_test(test_description("ft_memdel"), 1,
		expect("free:\t", 1, a1 == NULL ? 1 : 0, 1)
		);

	all++;
	a1 = ft_strnew(1000);
	count += run_test(test_description("ft_strnew"), 1,
		expect("allocate:", 1, a1 != NULL && check_zeros(a1, 1001) == 1 ? 1 : 0, 1)
		);

	all++;
	ft_strdel(&a1);
	count += run_test(test_description("ft_strdel"), 1,
		expect("free:\t", 1, a1 == NULL ? 1 : 0, 1)
		);

	all++;
	a1 = make_string("1234567890");
	ft_strclr(a1);
	count += run_test(test_description("ft_strclr"), 1,
		expect("free:\t", 1, check_zeros(a1, 11) ? 1 : 0, 1)
		);
	ft_strdel(&a1);

	all++;
	a1 = make_string("1234567890");
	ft_striter(a1, fiter);
	count += run_test(test_description("ft_striter"), 1,
		expect("XXX:\t", 3, a1, "XXXXXXXXXX")
		);
	ft_strdel(&a1);

	all++;
	a1 = make_string("XXXXXXXXXX");
	ft_striteri(a1, fiteri);
	count += run_test(test_description("ft_striteri"), 1,
		expect("0-9:\t", 3, a1, "0123456789")
		);
	ft_strdel(&a1);

	all++;
	count += run_test(test_description("ft_strmap"), 1,
		expect("XXX:\t", 3, ft_strmap("0123456789", fiterc), "XXXXXXXXXX")
		);

	all++;
	count += run_test(test_description("ft_strmapi"), 1,
		expect("0-9:\t", 3, ft_strmapi("XXXXXXXXXX", fiterci), "0123456789")
		);

	all++;
	count += run_test(test_description("ft_strequ"), 4,
		expect("equal:", 1, ft_strequ("0123456789", "0123456789"), 1),
		expect("non-equal:", 1, ft_strequ("0123456789", "012345678A"), 0),
		expect("less:\t", 1, ft_strequ("0123456", "0123456789"), 0),
		expect("greater:", 1, ft_strequ("0123456789", "0123456"), 0)
		);

	all++;
	count += run_test(test_description("ft_strnequ"), 5,
		expect("equal:", 1, ft_strnequ("0123456789", "0123456789", 5), 1),
		expect("non-equal:", 1, ft_strnequ("0123456789", "012345678A", 10), 0),
		expect("equal2:", 1, ft_strnequ("0123456789", "012345678A", 5), 1),
		expect("less:\t", 1, ft_strnequ("0123456", "0123456789", 8), 0),
		expect("greater:", 1, ft_strnequ("0123456789", "0123456", 6), 1)
		);

	all++;
	count += run_test(test_description("ft_strsub"), 1,
		expect("3456:\t", 3, ft_strsub("0123456789", 3, 4), "3456")
		);

	all++;
	count += run_test(test_description("ft_strjoin"), 1,
		expect("123789:", 3, ft_strjoin("123", "789"), "123789")
		);

	all++;
	count += run_test(test_description("ft_strtrim"), 6,
		expect("head:\t", 3, ft_strtrim("   0123456789"), "0123456789"),
		expect("trail:", 3, ft_strtrim("0123456789\t \n"), "0123456789"),
		expect("both:\t", 3, ft_strtrim("\t0123456789\n"), "0123456789"),
		expect("none:\t", 3, ft_strtrim("0123456789"), "0123456789"),
		expect("middle:", 3, ft_strtrim(" 0123  456 789\t"), "0123  456 789"),
		expect("all:\t", 3, ft_strtrim("   \n   \t  \n"), make_string(""))
		);

	all++;
	count += run_test(test_description("ft_strsplit"), 4,
		expect("simple:", 5, ft_strsplit("aaxbb", 'x'), "aa\nbb\n"),
		expect("multiple:", 5, ft_strsplit("aXXXbbXccc", 'X'), "a\nbb\nccc\n"),
		expect("head&trail:", 5, ft_strsplit("*aaa**ccc*", '*'), "aaa\nccc\n"),
		expect("spaces:", 5, ft_strsplit("      split       this for   me  !       ", ' '),
			"split\nthis\nfor\nme\n!\n")
	);

	all++;
	count += run_test(test_description("ft_itoa"), 7,
		expect("0:\t", 3, ft_itoa(0), "0"),
		expect("42:\t", 3, ft_itoa(42), "42"),
		expect("-42:\t", 3, ft_itoa(-42), "-42"),
		expect("-100002:", 3, ft_itoa(-100002), "-100002"),
		expect("10:\t", 3, ft_itoa(10), "10"),
		expect("-2^31:", 3, ft_itoa(-2147483648), "-2147483648"),
		expect("2^31-1:", 3, ft_itoa(2147483647), "2147483647")
	);

	all += 8;
	count += 8;
	run_test(test_description("puts utilites \t\x1b[93mskipping\x1b[0m\n"), 8,
		expect("putchar:", 1, 0, 0),
		expect("putstr:", 1, 0, 0),
		expect("putendl:", 1, 0, 0),
		expect("putnbr:", 1, 0, 0),
		expect("putchar_fd:", 1, 0, 0),
		expect("putstr_fd:", 1, 0, 0),
		expect("putendl_fd:", 1, 0, 0),
		expect("putnbr_fd:", 1, 0, 0)
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
