/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/17 21:24:31 by vaghazar          #+#    #+#             */
/*   Updated: 2022/03/20 12:35:44 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	char	*ptr;
	int		i;

	ptr = (char *)s;
	i = 0;
	if (c == 0 && n == 0)
		return (0);
	if (c == 0)
		return (ptr);
	while (n--)
	{
		if (ptr[i] == (char)c)
			return (&ptr[i]);
		i++;
	}
	return (0);
}
