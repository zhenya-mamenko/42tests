/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:55:08 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/15 16:15:11 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#ifndef LIBTEST_H
# define LIBTEST_H

# define FARG(X, ...) X
# define flatten_array(...) _Generic(FARG(__VA_ARGS__),	\
	char **:		flatten_array_char,		\
	int *:			flatten_array_int,		\
	unsigned int *:	flatten_array_uint,		\
	unsigned char *:	flatten_array_uchar		\
	)(__VA_ARGS__)

int		expect(char *name, int type, ...);
char	*test_description(char *description);
int		run_test(char *description, int count, ...);
char	*make_buf(size_t len, char c);
char	*make_string(char *src);
char	*wrapper_char(void *stub, char *value);
void	margin(void);
char	*flatten_array_char(char **a);
char	*flatten_array_int(int *a, size_t n);
char	*flatten_array_uint(unsigned int *a, size_t n);
char	*flatten_array_uchar(unsigned char *a, size_t n);

#endif