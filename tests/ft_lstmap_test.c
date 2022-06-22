/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:40:56 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/17 17:55:36 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))    */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The ft_lstmap function iterates the list lst and applies the function f on */
/* the content of each node. Creates a new list resulting of the successive   */
/* applications of the function f. The del function is used to delete the     */
/* content of a node if needed.                                               */
/*                                                                            */
/*                                                                            */
/* RETURN                                                                     */
/*                                                                            */
/* The ft_lstmap function returns a pointer to the start of the new list or   */
/* NULL if the allocation fails.                                              */
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

void    *to_upper(void *s)
{
    char    *str;
    size_t  i;

    str = malloc(strlen(s) + 1);
    if (str != NULL)
    {
        i = 0;
        while (((char *)s)[i] != '\0')
        {
            str[i] = toupper(((char *)s)[i]);
            i++;
        }
        str[i] = '\0';        
    }
    return ((void *)str);
}

// ft_lstmap must create a new list resulting on the successive applications of
// the function f.
int test_ft_lstmap(void)
{
    t_list  *lst;
    t_list  *mlst;
    int     res;

    lst = ft_lstnew(strdup("alpha"));
    lst->next = ft_lstnew(strdup("bravo"));
    lst->next->next = ft_lstnew(strdup("charlie"));
    mlst = ft_lstmap(lst, &to_upper, &free);
    res = strcmp(mlst->content, "ALPHA") == 0
        && strcmp(mlst->next->content, "BRAVO") == 0
        && strcmp(mlst->next->next->content, "CHARLIE") == 0;
    free(lst->next->next->content);
    free(lst->next->next);
    free(lst->next->content);
    free(lst->next);
    free(lst->content);
    free(lst);
    free(mlst->next->next->content);
    free(mlst->next->next);
    free(mlst->next->content);
    free(mlst->next);
    free(mlst->content);
    free(mlst);
    return (res);
}

// ft_lstmap must apply del in the content of each node it already created if
// allocation fails in a node creation.
// todo

int main(void)
{
    print_test_result("test_ft_lstmap", test_ft_lstmap());
    return (0);
}
