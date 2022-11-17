/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisfern <luisfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:47:17 by luisfern          #+#    #+#             */
/*   Updated: 2022/11/17 13:03:16 by luisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	store_map(int fd, int index, t_program *game)
{
	char	*line;

	line = get_next_line(fd);
	if (line)
		store_map(fd, index + 1, game);
	else
	{
		game->height = index;
		game->map = malloc(sizeof(char *) * (index + 1));
		if (!game->map)
			return ;
	}
	game->map[index] = ft_strtrim(line, "\n");
	free (line);
	return ;
}

int	check_extension(char *map_path)
{
	int		length;
	char	*extension;
	char	*pattern;

	length = (int)ft_strlen(map_path);
	if (length < 5)
		return (0);
	pattern = ".ber";
	extension = ft_substr(map_path, length - 4, length);
	if (ft_strncmp(pattern, extension, 5) != 0)
	{
		free (extension);	
		return (0);
	}
	free (extension);
	return (1);
}

int	verify_map(char *map_path, int fd, t_program *game)
{
	int	index;

	if (fd < 0 || !check_extension(map_path))
	{
		ft_printf("Error\nInvalid map path!\n");
		return (0);
	}
	store_map(fd, 0, game);
	game->count_player = 0;
	game->count_collect = 0;
	game->count_exit = 0;
	if (!check_shape(game) || !check_content(game)
		|| game->count_collect == 0 || game->count_exit != 1 || game->count_player != 1)
	{
		ft_printf("Error\nInvalid map!\n");
		index = 0;
		while (game->map[index])
			free (game->map[index++]);
		free (game->map);
		return (0);
	}
	return (1);
}
