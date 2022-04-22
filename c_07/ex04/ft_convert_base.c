/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_convert_base.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/20 22:26:11 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/04/20 22:57:12 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/12 20:28:41 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/04/12 20:42:38 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_putnbr_base(int nbr, char *base);

int	checkerror_atoi(char *str)
{
	int	i;
	int	j;

	i = 0;
	if (str[0] == '\0' || str[1] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		if (str[i] <= 32 || str[i] == 127 || str[i] == 43 || str[i] == 45)
			return (0);
		j = i + 1;
		while (str[j] != '\0')
		{
			if (str[i] == str[j])
				return (0);
			j++;
		}
		i++;
	}
	return (i);
}

int	nb_base(char c, char *base)
{
	int	nbr;

	nbr = 0;
	while (base[nbr] != '\0')
	{
		if (c == base[nbr])
			return (nbr);
		nbr++;
	}
	return (-1);
}

int	helper_white_and_sing(char *str, int *i)
{
	int	count;
	int	j;

	j = 0;
	while ((str[j] >= 9 && str[j] <= 13) || str[j] == 32)
		j++;
	count = 1;
	while (str[j] && (str[j] == 43 || str[j] == 45))
	{
		if (str[j] == 45)
			count *= -1;
		j++;
	}
	*i = j;
	return (count);
}

char	*ft_convert_base(char *nbr, char *base_from, char *base_to)
{
	int		i;
	int		sign;
	int		nb;
	int		nbr_in_base;
	int		base_in_int;

	nb = 0;
	i = 0;
	base_in_int = checkerror_atoi(base_from);
	if (base_in_int > 1)
	{
		sign = helper_white_and_sing(nbr, &i);
		nbr_in_base = nb_base(nbr[i], base_from);
		while (nbr_in_base != -1)
		{
			nb = (nb * base_in_int) + nbr_in_base;
			i++;
			nbr_in_base = nb_base(nbr[i], base_from);
		}
		ft_putnbr_base(nb * sign, base_to);
	}
	return (0);
}
