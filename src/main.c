/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/06 20:22:21 by livsauze          #+#    #+#             */
/*   Updated: 2024/07/05 12:56:56 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	main(int ac, char **av)
{
	t_p	p;

	if (ft_errors(ac, av) == 1)
		exit(EXIT_FAILURE);
	ft_init_data(av, ac, &p);
	ft_start_routine(&p);
	free(p.ph);
	return (0);
}
