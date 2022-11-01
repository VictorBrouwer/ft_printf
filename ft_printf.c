/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   ft_printf.c                                        :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/20 19:41:25 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/11/01 12:23:37 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	(*g_cfp[256])(va_list args) = {
['c'] = print_char,
['s'] = print_putstr,
['p'] = print_ptr,
['d'] = print_di,
['i'] = print_di,
['u'] = print_uns,
['x'] = print_hex_low,
['X'] = print_hex_up,
['%'] = print_per
};

int	ft_printf(const char *s, ...)
{
	va_list	args;
	int		len;
	int		i;

	va_start(args, s);
	len = 0;
	i = 0;
	while (s[i])
	{
		if (s[i] == '%' && g_cfp[(int)s[i + 1]])
		{
			len += g_cfp[(int)s[i + 1]](args);
			i++;
		}
		else
		{
			print_putchar(s[i]);
			len++;
		}
		i++;
	}
	va_end(args);
	return (len);
}

// #include <stdio.h>

// int	main()
// {
// 	ft_printf("hello %%", 'X');
// 	printf("\nhello %%", 'X');
// 	return (0);
// }