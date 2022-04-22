/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_int_tab.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/08 05:04:34 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/04/14 03:59:19 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

void	ft_rev_int_tab(int tab[], int size)
{
	int	i;	
	int	tmp;

	i = 0;
	while (i < (size / 2))
	{
		tmp = tab[i];
		tab [i] = tab [size - 1 - i];
		tab [size - 1 - i] = tmp;
		i++;
	}	
}