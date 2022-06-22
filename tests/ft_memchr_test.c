/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:30:57 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/14 03:01:24 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* void *memchr(const void *s, int c, size_t n)                               */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The memchr function locates the first occurrence of c (converted to an     */
/* unsigned char) in the initial n characters (each interpreted as unsigned   */
/* char) of the object pointed to by s. The implementation shall behave as if */
/* it reads the characters sequentially and stops as soon as a matching       */
/* character is found.                                                        */
/*                                                                            */
/*                                                                            */
/* RETURN                                                                     */
/*                                                                            */
/* The memchr function returns a pointer to the located character, or a null  */
/* pointer if the character does not occur in the object.                     */
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

// ft_memchr must return a pointer to the address of the first occurrence of c
// in s.
int test_ft_memchr_success(void)
{
    char    s[] = "abcdeabcdeabcdeabcde";

    return (ft_memchr((void *)s, 'e', sizeof(s)) == s + 4);
}

// ft_memchr must return a null pointer if no occurrence of the parameter c was
// found in s.
int test_ft_memchr_failure(void)
{
    char    s[] = "abcde";

    return (ft_memchr((void *)s, 'x', sizeof(s)) == NULL);
}

int main(void)
{
	print_test_result("test_ft_memchr_success", test_ft_memchr_success());
	print_test_result("test_ft_memchr_failure", test_ft_memchr_failure());
    return (0);
}
