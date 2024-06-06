/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/04 12:06:42 by livsauze          #+#    #+#             */
/*   Updated: 2023/10/04 12:55:19 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	const char	*s;
	char		*d;
	size_t		i;

	if (dest == NULL && src == NULL)
		return (NULL);
	s = src;
	d = dest;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return ((char *)dest);
}
/*
int	main(void)
{
	char	src[] = "coucou";
	char	dest[50];
	
	printf("%s", ft_memcpy(dest, src, 6);
	return (0);
}*/
