/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putchar_fd_test.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 10:03:21 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/17 01:42:47 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* void ft_putchar_fd(char c, int fd)                                         */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The ft_putchar_fd function outputs the character c to the given file       */
/* descriptor.                                                                */
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
#include <unistd.h>

// ft_pustr_fd must output the character c to the given file descriptor.
int test_ft_putchar_fd(void)
{
    int     fd;
    char    c;
    int     res;
    char    *filename;

    filename = gen_filename("/tmp/test_ft_putchar_fd_");
    fd = open(filename, O_CREAT | O_RDWR, 0777); // todo: handle open error
    free(filename);
    ft_putchar_fd('z', fd);
    lseek(fd, 0, SEEK_SET);
    res = 0;
    if (read(fd, &c, 1) == 1) // todo: handle read error
    {
        if (c == 'z')
            res = 1;
        if (read(fd, &c, 1) > 0) // todo: handle read error
            res = 0;
    }
    close(fd);
    // todo: delete file
    return (res);
}

int main(void)
{
    print_test_result("test_ft_putchar_fd", test_ft_putchar_fd());
    return (0);
}
