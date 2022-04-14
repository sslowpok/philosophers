/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/14 16:02:34 by sslowpok          #+#    #+#             */
/*   Updated: 2022/04/14 16:03:06 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>
# include <sys/time.h>

typedef pthread_mutex_t	t_mutex;

typedef struct s_input
{
	int				num;
	unsigned long	t2die;
	unsigned long	t2eat;
	unsigned long	t2sleep;
	int				num_of_meals;
}			t_input;

typedef struct s_philo
{
	int				id;
	int				xate;
	int				leftfirst;
	unsigned long	lasttime;
	unsigned long	starttime;
	t_mutex			*left_fork;
	t_mutex			*right_fork;
	t_mutex			*print;
	t_mutex			mutex;
	t_input			input;
	pthread_t		thread;
}			t_philo;

typedef struct s_info
{
	t_input			input;
	t_philo			*philos;
	t_mutex			*forks;
	t_mutex			print;
	unsigned long	starttime;
}			t_info;

int				ft_atoi(const char *str);
int				ft_strlen(char *s);
int				ft_isdigit(int c);
int				ft_strncmp(const char *s1, const char *s2, int n);
int				check_args(int argc, char **argv);
int				str_error(char *s);
void			input(int argc, char **argv, t_input *info);
int				init_philos(t_info *info);
int				init_forks(t_info *info);
int				create_threads(t_info *info);
void			*routine(void *data);
void			copy_input(t_info *info, t_philo *philo);
unsigned long	get_time(void);
void			my_sleep(unsigned long ms);
void			philo_print(char *s1, char *s2, t_philo *philo);
int				count_meals(t_philo *philo);
int				take_forks(t_philo *philo);
void			drop_forks(t_philo *philo);
int				join_all_threads(t_info *info);
int				detach_threads(t_info *info);
int				is_dead(t_philo *philo);

#endif