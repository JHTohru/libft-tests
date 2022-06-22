/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isdigit_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:41:06 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/11 17:42:44 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_utils.h"
#include <stdio.h>
#include <string.h>

/* ************************************************************************** */
/*                                                                            */
/* int isdigit(int c)                                                         */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The isdigit function tests for any decimal-digit character (as defined in  */
/* 5.2.1).                                                                    */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/* SOURCE                                                                     */
/*                                                                            */
/* The C Programming Language International Standard                          */
/* Working draft — October 18, 2021 ISO/IEC 9899:202x (E)                     */
/* https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2731.pdf                 */
/*                                                                            */
/* ************************************************************************** */

// The ft_isdigit must return true when the argument is a digit character and
// false otherwise.
int	test_ft_isdigit(void)
{
	char	digit_chars[] = "0123456789";
	char	not_digit_chars[] = "!\"#$%&'()*+,-./:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	size_t	i;

	if (ft_isdigit(EOF))
		return (0);
	i = 0;
	while (i < strlen(digit_chars))
		if (!ft_isdigit(digit_chars[i++]))
			return (0);
	i = 0;
	while (i < strlen(not_digit_chars))
		if (ft_isdigit(not_digit_chars[i++]))
			return (0);
	return (1);
}

int	main(void)
{
	print_test_result("test_ft_isdigit", test_ft_isdigit());
	return (0);
}
