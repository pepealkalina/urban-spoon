/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:29:00 by pepealkalin       #+#    #+#             */
/*   Updated: 2023/01/10 17:59:06 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_map_data(t_game_data *game, char **map)
{
	int	i;

	game->width = ft_strlen(map[0]);
	i = 0;
	while (map[i++])
		;
	game->heigth = i;
}

int	ft_count_collectables(t_game_data *game)
{
	int	count;
	int	i;
	int	j;

	count = 0;
	i = 0;
	while (game->map[i])
	{
		j = 0;
		while (game->map[i][j])
		{
			if (game->map[i][j] == COLLECT)
				count++;
			j++;
		}
		i++;
	}
	return (count);
}

void	ft_delete_collect(t_game_data *game)
{
	int	i;

	i = 0;
	while (i < game->count)
	{
		if ((((*game).img.collect_img->instances[i].y
					== (*game).img.icon_img->instances[0].y)
				&& ((*game).img.collect_img->instances[i].x
					== (*game).img.icon_img->instances[0].x))
			&& (*game).img.collect_img->instances[i].enabled == true)
		{
			(*game).img.collect_img->instances[i].enabled = false;
			return ;
		}
		i++;
	}
}

void	ft_is_collect(t_game_data *game)
{
	if (game->map[(*game).img.icon_img->instances[0].y / 64]
		[(*game).img.icon_img->instances[0].x / 64] == COLLECT)
	{
		ft_delete_collect(game);
		game->map[(*game).img.icon_img->instances[0].y / 64]
		[(*game).img.icon_img->instances[0].x / 64] = VOID;
		game->collect_count++;
		ft_printf("%i\n", game->collect_count);
	}
	if (game->map[(*game).img.icon_img->instances[0].y / 64]
		[(*game).img.icon_img->instances[0].x / 64] == EXIT)
	{
		if (game->count == game->collect_count)
			mlx_close_window(game->mlx);
		else
			mlx_put_string(game->mlx, "YOU CAN NOT EXIT", (game->width - 3) * 64, (game->heigth - 1) * 64);
	}
}


void	ft_gameplay(void *param)
{
	mlx_t		**mlx;
	t_game_data	*game;

	game = &(*param);
	mlx = &(*game).mlx;
	if (mlx_is_key_down(*mlx, MLX_KEY_ESCAPE))
		mlx_close_window(*mlx);
	if (mlx_is_key_down(*mlx, MLX_KEY_W))
		ft_move_up(game);
	if (mlx_is_key_down(*mlx, MLX_KEY_A))
		ft_move_left(game);
	if (mlx_is_key_down(*mlx, MLX_KEY_S))
		ft_move_down(game);
	if (mlx_is_key_down(*mlx, MLX_KEY_D))
		ft_move_right(game);
	if (game->count == game->collect_count)
		mlx_put_string(game->mlx, "YOU CAN EXIT", (game->width - 3) * 64, (game->heigth - 1) * 64);
	ft_is_collect(game);

}

int	ft_game_main(t_game_data *game)
{
	t_game_textures	textures;
	game->collect_count = 0;
	game->move_count = 0;
	ft_map_data(game, game->map);
	printf("%i, %i\n", game->heigth, game->width);
	game->mlx = mlx_init(game->width * 64, game->heigth * 64,
			"preina-g's so_long", false);
	if (!game->mlx)
		exit(EXIT_FAILURE);
	game->count = ft_count_collectables(game);
	ft_draw_map(game, &textures);
	mlx_loop_hook(game->mlx, &ft_gameplay, game);
	mlx_loop(game->mlx);
	mlx_terminate(game->mlx);
	return (0);
}
