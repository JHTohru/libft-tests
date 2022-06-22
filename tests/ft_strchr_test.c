/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:21:52 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/14 01:56:12 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* char *strchr(const char *s, int c)                                         */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The strchr function locates the first occurrence of c (converted to a      */
/* char) in the string pointed to by s. The terminating null character is     */
/* considered to be part of the string.                                       */
/*                                                                            */
/*                                                                            */
/* RETURN                                                                     */
/*                                                                            */
/* The strchr function returns a pointer to the located character, or a null  */
/* pointer if the character does not occur in the string.                     */
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
#include <string.h>

// ft_strchr must return a pointer to the address of the first occurrence of c
// in the string s.
int test_ft_strchr_success(void)
{
    char    s[] = "abcdeabcdeabcdeabcde";

    return (ft_strchr(s, 'e') == s + 4);
}

// ft_strchr must locate the terminating null character if that is given as the
// c parameter value.
int test_ft_strchr_terminating_null(void)
{
    char    s[] = "abcdeabcdeabcdeabcde";

    return (ft_strchr(s, '\0') == s + strlen(s));
}

// ft_strchr must return a null pointer if no occurrence of the parameter c was
// found in the string s.
int test_ft_strchr_failure(void)
{
    return (ft_strchr("abcde", 'x') == NULL);
}

int main(void)
{
	print_test_result("test_ft_strchr_success", test_ft_strchr_success());
	print_test_result("test_ft_strchr_terminating_null",
        test_ft_strchr_terminating_null());
	print_test_result("test_ft_strchr_failure", test_ft_strchr_failure());
    return (0);
}
