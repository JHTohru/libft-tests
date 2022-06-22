/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:56:53 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/19 15:21:35 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* char *ft_itoa(int n)                                                       */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The ft_itoa function allocates (with malloc(3)) and returns a string       */
/* representing the integer received as an argument. Negative numbers must be */
/* handled.                                                                   */
/*                                                                            */
/*                                                                            */
/* RETURN                                                                     */
/*                                                                            */
/* The ft_itoa function returns a pointer to the string representing the      */
/* integer or NULL if the allocation fails                                    */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/* SOURCE                                                                     */
/*                                                                            */
/* 42 Libft subject                                                           */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_utils.h"
#include <limits.h>
#include <stdlib.h>
#include <string.h>

// ft_itoa must handle positive numbers.
int test_ft_itoa_positive(void)
{
    char    *nbr;
    int     res;

    nbr = ft_itoa(42);
    res = strcmp(nbr, "42") == 0;
    free(nbr);
    return (res);
}

// ft_itoa must handle negative numbers.
int test_ft_itoa_negative(void)
{
    char    *nbr;
    int     res;

    nbr = ft_itoa(-42);
    res = strcmp(nbr, "-42") == 0;
    free(nbr);
    return (res);
}

// ft_itoa must handle zero.
int test_ft_itoa_zero(void)
{
    char    *nbr;
    int     res;

    nbr = ft_itoa(0);
    res = strcmp(nbr, "0") == 0;
    free(nbr);
    return (res);
}

// ft_itoa must handle INT_MAX
int test_ft_itoa_max(void)
{
    char    *nbr;
    int     res;

    nbr = ft_itoa(INT_MAX);
    res = strcmp(nbr, "2147483647") == 0;
    free(nbr);
    return (res);
}

// ft_itoa must handle INT_MIN
int test_ft_itoa_min(void)
{
    char    *nbr;
    int     res;

    nbr = ft_itoa(INT_MIN);
    res = strcmp(nbr, "-2147483648") == 0;
    free(nbr);
    return (res);
}

int test_ft_itoa_nomem(void)
{
    char    *nbr;

    simulate_malloc_failure();
    nbr = ft_itoa(42);
    free(nbr);
    reset_malloc();
    return (nbr == NULL);
}

int main(void)
{
	print_test_result("test_ft_itoa_positive", test_ft_itoa_positive());
	print_test_result("test_ft_itoa_negative", test_ft_itoa_negative());
	print_test_result("test_ft_itoa_zero", test_ft_itoa_zero());
	print_test_result("test_ft_itoa_max", test_ft_itoa_max());
	print_test_result("test_ft_itoa_min", test_ft_itoa_min());
	print_test_result("test_ft_itoa_nomem", test_ft_itoa_nomem());
    return (0);
}
