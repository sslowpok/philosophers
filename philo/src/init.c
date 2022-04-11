/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 15:20:45 by sslowpok          #+#    #+#             */
/*   Updated: 2022/04/11 16:39:45 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_philos(t_info *info)
{
	int	i;

	info->starttime = get_time();
	info->philos = malloc(sizeof(t_philo) * info->input.num);
	if (!info->philos)
		return (0);
	i = -1;
	while (++i < info->input.num)
	{
		info->philos[i].xate = 0;
		info->philos[i].starttime = info->starttime;
		info->philos[i].lasttime = info->starttime;
		info->philos[i].id = i + 1;
		info->philos[i].leftfirst = i % 2;
		pthread_mutex_init(&info->philos[i].mutex, NULL);
		copy_input(info, &info->philos[i]);
		printf("Philo %d created\n", info->philos[i].id);
	}
	return (1);
}

int	init_forks(t_info *info)
{
	int	i;

	i = 0;
	info->forks = malloc(sizeof(t_mutex) * info->input.num);
	if (!info->forks)
		return (0);
	pthread_mutex_init(&info->forks[0], NULL);
	printf("Fork 0 created\n");
	info->philos[0].right_fork = &info->forks[0];
	while (++i < info->input.num)
	{
		pthread_mutex_init(&info->forks[i], NULL);
		info->philos[i].right_fork = &info->forks[i];
		info->philos[i].left_fork = &info->forks[i - 1];
		printf("Fork %d created\n", i);
	}
	info->philos[0].left_fork = &info->forks[i - 1];
	return (1);
}

int	is_dead(t_philo *philo)
{
	unsigned long	now;

	now = get_time();
	pthread_mutex_lock(&philo->mutex);
	if (now - philo->lasttime > philo->input.t2die)
		return (1);
	pthread_mutex_unlock(&philo->mutex);
	return (0);
}

int	detach_threads(t_info *info)
{
	int	i;

	i = 0;
	while (i < info->input.num)
	{
		if (pthread_detach(info->philos[i].thread) != 0)
			return (0);
		i++;
	}
	return (1);
}

void	check_dead(t_info *info)
{
	int	i;

	i = 0;
	while (i <= info->input.num)
	{
		if (i == info->input.num)
			i = 0;
		if (is_dead(&info->philos[i]))
		{
			pthread_mutex_lock(info->philos[i].print);
			detach_threads(info);
			my_sleep(1);
			printf("%lu philo %d died\n", get_time() - info->philos[i].starttime - 1, \
					info->philos[i].id);
			return ;
		}

		
		i++;
	}
}

int	create_threads(t_info *info)
{
	int	i;

	i = 0;
	if (pthread_mutex_init(&info->print, NULL) != 0)
		return (0);
	while (i < info->input.num)
	{
		info->philos[i].print = &info->print;
		if (pthread_create(&info->philos[i].thread, NULL, &routine, \
				(void *)&info->philos[i]))
			return (0);
		i++;
		usleep(1);
	}
	check_dead(info);
	return (1);
}