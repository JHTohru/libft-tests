/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:58:49 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/19 15:22:52 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* char *ft_strmapi(const char *s, char (*f)(unsigned int, char))             */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The ft_strmapi function applies the function f to each character of the    */
/* string s, and passing its index as first argument to create a new string   */
/* (with malloc(3)) resulting from successive applications of f.              */ 
/*                                                                            */
/*                                                                            */
/* RETURN                                                                     */
/*                                                                            */
/* The ft_strmapi function returns a pointer to the string created from the   */
/* successive applications of f or NULL if the allocation fails.              */
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
#include <stdlib.h>
#include <string.h>

static char	strtoupper(unsigned int i, char c)
{
	(void)i;
	return (toupper(c));
}

// ft_strmapi must apply function f to each character of the input string.
int	test_ft_strmapi(void)
{
	char	*mstr;
	int		res;

	mstr = ft_strmapi("alpha bravo charlie", &strtoupper);
	res = strcmp(mstr, "ALPHA BRAVO CHARLIE") == 0;
	free(mstr);
	return (res);
}

// ft_strmapi must return NULL if memory allocation fails.
int	test_ft_strmapi_nomem(void)
{
	char	*mstr;

	simulate_malloc_failure();
	mstr = ft_strmapi("alpha bravo charlie", &strtoupper);
	free(mstr);
    reset_malloc();
	return (mstr == NULL);
}

int	main(void)
{
	print_test_result("test_ft_strmapi", test_ft_strmapi());
	print_test_result("test_ft_strmapi_nomem", test_ft_strmapi_nomem());
	return (0);
}
