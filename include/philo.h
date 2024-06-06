/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/02 14:00:11 by livsauze          #+#    #+#             */
/*   Updated: 2024/06/06 20:43:54 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <libft.h>
# include <stdio.h>
# include <stdlib.h>
# include <pthread.h>

typedef struct s_args t_args;

typedef struct s_philo
{
	pthread_t		thread;
	unsigned int	philo_id;
	int				nb_meals_eaten;
	t_args			*table;
}		t_philo;

typedef struct s_args
{
	int		philo_nb;
	int		start_time;
	int		time_to_die;
	int		time_to_sleep;
	int		time_to_eat;
	t_philo	*philos;
}		t_args;


int	ft_errors(int ac, char **av);

#endif