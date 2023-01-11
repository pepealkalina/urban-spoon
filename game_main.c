/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_main.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 12:29:00 by pepealkalin       #+#    #+#             */
/*   Updated: 2023/01/11 17:59:19 by preina-g         ###   ########.fr       */
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
	game->items = ft_count_collectables(game);
	ft_draw_map(game, &textures);
	mlx_set_instance_depth((*game).img.exit_img->instances, 0);
	mlx_loop_hook(game->mlx, &ft_gameplay, game);
	mlx_loop(game->mlx);
	return (0);
}
