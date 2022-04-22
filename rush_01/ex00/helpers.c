/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 01:10:13 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/04/18 01:52:55 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strcpy(char *dest, char *src)
{
	int	i;

	i = 0;
	while (src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

void	remove_possibillity(char *tower, char c)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (tower[i] == c)
		{
			tower[i] = '-';
			return ;
		}
		i++;
	}
	return ;
}

int	in_possible(char c, char *possible)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (possible[i] == c)
			return (1);
		i++;
	}
	return (0);
}

void	init_array(char *array, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		array[i] = '0';
		i++;
	}
}

int	not_done(char *a)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		if (a[i] == '0')
			return (1);
		i++;
	}
	return (0);
}
