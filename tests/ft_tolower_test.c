/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 01:32:28 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/11 06:30:01 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_utils.h"
#include <stdio.h>
#include <string.h>

int	ft_tolower(int c);

/* ************************************************************************** */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The tolower function converts an uppercase letter to a corresponding       */
/* lowercase letter.                                                          */
/*                                                                            */
/*                                                                            */
/* RETURNS                                                                    */
/*                                                                            */
/* If the argument is a character for which isupper is true and there are one */
/* or more corresponding characters, as specified by the current locale, for  */
/* which islower is true, the tolower function returns one of the 			  */
/* corresponding characters (always the same one for any given locale);       */
/* otherwise, the argument is returned unchanged.                             */
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

// When the parameter is a uppercase letter, the ft_toupper must return its
// corresponding lowercase letter. When the parameter is not uppercase letter,
// ft_toupper must be return it with no modifications.
int	test_ft_tolower(void)
{
	char	str1[] = "!\"#$%&'()*+,-./0123456789:;<=>?@[\\]^_`ABCDEFGHIJKLMNOPQRSTUVWXYZ{|}~";
	char	str2[] = "!\"#$%&'()*+,-./0123456789:;<=>?@[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	size_t	i;

	if (ft_tolower(EOF) != EOF)
		return (0);
	i = 0;
	while (i < strlen(str1))
	{
		if (ft_tolower(str1[i]) != str2[i])
			return (0);
		i++;
	}
	return (1);
}

int	main(void)
{
	print_test_result("test_ft_tolower", test_ft_tolower());
	return (0);
}
