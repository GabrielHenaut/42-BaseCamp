/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 04:44:02 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/04/08 17:07:26 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	ft_print_num(int pos1, int pos2, int pos3)
{
	write(1, &pos1, 1);
	write(1, &pos2, 1);
	write(1, &pos3, 1);
	if (pos1 != '7' || pos2 != '8' || pos3 != '9')
	{
		write(1, ", ", 2);
	}
}

void	ft_print_comb(void)
{
	char	pos1;
	char	pos2;
	char	pos3;

	pos1 = '0';
	while (pos1 <= '7')
	{
		pos2 = pos1 + 1;
		while (pos2 <= '8')
		{
			pos3 = pos2 + 1;
			while (pos3 <= '9')
			{
				ft_print_num(pos1, pos2, pos3);
				pos3++;
			}
			pos2++;
		}
		pos1++;
	}
}
