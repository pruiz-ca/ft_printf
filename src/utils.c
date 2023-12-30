/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/17 18:06:36 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/02/21 16:12:08 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			get_count(t_flag *flag)
{
	flag->count += flag->num_sp < 0 ? 0 : flag->num_sp;
	flag->count += flag->num_0s < 0 ? 0 : flag->num_0s;
	flag->count += flag->conv == 'p' ? 2 : 0;
	flag->count += flag->neg == 1 ? 1 : 0;
	flag->count += flag->len;
}

void			get_sp_zero(t_flag *flag)
{
	int			max;
	int			min;
	int			prec;

	max = ft_get_max(flag->dot, flag->len);
	min = ft_get_min(flag->dot, flag->len);
	if (flag->conv == 's')
		prec = (flag->dot < 0 ? (int)flag->len : min);
	else
		prec = (flag->dot < 0 ? (int)flag->len : max);
	if (ft_strchr("di", flag->conv) && flag->neg == 1)
		prec += 1;
	prec += flag->conv == 'p' ? 2 : 0;
	flag->num_sp = flag->width - prec;
	if (flag->conv != 's')
		flag->num_0s = flag->dot - flag->len;
	if (flag->zero == 1 && flag->minus == -1 && flag->dot < 0)
	{
		flag->num_0s = flag->num_sp;
		flag->num_sp = 0;
	}
}

static void		print_str_left(t_flag *flag, char *str)
{
	if (flag->conv == 'p')
		ft_putstr_fd("0x", 1);
	if (flag->neg == 1)
		ft_putchar_fd('-', 1);
	while (flag->num_0s-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(str, 1);
	while (flag->num_sp-- > 0)
		ft_putchar_fd(' ', 1);
}

static void		print_str_right(t_flag *flag, char *str)
{
	int		i;

	i = 0;
	if (flag->neg == 1 && (flag->num_sp <= 0))
		ft_putchar_fd('-', 1);
	while (i++ < flag->num_sp)
		ft_putchar_fd(' ', 1);
	if (flag->neg == 1 && flag->num_sp > 0)
		ft_putchar_fd('-', 1);
	if (flag->conv == 'p')
		ft_putstr_fd("0x", 1);
	while (flag->num_0s-- > 0)
		ft_putchar_fd('0', 1);
	ft_putstr_fd(str, 1);
}

void			print_str(t_flag *flag, char *str)
{
	if (flag->minus == -1)
		print_str_right(flag, str);
	else
		print_str_left(flag, str);
}
