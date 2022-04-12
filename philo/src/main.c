/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:58:35 by alex              #+#    #+#             */
/*   Updated: 2022/04/12 17:26:04 by sslowpok         ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	t_info	info;

	if (!check_args(argc, argv))
		return (1);
	input(argc, argv, &info.input);
	init_philos(&info);
	init_forks(&info);
	create_threads(&info);
	free_philos(&info);
	return (0);
}
