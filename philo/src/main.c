/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:58:35 by alex              #+#    #+#             */
/*   Updated: 2022/04/22 16:34:40 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	free_philos(t_info *info)
{
	if (info->philos)
		free(info->philos);
	if (info->forks)
		free(info->forks);
}

int	one_philo(t_info *info)
{
	unsigned long	time;
	
	if (pthread_mutex_init(&info->print, NULL) != 0)
		return (0);
	time = get_time();
	printf("%lu philo %d has taken a fork\n", time - info->starttime,\
			info->philos->id);
	my_sleep(info->philos[0].input.t2die);
	printf("%lu philo %d died\n", get_time() - info->starttime, \
			info->philos[0].id);
	free_philos(info);
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (!check_args(argc, argv))
		return (1);
	input(argc, argv, &info.input);
	if (!init_philos(&info) || !init_forks(&info))
	{
		free_philos(&info);
		return (0);
	}
	if (info.input.num == 1)
	{
		if (!one_philo(&info))
		{
			free_philos(&info);
			return (0);
		}
	}
	else
	{
		create_threads(&info);
		free_philos(&info);
	}
	return (0);
}
