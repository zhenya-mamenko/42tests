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

		a1 = ft_memalloc(1000);
	all += run_test(test_description("ft_memalloc"), &count,
		expect("allocate:", a1 != NULL && check_zeros(a1, 1000) == 1 ? 1 : 0, 1)
		);

		ft_memdel((void **)(&a1));
	all += run_test(test_description("ft_memdel"), &count,
		expect("free:\t", a1 == NULL ? 1 : 0, 1)
		);

		a1 = ft_strnew(1000);
	all += run_test(test_description("ft_strnew"), &count,
		expect("allocate:", a1 != NULL && check_zeros(a1, 1001) == 1 ? 1 : 0, 1)
		);

		ft_strdel(&a1);
	all += run_test(test_description("ft_strdel"), &count,
		expect("free:\t", a1 == NULL ? 1 : 0, 1)
		);

		a1 = make_string("1234567890");
	ft_strclr(a1);
	all += run_test(test_description("ft_strclr"), &count,
		expect("free:\t", check_zeros(a1, 11) ? 1 : 0, 1)
		);
	ft_strdel(&a1);

		a1 = make_string("1234567890");
	ft_striter(a1, fiter);
	all += run_test(test_description("ft_striter"), &count,
		expect("XXX:\t", a1, "XXXXXXXXXX")
		);
	ft_strdel(&a1);

		a1 = make_string("XXXXXXXXXX");
	ft_striteri(a1, fiteri);
	all += run_test(test_description("ft_striteri"), &count,
		expect("0-9:\t", a1, "0123456789")
		);
	ft_strdel(&a1);

	all += run_test(test_description("ft_strmap"), &count,
		expect("XXX:\t", ft_strmap("0123456789", fiterc), "XXXXXXXXXX")
		);

	all += run_test(test_description("ft_strmapi"), &count,
		expect("0-9:\t", ft_strmapi("XXXXXXXXXX", fiterci), "0123456789")
		);

	all += run_test(test_description("ft_strequ"), &count,
		expect("equal:", ft_strequ("0123456789", "0123456789"), 1),
		expect("non-equal:", ft_strequ("0123456789", "012345678A"), 0),
		expect("less:\t", ft_strequ("0123456", "0123456789"), 0),
		expect("greater:", ft_strequ("0123456789", "0123456"), 0)
		);

	all += run_test(test_description("ft_strnequ"), &count,
		expect("equal:", ft_strnequ("0123456789", "0123456789", 5), 1),
		expect("non-equal:", ft_strnequ("0123456789", "012345678A", 10), 0),
		expect("equal2:", ft_strnequ("0123456789", "012345678A", 5), 1),
		expect("less:\t", ft_strnequ("0123456", "0123456789", 8), 0),
		expect("greater:", ft_strnequ("0123456789", "0123456", 6), 1)
		);

	all += run_test(test_description("ft_strsub"), &count,
		expect("3456:\t", ft_strsub("0123456789", 3, 4), "3456")
		);

	all += run_test(test_description("ft_strjoin"), &count,
		expect("123789:", ft_strjoin("123", "789"), "123789")
		);

	all += run_test(test_description("ft_strtrim"), &count,
		expect("head:\t", ft_strtrim("   0123456789"), "0123456789"),
		expect("trail:", ft_strtrim("0123456789\t \n"), "0123456789"),
		expect("both:\t", ft_strtrim("\t0123456789\n"), "0123456789"),
		expect("none:\t", ft_strtrim("0123456789"), "0123456789"),
		expect("middle:", ft_strtrim(" 0123  456 789\t"), "0123  456 789"),
		expect("all:\t", ft_strtrim("   \n   \t  \n"), make_string(""))
		);

	all += run_test(test_description("ft_strsplit"), &count,
		expect("simple:", ft_flatten_charr(ft_strsplit("aaxbb", 'x')), "aa\nbb\n"),
		expect("multiple:", ft_flatten_charr(ft_strsplit("aXXXbbXccc", 'X')), "a\nbb\nccc\n"),
		expect("head&trail:", ft_flatten_charr(ft_strsplit("*aaa**ccc*", '*')), "aaa\nccc\n"),
		expect("spaces:", ft_flatten_charr(ft_strsplit("      split       this for   me  !       ", ' ')),
			"split\nthis\nfor\nme\n!\n")
	);

	all += run_test(test_description("ft_itoa"), &count,
		expect("0:\t", ft_itoa(0), "0"),
		expect("42:\t", ft_itoa(42), "42"),
		expect("-42:\t", ft_itoa(-42), "-42"),
		expect("-100002:", ft_itoa(-100002), "-100002"),
		expect("10:\t", ft_itoa(10), "10"),
		expect("-2^31:", ft_itoa(-2147483648), "-2147483648"),
		expect("2^31-1:", ft_itoa(2147483647), "2147483647")
	);

	all += skip_run_test(test_description("puts utilites"), &count,
		expect("putchar:", 0, 0),
		expect("putstr:", 0, 0),
		expect("putendl:", 0, 0),
		expect("putnbr:", 0, 0),
		expect("putchar_fd:", 0, 0),
		expect("putstr_fd:", 0, 0),
		expect("putendl_fd:", 0, 0),
		expect("putnbr_fd:", 0, 0)
		);

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
