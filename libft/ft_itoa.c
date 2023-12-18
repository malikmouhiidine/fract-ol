/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhiid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:16:07 by mmouhiid          #+#    #+#             */
/*   Updated: 2023/11/05 10:22:02 by mmouhiid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_digits(int n)
{
	int	count;

	count = 1;
	while (n / 10)
	{
		count++;
		n = n / 10;
	}
	return (count);
}

static void	lines_save(int is_negative, char *result, int *i, int *n)
{
	int	coefficient;

	coefficient = 1;
	if (is_negative)
		coefficient = -1;
	result[*i] = (*n % 10) * coefficient + '0';
	*n = *n / 10;
	(*i)--;
}

char	*ft_itoa(int n)
{
	char	*result;
	int		is_negative;
	int		num_digits;
	int		i;

	if (n == 0)
		return (ft_strdup("0"));
	is_negative = 0;
	if (n < 0)
		is_negative = 1;
	num_digits = count_digits(n) + is_negative;
	result = (char *)malloc(num_digits + 1);
	if (!result)
		return (NULL);
	if (is_negative)
		result[0] = '-';
	i = num_digits - 1;
	while (n)
	{
		lines_save(is_negative, result, &i, &n);
	}
	result[num_digits] = '\0';
	return (result);
}
