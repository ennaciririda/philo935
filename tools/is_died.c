/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_died.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:40:30 by rennacir          #+#    #+#             */
/*   Updated: 2023/05/30 20:59:24 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	is_died(t_table *table)
{
	int	i;

	i = -1;
	while (1)
	{
		i = -1;
		while(++i < table->philo_num)
		{
			pthread_mutex_lock(&table->philos[i].meal_mutex);
			if (actual_time() - table->philos[i].last_meal >= table->philos[i].time_to_die)
			{
				print_func("died\n",actual_time() - table->philos[i].start_time, &table->philos[i]);
				pthread_mutex_lock(&table->print);
				// pthread_mutex_unlock(&table->philos[i].meal_mutex);
				return;
			}
			pthread_mutex_unlock(&table->philos[i].meal_mutex);
			my_usleep(100);
		}
		if (check_num_of_eat(table))
			return;
	}
}
