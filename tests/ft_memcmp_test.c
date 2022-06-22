/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:33:03 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/14 03:10:52 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* int memcmp(const void *s1, const void *s2, size_t n)                       */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The memcmp function compares the first n characters of the object pointed  */
/* to by s1 to the first n characters of the object pointed to by s2.         */
/*                                                                            */
/*                                                                            */
/* RETURN                                                                     */
/*                                                                            */
/* The memcmp function returns an integer greater than, equal to, or less     */
/* than zero, accordingly as the object pointed to by s1 is greater than,     */
/* equal to, or less than the object pointed to by s2.                        */
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

#include "libft.h"
#include "test_utils.h"

// ft_memcmp must return an integer greater than zero if s1 is greater than s2. 
int test_ft_memcmp_greater(void) {
    char    s1[] = {0x00, 0x00, 0x00, 0x00};
    char    s2[] = {0x00, 0x00, 0x00, 0x01};

    return (ft_memcmp((void *)s1, (void *)s2, 4) < 0);
}

// ft_memcmp must return an integer less than zero if s1 is less than s2. 
int test_ft_memcmp_less(void) {
    char    s1[] = {0x00, 0x00, 0x00, 0x01};
    char    s2[] = {0x00, 0x00, 0x00, 0x00};

    return (ft_memcmp((void *)s1, (void *)s2, 4) > 0);
}

// ft_memcmp must return zero if s1 is equal to s2. 
// ft_memcmp compares not more than n characters.
int test_ft_memcmp_equal(void) {
    char    s1[] = {0x00, 0x00, 0x00, 0x00};
    char    s2[] = {0x00, 0x00, 0x00, 0x00};

    return (ft_memcmp((void *)s1, (void *)s2, 4) == 0);
}

int main(void)
{
	print_test_result("test_ft_memcmp_greater", test_ft_memcmp_greater());
	print_test_result("test_ft_memcmp_less", test_ft_memcmp_less());
	print_test_result("test_ft_memcmp_equal", test_ft_memcmp_equal());
}
