/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd_test.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:04:40 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/17 01:42:34 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* void ft_putstr_fd(char *s, int fd)                                         */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The ft_putsstr_fd function outputs the string s to the given file          */
/* descriptor                                                                 */
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
#include <fcntl.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

// ft_pustr_fd must output the input string to the given file descriptor.
int test_ft_putstr_fd(void)
{
    char    str[] = "lorem ipsum dolor sit amet";
    char    *filename;
    char    c;
    size_t  i;
    int     fd;
    int     res;

    filename = gen_filename("/tmp/test_ft_putstr_fd_");
    fd = open(filename, O_CREAT | O_RDWR, 0777); // todo: handle open error
    free(filename);
    ft_putstr_fd(str, fd);
    lseek(fd, 0, SEEK_SET);
    res = 1;
    i = 0;
    while (read(fd, &c, 1) == 1) // todo: handle read error
        if (str[i++] != c)
        {
            res = 0;
            break;
        }
    if (res && i != strlen(str))
        res = 0;
    close(fd);
    // todo: delete file
    return (res);
}

int main(void)
{
    print_test_result("test_ft_putstr_fd", test_ft_putstr_fd());
    return (0);
}
