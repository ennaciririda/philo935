/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rennacir <rennacir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/11 21:47:46 by rennacir          #+#    #+#             */
/*   Updated: 2023/05/31 21:22:08 by rennacir         ###   ########.fr       */
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

typedef struct s_table	t_table;
typedef struct s_philo
{
	int				philo_id;
	int				philo_num;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				num_of_meals;
	int				count_meals;
	pthread_mutex_t	meal_mutex;
	pthread_mutex_t			*lfork;
	pthread_mutex_t			*rfork;
	long long		last_meal;
	pthread_t		thread;
	long long		s_time;
	pthread_mutex_t	print;
}	t_philo;

typedef struct s_table
{
	int				philo_num;
	t_philo			*philos;
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
long long	act_t(void);
void		my_usleep(int time);
void		print_f(char *str, long long value, t_philo *philo);
void		is_died(t_table *table);
void		destroy_func(t_table *table);
int			check_num_of_eat(t_table *table);
void		init_each_philo(t_philo *philo, pthread_mutex_t	*forks, char **spl, int i);
#endif