/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_int.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/15 20:18:35 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/02/20 02:08:27 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void		is_int(t_flag *flag, va_list args)
{
	int				tmp;
	unsigned int	utmp;
	char			*str;

	tmp = va_arg(args, int);
	if (tmp < 0)
	{
		flag->neg = 1;
		utmp = tmp * -1;
	}
	else
		utmp = tmp;
	str = ft_itoa_base(utmp, 10);
	if (tmp == 0 && flag->dot == 0)
		str = NULL;
	if (str == NULL)
		flag->len = flag->dot == 0 ? 0 : ft_strlen(str);
	else
		flag->len = ft_strlen(str);
	get_sp_zero(flag);
	get_count(flag);
	print_str(flag, str);
	ft_free(&str);
}

void		is_uint(t_flag *flag, va_list args)
{
	unsigned int	tmp;
	char			*str;

	tmp = va_arg(args, unsigned int);
	str = ft_itoa_base_uint(tmp, 10);
	if (tmp == 0 && flag->dot == 0)
		str = NULL;
	if (str == NULL)
		flag->len = flag->dot == 0 ? 0 : ft_strlen(str);
	else
		flag->len = ft_strlen(str);
	get_sp_zero(flag);
	get_count(flag);
	print_str(flag, str);
	ft_free(&str);
}
