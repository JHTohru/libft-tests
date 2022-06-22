/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 12:54:37 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/11 17:47:28 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_utils.h"
#include <string.h>

/* ************************************************************************** */
/*                                                                            */
/* void ft_bzero(void *s, size_t n)                                           */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The bzero() function shall place n zero-valued bytes in the area pointed   */
/* to by s.                                                                   */
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

// The bzero() function shall place n zero-valued bytes in the area pointed to
// by s.
int	test_ft_bzero(void)
{
	char	s[10];
	int		c;
	size_t	n;
	size_t	i;

	c = 'x';
	memset(s, c, sizeof(s));
	n = 3;
	ft_bzero(s, n);
	i = 0;
	while (i < n)
		if (((unsigned char *)s)[i++] != '\0')
			return (0);
	while (i < sizeof(s))
		if (((unsigned char *)s)[i++] != c)
			return (0);
	return (1);
}

int	main(void)
{
	print_test_result("test_ft_bzero", test_ft_bzero());
	return (0);
}
