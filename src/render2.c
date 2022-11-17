/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisfern <luisfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:48:15 by luisfern          #+#    #+#             */
/*   Updated: 2022/11/17 12:53:13 by luisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/*Close window when press 'x'*/
int	close_window(void*anything)
{
	(void)anything;
	exit(0);
	return (0);
}

void	destroy_images(t_program *game)
{
	mlx_destroy_image(game->mlx, game->free_way);
	mlx_destroy_image(game->mlx, game->walls);
	mlx_destroy_image(game->mlx, game->player);
	mlx_destroy_image(game->mlx, game->money);
	mlx_destroy_image(game->mlx, game->door);
}

void	print_steps(t_program *game)
{
	if (game->moves > 0)
		ft_printf("step n%i\n", game->moves);
	if (game->game_over == 1)
		ft_printf("GAME OVER\n");
}
