/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:59:32 by rennacir          #+#    #+#             */
/*   Updated: 2023/05/30 15:04:48 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	args_num(int argc)
{
	if (argc != 4 && argc != 5)
		error("Error: number of args\n");
}

void	check_arg(char *str)
{
	if (ft_atoi(str) > 2147483647 || ft_atoi(str) < -2147483648)
		error("check the max and the min of int");
}

void	check_max_min(char **split)
{
	int	i;

	i = -1;
	while (split[++i])
		check_arg(split[i]);
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
				return (error("Error : args must be positif numbers\n"), -1);
			j++;
		}
	}
	return 0;
}
