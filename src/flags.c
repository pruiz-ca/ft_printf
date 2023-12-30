/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 00:34:16 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/02/20 00:50:39 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		flag_init(t_flag *flag)
{
	flag->pos = 0;
	flag->count = 0;
	flag->minus = -1;
	flag->zero = -1;
	flag->width = -1;
	flag->width_exists = 0;
	flag->dot = -1;
	flag->dot_exists = 0;
	flag->conv = '0';
	flag->len = 0;
	flag->num_sp = 0;
	flag->num_0s = 0;
	flag->neg = 0;
}

void		flag_reset(t_flag *flag)
{
	flag->minus = -1;
	flag->zero = -1;
	flag->width_exists = 0;
	flag->width = -1;
	flag->dot = -1;
	flag->dot_exists = 0;
	flag->conv = '0';
	flag->len = 0;
	flag->num_sp = 0;
	flag->num_0s = 0;
	flag->neg = 0;
}

static void	get_flags_wp(t_flag *flag, const char *input, va_list args, int i)
{
	if (i == 1)
	{
		flag->width_exists = 1;
		flag->width = ft_atoi(input + flag->pos);
	}
	else if (i == 2)
	{
		flag->pos++;
		flag->dot_exists = 1;
		if (ft_strchr(VALID_NUMS, input[flag->pos]))
			flag->dot = ft_atoi(input + flag->pos);
		else if (input[flag->pos] == '*')
			flag->dot = va_arg(args, int);
		else
			flag->dot = 0;
	}
	while (input[flag->pos] >= '0' && input[flag->pos] <= '9')
		flag->pos++;
	flag->pos--;
}

static void	get_flags_wp2(t_flag *flag, const char *input, va_list args, int i)
{
	if (i == 3)
	{
		flag->width_exists = 1;
		flag->width = va_arg(args, int);
		if (flag->width < 0)
		{
			flag->width *= -1;
			flag->minus = 1;
		}
		flag->pos++;
	}
	while (input[flag->pos] >= '0' && input[flag->pos] <= '9')
		flag->pos++;
	flag->pos--;
}

int			get_flags(t_flag *flag, const char *input, va_list args)
{
	flag->pos++;
	while (!ft_strchr(VALID_CONV, input[flag->pos]))
	{
		if (!ft_strchr(ALL_SYMBOLS, input[flag->pos]))
			return (0);
		else if (input[flag->pos] == '-')
			flag->minus = 1;
		else if (input[flag->pos] == '0')
			flag->zero = 1;
		else if (input[flag->pos] >= '0' && input[flag->pos] <= '9')
			get_flags_wp(flag, input, args, 1);
		else if (input[flag->pos] == '.')
			get_flags_wp(flag, input, args, 2);
		else if (input[flag->pos] == '*' && flag->dot_exists == 0)
			get_flags_wp2(flag, input, args, 3);
		flag->pos++;
	}
	flag->conv = input[flag->pos];
	return (1);
}
