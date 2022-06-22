/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 15:29:34 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/11 18:13:45 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_utils.h"
#include <string.h>

/* ************************************************************************** */
/*                                                                            */
/* void *memmove(void *s1, const void *s2, size_t n)                          */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The memmove function copies n characters from the object pointed to by s2  */
/* into the object pointed to by s1. Copying takes place as if the n          */
/* characters from the object pointed to by s2 are first copied into a        */
/* temporary array of n characters that does not overlap the objects pointed  */
/* to by s1 and s2, and then the n characters from the temporary array are    */
/* copied into the object pointed to by s1.                                   */
/*                                                                            */
/*                                                                            */
/* RETURN                                                                     */
/*                                                                            */
/* The memmove function returns the value of s1.                              */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/* SOURCE                                                                     */
/*                                                                            */
/* The Open Group Base Specifications Issue 6                                 */
/* IEEE Std 1003.1, 2004 Edition                                              */
/* https://pubs.opengroup.org/onlinepubs/009695399/functions/bzero.html       */
/*                                                                            */
/* ************************************************************************** */

// ft_memmove must copy the data from a memory area data to the other.
int	test_ft_memmove_non_overlapping(void)
{
	int	a;
	int	b;

	a = 42;
	ft_memmove((void *)&b, (void *)&a, sizeof(int));
	return (a == b);
}

// ft_memmove must handle overlapping memory areas.
int	test_ft_memmove_overlapping_desc(void)
{
	char	str[] = "abc";


	ft_memmove((void *)(str + 1), (void *)str, 2);
	return (strcmp(str, "aab") == 0);
}

int	test_ft_memmove_overlapping_asc(void)
{
	char	str[] = "abc";

	ft_memmove((void *)str, (void *)(str + 1), 2);
	return (strcmp(str, "bcc") == 0);
}

// ft_memmove must take no effect when the number of bytes to be moved is zero.
int	test_ft_memmove_zero_bytes(void)
{
	char	str[] = "abc";

	ft_memmove((void *)str, (void *)"xxx", 0);
	return (strcmp(str, "abc") == 0);
}

int	main(void)
{
	print_test_result("test_ft_memmove_non_overlapping",
		test_ft_memmove_non_overlapping());
	print_test_result("test_ft_memmove_overlapping_desc",
		test_ft_memmove_overlapping_desc());
	print_test_result("test_ft_memmove_overlapping_asc",
		test_ft_memmove_overlapping_asc());
	print_test_result("test_ft_memmove_zero_bytes",
		test_ft_memmove_zero_bytes());
	return (0);
}
