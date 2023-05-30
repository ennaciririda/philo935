/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_usleep.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 16:10:31 by rennacir          #+#    #+#             */
/*   Updated: 2023/05/30 23:54:20 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../philo.h"

void	my_usleep(int duration)
{
	long	time;

	time = actual_time();
	while (actual_time() < (long long) (time + duration))
		usleep(duration);
}