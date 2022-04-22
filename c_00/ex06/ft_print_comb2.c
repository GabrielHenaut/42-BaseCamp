/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_comb2.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/07 05:03:54 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/04/09 04:43:47 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>

void	printer(char sub_pos_1, char sub_pos_2)
{
	write(1, &sub_pos_1, 1);
	write(1, &sub_pos_2, 1);
}

void	writer(int num, int max)
{
	char	sub_pos_1;
	char	sub_pos_2;

	if (num <= 9)
	{
		sub_pos_2 = num + 48;
		printer('0', sub_pos_2);
	}
	else if (num <= max)
	{
		sub_pos_2 = (num % 10) + 48;
		sub_pos_1 = (num / 10) + 48;
		printer(sub_pos_1, sub_pos_2);
	}
}

void	combiner(int pos_1, int pos_2)
{
	writer(pos_1, 98);
	write(1, " ", 1);
	writer(pos_2, 99);
	if (pos_1 != 98 || pos_2 != 99)
		printer(',', ' ');
}

void	ft_print_comb2(void)
{
	int		pos_1;
	int		pos_2;

	pos_1 = 0;
	while (pos_1 <= 98)
	{
		pos_2 = pos_1 + 1;
		while (pos_2 <= 99)
		{
			combiner(pos_1, pos_2);
			pos_2++;
		}
		pos_1++;
	}
}

int main(void)
{
	ft_print_comb2();
	return (0);
}
