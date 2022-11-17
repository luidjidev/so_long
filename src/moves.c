/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisfern <luisfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:47:40 by luisfern          #+#    #+#             */
/*   Updated: 2022/11/17 12:19:38 by luisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	key_hook(int key, t_program *game)
{
	if (key == key_ESC || game->game_over == 1)
		exit(0);
	if (key == key_W)
		move_up(game);
	else if (key == key_A)
		move_left(game);
	else if (key == key_S)
		move_down(game);
	else if (key == key_D)
		move_right(game);
	print_map(game);
	return (0);
}

void	manage_collectables(t_program *game)
{
	game->count_collect--;
	if (game->count_collect == 0)
	{
		mlx_destroy_image(game->mlx, game->door);
		game->door = mlx_xpm_file_to_image(game->mlx,
				"../sprites/exit.xpm", &game->img_width, &game->img_height);
	}
}

int	actions(char *actual, char *new, t_program *game)
{
	if (*new == 'C')
		manage_collectables(game);
	if (*new == 'E' && game->count_collect == 0)
	{
		ft_printf("CONGRATS!\n");
		exit(0);
	}
	if (*new == 'E')
		return (0);
	*actual = '0';
	*new = 'P';
	game->moves++;
	print_steps(game);
	return (1);
}
