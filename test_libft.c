/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_libft.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 20:52:48 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/18 12:40:31 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"
#include "test_libft.h"

int	main(void)
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
