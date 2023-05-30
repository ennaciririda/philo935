/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:47:46 by rennacir          #+#    #+#             */
/*   Updated: 2023/05/30 20:59:50 by rennacir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_table t_table;
typedef struct	s_philo
{
	int	philo_id;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_meals;
	int	count_meals;
	pthread_mutex_t meal_mutex;
	int lfork;
	int rfork;
	long long last_meal;
	long long start_time;
	t_table *table;
	pthread_t	thread;
}	t_philo;

typedef struct s_table
{
	int philo_num;
	pthread_mutex_t	*forks;
	pthread_mutex_t print;
	t_philo	*philos;
}	t_table;

long		ft_atoi(const char *str);
char		*ft_strjoin(int size, char **strs, char *sep);
char		**ft_split(char const *s, char c);
int			ft_strcmp(const char *first, const char *second);
void		error(char *str);
void		args_num(int argc);
void		check_arg(char *str);
void		check_max_min(char **split);
int			ft_isdigit(int a);
int			check_is_digit(char **str);
long long	actual_time();
void		my_usleep(long time);
void		print_func(char *str, long long value, t_philo *philo);
void		is_died(t_table *table);
void		destroy_func(t_table *table);
int			check_num_of_eat(t_table *table);
void	init_each_philo(t_philo *philo,t_table *table, char **split, int i);

#endif