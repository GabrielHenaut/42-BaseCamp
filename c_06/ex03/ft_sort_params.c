/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_params.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/13 04:34:34 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/04/14 03:49:15 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

int	ft_strcmp(char *s1, char *s2)
{
	int	i;

	i = 0;
	while (s1[i] == s2[i] && (s1[i] != '\0' || s2[i] != '\0'))
	{
		i++;
	}
	return (s1[i] - s2[i]);
}

void	writer(char *arg)
{
	int	i;

	i = 0;
	while (arg[i] != '\0')
	{
		write(1, &arg[i], 1);
		i++;
	}
	write(1, "\n", 1);
}

int	is_in_order(char *argv[], int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (argv[i] > argv[i + 1])
			return (0);
		i++;
	}
	return (1);
}

void	sorter(char *argv[], int size)
{
	int		i;
	int		j;	
	char	*tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (ft_strcmp(argv[j], argv[j + 1]) > 0)
			{
				tmp = argv [j];
				argv[j] = argv [j + 1];
				argv [j + 1] = tmp;
			}
			j++;
		}
		if ((is_in_order(argv, size) == 1))
			return ;
		i++;
	}
}

int	main(int argc, char *argv[])
{
	int	i;

	i = 1;
	sorter(argv, argc);
	while (i < argc)
	{
		writer(argv[i]);
		i++;
	}
	return (0);
}
