/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/07 11:19:04 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/15 23:51:05 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* int isprint(int c)                                                         */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The isprint function tests for any printing character including space      */
/* (’ ’ ).                                                                    */
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
#include <stdio.h>
#include <string.h>

// The ft_isprint must return true when the argument is a printing character
// and false otherwise.
int	test_ft_isprint(void)
{
	char	print_chars[] = "!\"#$%&'()*+,-./0123456789:;<=>?@ABCDEFGHIJKLMNOPQRSTUVWXYZ[\\]^_`abcdefghijklmnopqrstuvwxyz{|}~";
	char	not_print_chars[] = "\001\002\003\004\005\006\007\b\t\n\v\f\r\016\017\020\021\022\023\024\025\026\027\030\031\032\033\034\035\036\037\177";
	size_t	i;

	if (ft_isprint(EOF))
		return (0);
	i = 0;
	while (i < strlen(print_chars))
		if (!ft_isprint(print_chars[i++]))
			return (0);
	i = 0;
	while (i < strlen(not_print_chars))
		if (ft_isprint(not_print_chars[i++]))
			return (0);
	return (1);

}

int	main(void)
{
	print_test_result("test_ft_isprint", test_ft_isprint());
	return (0);
}
