/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: docioban <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/22 00:36:41 by docioban          #+#    #+#             */
/*   Updated: 2017/12/24 17:11:51 by docioban         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

#include <stdlib.h>
#include <unistd.h>
#include <stdarg.h>

int		ft_printf(const char * restrict format, ...);




/*     ft_put     */
int		ft_putchar_f(char c);
int		ft_putstr_f(char *str);
int		ft_putstr_fm(char *str, double nr, char c);
int		ft_putnbr_f(int n);
int		ft_putnbr_fu(unsigned int n);
char	*ft_itoa_base(int nr, int base);
double	ft_atof_printf(const char *str);

/*    +++          */
char	*ft_mari(char *s);
char	*ft_mici(char *s);


#endif
