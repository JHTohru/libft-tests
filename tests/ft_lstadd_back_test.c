/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back_test.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:35:34 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/16 12:37:46 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* void ft_lstadd_back(t_list **lst, t_list *new)                             */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The ft_lstadd_back function adds the node new at the end of the list.      */
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

// ft_lstadd_back must add the given node at the end of the given list.
int test_ft_lstadd_back(void)
{
    t_list  *lst;
    t_list  *node_b;
    t_list  *node_c;
    int     res;

    lst = ft_lstnew("alpha");
    node_b = ft_lstnew("bravo");
    node_c = ft_lstnew("charlie");
    ft_lstadd_back(&lst, node_b);
    ft_lstadd_back(&lst, node_c);
    res = lst->next == node_b && lst->next->next == node_c;
    free(lst->next->next);
    free(lst->next);
    free(lst);
    return (res);
}

// ft_lstadd_back must define lst as node if lst is a null pointer.
int test_ft_lstadd_back_null(void)
{
    t_list  *lst;
    t_list  *node;
    int     res;

    lst = NULL;
    node = ft_lstnew("foo");
    ft_lstadd_back(&lst, node);
    res = lst == node;
    free(lst);
    return (res);
}

int main(void)
{
    print_test_result("test_ft_lstadd_back", test_ft_lstadd_back());
    print_test_result("test_ft_lstadd_back_null", test_ft_lstadd_back_null());
    return (0);
}
