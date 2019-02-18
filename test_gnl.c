/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_gnl.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/16 20:52:48 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/18 13:52:28 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libtest.h"

int			test_files(void);

int	main(void)
{
	int count;

	g_all_tests_count = 0;
	count = 0;
	run_test_global(test_description("\x1b[95mGet Next Line\x1b[0m"), &count,
		test_files()
		);
	return (0);
}
