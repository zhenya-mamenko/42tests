#include "libtest.h"
#include "libft/libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <string.h>
#include <unistd.h>
#include "get_next_line/get_next_line.h"

int			test_files(void)
{
	int		count, all, fd1, fd2, fd3, fd4, fd5;
	char	*line;

	count = 0;
	all = 0;
	line = NULL;

	margin();
	printf("    \x1b[1;39mread from file\x1b[0m\n");

	fd1 = open("gnl_tests/test1.txt", O_RDONLY);
	all += run_test(test_description("test1.txt"), &count,
		expect("1:\t", wrapper_char(get_next_line(fd1, &line), line), "Line 1"),
		expect("2:\t", wrapper_char(get_next_line(fd1, &line), line), "		Second line"),
		expect("3:\t", wrapper_char(get_next_line(fd1, &line), line), "3rd LINE")
		);

	fd2 = open("gnl_tests/test2.txt", O_RDONLY);
	all += run_test(test_description("test2.txt"), &count,
		expect("1:\t", wrapper_char(get_next_line(fd2, &line), line), "# **************************************************************************** #"),
		expect("2:\t", wrapper_char(get_next_line(fd2, &line), line), "#                                                                              #"),
		expect("3:\t", wrapper_char(get_next_line(fd2, &line), line), "#                                                         :::      ::::::::    #")
		);

	fd3 = open("gnl_tests/test3.txt", O_RDONLY);
	all += run_test(test_description("test3.txt"), &count,
		expect("line w/o \\n:", wrapper_char(get_next_line(fd3, &line), line), "12345678")
		);

	all += run_test(test_description("test1.txt after test3"), &count,
		expect("4:\t", wrapper_char(get_next_line(fd1, &line), line), "FINISH!"),
		expect("5:\t", wrapper_char(get_next_line(fd1, &line), line), "cool")
		);

	all += run_test(test_description("test2.txt after test1"), &count,
		expect("4:\t", wrapper_char(get_next_line(fd2, &line), line), "#    test2.txt                                          :+:      :+:    :+:    #"),
		expect("5:\t", wrapper_char(get_next_line(fd2, &line), line), "#                                                     +:+ +:+         +:+      #")
		);

	fd4 = open("gnl_tests/test4.txt", O_RDONLY);
	char *test4 = "abcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxyzabcdefghijklmnopqrstuvwxzabcdefghi";
	char *result = ft_strnew(1000);
	while (get_next_line(fd4, &line) > 0)
		ft_strsetdel(&result, ft_strjoin(result, line));
	all += run_test(test_description("test4.txt"), &count,
		expect("7 lines:", result, test4)
		);

	fd5 = open("gnl_tests/test5.txt", O_RDONLY);
	char *test5 = ft_strnew(50000);
	read(fd5, test5, 50000);
	lseek(fd5, 0, SEEK_SET);
	all += run_test(test_description("test5.txt"), &count,
		expect("big line:", wrapper_char(get_next_line(fd5, &line), line), test5)
		);

	int		out;
	int		p[2];

	out = dup(1);
	pipe(p);

	dup2(p[1], 1);
	write(1, "abcdefghijklmnop\n", 17);
	write(1, "qrstuvwxyzabcdef\n", 17);
	write(1, "ghijklmnopqrstuv\n", 17);
	write(1, "wxyzabcdefghijkl\n", 17);
	write(1, "mnopqrstuvwxyzab\n", 17);
	write(1, "cdefghijklmnopqr\n", 17);
	write(1, "stuvwxzabcdefghi\n", 17);
	close(p[1]);
	dup2(out, 1);
	ft_strclr(result);
	while (get_next_line(p[0], &line) > 0)
	{
		ft_strsetdel(&result, ft_strjoin(result, line));
	}

	all += run_test(test_description("dup"), &count,
		expect("pipe:", result, test4)
		);

	finish_test_block(count, all);
	g_all_tests_count += all;

	return (count);
}
