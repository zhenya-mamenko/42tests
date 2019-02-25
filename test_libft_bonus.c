#include "libft/libft.h"
#include "libtest.h"
#include <stdio.h>

static char	*flatten_tlist(t_list *lst)
{
	int		i;
	int		len;
	char	*s;
	t_list	*el;

	i = 0;
	len = 0;
	el = lst;
	if (el == NULL || el->content == NULL)
		return (make_string("(null)"));
	while (el)
	{
		len += el->content_size + 1;
		el = el->next;
	}
	len++;
	s = malloc(sizeof(char) * len);
	i = 0;
	len = 0;
	el = lst;
	while (el)
	{
		memcpy(&s[len], el->content, el->content_size);
		len += el->content_size;
		s[len-1] = '\n';
		i += 1;
		el = el->next;
	}
	s[len] = '\0';
	return (s);
}

static void	del(void *b, size_t size)
{
	size = 0;
	free(b);
}

static void	fli(t_list *elem)
{
	char *s;

	s = (char *)elem->content;
	while (*s)
	{
		*s = 'X';
		s++;
	}
}

static t_list	*flm(t_list *elem)
{
	char *s;
	t_list *new;

	s = (char *)elem->content;
	s = ft_itoa(ft_strlen(s));
	new = ft_lstnew(s, ft_strlen(s) + 1);
	return (new);
}

int			test_bonus(void)
{
	t_list	*el1;
	t_list	*el2;

	int		count, all;

	margin();
	printf("    \x1b[1;39mbonus\x1b[0m\n");

	count = 0;
	all = 0;

	el1 = ft_lstnew("Test list", 10);
	all += run_test(test_description("ft_lstnew"), &count,
		expect("create:", flatten_tlist(el1), "Test list\n"),
		expect("null:\t", flatten_tlist(ft_lstnew(NULL, 2^32-1)), "(null)"),
		expect("0:\t", flatten_tlist(ft_lstnew("Test list", 0)), "(null)")
		);

	ft_lstdel(&el1, del);
	all += run_test(test_description("ft_lstdelone"), &count,
		expect("free:", flatten_tlist(el1), "(null)")
		);

	el1 = ft_lstnew("Test list", 10);
	el1->next = ft_lstnew("Test list", 10^20);
	ft_lstdel(&el1, del);
	all += run_test(test_description("ft_lstdel"), &count,
		expect("free:", flatten_tlist(el1), "(null)")
		);

	el1 = ft_lstnew("Test list", 10);
	el2 = ft_lstnew("Begin of list", 14);
	ft_lstadd(&el1, el2);
	all += run_test(test_description("ft_lstadd"), &count,
		expect("new:", flatten_tlist(el2), "Begin of list\nTest list\n")
		);

	ft_lstiter(el2, fli);
	all += run_test(test_description("ft_lstiter"), &count,
		expect("XXX:", flatten_tlist(el2), "XXXXXXXXXXXXX\nXXXXXXXXX\n")
		);

	all += run_test(test_description("ft_lstmap"), &count,
		expect("13-9:", flatten_tlist(ft_lstmap(el2, flm)), "13\n9\n")
		);

	finish_test_block(count, all);
	g_all_tests_count += all;
	return (count);
}
