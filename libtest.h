/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libtest.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emamenko <emamenko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/13 10:55:08 by emamenko          #+#    #+#             */
/*   Updated: 2019/02/18 13:50:51 by emamenko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

#ifndef LIBTEST_H
# define LIBTEST_H

# define PP_NARG(...) \
		 PP_NARG_(__VA_ARGS__,PP_RSEQ_N())
# define PP_NARG_(...) \
		 PP_ARG_N(__VA_ARGS__)
# define PP_ARG_N( \
		  _1, _2, _3, _4, _5, _6, _7, _8, _9,_10, \
		 _11,_12,_13,_14,_15,_16,_17,_18,_19,_20, \
		 _21,_22,_23,_24,_25,_26,_27,_28,_29,_30, \
		 _31,_32,_33,_34,_35,_36,_37,_38,_39,_40, \
		 _41,_42,_43,_44,_45,_46,_47,_48,_49,_50, \
		 N,...) N
# define PP_RSEQ_N() \
		 50,49,48,47,46,45,44,43,42,41,40, \
		 39,38,37,36,35,34,33,32,31,30, \
		 29,28,27,26,25,24,23,22,21,20, \
		 19,18,17,16,15,14,13,12,11,10, \
		 9,8,7,6,5,4,3,2,1,0
# define FARG(X, ...) X
# define SARG(Y, X, ...) X
# define TARG(Z, Y, X, ...) X
# define ARGS(Z, Y, ...) __VA_ARGS__

# define skip_run_test(...) skip_run_test_1(FARG(__VA_ARGS__), \
		 SARG(__VA_ARGS__), (PP_NARG(__VA_ARGS__) - 2))
# define run_test(...) run_test_1(FARG(__VA_ARGS__), \
		 SARG(__VA_ARGS__), (PP_NARG(__VA_ARGS__) - 2), ARGS(__VA_ARGS__))
# define run_test_global(...) run_test_global_1(FARG(__VA_ARGS__), \
		 SARG(__VA_ARGS__), (PP_NARG(__VA_ARGS__) - 2), ARGS(__VA_ARGS__))

# define flatten_array(...) _Generic(FARG(__VA_ARGS__),	\
	char **:			flatten_array_char,		\
	int *:				flatten_array_int,		\
	unsigned int *:		flatten_array_uint,		\
	unsigned char *:	flatten_array_uchar		\
	)(__VA_ARGS__)

# define wrapper_char(X, Y) _Generic(1, int: wrapper_char_1)(Y, X)

# define expect(X, ...) expect_1(X, _Generic(SARG(__VA_ARGS__), \
	int:		1,	\
	size_t:		1,	\
	char *:		2,	\
	void *:		3,	\
	default:	2	\
	), __VA_ARGS__)

static int		g_all_tests_count = 0;

int		expect_1(char *name, int type, ...);
char	*test_description(char *description);
int		run_test_1(char *description, int *count, int argc, ...);
int		run_test_global_1(char *description, int *count, int argc, ...);
int		skip_run_test_1(char *description, int *count, int argc);
char	*make_buf(size_t len, char c);
char	*make_string(char *src);
char	*wrapper_char_1(char *value, ...);
void	margin(void);
char	*flatten_array_char(char **a);
char	*flatten_array_int(int *a, size_t n);
char	*flatten_array_uint(unsigned int *a, size_t n);
char	*flatten_array_uchar(unsigned char *a, size_t n);
void	finish_test_block(int count, int all);

#endif
