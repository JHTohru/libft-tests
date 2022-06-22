/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:36:51 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/19 15:46:05 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* void ft_lstdelone(t_list *lst, void (*del)(void *))                        */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The ft_lstdelone function takes as a parameter a node and frees the memory */
/* of the node's content using the function del given as a parameter and free */
/* the node. The memory of next must not be freed.                            */
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

// ft_lstdelone must use the given del function to free the given node's content
// and then free the node making no changes to its next node.
int test_ft_lstdelone(void)
{
    t_list  *node_a;
    t_list  *node_b;

    reset_memory_cnt();
    node_a = ft_lstnew(ft_strdup("alpha")); // todo: use libc strdup once its memory allocation becames recorded
    node_b = ft_lstnew(ft_strdup("bravo")); // todo: use libc strdup once its memory allocation becames recorded
    node_a->next = node_b;
    ft_lstdelone(node_a, &free);
    ft_lstdelone(node_b, &free);
    return (all_allocations_were_freed());
}

int main(void)
{
    print_test_result("test_ft_lstdelone", test_ft_lstdelone());
    return (0);
}
