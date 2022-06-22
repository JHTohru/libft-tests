/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front_test.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:31:29 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/16 11:45:18 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* void ft_lstadd_front(t_list **lst, t_list *new)                            */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The ft_lstadd_front function adds the node new at the beginning of the     */
/* list.                                                                      */
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

// ft_lstadd must add the given node at the beginning of the list.
int test_ft_lstadd_front(void)
{
    t_list  *lst;
    t_list  *node_a;
    t_list  *node_b;
    int     res;

    node_b = ft_lstnew("bravo");
    node_a = ft_lstnew("alpha");
    lst = node_b;
    ft_lstadd_front(&lst    , node_a);
    res = lst == node_a && lst->next == node_b;
    free(lst->next);
    free(lst);
    return (res);
}

// ft_lstadd must initialize lst if it is a null pointer.
int test_ft_lstadd_front_null(void)
{
    t_list  *lst;
    t_list  *node;
    int     res;

    lst = NULL;
    node = ft_lstnew("foo");
    ft_lstadd_front(&lst, node);
    res = lst == node;
    free(lst);
    return (res);
}

int main(void)
{
	print_test_result("test_ft_lstadd_front", test_ft_lstadd_front());
	print_test_result("test_ft_lstadd_front_null",
        test_ft_lstadd_front_null());
    return (0);
}
