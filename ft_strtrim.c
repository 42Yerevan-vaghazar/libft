/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vaghazar <vaghazar@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 19:27:44 by vaghazar          #+#    #+#             */
/*   Updated: 2022/04/17 15:35:09 by vaghazar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	find_first(char const *s1, char const *set)
{
	int	i;
	int	j;

	i = 0;
	j = -1;
	while (set[++j] && s1[i])
	{
		if (s1[i] == set[j] && set[j] != '\0')
		{
			j = -1;
			i++;
		}
	}
	return (i);
}

int	find_last(char const *s1, char const *set)
{
	int	lens1;
	int	j;

	lens1 = ft_strlen(s1) - 1;
	j = -1;
	while (set[++j] && lens1)
	{
		if (s1[lens1] == set[j])
		{
			j = -1;
			lens1--;
		}
	}
	return (lens1);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*ptr;
	int		var[4];

	var[2] = find_first(s1, set);
	var[3] = find_last(s1, set);
	var[1] = 0;
	var[0] = -1;
	if (!ft_strlen(s1) || (var[2] == 0
			&& var[3] == (int)(ft_strlen(s1) - 1)))
		ptr = (char *) malloc(ft_strlen(s1) + 1);
	else if (var[2] < var[3])
		ptr = (char *) malloc(ft_strlen(s1)
				- (var[2] + (ft_strlen(s1) - var[3])));
	else
		ptr = malloc(sizeof(char));
	if (ptr == 0)
		return (0);
	while (s1[++var[0]])
	{
		if (var[0] >= var[2] && var[0] <= var[3])
			ptr[var[1]++] = s1[var[0]];
	}
	ptr[var[1]] = '\0';
	return (ptr);
}
