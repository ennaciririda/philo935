/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_func.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/27 18:24:32 by rennacir          #+#    #+#             */
/*   Updated: 2023/06/01 15:32:52 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	destroy_func(t_table *table)
{
	int	i;

	i = -1;
	pthread_mutex_destroy(&table->print);
	while (++i < table->philo_num)
	{
		pthread_mutex_destroy(&table->philos[i].meal_mutex);
	}
}
