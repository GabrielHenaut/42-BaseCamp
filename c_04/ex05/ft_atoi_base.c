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

int	checkerror(char *str)
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

int	ft_atoi_base(char *str, char *base)
{
	int		i;
	int		sign;
	int		nbr;
	int		nbr_in_base;
	int		base_in_int;

	nbr = 0;
	i = 0;
	base_in_int = checkerror(base);
	if (base_in_int > 1)
	{
		sign = helper_white_and_sing(str, &i);
		nbr_in_base = nb_base(str[i], base);
		while (nbr_in_base != -1)
		{
			nbr = (nbr * base_in_int) + nbr_in_base;
			i++;
			nbr_in_base = nb_base(str[i], base);
		}
		return (nbr *= sign);
	}
	return (0);
}
