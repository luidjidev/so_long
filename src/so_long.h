/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: luisfern <luisfern@student.42lisboa.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/10 10:47:56 by luisfern          #+#    #+#             */
/*   Updated: 2022/11/17 12:52:25 by luisfern         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"
# include "../printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../minilibx_linux/mlx.h"

typedef struct s_program {
	void	*mlx;
	void	*win;
	char	**map;
	int		moves;
	int		height;
	int		width;
	int		x;
	int		y;
	int		count_collect;
	int		count_player;
	int		count_exit;
	int		position[2];
	void	*free_way;
	void	*walls;
	void	*player;
	void	*money;
	void	*door;
	int		img_width;
	int		img_height;
	int		game_over;
	int		count_to_robot;
}	t_program;

enum	e_keys{
	key_W = 119,
	key_S = 115,
	key_A = 97,
	key_D = 100,
	key_ESC = 65307
};

// map
int		verify_map(char *map_path, int fd, t_program *game);
int		check_extension(char *map_path);
void	store_map(int fd, int index, t_program *game);
int		check_shape(t_program *game);
int		check_content(t_program *game);
void	count_elements(t_program *game);
// img and window
void	render(t_program *game);
void	open_images(t_program *game);
void	include_enemy(t_program *game);
void	print_map(t_program *game);
void	choose_image(t_program *game);
void	print_steps(t_program *game);
int		close_window(void*anything);
void	destroy_images(t_program *game);
// player movement
int		key_hook(int key, t_program *game);
void	move_up(t_program *game);
void	move_left(t_program *game);
void	move_down(t_program *game);
void	move_right(t_program *game);
int		actions(char *actual, char *new, t_program *game);
void	manage_collectables(t_program *game);

#endif