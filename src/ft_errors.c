/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_errors.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:21:11 by livsauze          #+#    #+#             */
/*   Updated: 2024/07/05 12:43:48 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_check_content(char **av)
{
	int	i;
	int	j;

	i = 1;
	while (av[i])
	{
		j = 0;
		while (av[i][j])
		{
			if (av[i][j] == '-')
				j++;
			if (!ft_isdigit(av[i][j]))
			{
				printf("Invalid input : please use only digits.\n");
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

int	ft_errors(int ac, char **av)
{
	(void)av;
	if (!(ac == 5 || ac == 6))
	{
		printf("Invalid input : there must be 4 or 5 arguments.\n");
		return (1);
	}
	if (ft_check_content(av))
		return (1);
	if (ft_atol(av[1]) < 0 || ft_atol(av[1]) > 200)
	{
		printf("Invalid input : use a nb of philos between 0 and 200.\n");
		return (1);
	}
	if (ft_atol(av[2]) < 0 || ft_atol(av[3]) < 0 || ft_atol(av[4]) < 0)
	{
		printf("Invalid input : use an unsiged int between 0 and INT_MAX.\n");
		return (1);
	}
	if (ft_atol(av[2]) > INT_MAX || ft_atol(av[3]) > INT_MAX
		|| ft_atol(av[4]) > INT_MAX)
	{
		printf("Invalid input : use an unsigned int between 0 and INT_MAX.\n");
		return (1);
	}
	return (0);
}
