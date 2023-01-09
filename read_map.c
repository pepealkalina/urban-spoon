/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pepealkalina <pepealkalina@student.42.f    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 17:46:10 by pepealkalin       #+#    #+#             */
/*   Updated: 2023/01/04 09:35:39 by pepealkalin      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**ft_read_map(char *file)
{
	char	**map;
	int		fd;
	char	*line;
	char	*tmp;
	char	*map_tmp;

	fd = open(file, O_RDONLY);
	if (fd == -1)
		return (NULL);
	tmp = NULL;
	while (1)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break ;
		map_tmp = tmp;
		tmp = ft_strjoin(map_tmp, line);
		free(line);
	}
	map = ft_split(tmp, '\n');
	free(tmp);
	close(fd);
	return (map);
}
