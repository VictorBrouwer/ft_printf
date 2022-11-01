/* ************************************************************************** */
/*                                                                            */
/*                                                        ::::::::            */
/*   helpers.c                                          :+:    :+:            */
/*                                                     +:+                    */
/*   By: vbrouwer <vbrouwer@student.codam.nl>         +#+                     */
/*                                                   +#+                      */
/*   Created: 2022/10/26 15:53:33 by vbrouwer      #+#    #+#                 */
/*   Updated: 2022/10/31 10:21:00 by vbrouwer      ########   odam.nl         */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_putchar(char c)
{
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	print_char(va_list args)
{
	char	c;

	c = va_arg(args, int);
	if (write(1, &c, 1) == -1)
		return (-1);
	return (1);
}

int	print_putstr(va_list args)
{
	int		x;
	char	*s;

	x = 0;
	s = va_arg(args, char *);
	if (!s)
		return (write(1, "(null)", 6));
	while (s[x])
	{
		write(1, &s[x], 1);
		x++;
	}
	return (x);
}

int	print_per(va_list args)
{
	(void) args;
	write(1, "%", 1);
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	unsigned int	x;
	char			*p;

	p = (char *) s;
	x = 0;
	while (p[x])
	{
		if (p[x] == (unsigned char) c)
			return (&p[x]);
		x++;
	}
	if (p[x] == (unsigned char) c)
		return (&p[x]);
	else
		return (NULL);
}
