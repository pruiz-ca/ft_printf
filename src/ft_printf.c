/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/09 16:19:08 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/02/20 02:05:30 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			ft_free(char **str)
{
	free(*str);
	*str = NULL;
}

static void		get_conversion(t_flag *flag, va_list args)
{
	if (ft_strchr("%c", flag->conv))
		is_char(flag, args);
	else if (ft_strchr("pxX", flag->conv))
		is_hexa(flag, args);
	else if (flag->conv == 's')
		is_string(flag, args);
	else if (ft_strchr("di", flag->conv))
		is_int(flag, args);
	else if (flag->conv == 'u')
		is_uint(flag, args);
}

int				ft_printf(const char *input, ...)
{
	va_list		args;
	t_flag		flag;

	flag_init(&flag);
	va_start(args, input);
	while (input[flag.pos] != '\0')
	{
		if (input[flag.pos] != '%')
		{
			write(1, &input[flag.pos], 1);
			flag.count++;
		}
		else
		{
			flag_reset(&flag);
			if (!get_flags(&flag, input, args) || !input[flag.pos])
				return (0);
			get_conversion(&flag, args);
		}
		flag.pos++;
	}
	va_end(args);
	return (flag.count);
}
