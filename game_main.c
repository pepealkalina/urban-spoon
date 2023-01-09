/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:29:00 by pepealkalin       #+#    #+#             */
/*   Updated: 2023/01/07 16:11:46 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_data(t_game_data *game, char **map)
{
	int i;

	game->width = ft_strlen(map[0]);
	i = 0;
	while (map[i++])
		;
	game->heigth = i;
}

void	ft_gameplay(void *param)
{
	mlx_t		*mlx;
	t_player	*p;
	t_game_img	*img;

	img = NULL;
	p = NULL;
	mlx = param;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_D))
		mlx_image_to_window(mlx, img->icon_img, (p->x + 1) * 64, p->y * 64);
}

int	ft_game_main(t_game_data *game)
{
	t_game_img		img;
	t_game_textures	textures;
	t_player		player;

	ft_map_data(game, game->map);
	printf("%i, %i\n", game->heigth, game->width);
	game->mlx = mlx_init(game->width * 64, game->heigth * 64,
			"preina-g's so_long", false);
	if (!game->mlx)
		exit(EXIT_FAILURE);
	ft_draw_map(game, &img, &textures);
	ft_init_pos(game, &player);
	mlx_loop_hook(game->mlx, &ft_gameplay, game->mlx);
	mlx_loop(game->mlx);
	return (0);
}
