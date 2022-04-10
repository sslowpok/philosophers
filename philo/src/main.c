/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:58:35 by alex              #+#    #+#             */
/*   Updated: 2022/04/10 16:36:17 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

unsigned long	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	my_sleep(unsigned long ms)
{
	unsigned long	starttime;
	unsigned long	currenttime;

	starttime = get_time();
	currenttime = starttime;
	while (currenttime - starttime < ms)
	{
		currenttime = get_time();
		usleep(ms);
	}
}

void	philo_print(char *s1, char *s2, t_philo *philo)
{
	if (!s2)
		printf("philo %d %s",  philo->id, s1);
	else
		printf("philo %d %s\nphilo %d %s\n",  philo->id, s1, philo->id, s2);
}

int	take_forks(t_philo *philo)
{
	// if (philo->num of meals)

	// if ()

	pthread_mutex_lock(philo->left_fork);
	philo_print("has taken a fork\n", NULL, philo);
	pthread_mutex_lock(philo->right_fork);
	philo_print("has taken a fork", "is eating", philo);
	return (1);
}

void	drop_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);
	pthread_mutex_unlock(philo->right_fork);
}

int	eat(t_philo *philo)
{
	if (!take_forks(philo))
		return (0);
	pthread_mutex_lock(&philo->mutex);

	
	pthread_mutex_unlock(&philo->mutex);
	// mysleep(philo->t2eat)
	drop_forks(philo);
	return (1);
}

// int	sleep_think(t_philo *philo)
// {
	
// }

void	*routine(void *data)
{
	t_philo	*philo;
	
	philo = (t_philo *)data;
	while (1)
	{
		if (!eat(philo))
			break ;
		// if (!sleep_think(philo))
		// 	break ;
	}

	printf("Text from routine\n");
	return (0);
}

void	copy_input(t_info *info, t_philo *philo)
{
	philo->input.num = info->input.num;
	philo->input.num_of_meals = info->input.num_of_meals;
	philo->input.t2die = info->input.t2die;
	philo->input.t2eat = info->input.t2eat;
	philo->input.t2sleep = info->input.t2sleep;
}

int	init_philos(t_info *info, int num)
{
	int	i;

	info->starttime = get_time();
	info->philos = malloc(sizeof(t_philo) * num);
	if (!info->philos)
		return (0);
	i = -1;
	while (++i < num)
	{
		if (pthread_create(&info->philos[i].thread, NULL, routine, info->philos) != 0)
		{
			printf("Thread creation error\n");
			return (0);
		}
		info->philos[i].starttime = info->starttime;
		info->philos[i].lasttime = info->starttime;
		info->philos[i].id = i + 1;
		info->philos[i].leftfirst = i % 2;
		copy_input(info, &info->philos[i]);
		printf("Philo %d created\n", info->philos[i].id);
	}
	return (1);
}

int	init_forks(t_info *info, int num)
{
	int	i;

	i = 0;
	info->forks = malloc(sizeof(t_mutex) * num);
	if (!info->forks)
		return (0);
	pthread_mutex_init(&info->forks[0], NULL);
	info->philos[0].right_fork = &info->forks[0];
	while (++i < num)
	{
		pthread_mutex_init(&info->forks[i], NULL);
		info->philos[i].right_fork = &info->forks[i];
		info->philos[i].left_fork = &info->forks[i - 1];
		printf("Fork %d created\n", i);
	}
	info->philos[0].left_fork = &info->forks[i - 1];
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (!check_args(argc, argv))
		return (1);
	input(argc, argv, &info.input);
	if (!init_philos(&info, info.input.num) || !init_forks(&info, info.input.num))
		return (1);
	// unsigned long	time = get_time();
	// printf("time = %lu\n", time);
	// my_sleep(200);
	// printf("current time = %lu\n", get_time() - time);


	return (0);
}