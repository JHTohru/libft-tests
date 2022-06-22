/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:41:12 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/19 15:05:12 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* char *strdup(const char *s)                                                */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The strdup function creates a copy of the string pointed to by s in a      */
/* space allocated as if by a call to malloc.                                 */
/*                                                                            */
/*                                                                            */
/* RETURN                                                                     */
/*                                                                            */
/* The strdup function returns a pointer to the first character of the        */
/* duplicate string. The returned pointer can be passed to free. If no space  */
/* can be allocated the strdup function returns a null pointer.               */
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
#include <stdlib.h>
#include <string.h>

// ft_strdup must allocate memory and create a copy of the string pointed by s
// and return a pointer to it.
int test_ft_strdup(void)
{
    char    str[] = "foo";
    char    *dup;
    int     res;

    dup = ft_strdup(str);
    res = strcmp(str, dup) == 0 && str != dup;
    free(dup);
    return (res);
}

// ft_strdup must return null if memory allocation fails.
int test_ft_strdup_nomem(void)
{
    char    str[] = "foo";
    char    *dup;

    simulate_malloc_failure();
    dup = ft_strdup(str);
    free(dup);
	reset_malloc();
    return (dup == NULL);
}

int main(void)
{
	print_test_result("test_ft_strdup", test_ft_strdup());
	print_test_result("test_ft_strdup_nomem", test_ft_strdup_nomem());
    return (0);
}
