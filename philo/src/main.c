/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:58:35 by alex              #+#    #+#             */
/*   Updated: 2022/04/09 12:38:02 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	*routine(void *data)
{
	(void)	data;
	printf("Philo created!\n");
	return ((void *)0);
}

int	init_philos(t_philo *philos, int num)
{
	int	i;

	philos = malloc(sizeof(t_philo) * num);
	if (!philos)
		return (0);
	i = -1;
	while (++i < num)
	{
		philos[i].id = pthread_create(&philos[i].thread, NULL, routine, philos + i);
		if (philos[i].id != 0)
		{
			printf("Thread create error\n");
			return (0);
		}
		// pthread_join(philos[i].thread, 0);
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_info	info;

	if (!check_args(argc, argv))
		return (1);
	input(argc, argv, &info);
	if (!init_philos(info.philos, info.num))
		return (1);
	



	return (0);
}