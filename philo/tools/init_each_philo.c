/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_each_philo.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/28 19:09:21 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/01 14:55:14 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	init_each_philo(t_philo *philo, pthread_mutex_t	*forks,
		t_table *table, int i)
{
	philo->philo_id = i + 1;
	philo->s_time = act_t();
	philo->philo_num = ft_atoi(table->split[0]);
	philo->time_to_die = ft_atoi(table->split[1]);
	philo->time_to_eat = ft_atoi(table->split[2]);
	philo->time_to_sleep = ft_atoi(table->split[3]);
	philo->num_of_meals = -1;
	philo->lfork = &forks[i];
	philo->table = table;
	philo->rfork = &forks[(i + 1) % ft_atoi(table->split[0])];
	if (table->split[4])
		philo->num_of_meals = ft_atoi(table->split[4]);
	philo->count_meals = 0;
	philo->last_meal = act_t();
	if (pthread_mutex_init(&philo->meal_mutex, NULL))
	{
		printf("Error: pthread_mutex_init\n");
		return ;
	}
	if (pthread_mutex_init(&table->print, NULL) != 0)
	{
		printf("Error: pthread_mutex_init\n");
		return ;
	}
}
