/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:25:54 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/14 02:00:11 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* char *ft_strrchr(const char *s, int c)                                     */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The strrchr function locates the last occurrence of c (converted to a      */
/* char) in the string pointed to by s. The terminating null character is     */
/* considered to be part of the string.                                       */
/*                                                                            */
/*                                                                            */
/* RETURN                                                                     */
/*                                                                            */
/* The strrchr function returns a pointer to the character, or a null pointer */
/* if c does not occur in the string.                                         */
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

// ft_strrchr must return a pointer to the address of the first occurrence of c
// in the string s.
int test_ft_strrchr_success(void)
{
    char    s[] = "abcdeabcdeabcdeabcde";

    return (ft_strrchr(s, 'e') == s + 19);
}

// ft_strrchr must locate the terminating null character if that is given as the
// c parameter value.
int test_ft_strrchr_terminating_null(void)
{
    char    s[] = "abcdeabcdeabcdeabcde";

    return (ft_strrchr(s, '\0') == s + strlen(s));
}

// ft_strrchr must return a null pointer if no occurrence of the parameter c was
// found in the string s.
int test_ft_strrchr_failure(void)
{
    return (ft_strrchr("abcde", 'x') == NULL);
}

int main(void)
{
	print_test_result("test_ft_strrchr_success", test_ft_strrchr_success());
	print_test_result("test_ft_strrchr_terminating_null",
        test_ft_strrchr_terminating_null());
	print_test_result("test_ft_strrchr_failure", test_ft_strrchr_failure());
    return (0);
}
