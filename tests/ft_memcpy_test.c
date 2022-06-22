/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 13:42:49 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/11 17:48:28 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_utils.h"
#include <string.h>

/* ************************************************************************** */
/*                                                                            */
/* void *memcpy(void *s1, const void *s2, size_t n)                           */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The memcpy function copies n characters from the object pointed to by s2   */
/* into the object pointed to by s1. If copying takes place between objects   */
/* that overlap, the behavior is undefined.                                   */
/*                                                                            */
/*                                                                            */
/* RETURNS                                                                    */
/*                                                                            */
/* The memcpy function returns the value of s1.                               */
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

// The ft_memcpy must copy n characters from s2 to s1.
int	test_ft_memcpy_effect(void)
{
	char	s[] = "abcdef";

	ft_memcpy((void *)s, (void *)(s + 3), 3);
	return (strcmp(s, "defdef") == 0);
}

// The ft_memcpy must copy n characters from s2 to s1.
int	test_ft_memcpy_effect_2(void)
{
	char	s[] = "abcdef";

	ft_memcpy((void *)(s + 3), (void *)s, 3);
	return (strcmp(s, "abcabc") == 0);
}

// The ft_memcpy must copy no bytes if the n parameter value is zero.
int	test_ft_memcpy_effect_3(void)
{
	char	s[] = "abcdef";

	ft_memcpy((void *)s, (void *)"ghijkl", 0);
	return (strcmp(s, "abcdef") == 0);
}

// The ft_memcpy must return the value of its first parameter.
int	test_ft_memcpy_return(void)
{
	char	s[] = "abcdef";

	return (ft_memcpy((void *)s, (void *)"ghijkl", 0) == (void *)s);
}

int	main(void)
{
	print_test_result("test_ft_memcpy_effect", test_ft_memcpy_effect());
	print_test_result("test_ft_memcpy_effect_2", test_ft_memcpy_effect_2());
	print_test_result("test_ft_memcpy_effect_3", test_ft_memcpy_effect_3());
	print_test_result("test_ft_memcpy_return", test_ft_memcpy_return());
	return (0);

}
