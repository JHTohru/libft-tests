/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/01 09:58:20 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/19 14:23:25 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_UTILS_H
# define TEST_UTILS_H

void	print_test_result(char *name, int res);

char    *gen_filename(char *pref);

void	simulate_malloc_failure(void);

void	simulate_malloc_failure_on_nth_call(int n);

void	restore_malloc(void);

void	reset_malloc_call_cnt(void);

void	reset_memory_cnt(void);

int 	all_allocations_were_freed(void);

void    reset_malloc(void);

#endif
