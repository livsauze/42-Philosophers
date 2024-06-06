/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 10:42:55 by livsauze          #+#    #+#             */
/*   Updated: 2023/10/06 08:09:53 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const char	*str;
	size_t		i;

	str = s;
	i = 0;
	while (i < n)
	{
		if (str[i] == (char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
/*
int	main(void)
{
	//int	tab[7] = {-49, 49, 1, -1, 0, -2, 2};
	char 	tab[] = "coucou";
	printf("%s", (char *)ft_memchr(tab, 'o' , 7));
	return (0);
}*/
