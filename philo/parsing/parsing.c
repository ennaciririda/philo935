/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:59:32 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/01 14:42:03 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	args_num(int argc)
{
	if (argc != 4 && argc != 5)
	{
		error("Error: number of args\n");
		return (0);
	}
	return (1);
}

int	check_arg(char *str)
{
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
	{
		error("check the max and the min of int");
		return (0);
	}
	return (1);
}

int	check_max_min(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		if (!check_arg(split[i]))
			return (0);
	return (1);
}

int	check_is_digit(char **str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = 0;
		if (str[i][j] == '+' && str[i][j + 1])
			j++;
		while (str[i][j])
		{
			if (ft_isdigit(str[i][j]) == 0)
				return (error("Error : args must be positif numbers\n"), 0);
			j++;
		}
	}
	return (1);
}
