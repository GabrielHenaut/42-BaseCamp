/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   assign.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 16:32:41 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/04/19 15:34:20 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

int	only_one_last(char *tower, char *height)
{
	int		i;
	int		counter;
	char	final_tower_height;

	i = 0;
	counter = 0;
	while (tower[i] != '\0')
	{
		if (tower[i] == '-')
			counter++;
		else
			final_tower_height = tower[i];
		i++;
	}
	if (counter == 3)
	{
		*height = final_tower_height;
		return (1);
	}
	return (0);
}

void	warn_col(t_Game *game, char height, int col, int cur_row)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i != cur_row)
		{
			remove_possibillity(game->towers[i][col], height);
		}
		i++;
	}
}

void	warn_row(t_Game *game, char height, int row, int cur_row)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (i != cur_row)
		{
			remove_possibillity(game->towers[row][i], height);
		}
		i++;
	}
}

int	check_invalid(char *tower)
{
	int	i;
	int	counter;

	i = 0;
	counter = 0;
	while (i < 4)
	{
		if (tower[i] == '-')
			counter++;
		i++;
	}
	if (counter == 4)
		return (0);
	return (1);
}

int	assign_towers(t_Game *game, char *final_towers)
{
	int		i;
	char	height;

	i = 0;
	height = '0';
	while (i < 16)
	{
		if (only_one_last(game->towers[i / 4][i % 4], &height))
		{
			final_towers[i] = height;
			warn_row(game, height, i / 4, i % 4);
			warn_col(game, height, i % 4, i / 4);
		}
		if (check_invalid(game->towers[i / 4][i % 4]) == 0)
			return (1);
		i++;
	}
	if (not_done(final_towers))
		assign_towers(game, final_towers);
	return (0);
}
