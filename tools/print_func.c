/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:40:53 by rennacir          #+#    #+#             */
/*   Updated: 2023/05/30 20:59:45 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_func(char *str, long long value, t_philo *philo)
{
	pthread_mutex_lock(&philo->table->print);
	printf("%llu %d %s", value, philo->philo_id, str);
	pthread_mutex_unlock(&philo->table->print);
}
