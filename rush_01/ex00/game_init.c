/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: Ghenaut- <ghenaut-@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/17 23:27:09 by Ghenaut-          #+#    #+#             */
/*   Updated: 2022/04/18 14:05:04 by Ghenaut-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rush.h"

void	init_side(t_Game *game, int *arg)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		game->col_up[i] = arg[i];
		i++;
	}
	while (i < 8)
	{
		game->col_down[i - 4] = arg[i];
		i++;
	}
	while (i < 12)
	{
		game->row_left[i - 8] = arg[i];
		i++;
	}
	while (i < 16)
	{
		game->row_right[i - 12] = arg[i];
		i++;
	}
}

void	init_towers(t_Game *game)
{
	int	i;

	i = 0;
	while (i < 16)
	{
		// i/4 e i/4 dao a posicao correta da matriz 2x2
		ft_strcpy(game->towers[i / 4][i % 4], "1234");
		i++;
	}
}

void	init_pairs(t_Game *game, int *arg)
{
	int	i;
	int	pos;

	i = 0;
	while (i < 4)
	{	//    1a pos             2pos
		pos = (arg[i] - 1) * 4 + arg[i + 4] - 1;
		game->pairs[i] = pos;
		i++;
	}
	i += 4; //soma para checar na primeira linha
	while (i < 12)
	{	
		pos = (arg[i] - 1) * 4 + arg[i + 4] - 1;
		game->pairs[i - 4] = pos;
		i++;
	}
}

void	init_game(t_Game *game, int *arg)
{
	init_side(game, arg);
	init_towers(game);
	init_pairs(game, arg);
}
