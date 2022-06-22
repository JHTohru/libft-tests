/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:43:43 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/19 15:07:26 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* char *ft_substr(const char *s, unsigned int start, size_t len)             */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The ft_substr function allocates (with malloc(3)) and returns a substring  */
/* from the string 's'. The substring begins at index 'start' and is of       */
/* maximum length 'len                                                        */
/*                                                                            */
/*                                                                            */
/* RETURN                                                                     */
/*                                                                            */
/* The ft_substr function returns a pointer to the substring or NULL if the   */
/* allocation fails.                                                          */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/* SOURCE                                                                     */
/*                                                                            */
/* 42 Libft subject                                                           */
/* https://cdn.intra.42.fr/pdf/pdf/50832/en.subject.pdf                       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_utils.h"
#include <stdlib.h>
#include <string.h>

// ft_substr must allocate memory for, create, and return a substring from the
// string 's'.
int test_ft_substr_success(void)
{
    char    str[] = "abcde";
    char    *sub;
    int     res;

    sub = ft_substr(str, 2, 2);
    res = strcmp(sub, "cd") == 0 && sub != str + 2;
    free(sub);
    return (res);
}

// ft_substr must return an empty string if the start parameter value is greater
// than the str length.
int test_ft_substr_late_start(void)
{
    char    str[] = "abcde";
    char    *sub;
    int     res;

    sub = ft_substr(str, 5, 5);
    res = strcmp(sub, "") == 0 && sub != str + 5;
    free(sub);
    return (res);
}

// ft_substr must return an empty string if the len parameter value is zero.
int test_ft_substr_zero_len(void)
{
    char    str[] = "abcde";
    char    *sub;
    int     res;

    sub = ft_substr(str, 0, 0);
    res = strcmp(sub, "") == 0 && sub != str + 5;
    free(sub);
    return (res);
}

// ft_substr must return null if memory allocation fails.
int test_ft_substr_nomem(void)
{
    char    str[] = "abcde";
    char    *sub;

    simulate_malloc_failure();
    sub = ft_substr(str, 2, 2);
    free(sub);
    reset_malloc();
    return (sub == NULL);
}

int main(void)
{
	print_test_result("test_ft_substr_success", test_ft_substr_success());
	print_test_result("test_ft_substr_late_start", test_ft_substr_late_start());
	print_test_result("test_ft_substr_zero_len", test_ft_substr_zero_len());
	print_test_result("test_ft_substr_nomem", test_ft_substr_nomem());
    return (0);
}
