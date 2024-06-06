/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 12:33:03 by livsauze          #+#    #+#             */
/*   Updated: 2024/02/23 22:32:03 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*s;
	size_t	len;

	len = nmemb * size;
	s = (void *)malloc(len);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, len);
	return ((void *)s);
}
/*
int	main(void)
{
	int i = 0;
	char *tab = (char *)ft_calloc(6, sizeof(char));
	while (i < 6)
		printf("%d", (int)tab[i++]);
	free(tab);
	return (0);
}*/
