/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 14:48:59 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/11 17:42:57 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_utils.h"
#include <stdio.h>
#include <string.h>

/* ************************************************************************** */
/*                                                                            */
/* int isalnum(int c)                                                         */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The isalnum function tests for any character for which isalpha or isdigit  */
/* is true.                                                                   */
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

// The ft_isalnum must return true when the argument is either an alphabetic
// or a numeric character and false otherwise.
int	test_ft_isalnum(void)
{
	char	alnum_chars[] = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char	not_alnum_chars[] = "!\"#$%&'()*+,-./:;<=>?@[\\]^_`{|}~";
	size_t	i;

	if (ft_isalnum(EOF))
		return (0);
	i = 0;
	while (i < strlen(alnum_chars))
		if (!ft_isalnum(alnum_chars[i++]))
			return (0);
	i = 0;
	while (i < strlen(not_alnum_chars))
		if (ft_isalnum(not_alnum_chars[i++]))
			return (0);
	return (1);
}

int	main(void)
{
	print_test_result("test_ft_isalnum", test_ft_isalnum());
	return (0);
}
