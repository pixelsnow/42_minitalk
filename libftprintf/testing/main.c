/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vvagapov <vvagapov@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/23 16:53:23 by vvagapov          #+#    #+#             */
/*   Updated: 2022/12/28 15:46:35 by vvagapov         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"
#include <limits.h>
#include <stdio.h>

void	test_char(char c)
{
	int	len_orig;
	int	len_mine;

	len_orig = printf("ORIG: '%c'", c);
	printf("\n");
	len_mine = ft_printf("MINE: '%c'", c);
	printf("\n");
	if (len_orig != len_mine)
		printf("LENGTH DOESN'T MATCH! %d != %d\n", len_orig, len_mine);
}

void	test_c(void)
{
	printf("\n--- C TEST ---\n\n");
	test_char('\0');
	test_char(100);
	test_char(55);
	test_char('0' - 256);
	test_char('0' + 256);
	test_char(' ');
	test_char(0);
	printf(" %c %c %c \n", 'a', 'b', 'c');
	ft_printf(" %c %c %c \n", 'a', 'b', 'c');
}

void	test_string(char *s)
{
	int	len_orig;
	int	len_mine;

	len_orig = printf("ORIG: '%s'", s);
	printf("\n");
	len_mine = ft_printf("MINE: '%s'", s);
	printf("\n");
	if (len_orig != len_mine)
		printf("----- LENGTH DOESN'T MATCH! %d != %d -----\n", len_orig,
				len_mine);
}

void	test_s(void)
{
	char	*str;

	printf("\n--- S TEST ---\n\n");
	str = malloc(4);
	str[3] = '\0';
	str[0] = 'a';
	str[1] = 'b';
	str[2] = 'c';
	test_string(NULL);
	test_string("");
	test_string(str);
	test_string("hepjaerrouh08q33 q3 977y3 0qivy;  jdjsrj	f");
	test_string("-");
}

void	test_pointer(void *p)
{
	int	len_orig;
	int	len_mine;

	len_orig = printf("ORIG: '%p'", p);
	printf("\n");
	len_mine = ft_printf("MINE: '%p'", p);
	printf("\n");
	if (len_orig != len_mine)
		printf("----- LENGTH DOESN'T MATCH! %d != %d -----\n", len_orig,
				len_mine);
}

void	test_p(void)
{
	int		a;
	char	*s;

	s = "hello";
	printf("\n--- P TEST ---\n\n");
	test_pointer(&a);
	test_pointer(s);
	test_pointer(NULL);
	test_pointer(-1);
	test_pointer(1);
	test_pointer(15);
	test_pointer(16);
	test_pointer(17);
	test_pointer(LONG_MIN);
	test_pointer(LONG_MAX);
	test_pointer(INT_MIN);
	test_pointer(INT_MAX);
	test_pointer(ULONG_MAX);
	test_pointer(-ULONG_MAX);
}

void	test_decimal(int n)
{
	int	len_orig;
	int	len_mine;

	len_orig = printf("ORIG: '%d'", n);
	printf("\n");
	len_mine = ft_printf("MINE: '%d'", n);
	printf("\n");
	if (len_orig != len_mine)
		printf("----- LENGTH DOESN'T MATCH! %d != %d -----\n", len_orig,
				len_mine);
}

void	test_d(void)
{
	printf("\n--- D TEST ---\n\n");
	test_decimal(34685);
	test_decimal(-34685);
	test_decimal(1);
	test_decimal(-1);
	test_decimal(0);
	test_decimal(INT_MIN);
	test_decimal(INT_MAX);
	test_decimal(LONG_MAX);
	test_decimal(LONG_MIN);
	test_decimal(UINT_MAX);
	test_decimal(ULONG_MAX);
	test_decimal(9223372036854775807LL);
	printf(" %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
	ft_printf(" %d %d %d %d %d %d %d\n", INT_MAX, INT_MIN, LONG_MAX, LONG_MIN, ULONG_MAX, 0, -42);
}

void	test_integer(int n)
{
	int	len_orig;
	int	len_mine;

	len_orig = printf("ORIG: '%i'", n);
	printf("\n");
	len_mine = ft_printf("MINE: '%i'", n);
	printf("\n");
	if (len_orig != len_mine)
		printf("----- LENGTH DOESN'T MATCH! %d != %d -----\n", len_orig,
				len_mine);
}

void	test_i(void)
{
	printf("\n--- I TEST ---\n\n");
	test_integer(34685);
	test_integer(-34685);
	test_integer(1);
	test_integer(-1);
	test_integer(0);
	test_integer(INT_MIN);
	test_integer(INT_MAX);
	test_decimal(LONG_MAX);
	test_decimal(LONG_MIN);
	test_decimal(UINT_MAX);
	test_decimal(ULONG_MAX);
	test_decimal(9223372036854775807LL);
}

void	test_unsigned(unsigned int n)
{
	int	len_orig;
	int	len_mine;

	len_orig = printf("ORIG: '%u'", n);
	printf("\n");
	len_mine = ft_printf("MINE: '%u'", n);
	printf("\n");
	if (len_orig != len_mine)
		printf("----- LENGTH DOESN'T MATCH! %d != %d -----\n", len_orig,
				len_mine);
}

void	test_u(void)
{
	printf("\n--- U TEST ---\n\n");
	test_unsigned(34685);
	test_unsigned(1);
	test_unsigned(0);
	test_unsigned(UINT_MAX);
	test_unsigned(-1);
	test_unsigned(99);
	test_unsigned(100);
	test_unsigned(101);
	test_unsigned(-9);
	test_unsigned(-99);
	test_unsigned(-100);
	test_unsigned(INT_MAX);
	test_unsigned(INT_MIN);
	test_unsigned(LONG_MAX);
	test_unsigned(LONG_MIN);
	test_unsigned(UINT_MAX);
	test_unsigned(ULONG_MAX);
	test_unsigned(9223372036854775807LL);
	test_unsigned(-42);
	
}

void	test_hex_lowercase(unsigned int n)
{
	int	len_orig;
	int	len_mine;

	len_orig = printf("ORIG: '%x'", n);
	printf("\n");
	len_mine = ft_printf("MINE: '%x'", n);
	printf("\n");
	if (len_orig != len_mine)
		printf("----- LENGTH DOESN'T MATCH! %d != %d -----\n", len_orig,
				len_mine);
}

void	test_x(void)
{
	printf("\n--- X TEST ---\n\n");
	test_hex_lowercase(34685);
	test_hex_lowercase(1);
	test_hex_lowercase(32);
	test_hex_lowercase(0);
	test_hex_lowercase(UINT_MAX);
	test_hex_lowercase(-1);
	test_hex_lowercase(15);
	test_hex_lowercase(16);
	test_hex_lowercase(17);
	test_hex_lowercase(-15);
	test_hex_lowercase(-16);
	test_hex_lowercase(-17);
	test_hex_lowercase(-100);
	test_hex_lowercase(INT_MAX);
	test_hex_lowercase(INT_MIN);
	test_hex_lowercase(LONG_MAX);
	test_hex_lowercase(LONG_MIN);
	test_hex_lowercase(UINT_MAX);
	test_hex_lowercase(ULONG_MAX);
	test_hex_lowercase(9223372036854775807LL);
	test_hex_lowercase(-42);
}

void	test_hex_uppercase(unsigned int n)
{
	int	len_orig;
	int	len_mine;

	len_orig = printf("ORIG: '%X'", n);
	printf("\n");
	len_mine = ft_printf("MINE: '%X'", n);
	printf("\n");
	if (len_orig != len_mine)
		printf("----- LENGTH DOESN'T MATCH! %d != %d -----\n", len_orig,
				len_mine);
}

void	test_xx(void)
{
	printf("\n--- XX TEST ---\n\n");
	test_hex_uppercase(34685);
	test_hex_uppercase(1);
	test_hex_uppercase(32);
	test_hex_uppercase(0);
	test_hex_uppercase(UINT_MAX);
	test_hex_uppercase(-1);
	test_hex_uppercase(15);
	test_hex_uppercase(16);
	test_hex_uppercase(17);
	test_hex_uppercase(-15);
	test_hex_uppercase(-16);
	test_hex_uppercase(-17);
	test_hex_uppercase(-100);
	test_hex_uppercase(INT_MAX);
	test_hex_uppercase(INT_MIN);
	test_hex_uppercase(LONG_MAX);
	test_hex_uppercase(LONG_MIN);
	test_hex_uppercase(UINT_MAX);
	test_hex_uppercase(ULONG_MAX);
	test_hex_uppercase(9223372036854775807LL);
	test_hex_uppercase(-42);
}

void	test_percent_sign(void)
{
	int	len_orig;
	int	len_mine;

	len_orig = printf("ORIG: '%%    %%%%'");
	printf("\n");
	len_mine = ft_printf("MINE: '%%    %%%%'");
	printf("\n");
	if (len_orig != len_mine)
		printf("----- LENGTH DOESN'T MATCH! %d != %d -----\n", len_orig,
				len_mine);
}

void	test_percent(void)
{
	printf("\n--- %% TEST ---\n\n");
	test_percent_sign();
}

void	test_extra(const char *s)
{
	int	len_orig;
	int	len_mine;

	len_orig = printf(s);
	len_mine = ft_printf(s);
	if (len_orig != len_mine)
		printf("----- LENGTH DOESN'T MATCH! %d != %d -----\n", len_orig,
				len_mine);
}

void	test_extras(void)
{
	/* char * test = "Test string %";

	printf("%s\n", test);
	ft_printf("%s\n", test); */


	printf("\n--- EXTRA TEST ---\n\n");
	test_extra("\n1%\n");
	test_extra("2%");
	test_extra("\n3df%yjh\n");
}

int	main(void)
{
	/*test_c();
	 test_s();
	test_p(); 
	test_d();*/
	/* test_i();
	test_u();
	test_x();
	test_xx();
	test_percent();*/
	test_extras(); 
}

// INTERESTING TEST CASES
/*
ft_printf("%\n");
null pointer
ft_printf("%.c", 'a')
*/