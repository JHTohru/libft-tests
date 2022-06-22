/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:01:07 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/16 11:19:03 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* void ft_striteri(char *s, void (*f)(unsigned int, char *))                 */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The ft_striteri function applies the function f on each character of the   */
/* string passed as argument, passing its index as first argument. Each       */
/* character is passed by addres to f to be modified if necessary.            */
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
#include <ctype.h>
#include <string.h>

static void    strtoupper(unsigned int i, char *c)
{
    (void)i;
    *c = toupper(*c);
}

// ft_striteri must apply function f to each character of the input string.
int test_ft_striteri(void)
{
    char    str[] = "alpha bravo charlie";

    ft_striteri(str, &strtoupper);
    return (strcmp(str, "ALPHA BRAVO CHARLIE") == 0);
}

int main(void)
{
	print_test_result("test_ft_striteri", test_ft_striteri());
    return (0);
}
