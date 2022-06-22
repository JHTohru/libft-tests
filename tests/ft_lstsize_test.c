/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize_test.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:32:56 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/16 11:56:30 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* int ft_lstsize(t_list *lst)                                                */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The ft_lstsize function counts the number of nodes in a list.              */
/*                                                                            */
/*                                                                            */
/* RETURN                                                                     */
/*                                                                            */
/* The ft_lstsize function returns the length of the list.                    */
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

// ft_lstsize must return the number of nodes in a list.
int test_ft_lstsize(void)
{
    t_list  *lst;
    int     res;

    lst = ft_lstnew("alpha");
    lst->next = ft_lstnew("bravo");
    lst->next->next = ft_lstnew("charlie");
    res = ft_lstsize(lst) == 3;
    free(lst->next->next);
    free(lst->next);
    free(lst);
    return (res);
}

// ft_lstsize must handle a list containing a single node.
int test_ft_lstsize_one(void)
{
    t_list  *lst;
    int     res;

    lst = ft_lstnew("foo");
    res = ft_lstsize(lst) == 1;
    free(lst);
    return (res);
}

// ft_lstsize must handle a null pointer given as parameter.
int test_ft_lstsize_zero(void)
{
    return (ft_lstsize(NULL) == 0);
}

int main(void)
{
	print_test_result("test_ft_lstsize", test_ft_lstsize());
	print_test_result("test_ft_lstsize_one", test_ft_lstsize_one());
	print_test_result("test_ft_lstsize_zero", test_ft_lstsize_zero());
    return (0);
}
