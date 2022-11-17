/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisfern <luisfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:48:05 by luisfern          #+#    #+#             */
/*   Updated: 2022/11/17 12:58:20 by luisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	open_images(t_program *game)
{
	game->free_way = mlx_xpm_file_to_image(game->mlx,
			"../sprites/background.xpm", &game->img_width, &game->img_height);
	game->walls = mlx_xpm_file_to_image(game->mlx,
			"../sprites/walls.xpm", &game->img_width, &game->img_height);
	game->money = mlx_xpm_file_to_image(game->mlx,
			"../sprites/money1.xpm", &game->img_width, &game->img_height);
	game->door = mlx_xpm_file_to_image(game->mlx,
			"../sprites/exitlocked.xpm", &game->img_width, &game->img_height);
	game->player = mlx_xpm_file_to_image(game->mlx,
			"../sprites/charidle.xpm", &game->img_width, &game->img_height);
}

void	print_map(t_program *game)
{
	game->y = 0;
	while (game->y < game->height)
	{
		game->x = 0;
		while (game->x < game->width)
		{
			choose_image(game);
			game->x++;
		}
		game->y++;
	}
}

void	choose_image(t_program *game)
{
	if (game->map[game->y][game->x] == '1')
		mlx_put_image_to_window(game->mlx, game->win,
			game->walls, 32 * game->x, 32 * game->y);
	else if (game->map[game->y][game->x] == 'C')
		mlx_put_image_to_window(game->mlx, game->win,
			game->money, 32 * game->x, 32 * game->y);
	else if (game->map[game->y][game->x] == 'E')
		mlx_put_image_to_window(game->mlx, game->win,
			game->door, 32 * game->x, 32 * game->y);
	else if (game->map[game->y][game->x] == '0')
		mlx_put_image_to_window(game->mlx, game->win,
			game->free_way, 32 * game->x, 32 * game->y);
	else if (game->map[game->y][game->x] == 'P')
		mlx_put_image_to_window(game->mlx, game->win,
			game->player, 32 * game->x, 32 * game->y);
}

void	render(t_program *game)
{
	open_images(game);
	game->game_over = 0;
	print_map(game);
	game->moves = 0;
	print_steps(game);
}
