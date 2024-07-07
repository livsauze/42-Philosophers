/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_dead.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/25 18:45:05 by livsauze          #+#    #+#             */
/*   Updated: 2024/07/07 17:09:55 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/philo.h"

int	ft_is_full(t_philo *ph)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (i < ph->p_data->philos_nb)
	{
		pthread_mutex_lock(&ph[i].p_data->meal_m);
		if (ph[i].meal_count == ph->p_data->max_meal)
			count++;
		pthread_mutex_unlock(&ph[i].p_data->meal_m);
		i++;
	}
	if (count == ph->p_data->philos_nb)
		return (1);
	else
		return (0);
}

void	*ft_death(void	*arg)
{
	t_philo	*ph;
	int		i;
	int		eat;

	ph = (t_philo *)arg;
	while (1)
	{
		i = 0;
		while (i < ph->p_data->philos_nb && !ph->p_data->stop)
		{
			eat = ft_is_full(ph);
			pthread_mutex_lock(&ph->p_data->meal_m);
			if (eat)
				ph->p_data->full++;
			if (ft_is_dead(&ph[i]) || eat)
			{
				ph->p_data->stop++;
				pthread_mutex_unlock(&ph->p_data->meal_m);
				return (NULL);
			}
			pthread_mutex_unlock(&ph->p_data->meal_m);
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
