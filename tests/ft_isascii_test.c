/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isascii_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/03 10:13:35 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/11 17:43:08 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_utils.h"
#include <limits.h>

/* ************************************************************************** */
/*                                                                            */
/* int isascii(int c)                                                         */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The isascii() function shall test whether c is a 7-bit US-ASCII character  */
/* code.                                                                      */
/*                                                                            */
/* The isascii() function is defined on all integer values.                   */
/*                                                                            */
/*                                                                            */
/* RETURNS                                                                    */
/*                                                                            */
/* The isascii() function shall return non-zero if c is a 7-bit US-ASCII      */
/* character code between 0 and octal 0177 inclusive; otherwise, it shall     */
/* return 0.                                                                  */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/* SOURCE                                                                     */
/*                                                                            */
/* The Open Group Base Specifications Issue 7, 2018 edition                   */
/* IEEE Std 1003.1-2017 (Revision of IEEE Std 1003.1-2008)                    */
/* https://pubs.opengroup.org/onlinepubs/9699919799/functions/isascii.html    */
/*                                                                            */
/* ************************************************************************** */

// The ft_isascii function must return 1 when the argument c is an ASCII
// characters and 0 otherwise
int	ft_isascii_test(void)
{
	int	i;

	i = INT_MIN;
	while (i < 0)
		if (ft_isascii(i++))
			return (0);
	while (i < 128)
		if (!ft_isascii(i++))
			return (0);
	while (1)
	{
		if (ft_isascii(i))
			return (0);
		if (i == INT_MAX)
			break ;
		i++;
	}
	return (1);
}

int	main(void)
{
	print_test_result("ft_isascii_test", ft_isascii_test());
	return (0);
}
