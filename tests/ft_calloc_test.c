/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/31 05:54:41 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/19 14:23:03 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* void *calloc(size_t nmemb, size_t size)                                    */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The calloc function allocates space for an array of nmemb objects, each of */
/* whose size is size. The space is initialized to all bits zero.             */
/*                                                                            */
/*                                                                            */
/* RETURNS                                                                    */
/*                                                                            */
/* The calloc function returns either a null pointer or a pointer to the      */
/* allocated space.                                                           */
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

#include "libft.h"
#include "test_utils.h"
#include <errno.h>
#include <stdlib.h>

// The ft_calloc function must return null if the requested amount of memory is
// not available. int	test_ft_calloc_nomem(test_ft_calloc_nomemd)
int	test_ft_calloc_nomem(void)
{
	void	*s;
	size_t	len;
	size_t	sz;

	simulate_malloc_failure();
	len = 42;
	sz = 4;
	s = ft_calloc(len, sz);
	reset_malloc();
	if (s == NULL)
		return (1);
	free(s);
	return (0);
}

// The ft_calloc implemented in the Linux fashion must emulate the lack of
// enough memory when the multiplication of its args results in overflow.
int	test_ft_calloc_overflow(void)
{
	void	*s;
	size_t	len;
	size_t	sz;

	len = (size_t)-1;
	sz = (size_t)-1;
	s = ft_calloc(len, sz);
	if (s == NULL && errno == ENOMEM)
		return (1);
	free(s);
	return (0);
}

// The ft_calloc function must allocate nmemb * size bytes of memory, set them
// all to zero and return a pointer to its starting address.
int	test_ft_calloc_success(void)
{
	void	*s;
	size_t	len;
	size_t	sz;
	size_t	i;

	len = 42;
	sz = 4;
	s = ft_calloc(len, sz);
	if (s == NULL)
		return (0);
	i = 0;
	while (i < len * sz)
	{
		if (((char *)s)[i] != 0)
		{
			free(s);
			return (0);
		}
		i++;
	}
	free(s);
	return (1);
}

int	main(void)
{
	print_test_result("test_ft_calloc_nomem", test_ft_calloc_nomem());
	print_test_result("test_ft_calloc_overflow", test_ft_calloc_overflow());
	print_test_result("test_ft_calloc_success", test_ft_calloc_success());
	return (0);
}
