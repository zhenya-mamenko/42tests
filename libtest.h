/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:55:08 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/14 16:52:29 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#ifndef LIBTEST_H
# define LIBTEST_H

int		expect(char *name, int type, ...);
char	*test_description(char *description);
int		run_test(char *description, int count, ...);
char	*make_buf(size_t len, char c);
char	*make_string(char *src);
char	*wrapper_char(void *stub, char *value);
void	margin(void);
char	*flatten_array(char **a);

#endif