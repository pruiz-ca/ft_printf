/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conv_str.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/12 01:04:50 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/02/20 16:29:40 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/ft_printf.h"

void			is_char(t_flag *flag, va_list args)
{
	int		c;
	int		i;

	i = 1;
	c = flag->conv == '%' ? '%' : va_arg(args, int);
	if (flag->minus == -1)
	{
		while (i++ < flag->width)
		{
			ft_putchar_fd(flag->zero == -1 ? ' ' : '0', 1);
			flag->count++;
		}
		ft_putchar_fd(c, 1);
	}
	else
	{
		ft_putchar_fd(c, 1);
		while (i++ < flag->width)
		{
			ft_putchar_fd(' ', 1);
			flag->count++;
		}
	}
	flag->count += 1;
}

void			is_string(t_flag *flag, va_list args)
{
	char			*str;
	char			*tmp;
	unsigned int	str_size;

	if (!(tmp = va_arg(args, char *)))
		tmp = "(null)";
	flag->len = flag->dot == 0 ? 0 : ft_strlen(tmp);
	get_sp_zero(flag);
	str_size = flag->dot < 0 ? (int)flag->len : flag->dot;
	if (flag->dot_exists && flag->dot < 0)
		str_size = flag->len;
	str = ft_strdup_limit(tmp, str_size);
	flag->len = ft_strlen(str);
	get_count(flag);
	print_str(flag, str);
	ft_free(&str);
}

void			is_hexa(t_flag *flag, va_list args)
{
	unsigned long int	address;
	char				*str;

	if (flag->conv == 'p')
		address = va_arg(args, unsigned long);
	else
		address = va_arg(args, unsigned int);
	if (!address)
		address = 0;
	if (flag->conv == 'p')
		str = ft_itoa_base_llu(address, 16);
	else
		str = ft_itoa_base_uint(address, 16);
	if (address == 0 && flag->dot == 0)
		str = NULL;
	if (flag->conv == 'X' && str)
		str = ft_strupper(str);
	if (str == NULL)
		flag->len = flag->dot == 0 ? 0 : ft_strlen(str);
	else
		flag->len = ft_strlen(str);
	get_sp_zero(flag);
	get_count(flag);
	print_str(flag, str);
	ft_free(&str);
}
