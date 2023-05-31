/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_func.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/24 16:40:53 by rennacir          #+#    #+#             */
/*   Updated: 2023/05/31 21:22:14 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	print_f(char *str, long long value, t_philo *philo)
{
	pthread_mutex_lock(&philo->print);
	printf("%llu %d %s", value, philo->philo_id, str);
	pthread_mutex_unlock(&philo->print);
}
