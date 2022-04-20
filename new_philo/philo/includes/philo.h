/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 13:48:43 by sslowpok          #+#    #+#             */
/*   Updated: 2022/04/20 14:50:54 by sslowpok         ###   ########.fr       */
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
	int				left;
	int				right;
	unsigned long	lasttime;
	unsigned long	starttime;
	t_mutex			*left_fork;
	t_mutex			*right_fork;
	t_mutex			print;
	// t_mutex			mutex;
	t_input			input;
	pthread_t		thread;
	int				is_dead;
}			t_philo;

typedef struct s_table
{
	t_input			input;
	t_mutex			*forks;
	t_philo			*philos;
	unsigned long	starttime;
	t_mutex			print;

	
}		t_table;

int	check_args(int argc, char **argv);

int				ft_strlen(char *s);
int				ft_isdigit(int c);
int				ft_strncmp(const char *s1, const char *s2, int n);
int				ft_atoi(const char *str);
void			input(int argc, char **argv, t_input *input);
int				str_error(char *s);
void			init_philos(t_table *table);
void			init_forks(t_table *table);
unsigned long	get_time(void);
void			my_sleep(unsigned long ms);
void			*life_cycle(void *data);



#endif
