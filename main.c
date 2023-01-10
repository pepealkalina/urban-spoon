/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: preina-g <preina-g@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:46:13 by pepealkalin       #+#    #+#             */
/*   Updated: 2023/01/09 11:49:17 by preina-g         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_argv(char *argv)
{
	int	i;

	i = ft_strlen(argv) - 1;
	if (argv[i] == 'r' && argv[i - 1] == 'e' && argv[i - 2] == 'b'
		&& argv[i - 3] == '.')
		return (TRUE);
	ft_printf("ERROR, INVALID MAP!!");
	return (FALSE);
}

int	main(int argc, char **argv)
{
	t_game_data	game;

	if (argc == 2)
	{
		if (ft_argv(argv[1]) == FALSE)
			return (-1);
		game.map = ft_read_map(argv[1]);
		if (game.map == NULL)
			return (ft_printf("ERROR, INVALID MAP!!"));
		if (ft_check_map(game.map, &game) == FALSE)
			return (-1);
		ft_game_main(&game);
	}
	else
		return (ft_printf("ERROR, NO MAP!"));
	return (0);
}
