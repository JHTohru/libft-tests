/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:39:46 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/16 22:33:30 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* void ft_lstiter(t_list *lst, void (*f)(void *))                            */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The ft_lstiter function iterates the list lst and applies the function f   */
/* on the content of each node.                                               */
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

void    to_upper(void *s)
{
    while (*((char *)s) != '\0')
    {
        *((char *)s) = toupper(*((char *)s));
        s++;
    }
}

int test_ft_lstiter(void)
{
    t_list  *lst;
    int     res;

    lst = ft_lstnew((void *)strdup("alpha"));
    lst->next = ft_lstnew((void *)strdup("bravo"));
    lst->next->next = ft_lstnew((void *)strdup("charlie"));
    ft_lstiter(lst, &to_upper);
    res = strcmp(lst->content, "ALPHA") == 0
        && strcmp(lst->next->content, "BRAVO") == 0
        && strcmp(lst->next->next->content, "CHARLIE") == 0;
    free(lst->next->next->content);
    free(lst->next->next);
    free(lst->next->content);
    free(lst->next);
    free(lst->content);
    free(lst);
    return (res);
}

int main(void)
{
    print_test_result("test_ft_lstiter", test_ft_lstiter());
    return (0);
}
