/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:06:22 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/11 17:46:50 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_utils.h"

/* ************************************************************************** */
/*                                                                            */
/* void *ft_memset(void *s, int c, size_t n)                                  */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The memset function copies the value of c (converted to an unsigned char)  */
/* into each of the first n characters of the object pointed to by s.         */
/*                                                                            */
/*                                                                            */
/* RETURNS                                                                    */
/*                                                                            */
/* The memset function returns the value of s.                                */
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

// The ft_strlen must copy the value of c into each of the first n characters
// of s.
int	test_ft_memset_effect(void)
{
	char	s[10];
	int		c1;
	int		c2;
	size_t	n;
	size_t	i;

	c1 = 'x';
	c2 = 'y';
	ft_memset((void *)s, c1, sizeof(s));
	i = 0;
	while (i < sizeof(s))
		if (((unsigned char *)s)[i++] != c1)
			return (0);
	n = 3;
	ft_memset((void *)s, c2, n);
	i = 0;
	while (i < n)
		if (((unsigned char *)s)[i++] != c2)
			return (0);
	while (i < sizeof(s))
		if (((unsigned char *)s)[i++] != c1)
			return (0);
	return (1);
}

// The ft_memset must return the given s parameter.
int	test_ft_memset_return(void)
{
	void	*s;

	s = (void *)42;
	return (ft_memset(s, 0, 0) == s);
}

int	main(void)
{
	print_test_result("test_ft_memset_effect", test_ft_memset_effect());
	print_test_result("test_ft_memset_return", test_ft_memset_return());
	return (0);
}
