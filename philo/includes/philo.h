#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>

typedef pthread_mutex_t	t_mutex;

typedef struct	s_args
{
	int	count;
	int	time_to_die;
	int	time_to_eat;
	int	time_to_sleep;
	int	num_of_eat;	//	optional
}			t_args;

typedef struct s_philo
{
	t_mutex	forks[200];
	t_args	args;
	bool	is_dead;
}		t_philo;

int		ft_atoi(const char *str);
int		ft_strlen(char *s);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		check_args(int argc, char **argv);
int		str_error(char *s);
void	input(int argc, char **argv, t_philo *philo);

#endif