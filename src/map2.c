/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map2.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisfern <luisfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:47:30 by luisfern          #+#    #+#             */
/*   Updated: 2022/11/17 12:25:05 by luisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	count_elements(t_program *game)
{
	if (game->map[game->y][game->x] == 'C')
		game->count_collect++;
	if (game->map[game->y][game->x] == 'P')
	{
		if (game->count_player == 0)
		{
			game->position[0] = game->y;
			game->position[1] = game->x;
		}
		else
			game->map[game->y][game->x] = '0';
		game->count_player++;
	}
	if (game->map[game->y][game->x] == 'E')
		game->count_exit++;
}

int	check_content(t_program *game)
{
	game->y = 0;
	while (game->y < game->height)
	{
		game->x = 0;
		while (game->x < game->width)
		{
			if (game->map[0][game->x] != '1'
			|| game->map[game->height - 1][game->x] != '1'
			|| game->map[game->y][0] != '1'
				|| game->map[game->y][game->width - 1] != '1')
				return (0);
			if (game->map[game->y][game->x] != '1'
				&& game->map[game->y][game->x] != '0'
				&& game->map[game->y][game->x] != 'C'
				&& game->map[game->y][game->x] != 'P'
				&& game->map[game->y][game->x] != 'E')
				return (0);
			count_elements(game);
			game->x++;
		}
		game->y++;
	}
	return (1);
}

int	check_shape(t_program *game)
{
	int	width;
	int	index;

	if (!game->map[0])
		return (0);
	width = (int)ft_strlen(game->map[0]);
	index = 0;
	while (index < game->height)
	{
		if ((int)ft_strlen(game->map[index]) != width)
			return (0);
		index++;
	}
	game->width = width;
	return (1);
}
