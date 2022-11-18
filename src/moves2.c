/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisfern <luisfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:47:48 by luisfern          #+#    #+#             */
/*   Updated: 2022/11/18 10:10:13 by luisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	move_up(t_program *game)
{
	if (game->map[game->position[0] - 1][game->position[1]] != '1')
	{
		if (actions(&game->map[game->position[0]][game->position[1]],
			&game->map[game->position[0] - 1][game->position[1]], game))
			game->position[0]--;
	}
	if (game->game_over == 0)
	{
		mlx_destroy_image(game->mlx, game->player);
		game->player = mlx_xpm_file_to_image(game->mlx, "../sprites/charup.xpm",
				&game->img_width, &game->img_height);
	}
}

void	move_left(t_program *game)
{
	if (game->map[game->position[0]][game->position[1] - 1] != '1')
	{
		if (actions(&game->map[game->position[0]][game->position[1]],
			&game->map[game->position[0]][game->position[1] - 1], game))
			game->position[1]--;
	}
	if (game->game_over == 0)
	{
		mlx_destroy_image(game->mlx, game->player);
		game->player = mlx_xpm_file_to_image(game->mlx,
				"../sprites/charleft.xpm", &game->img_width, &game->img_height);
	}
}

void	move_down(t_program *game)
{
	if (game->map[game->position[0] + 1][game->position[1]] != '1')
	{
		if (actions(&game->map[game->position[0]][game->position[1]],
			&game->map[game->position[0] + 1][game->position[1]], game))
			game->position[0]++;
	}
	if (game->game_over == 0)
	{
		mlx_destroy_image(game->mlx, game->player);
		game->player = mlx_xpm_file_to_image(game->mlx,
				"../sprites/charidle.xpm", &game->img_width, &game->img_height);
	}
}

void	move_right(t_program *game)
{
	if (game->map[game->position[0]][game->position[1] + 1] != '1')
	{
		if (actions(&game->map[game->position[0]][game->position[1]],
			&game->map[game->position[0]][game->position[1] + 1], game))
			game->position[1]++;
	}
	if (game->game_over == 0)
	{
		mlx_destroy_image(game->mlx, game->player);
		game->player = mlx_xpm_file_to_image(game->mlx,
				"../sprites/charright.xpm", &game->img_width,
				&game->img_height);
	}
}
