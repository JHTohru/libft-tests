/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:06:22 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/11 17:45:44 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_utils.h"

/* ************************************************************************** */
/*                                                                            */
/* size_t strlen(const char *s)                                               */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The strlen function computes the length of the string pointed to by s.     */
/*                                                                            */
/*                                                                            */
/* RETURNS                                                                    */
/*                                                                            */
/* The strlen function returns the number of characters that precede the      */
/* terminating null character.                                                */
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

// The ft_strlen must return the length of the given string.
int	test_ft_strlen(void)
{
	return (ft_strlen("42") == 2);
}

// The ft_strlen must return 0 for a empty string as parameter.
int	test_ft_strlen_empty(void)
{
	return (ft_strlen("") == 0 && ft_strlen("\0it should be ignored") == 0);
}

int	main(void)
{
	print_test_result("test_ft_strlen", test_ft_strlen());
	print_test_result("test_ft_strlen_empty", test_ft_strlen_empty());
	return (0);
}
