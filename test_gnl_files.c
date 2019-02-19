#include "libtest.h"
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include "/nfs/2018/e/emamenko/projects/get_next_line/get_next_line.h"

int			test_files(void)
{
	int		count, all, fd1, fd2, fd3;
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
	all += skip_run_test(test_description("test2.txt"), &count,
		expect("1:\t", wrapper_char(get_next_line(fd2, &line), line), "# **************************************************************************** #"),
		expect("2:\t", wrapper_char(get_next_line(fd2, &line), line), "#                                                                              #"),
		expect("3:\t", wrapper_char(get_next_line(fd2, &line), line), "/*                                                        :::      ::::::::   */"),
		expect("4:\t", wrapper_char(get_next_line(fd2, &line), line), "#                                                     +:+ +:+         +:+      #"),
		expect("5:\t", wrapper_char(get_next_line(fd2, &line), line), "#    By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+         #")
		);

	fd3 = open("gnl_tests/test3.txt", O_RDONLY);
	all += skip_run_test(test_description("test3.txt"), &count,
		expect("1:\t", wrapper_char(get_next_line(fd3, &line), line), "1"),
		expect("2:\t", wrapper_char(get_next_line(fd3, &line), line), "2")
		);

	all += skip_run_test(test_description("test1.txt after test3"), &count,
		expect("4:\t", wrapper_char(get_next_line(fd1, &line), line), "FINISH!"),
		expect("5:\t", wrapper_char(get_next_line(fd1, &line), line), "cool")
		);

	all += skip_run_test(test_description("test3.txt after test1"), &count,
		expect("3:\t", wrapper_char(get_next_line(fd3, &line), line), "3"),
		expect("4:\t", wrapper_char(get_next_line(fd3, &line), line), "4")
		);

	finish_test_block(count, all);
	g_all_tests_count += all;

	return (count);
}
