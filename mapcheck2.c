/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mapcheck2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/14 16:03:01 by dgarizad          #+#    #+#             */
/*   Updated: 2023/04/16 21:48:36 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	ft_add(t_queue *queue, char c)
{
	if (c == 'E')
		(queue->exits)++;
	if (c == 'C')
		(queue->coins)++;
}

/**
 * @brief Does the flooding thing. Visits the nodes of each point 
 * and sets it to "visited" to mark them.
 * @param queue 
 * @param row 
 * @param col 
 * @param map_s 
 * @return int 
 */
int	ft_neighbors(t_queue *queue, int row, int col, char **map_s)
{
	int	i;
	int	j;

	i = 1;
	j = 0;
	while (j < 2)
	{
		if (queue->visited[row][col + i] == 'N' && map_s[row][col + i] != '1')
		{
			queue->visited[row][col + i] = 'Y';
			ft_add(queue, map_s[row][col + i]);
			ft_add2queue(queue, row, col + i);
		}
		if (queue->visited[row + i][col] == 'N' && map_s[row + i][col] != '1')
		{
			queue->visited[row + i][col] = 'Y';
			ft_add(queue, map_s[row + i][col]);
			ft_add2queue(queue, row + i, col);
		}
		j++;
		i *= -1;
	}
	return (1);
}

/**
 * @brief Checks the outter borders and returns 1 if something is 
 * not '1'. auxiliary function for surround ft.
 * @param map 
 * @param c 
 * @param flag 
 * @param data 
 * @return int 
 */
static int	ft_look(char **map, t_data *data)
{
	int	i;

	i = 0;
	while (i < data->map_w)
	{
		if (map[0][i] != '1' || map[data->map_h - 1][i] != '1')
			return (1);
		i++;
	}
	i = 0;
	while (i < data->map_h)
	{
		if (map[i][0] != '1' || map[i][data->map_w - 1] != '1')
			return (1);
		i++;
	}
	return (0);
}

/**
 * @brief Checks if the map is properly borded.
 * This functions splits the map in a widthxheight array.
 * and free it after that.
 * @param data 
 * @return int 
 */
int	ft_surround(t_data *data)
{
	char	**map_s;
	int		flag;

	flag = 0;
	map_s = ft_split(data->map, '\n');
	if (ft_look(map_s, data) == 1)
		flag = 1;
	ft_free_splits(map_s);
	if (flag == 1)
		ft_error(MAP_BORDER);
	return (0);
}

/**
 * @brief Checks if there is at least 1 coin, exactly 1 player 
 * and 1 exit. Stores the number of coins in data.
 * @param data 
 * @return int 
 */
int	ft_check_chars(t_data *data)
{
	int		i;
	int		flags[3];
	char	wd;

	i = 0;
	ft_bzero(flags, sizeof(flags));
	while (data->map[i] != '\0')
	{
		wd = data->map[i];
		if (wd == 'C')
			flags[0]++;
		if (wd == 'P')
			flags[1]++;
		if (wd == 'E')
			flags[2]++;
		if (wd != '0' && wd != '1' && wd != 'C'\
		&& wd != 'E' && wd != 'P' && wd != '\n')
			ft_error(MAP_CHAR);
		i++;
	}
	if (flags[0] < 1 || flags[1] != 1 || flags[2] != 1)
		ft_error(MAP_CHAR2);
	data->coins = flags[0];
	return (0);
}
