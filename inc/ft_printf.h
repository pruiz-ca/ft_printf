/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pruiz-ca <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/02/10 17:15:28 by pruiz-ca          #+#    #+#             */
/*   Updated: 2021/02/20 02:05:23 by pruiz-ca         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

# define ALL_SYMBOLS	"cspdiuxX%-0.*123456789"
# define VALID_CONV		"cspdiuxX%"
# define VALID_NUMS		"0123456789+-"

typedef struct	s_flag
{
	int			pos;
	int			count;
	int			minus;
	int			zero;
	int			width;
	int			width_exists;
	int			dot;
	int			dot_exists;
	char		conv;
	size_t		len;
	int			num_sp;
	int			num_0s;
	int			neg;
}				t_flag;

int				ft_printf(const char *input, ...);
void			print_str(t_flag *flag, char *str);
void			get_sp_zero(t_flag *flag);
void			get_count(t_flag *flag);
void			flag_init(t_flag *flag);
void			flag_reset(t_flag *flag);
int				get_flags(t_flag *flag, const char *input, va_list args);
void			is_char(t_flag *flag, va_list args);
void			is_string(t_flag *flag, va_list args);
void			is_hexa(t_flag *flag, va_list args);
void			is_int(t_flag *flag, va_list args);
void			is_uint(t_flag *flag, va_list args);
void			ft_free(char **str);

int				ft_atoi(const char *str);
int				ft_get_max(int a, int b);
int				ft_get_min(int a, int b);
char			*ft_itoa_base_uint(unsigned int n, unsigned int base);
char			*ft_itoa_base_llu(unsigned long n, unsigned long base);
char			*ft_itoa_base(int n, unsigned long base);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);
char			*ft_strchr(const char *str, int c);
char			*ft_strdup_limit(const char *src, int end);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strupper(char *str);

#endif
