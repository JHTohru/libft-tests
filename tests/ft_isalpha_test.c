/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 13:49:04 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/11 17:42:34 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_utils.h"
#include <stdio.h>
#include <string.h>

/* ************************************************************************** */
/*                                                                            */
/* int isalpha(int c)                                                         */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The isalpha function tests for any character for which isupper or islower  */
/* is true, or any character that is one of a locale-specific set of          */
/* alphabetic characters for which none of iscntrl, isdigit, ispunct, or      */
/* isspace is true.) In the "C" locale, isalpha returns true only for the     */
/* characters for which isupper or islower is true.                           */
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

// The ft_isalpha must return true when the argument is an alphabetic character
// and false otherwise.
int	test_ft_isalpha(void)
{
	char	alpha_chars[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char	not_alpha_chars[] = "!\"#$%&'()*+,-./0123456789:;<=>?@[\\]^_`{|}~";
	size_t	i;

	if (ft_isalpha(EOF))
		return (0);
	i = 0;
	while (i < strlen(alpha_chars))
		if (!ft_isalpha(alpha_chars[i++]))
			return (0);
	i = 0;
	while (i < strlen(not_alpha_chars))
		if (ft_isalpha(not_alpha_chars[i++]))
			return (0);
	return (1);
}


int	main(void)
{
	print_test_result("test_ft_isalpha", test_ft_isalpha());
	return (0);
}
