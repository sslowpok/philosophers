/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 09:58:35 by alex              #+#    #+#             */
/*   Updated: 2022/04/07 15:22:23 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	main(int argc, char **argv)
{
	t_philo	philo;

	if (!check_args(argc, argv))
		return (1);
	input(argc, argv, &philo);
	
	
	return (0);
}