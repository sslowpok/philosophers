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
	int	num;
	unsigned long	t2die;
	unsigned long	t2eat;
	unsigned long	t2sleep;
	int				num_of_meals;
}			t_input;

typedef struct s_philo
{
	
	int				id;
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
	unsigned long	starttime;
}			t_info;

int		ft_atoi(const char *str);
int		ft_strlen(char *s);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		check_args(int argc, char **argv);
int		str_error(char *s);
void	input(int argc, char **argv, t_input *info);

#endif