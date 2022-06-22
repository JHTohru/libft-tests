/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 11:37:16 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/15 20:55:27 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* char *strnstr(const char *big, const char *little, size_t len)             */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The strnstr() function locates the first occurrence of the null-terminated */
/* string little in the string big, where not more than len characters are    */
/* searched. Characters that appear after a '\0' character are not searched.  */
/*                                                                            */
/*                                                                            */
/* RETURN                                                                     */
/*                                                                            */
/* If little is an empty string, big is returned; if little occurs nowhere in */
/* big, NULL is returned; otherwise a pointer to the first character of the   */
/* first occurrence of little is returned.                                    */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/* SOURCE                                                                     */
/*                                                                            */
/* The FreeBSD Library Functions Manual STRLCPY(3)                            */
/* https://www.freebsd.org/cgi/man.cgi?query=strnstr&sektion=3                */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_utils.h"
#include <string.h>

// ft_strnstr must return a pointer to the first occurrence of little in big.
int test_ft_strnstr_success(void)
{
    char    str[] = "alpha bravo charlie bravo alpha delta bravo";

    return (ft_strnstr(str, "bravo", strlen(str)) == str + 6);
}

// ft_strnstr must return null if there is no occurrence of little in str.
int test_ft_strnstr_no_occurrence(void)
{
    char    str[] = "alpha bravo charlie bravo alpha delta bravo";

    return (ft_strnstr(str, "echo", strlen(str)) == NULL);
}

// ft_strnstr must return str if little is an empty string.
int test_ft_strnstr_empty_little(void)
{
    char    str[] = "alpha bravo charlie bravo alpha delta bravo";

    return (ft_strnstr(str, "", strlen(str)) == str);
}

// ft_strnstr must return NULL if there is no occurrence of little in the n
// first characters of str.
int test_ft_strnstr_occurrence_after_limit(void)
{
    char    str[] = "alpha bravo charlie delta echo";

    return (ft_strnstr(str, "echo", strlen(str) - 1) == NULL);
}

// ft_strnstr must return NULL if there is no occurrence of little before the
// str's terminating NUL-character.
int test_ft_strnstr_hidden_characters(void)
{
    char    str[] = "alpha bravo charlie \0delta";

    return (ft_strnstr(str, "delta", 26) == NULL);
}

int main(void)
{
    print_test_result("test_ft_strnstr_success", test_ft_strnstr_success());
    print_test_result("test_ft_strnstr_no_occurrence",
        test_ft_strnstr_no_occurrence());
    print_test_result("test_ft_strnstr_empty_little",
        test_ft_strnstr_empty_little());
    print_test_result("test_ft_strnstr_occurrence_after_limit",
        test_ft_strnstr_occurrence_after_limit());
    print_test_result("test_ft_strnstr_hidden_characters",
        test_ft_strnstr_hidden_characters());
    return (0);
}
