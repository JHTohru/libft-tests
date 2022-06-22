/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putendl_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:05:46 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/17 01:47:14 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* void ft_putendl_fd(char *s, int fd)                                        */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The ft_putendl_fd function outputs the string s to the given file          */
/* descriptor followed by a newline.                                          */
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

// ft_pustr_fd must output the input string to the given file descriptor
// followed by a newline.
int test_ft_putendl_fd(void)
{
    char    str[] = "lorem ipsum dolor sit amet";
    char    *filename;
    char    c;
    size_t  i;
    int     fd;
    int     res;

    filename = gen_filename("/tmp/test_ft_putendl_fd_");
    fd = open(filename, O_CREAT | O_RDWR, 0777); // todo: handle open error
    free(filename);
    ft_putendl_fd(str, fd);
    lseek(fd, 0, SEEK_SET);
    res = 1;
    i = 0;
    while (read(fd, &c, 1) == 1 && i < strlen(str)) // todo: handle read error
        if (str[i++] != c)
        {
            res = 0;
            break;
        }
    if (i < strlen(str))
        res = 0;
    if (res && read(fd, &c, 1) == 1) // todo: handle read error
    {
        if (c != '\n')
            res = 0;
        if (read(fd, &c, 1) != 0) // todo: handle read error
            res = 0;
    }
    close(fd);
    // todo: delete file
    return (res);
}

int main(void)
{
    print_test_result("test_ft_putendl_fd", test_ft_putendl_fd());
    return (0);
}
