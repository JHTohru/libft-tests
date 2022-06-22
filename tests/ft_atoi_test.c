/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_test.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jmenezes <jmenezes@student.42.rio>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/08 09:36:26 by jmenezes          #+#    #+#             */
/*   Updated: 2022/06/16 10:02:21 by jmenezes         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/* int atoi(const char *nptr)                                                 */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The atoi function convert the initial portion of the string pointed to by  */
/* nptr to int representation. Except for the behavior on error, it is        */
/* equivalent to (int)strtol(nptr, (char **)NULL, 10)                         */
/*                                                                            */
/*                                                                            */
/* RETURN                                                                     */
/*                                                                            */
/* The atoi function return the converted value.                              */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                           --------------------                             */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* long int strtol(const char *nptr, char **endptr, int base)                 */
/*                                                                            */
/* DESCRIPTION                                                                */
/*                                                                            */
/* The strtol function convert the initial portion of the string pointed to   */
/* by nptr to long int representation. First, it decompose the input string   */
/* into three parts: an initial, possibly empty, sequence of white-space      */
/* characters, a subject sequence resembling an integer represented in some   */
/* radix determined by the value of base, and a final string of one or more   */
/* unrecognized characters, including the terminating null character of the   */
/* input string. Then, they attempt to convert the subject sequence to an     */
/* integer, and return the result.                                            */
/*                                                                            */
/* If the value of base is zero, the expected form of the subject sequence is */
/* that of an integer constant as described in 6.4.4.1, optionally preceded   */
/* by a plus or minus sign, but not including an integer suffix or any        */
/* optional digit separators. If the value of base is between 2 and 36        */
/* (inclusive), the expected form of the subject sequence is a sequence of    */
/* letters and digits representing an integer with the radix specified by     */
/* base, optionally preceded by a plus or minus sign, but not including an    */
/* integer suffix or any optional digit separators. The letters from a (or A) */
/* through z (or Z) are ascribed the values 10 through 35; only letters and   */
/* digits whose ascribed values are less than that of base are permitted. If  */
/* the value of base is 2, the characters 0b or 0B may optionally precede the */
/* sequence of letters and digits, following the sign if present. If the      */
/* value of base is 16, the characters 0x or 0X may optionally precede the    */
/* sequence of letters and digits, following the sign if present.             */
/*                                                                            */
/* The subject sequence is defined as the longest initial subsequence of the  */
/* input string, starting with the first non-white-space character, that is   */
/* of the expected form. The subject sequence contains no characters if the   */
/* input string is empty or consists entirely of white-space characters, or   */
/* if the first non-white-space character is other than a sign or a           */
/* permissible letter or digit.                                               */
/*                                                                            */
/* If the subject sequence has the expected form and the value of base is     */
/* zero, the sequence of characters starting with the first digit is          */
/* interpreted as an integer constant according to the rules of 6.4.4.1. If   */
/* the subject sequence has the expected form and the value of base is        */
/* between 2 and 36, it is used as the base for conversion, ascribing to each */
/* letter its value as given above. If the subject sequence begins with a     */
/* minus sign, the value resulting from the conversion is negated (in the     */
/* return type). A pointer to the final string is stored in the object        */
/* pointed to by endptr, provided that endptr is not a null pointer.          */
/*                                                                            */
/* In other than the "C" locale, additional locale-specific subject sequence  */
/* forms may be accepted.                                                     */
/*                                                                            */
/* If the subject sequence is empty or does not have the expected form, no    */
/* conversion is performed; the value of nptr is stored in the object pointed */
/* to by endptr, provided that endptr is not a null pointer.                  */
/*                                                                            */
/*                                                                            */
/* RETURN                                                                     */
/*                                                                            */
/* The strtol function return the converted value, if any. If no conversion   */
/* could be performed, zero is returned. If the correct value is outside the  */
/* range of representable values, LONG_MIN or LONG_MAX is returned (according */
/* to the return type and sign of the value, if any), and the value of the    */
/* macro ERANGE is stored in errno.                                           */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/*                           --------------------                             */
/*                                                                            */
/*                                                                            */
/*                                                                            */
/* 7.22.1 Numeric conversion functions                                        */
/* The functions atof, atoi, atol, and atoll need not affect the value of the */
/* integer expression errno on an error. If the value of the result cannot be */
/* represented, the behavior is undefined.                                    */
/*                                                                            */
/* ************************************************************************** */
/*                                                                            */
/* SOURCE                                                                     */
/*                                                                            */
/* The C Programming Language International Standard                          */
/* Working draft — October 18, 2021 ISO/IEC 9899:202x (E)                     */
/* https://www.open-std.org/jtc1/sc22/wg14/www/docs/n2731.pdf                 */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "test_utils.h"
#include <limits.h>

// ft_atoi must read the input string (that may be composed by an initial,
// possibily empty, sequence of white-space characters, a subject sequence of
// decimal digits, optionally preceded by a plus or minus sign, and a final
// string of one or more unrecognized characters, including the terminating null
// character of the input string.
int test_ft_atoi_positive(void)
{
    return (ft_atoi(" \f\f\n\n\r\r\t\t\v\v+123ab45678") == 123);
}

int test_ft_atoi_negative(void)
{
    return (ft_atoi(" \f\f\n\n\r\r\t\t\v\v-42ld09803") == -42);
}

// ft_atoi must return zero if nptr is empty.
int test_ft_atoi_empty_nptr(void)
{
    return (ft_atoi("") == 0);
}

// ft_atoi must return zero if nptr dos not have the expected form.
int test_ft_atoi_invalid_form(void)
{
    return (ft_atoi("abc") == 0);
}

int main(void)
{
	print_test_result("test_ft_atoi_positive", test_ft_atoi_positive());
	print_test_result("test_ft_atoi_negative", test_ft_atoi_negative());
	print_test_result("test_ft_atoi_empty_nptr", test_ft_atoi_empty_nptr());
	print_test_result("test_ft_atoi_invalid_form", test_ft_atoi_invalid_form());
    return (0);
}
