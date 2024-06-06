/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/06 08:32:09 by livsauze          #+#    #+#             */
/*   Updated: 2023/10/06 08:38:25 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned const char		*tab1;
	unsigned const char		*tab2;
	unsigned int			i;

	tab1 = s1;
	tab2 = s2;
	i = 0;
	while (i < (unsigned int)n)
	{
		if (tab1[i] != tab2[i])
			return (tab1[i] - tab2[i]);
		i++;
	}
	return (0);
}
/*
int	main()
{
	printf("%d", ft_memcmp("holla", "hollo", 25));
	return (0);
}*/
