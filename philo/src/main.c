/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:58:35 by alex              #+#    #+#             */
/*   Updated: 2022/04/09 11:59:32 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	init_philos(t_philo *philos, int num)
{
	int	i;

	i = 0;
	while (i < num)
	{
		philos->id = pthread_create(&philos->thread, NULL, NULL, NULL);
		if (philos->id != 0)
		{
			printf("Thread create error\n");
			return (0);
		}
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