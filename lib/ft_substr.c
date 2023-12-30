/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/01/28 00:27:29 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/02/18 21:34:31 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	unsigned int	i;
	char			*str;
	unsigned int	s_size;

	if (!s)
		return (0);
	i = -1;
	s_size = ft_strlen((char *)s);
	if (!(str = (char *)malloc(sizeof(*s) * len + 1)))
		return (NULL);
	while (++i < len && start < s_size)
		str[i] = s[start + i];
	str[i] = '\0';
	return (str);
}
