/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:45:05 by livsauze          #+#    #+#             */
/*   Updated: 2024/06/29 18:25:28 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

void	*ft_death(void	*arg)
{
	t_philo	*ph;
	int i;

	ph = (t_philo *)arg;
	while (1)
	{
		i = 0;
		while (i < ph->p_data->philos_nb && !ph->p_data->stop)
		{
			if (ft_is_dead(&ph[i]))
			{
				ph->p_data->stop++;
				return (NULL);
			}
			i++;
		}
	}
	return (NULL);
}

int	ft_is_dead(t_philo *ph)
{
	pthread_mutex_lock(&ph->p_data->time_m);
	if (ft_get_time() - ph->last_eat >= ph->p_data->time_to_die)
	{
		ft_write("died", ph);
		pthread_mutex_unlock(&ph->p_data->time_m);
		return (1);
	}
	pthread_mutex_unlock(&ph->p_data->time_m);
	return (0);
}
