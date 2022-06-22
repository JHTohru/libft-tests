/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:34:17 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/16 12:03:32 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* t_list *ft_lstlast(t_list *lst)                                            */
/*                                                                            */
/* RETURN                                                                     */
/*                                                                            */
/* The ft_lstlast function returns the last node of the list.                 */
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

// ft_lstlast must return the last node of the list.
int test_ft_lstlast(void)
{
    t_list  *lst;
    t_list  *node_a;
    t_list  *node_b;
    t_list  *node_c;
    int     res;

    node_a = ft_lstnew("alpha");
    node_b = ft_lstnew("bravo");
    node_c = ft_lstnew("charlie");
    lst = node_a;
    lst->next = node_b;
    lst->next->next = node_c;
    res = ft_lstlast(lst) == node_c;
    free(lst->next->next);
    free(lst->next);
    free(lst);
    return (res);
}

// ft_lstlast must return the given lst parameter if it contains only a single
// node.
int test_ft_lstlast_single_node(void)
{
    t_list  *lst;
    int     res;

    lst = ft_lstnew("foo");
    res = ft_lstlast(lst) == lst;
    free(lst);
    return (res);
}

// ft_lstlast must return the null pointer if the given lst parameter is NULL.
int test_ft_lstlast_null(void)
{
    return (ft_lstlast(NULL) == NULL);
}

int main(void)
{
    print_test_result("test_ft_lstlast", test_ft_lstlast());
    print_test_result("test_ft_lstlast_single_node",
        test_ft_lstlast_single_node());
    print_test_result("test_ft_lstlast_null", test_ft_lstlast_null());
    return (0);
}
