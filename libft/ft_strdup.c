/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmouhiid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/05 09:18:20 by mmouhiid          #+#    #+#             */
/*   Updated: 2023/11/05 11:22:29 by mmouhiid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	char	*duplicate;
	size_t	len;

	len = ft_strlen(s1);
	duplicate = (char *)malloc(len + 1);
	if (!duplicate)
		return (NULL);
	ft_memcpy(duplicate, s1, len);
	duplicate[len] = '\0';
	return (duplicate);
}
