/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 01:14:48 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/02/18 21:34:31 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		char_in_set(char c, char const *set)
{
	while (*set)
	{
		if (*set == c)
			return (1);
		set++;
	}
	return (0);
}

char			*ft_strtrim(char const *s1, char const *set)
{
	int		i;
	int		start;
	int		end;
	char	*str;

	if (!s1 || !set)
		return (NULL);
	i = 0;
	start = 0;
	end = ft_strlen((char *)s1);
	while (char_in_set(s1[start], set) && s1[start])
		start++;
	while (char_in_set(s1[end - 1], set) && end > start)
		end--;
	if (!(str = malloc(sizeof(*s1) * (end - start) + 1)))
		return (NULL);
	while (start < end)
		str[i++] = s1[start++];
	str[i] = '\0';
	return (str);
}
