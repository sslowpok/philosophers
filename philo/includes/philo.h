#ifndef PHILO_H
# define PHILO_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <stdbool.h>

typedef pthread_mutex_t	t_mutex;

typedef struct s_philo
{
	pthread_t	thread;
	int			id;
	unsigned long	lasttime;
	unsigned long	starttime;
	t_mutex		*left_fork;
	t_mutex		*right_fork;
	t_mutex		*print;
	t_mutex		mutex;
}			t_philo;

typedef struct s_info
{
	int				num;
	unsigned long	t2die;
	unsigned long	t2eat;
	unsigned long	t2sleep;
	int				num_of_meals;
	t_philo			*philos;
}			t_info;

int		ft_atoi(const char *str);
int		ft_strlen(char *s);
int		ft_isdigit(int c);
int		ft_strncmp(const char *s1, const char *s2, int n);
int		check_args(int argc, char **argv);
int		str_error(char *s);
void	input(int argc, char **argv, t_info *info);

#endif