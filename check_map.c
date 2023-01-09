/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 11:23:59 by pepealkalin       #+#    #+#             */
/*   Updated: 2023/01/05 10:14:37 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map(char **map, t_game_data *game)
{
	if (ft_is_rectangle(map) == FALSE)
	{
		ft_printf("Error! The map is not a rectangle.");
		return (FALSE);
	}
	else if (ft_check_wall(map) == FALSE)
	{
		ft_printf("Error! The map is not closed by walls.");
		return (FALSE);
	}
	else if (ft_is_tile(map) == FALSE)
	{
		ft_printf("Error! The map have a wrong tile.\n");
		return (FALSE);
	}
	else if (ft_have_exit(game) == FALSE)
	{
		ft_printf("Error! The map do not have a exit ");
		ft_printf("or init position or collectable.");
		return (FALSE);
	}
	else
		return (TRUE);
}
