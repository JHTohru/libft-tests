/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:50:52 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/19 15:15:14 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* char *ft_strtrim(const char *s, const char *set)                           */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The ft_strtrim function allocates (with malloc(3)) and returns a copy of s */
/* with the characters specified in set removed from the beginning and the    */
/* end of the string.                                                         */
/*                                                                            */
/*                                                                            */
/* RETURN                                                                     */
/*                                                                            */
/* The ft_strtrim function returns a pointer to the trimmed string or NULL if */
/* the allocation fails.                                                      */
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

// ft_strtrim must allocate memory and returns a copy of s without the
// characters specified in set removed from the beginning and the end of the
// string.
int	test_ft_strtrim_success(void)
{
	char	str[] = ".:|||:.a.b:|:c.:|:.d:|:e.:|||:.";
	char	*tstr;
	int		res;

	tstr = ft_strtrim(str, ".:|");
	res = strcmp(tstr, "a.b:|:c.:|:.d:|:e") == 0;
	free(tstr);
	return (res);
}

// ft_strtrim must take no effect over strings which its extremities have no
// character specified in set.
int	test_ft_strtrim_no_effect(void)
{
	char	str[] = ".:|||:.a.b:|:c.:|:.d:|:e.:|||:.";
	char	*tstr;
	int		res;

	tstr = ft_strtrim(str, "abc");
	res = strcmp(tstr, str) == 0;
	free(tstr);
	return (res);
}

// ft_strtrim must take no effect if set is an empty string.
int	test_ft_strtrim_empty_set(void)
{
	const char	str[] = ".:|||:.a.b:|:c.:|:.d:|:e.:|||:.";
	char		*tstr;
	int			res;

	tstr = ft_strtrim(str, "");
	res = strcmp(tstr, str) == 0;
	free(tstr);
	return (res);
}

// ft_strtrim must return NULL if memory allocation fails.
int	test_ft_strtrim_nomem(void)
{
	char	str[] = ".:|||:.a.b:|:c.:|:.d:|:e.:|||:.";
	char	*tstr;

	simulate_malloc_failure();
	tstr = ft_strtrim(str, ".:|");
	free(tstr);
    reset_malloc();
	return (tstr == NULL);
}

int main(void)
{
	print_test_result("test_ft_strtrim_success", test_ft_strtrim_success());
	print_test_result("test_ft_strtrim_no_effect", test_ft_strtrim_no_effect());
	print_test_result("test_ft_strtrim_empty_set", test_ft_strtrim_empty_set());
	print_test_result("test_ft_strtrim_nomem", test_ft_strtrim_nomem());
	return (0);
}
