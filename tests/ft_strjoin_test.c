/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:48:33 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/19 15:11:18 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* char *ft_strjoin(const char *s1, const char *s2)                           */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The ft_strjoin function allocates (with malloc(3)) and returns a new       */
/* string, which is the result of the concatenation of s1 and s2.             */
/*                                                                            */
/*                                                                            */
/* RETURN                                                                     */
/*                                                                            */
/* The ft_strjoin function returns a pointer to the new string or NULL if the */
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

// ft_strjoin must allocate and return a new string resulting from the
// concatenation of s1 and s2.
int test_ft_strjoin_success(void)
{
    char    str1[] = "abcde";
    char    str2[] = "fghij";
    char    *cat;
    int     res;

    cat = ft_strjoin(str1, str2);
    res = strcmp(cat, "abcdefghij") == 0;
    free(cat);
    return (res);
}

// ft_strjoin must return NULL if memory allocation fails.
int test_ft_strjoin_nomem(void)
{
    char    str1[] = "abcde";
    char    str2[] = "fghij";
    char    *cat;

    simulate_malloc_failure();
    cat = ft_strjoin(str1, str2);
    free(cat);
    reset_malloc();
    return (cat == NULL);
}

int main(void)
{
	print_test_result("test_ft_strjoin_success", test_ft_strjoin_success());
	print_test_result("test_ft_strjoin_nomem", test_ft_strjoin_nomem());
    return (0);
}
