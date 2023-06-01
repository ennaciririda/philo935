/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_died.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/25 18:40:30 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/01 16:50:40 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	is_died(t_table *table)
{
	int			i;
	long long	now;

	i = -1;
	while (1)
	{
		i = -1;
		my_usleep(10);
		while (++i < table->philo_num)
		{
			now = act_t();
			pthread_mutex_lock(&table->philos[i].meal_mutex);
			if (now - table->philos[i].last_meal
				>= (long long) table->philos[i].time_to_die)
			{
				pthread_mutex_lock(&table->print);
				printf("%llu %d died\n", now - table->philos[i].s_time,
					table->philos[i].philo_id);
				return ;
			}
			pthread_mutex_unlock(&table->philos[i].meal_mutex);
		}
		if (check_num_of_eat(table))
			return ;
	}
}
