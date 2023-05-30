/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_each_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:09:21 by rennacir          #+#    #+#             */
/*   Updated: 2023/05/30 20:59:31 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_each_philo(t_philo *philo,t_table *table, char **split, int i)
{
	philo->philo_id = i + 1;
	philo->time_to_die = ft_atoi(split[1]);
	philo->time_to_eat = ft_atoi(split[2]);
	philo->time_to_sleep = ft_atoi(split[3]);
	philo->num_of_meals = -1;
	philo->lfork = i;
	philo->rfork = (i + 1) % table->philo_num;
	if (split[4])
		philo->num_of_meals = ft_atoi(split[4]);
	philo->count_meals = 0;
	philo->table = table;
	philo->last_meal = actual_time();
	if (pthread_mutex_init(&philo->meal_mutex, NULL))
	{
		printf("Error: pthread_mutex_init\n");
		return;
	}
}
