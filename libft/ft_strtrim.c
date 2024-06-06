/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: livsauze <livsauze@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/15 10:09:46 by livsauze          #+#    #+#             */
/*   Updated: 2023/11/04 15:18:12 by livsauze         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*newstr;
	int		start;
	int		end;

	if (!s1 && !set)
		return (NULL);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = ft_strlen(s1);
	while (end > 0 && ft_strrchr(set, s1[end - 1]))
		end--;
	newstr = ft_substr(s1, start, end - start);
	return (newstr);
}
/*
int	main(void)
{
	char	*newstr;

	newstr = ft_strtrim("12Hello12", "12");
	printf("%s", newstr);
	free(newstr);
	return (0);
}*/
