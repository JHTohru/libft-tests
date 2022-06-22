/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:28:13 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/14 02:51:53 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* int strncmp(const char *s1, const char *s2, size_t n)                      */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The strncmp function compares not more than n characters (characters that  */
/* follow a null character are not compared) from the array pointed to by s1  */
/* to the array pointed to by s2.                                             */
/*                                                                            */
/*                                                                            */
/* RETURN                                                                     */
/*                                                                            */
/* The strncmp function returns an integer greater than, equal to, or less    */
/* than zero, accordingly as the possibly null-terminated array pointed to by */
/* s1 is greater than, equal to, or less than the possibly null-terminated    */
/* array pointed to by s2.                                                    */
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

// ft_strncmp must return an integer greater than zero if s1 is greater than s2. 
// ft_strncmp compares not more than n characters.
int test_ft_strncmp_greater(void) {
    return (ft_strncmp("abdef", "abcgh", 3) > 0);
}

// ft_strncmp must return an integer less than zero if s1 is less than s2. 
// ft_strncmp compares not more than n characters.
int test_ft_strncmp_less(void) {
    return (ft_strncmp("abcgh", "abdef", 3) < 0);
}

// ft_strncmp must return zero if s1 is equal to s2. 
// ft_strncmp compares not more than n characters.
int test_ft_strncmp_equal(void) {
    return (ft_strncmp("abdef", "abcgh", 2) == 0);
}

int main(void)
{
	print_test_result("test_ft_strncmp_greater", test_ft_strncmp_greater());
	print_test_result("test_ft_strncmp_less", test_ft_strncmp_less());
	print_test_result("test_ft_strncmp_equal", test_ft_strncmp_equal());
}
