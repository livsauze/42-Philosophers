/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/07 15:41:53 by livsauze          #+#    #+#             */
/*   Updated: 2023/10/07 15:46:53 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	lend;
	size_t	lens;

	lend = ft_strlen(dest);
	lens = ft_strlen(src);
	if (size == 0)
		return (lens);
	if (size < lend)
		return (lens + size);
	i = 0;
	while (dest[i])
		i++;
	j = 0;
	while (src[j] && i < size - 1)
	{
		dest[i] = src[j];
		i++;
		j++;
	}
	dest[i] = '\0';
	return (lens + lend);
}
/*
int	main(void)
{
	const char	src[] = "Hello ";
	char	dest[] = "World";
	printf("%zu", ft_strlcat(dest, src, 8));
	printf("\n%s", dest);
	return (0);
}*/
