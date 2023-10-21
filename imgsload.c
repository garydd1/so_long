/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   imgsload.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/15 18:12:27 by dgarizad          #+#    #+#             */
/*   Updated: 2023/04/16 21:48:46 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Auxiliary for draw things. Norminette issues.
 * 
 * @param data 
 * @param i 
 * @param j 
 * @return int 
 */
static int	ft_draw_aux(t_data *data, int i, int j)
{
	while (j < data->map_w)
	{
		if (data->map_s[i][j] == '1')
			mlx_image_to_window(data->mlx, data->img[W], \
			j * SQUARE -1, i * SQUARE -1);
		if (data->map_s[i][j] == 'C')
			mlx_image_to_window(data->mlx, data->img[C], \
			(j * SQUARE -1) + 16, (i * SQUARE -1) + 16);
		if (data->map_s[i][j] == 'E')
			mlx_image_to_window(data->mlx, data->img[E], \
			j * SQUARE -1, i * SQUARE -1);
		if (data->map_s[i][j] == 'P')
			mlx_image_to_window(data->mlx, data->img[P], \
			j * SQUARE -1, i * SQUARE -1);
		j++;
	}
	return (0);
}

/**
 * @brief reads the map array and put the corresponding image to window.
 * 
 * @param data 
 * @return int 
 */
int	ft_draw_things(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_h)
	{	
		j = 0;
		ft_draw_aux(data, i, j);
		i++;
	}
	return (0);
}

int	ft_draw_grass(t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->map_h)
	{	
		j = 0;
		while (j < data->map_w)
		{
			mlx_image_to_window(data->mlx, data->img[G], j * 64 -1, i * 64 -1);
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * @brief loads all textures into images 
 * 
 * @param data 
 * @return int 
 */
int	ft_load_imgs(t_data *data)
{
	data->img[G] = mlx_texture_to_image(data->mlx, \
	&(data->xpm[G]->texture));
	data->img[P] = mlx_texture_to_image(data->mlx, \
	&(data->xpm[P]->texture));
	data->img[W] = mlx_texture_to_image(data->mlx, \
	&(data->xpm[W]->texture));
	data->img[C] = mlx_texture_to_image(data->mlx, \
	&(data->xpm[C]->texture));
	data->img[E] = mlx_texture_to_image(data->mlx, \
	&(data->xpm[E]->texture));
	return (0);
}

/**
 * @brief Loads all xpm images into textures.
 * Also here is done almost all the free things.
 * @param data 
 * @return int 
 */
int	ft_load_sprites(t_data *data)
{
	data->map_s = ft_split(data->map, '\n');
	data->mlx = mlx_init(data->map_w * SQUARE, data->map_h * SQUARE, "G", true);
	data->xpm[G] = mlx_load_xpm42("./textures/grass.xpm42");
	data->xpm[P] = mlx_load_xpm42("./textures/luffyF.xpm42");
	data->xpm[W] = mlx_load_xpm42("./textures/Rocky.xpm42");
	data->xpm[C] = mlx_load_xpm42("./textures/btc.xpm42");
	data->xpm[E] = mlx_load_xpm42("./textures/doorclosed.xpm42");
	ft_load_imgs(data);
	ft_draw_grass(data);
	ft_draw_things(data);
	ft_set_hooks(data);
	mlx_loop_hook(data->mlx, ft_hook, data);
	mlx_loop(data->mlx);
	ft_free_sprites(data);
	ft_free_splits(data->map_s);
	free(data->map);
	mlx_terminate(data->mlx);
	return (0);
}
