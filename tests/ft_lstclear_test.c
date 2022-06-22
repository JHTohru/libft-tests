/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_test.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:38:17 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/16 19:24:09 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* void ft_lstclear(t_list **lst, void (*del)(void *))                        */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The ft_lstclear function deletes and frees the given node and every        */
/* successor of that node, using the function del and free(3). Finally, the   */
/* pointer to the list must be set to NULL.                                   */
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

int test_ft_lstclear(void)
{
    char    content_a[] = "alpha";
    char    content_b[] = "bravo";
    char    content_c[] = "charlie";
    t_list  *lst;
    int     res;

    lst = malloc(sizeof(t_list));
    lst->content = malloc(sizeof(content_a));
    strcpy(lst->content, content_a);
    lst->next = malloc(sizeof(t_list));
    lst->next->content = malloc(sizeof(content_b));
    strcpy(lst->next->content, content_b);
    lst->next->next = malloc(sizeof(t_list));
    lst->next->next->content = malloc(sizeof(content_c));
    strcpy(lst->next->next->content, content_c);
    lst->next->next->next = NULL;
    ft_lstclear(&lst->next, &free);
    res = lst->next == NULL;
    free(lst->content);
    free(lst);
    return (res);
    // todo: check if lst->next and lst->next->next were freed.
    // todo: check if clear was called for both lst->next->content and
    // lst->next->next->content.
}

int main(void)
{
    print_test_result("test_ft_lstclear", test_ft_lstclear());
    return (0);
}
