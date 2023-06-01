/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num_of_eat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:54:06 by rennacir          #+#    #+#             */
/*   Updated: 2023/05/31 14:48:19 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_num_of_eat(t_table *table)
{
	int	i;

	i = -1;
	while (++i < table->philo_num)
	{
		pthread_mutex_lock(&table->philos[i].meal_mutex);
		if (table->philos[i].num_of_meals == -1
			|| table->philos[i].count_meals < table->philos[i].num_of_meals)
		{
			pthread_mutex_unlock(&table->philos[i].meal_mutex);
			return (0);
		}
		pthread_mutex_unlock(&table->philos[i].meal_mutex);
	}
	return (1);
}
