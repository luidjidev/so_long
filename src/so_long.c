/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisfern <luisfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:46:54 by luisfern          #+#    #+#             */
/*   Updated: 2022/11/18 10:19:16 by luisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int ac, char **av)
{
	int			fd;
	t_program	game;

	if (ac != 2)
		return (0);
	fd = open(av[1], O_RDONLY);
	if (!verify_map(av[1], fd, &game))
		return (0);
	game.mlx = mlx_init();
	game.win = mlx_new_window(game.mlx,
			game.width * 32, game.height * 32, "so_long");
	render(&game);
	mlx_hook(game.win, 17, 0, close_window, NULL);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
	close(fd);
	destroy_images(&game);
	mlx_destroy_window(game.mlx, game.win);
	free (game.map);
	free (game.win);
	free (game.mlx);
	return (0);
}
