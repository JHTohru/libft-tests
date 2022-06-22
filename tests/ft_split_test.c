/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_test.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:52:55 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/14 11:01:40 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* char **ft_split(const char *s, char c)                                     */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The ft_split function allocates (with malloc(3)) and returns an array of   */
/* strings obtained by splitting s using the character c as a delimiter. The  */
/* array must end with a NULL pointer.                                        */
/*                                                                            */
/* RETURN                                                                     */
/*                                                                            */
/* The ft_split function returns a pointer to the array of new strings        */
/* resulting from the split or NULL if the allocation fails                   */
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
#include <stdlib.h>
#include <string.h>

static void	delete_tokens(char ***tokens)
{
	size_t	i;

	i = 0;
	while ((*tokens)[i] != NULL)
	{
		free((*tokens)[i]);
		(*tokens)[i] = NULL;
		i++;
	}
	free(*tokens);
    *tokens = NULL;
}

// ft_split must allocate and return a null terminated array of the substrings
// delimited by the character c.
int test_ft_split_success(void)
{
    char    str[] = "alpha bravo charlie delta echo";
    char    **tokens;
    int     res;

    tokens = ft_split(str, ' ');
    res = strcmp(tokens[0], "alpha") == 0 && strcmp(tokens[1], "bravo") == 0
        && strcmp(tokens[2], "charlie") == 0 && strcmp(tokens[3], "delta") == 0
        && strcmp(tokens[4], "echo") == 0 && tokens[5] == NULL;
    delete_tokens(&tokens);
    return (res);
}

// ft_split must generate no substrings if the delimiter c is not present in the
// source string. Instead, it must return a null terminated array with only a
// copy of the source string.
int test_ft_split_no_delimiter(void)
{
    char    str[] = "alpha bravo charlie delta echo";
    char    **tokens;
    int     res;

    tokens = ft_split(str, 'x');
    res = strcmp(tokens[0], str) == 0 && tokens[1] == NULL;
    delete_tokens(&tokens);
    return (res);
}

// ft_split must generate no substrings if the delimiter c is a NUL-byte.
// Instead, it must return a null terminated array with only a copy of the
// source string.
int test_ft_split_nul_delimiter(void)
{
    char    str[] = "alpha bravo charlie delta echo";
    char    **tokens;
    int     res;

    tokens = ft_split(str, '\0');
    res = strcmp(tokens[0], str) == 0 && tokens[1] == NULL;
    delete_tokens(&tokens);
    return (res);
}

// ft_split must return NULL if allocation fails.
// todo: force allocation failure for the not first array element.

int main(void)
{
	print_test_result("test_ft_split_success", test_ft_split_success());
	print_test_result("test_ft_split_no_delimiter",
        test_ft_split_no_delimiter());
	print_test_result("test_ft_split_nul_delimiter",
        test_ft_split_nul_delimiter());
    return (0);
}
