/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/19 18:04:01 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/01 13:49:24 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*routine(void* arg)
{
	t_philo *philo = (t_philo *)arg;

	if (philo->philo_id % 2 == 0)
		my_usleep(5);
	while (1)
	{
		pthread_mutex_lock(philo->lfork);
		print_f("has taken a fork\n",act_t() - philo->s_time, philo);
		pthread_mutex_lock(philo->rfork);
		print_f("has taken a fork\n",act_t() - philo->s_time, philo);
		print_f("is eating\n", act_t() - philo->s_time, philo);
		pthread_mutex_lock(&philo->meal_mutex);
		philo->last_meal = act_t();
		philo->count_meals++;
		pthread_mutex_unlock(&philo->meal_mutex);
		my_usleep(philo->time_to_eat);
		pthread_mutex_unlock(philo->lfork);
		pthread_mutex_unlock(philo->rfork);
		print_f("is sleeping\n",act_t() - philo->s_time, philo);
		my_usleep(philo->time_to_sleep);
		print_f("is thinking\n",act_t() - philo->s_time, philo);
	}
	return (0);
}
t_table *init_table(char **split)
{
	t_table *table;
	pthread_mutex_t	*forks;
	int i = -1;

	table = malloc(sizeof(t_table));
	if (!table)
		return (0);
	table->philo_num = ft_atoi(split[0]);
	table->philos = malloc (sizeof(t_philo) * table->philo_num);
	if (!table->philos)
		return (NULL);
	forks = malloc (sizeof(pthread_mutex_t) * table->philo_num);
	if (!forks)
		return (NULL);
	if (pthread_mutex_init(&table->print, NULL) != 0)
		return(printf("Error: pthread_mutex_init\n"), NULL);
	while(++i < table->philo_num)
		if (pthread_mutex_init(&forks[i], NULL) != 0)
			return(printf("Error: pthread_mutex_init\n"), NULL);
	i = -1;
	while(++i < table->philo_num)
		init_each_philo(table->philos + i, forks, table, split, i);
	return (table);
}

int	create_threads(t_table *table)
{
	int i = -1;
	i = -1;
	while(++i < table->philo_num)
	{
		if (pthread_create(&table->philos[i].thread, NULL, &routine, table->philos + i) != 0)
			return(printf("Error: pthread_create\n"), -1);
		if (pthread_detach(table->philos[i].thread) != 0)
			return(printf("Error: pthread_detach\n"), -1); }

	return (0);
}

int main(int argc, char **argv)
{
	char *str;
	char **split;
	t_table *table;
	int num = 0;
	str = ft_strjoin(argc - 1, argv + 1, " ");
	split = ft_split(str,' ');
	while(split[num])
		num++;
	args_num(num);
	check_is_digit(split);
	check_max_min(split);
	table = init_table(split);
	create_threads(table);
	is_died(table);
	destroy_func(table);
	return (0);
}
