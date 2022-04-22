/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 17:32:46 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/04/20 00:38:00 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_putchar(char c)
{
	write(1, &c, 1);
}

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	checkerror(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[0] == '\0' || ft_strlen(str) == 1)
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] <= 32 || str[i] == 127 || str[i] == 43 || str[i] == 45)
			return (0);
		j = i + 1;
		while (j < ft_strlen(str))
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

void	ft_putnbr_base(int nbr, char *base)
{
	int		base_in_int;
	int		error;
	long	nb;

	error = checkerror(base);
	base_in_int = ft_strlen(base);
	nb = nbr;
	if (error == 1)
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb *= -1;
		}
		if (nb < base_in_int)
			ft_putchar(base[nb]);
		if (nb >= base_in_int)
		{
			ft_putnbr_base(nb / base_in_int, base);
			ft_putnbr_base(nb % base_in_int, base);
		}
	}
}
// c_04_04

#include <stdio.h>

int		main(void)
{
	// ft_putnbr_base(-12, "01");
	// printf("\n");
	ft_putnbr_base(-2147483648, "poneyvif");
	printf("\n");
	// ft_putnbr_base(-2147483648, "01234567");
	// printf("\n");
	// ft_putnbr_base(64, "0123456789abcdef");
}