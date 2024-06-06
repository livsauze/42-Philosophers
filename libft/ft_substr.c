/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/08 13:20:57 by livsauze          #+#    #+#             */
/*   Updated: 2024/03/23 16:26:29 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*str;
	size_t	i;
	size_t	j;
	size_t	lens;

	lens = ft_strlen(s);
	if (start >= lens)
		return ((char *)ft_strdup(""));
	if (len + start >= lens)
		str = (char *)malloc(sizeof(char) * (lens - start + 1));
	if (len + start < lens)
		str = (char *)malloc((len + 1) * sizeof(char));
	if (str == NULL)
		return (NULL);
	i = start;
	j = 0;
	while (i < lens && j < len)
	{
		str[j] = s[i];
		i++;
		j++;
	}
	str[j] = '\0';
	return (str);
}
/*
int	main(void)
{
	char src[]= "01234";
	printf("%s", ft_substr(src, 10, 10));
	return (0);
}*/
