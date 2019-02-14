/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:55:08 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/13 17:14:27 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#ifndef LIBTEST_H
# define LIBTEST_H

char	*expect(char *name, int type, ...);
char	*test_description(char *description);
void	run_test(char *description, int count, ...);
char	*make_buf(size_t len, char c);
char	*make_string(char *src);

#endif