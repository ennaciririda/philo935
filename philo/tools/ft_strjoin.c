/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/13 13:29:38 by rennacir          #+#    #+#             */
/*   Updated: 2023/05/31 14:49:04 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	str_len(char *str)
{
	int	i;

	i = 0;
	while (*str)
	{
		str++;
		i++;
	}
	return (i);
}

char	*for_line(int size, char **strs, char *sep, char *join)
{
	int	i;
	int	j;
	int	k;

	i = -1;
	k = 0;
	while (++i < size)
	{
		j = 0;
		while (strs[i][j])
			join[k++] = strs[i][j++];
		j = 0;
		while (sep[j] && i < size - 1)
			join[k++] = sep[j++];
	}
	join[k] = '\0';
	return (join);
}

char	*ft_strjoin(int size, char **strs, char *sep)
{
	int		i;
	int		k;
	char	*join;

	k = 0;
	i = 0;
	if (size <= 0)
	{
		join = malloc(sizeof(char));
		if (!join)
			return (NULL);
		join[0] = '\0';
		return (join);
	}
	while (i < size)
		k += str_len(strs[i++]);
	k += (str_len(sep) * (size - 1)) + 1;
	join = malloc(sizeof(char) * k);
	if (!join)
		return (NULL);
	join = for_line (size, strs, sep, join);
	return (join);
}
