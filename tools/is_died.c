/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_died.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:40:30 by rennacir          #+#    #+#             */
/*   Updated: 2023/05/31 21:30:22 by rennacir         ###   ########.fr       */
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
		while (++i < table->philo_num)
		{
			pthread_mutex_lock(&table->philos[i].meal_mutex);
			if (act_t() - table->philos[i].last_meal
				>= (long long) table->philos[i].time_to_die)
			{
				print_f("died\n", act_t()
					- table->philos[i].s_time, &table->philos[i]);
				pthread_mutex_lock(&table->philos[i].print);
				return ;
			}
			pthread_mutex_unlock(&table->philos[i].meal_mutex);
		}
		if (check_num_of_eat(table))
			return ;
	}
}
