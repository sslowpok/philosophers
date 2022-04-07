/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sslowpok <sslowpok@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 14:05:13 by sslowpok          #+#    #+#             */
/*   Updated: 2022/04/07 15:48:54 by sslowpok         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philo.h"

int	str_error(char *s)
{
	write(2, s, ft_strlen(s));
	return (0);
}

static int	check_digits(int argc, char **argv)
{
	int	i;
	int	j;
	
	i = 1;
	while (i < argc)
	{
		j = 0;
		while (j < ft_strlen(argv[i]))
		{
			if (!ft_isdigit(argv[i][j]))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

static int	check_int(int argc, char **argv)
{
	int	i;

	i = 1;
	while (i < argc)
	{
		if (ft_atoi(argv[i]) == 2147483647 && \
			ft_strncmp(argv[i], "2147483647", 10))
			return (0);
		if (ft_atoi(argv[i]) < 0)
			return (0);
		i++;
	}	
	return (1);
}

int	check_args(int argc, char **argv)
{
	if (argc != 5 && argc != 6)
		return (str_error("Error: wrong number of args\n"));
	if (!check_digits(argc, argv))
		return (str_error("Error: invalid argument\n"));
	if (!check_int(argc, argv))
		return (str_error("Error: invalid argument\n"));
	return (1);
}