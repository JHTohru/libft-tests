/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:45:10 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/19 14:05:43 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#define RED "\e[0;31m"
#define GRN "\e[0;32m"
#define RESET "\e[0m"

void	print_test_result(char *name, int res)
{
	printf("%s: ", name);
	if (res)
		printf(GRN "OK!\n");
	else
		printf(RED "KO!\n");
	printf(RESET);
}

char    *gen_filename(char *pref) // todo: review code
{
    char    *str;
    size_t  rand;
    int     rlen;

    rlen = 0;
    rand = -1;
    while (rand > 0)
    {
        rand /= 10;
        rlen++;
    }
    arc4random_buf((char *)&rand, sizeof(rand));
    str = calloc(rlen + 1, sizeof(char));
    sprintf(str, "%s%0*zu", pref, rlen, rand);
    return (str);
}
