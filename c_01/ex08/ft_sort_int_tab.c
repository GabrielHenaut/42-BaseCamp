/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sort_int_tab.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 16:19:28 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/04/15 02:12:14 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdbool.h>

bool	is_in_order(int *tab, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (tab[i] > tab[i + 1])
			return (false);
		i++;
	}
	return (true);
}

void	ft_sort_int_tab(int *tab, int size)
{
	int	i;
	int	j;	
	int	tmp;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size - 1)
		{
			if (tab[j] > tab[j + 1])
			{
				tmp = tab [j];
				tab[j] = tab [j + 1];
				tab [j + 1] = tmp;
			}
			j++;
		}
		if ((is_in_order(tab, size) == true))
			return;
		i++;
	}
}

#include <stdio.h>
int	main()
{
	int tab[] = {7, 6, 3, 4, 2, 5, 1, 9, 7, 5};
	int size = 10;

	ft_sort_int_tab(tab, size);
	printf("%d, %d, %d, %d, %d, %d, ", tab[0], tab[1], tab[2], tab[3], tab[4], tab[5]);
	printf("%d, %d, %d, %d", tab[6], tab[7], tab[8], tab[9]); 
	return (0);
}