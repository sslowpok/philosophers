/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 15:22:54 by sslowpok          #+#    #+#             */
/*   Updated: 2022/04/09 17:31:02 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

void	input(int argc, char **argv, t_input *info)
{
	// philo->args.count = ft_atoi(argv[1]);
	// philo->args.time_to_die = ft_atoi(argv[2]);
	// philo->args.time_to_eat = ft_atoi(argv[3]);
	// philo->args.time_to_sleep = ft_atoi(argv[4]);
	// if (argc == 6)
	// 	philo->args.num_of_eat = ft_atoi(argv[5]);
	// else if (argc == 5)
	// 	philo->args.num_of_eat= -1;


	info->num = ft_atoi(argv[1]);
	info->t2die = ft_atoi(argv[2]);
	info->t2eat = ft_atoi(argv[3]);
	info->t2sleep = ft_atoi(argv[4]);
	if (argc == 6)
		info->num_of_meals = ft_atoi(argv[5]);
	else
		info->num_of_meals = -1;
}