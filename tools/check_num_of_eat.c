/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_num_of_eat.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 16:54:06 by rennacir          #+#    #+#             */
/*   Updated: 2023/05/30 15:05:29 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

int	check_num_of_eat(t_table *table)
{
	int	count;

	count = -1;
	while (++count < table->philo_num)
	{
		pthread_mutex_lock(&table->philos[count].meal_mutex);
		if (table->philos[count].num_of_meals == -1 || table->philos[count].count_meals < table->philos[count].num_of_meals)
		{
			pthread_mutex_unlock(&table->philos[count].meal_mutex);
			return 0;
		}
		pthread_mutex_unlock(&table->philos[count].meal_mutex);
	}
	return 1;
}