/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 19:28:22 by dgarizad          #+#    #+#             */
/*   Updated: 2023/04/16 21:48:50 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

/**
 * @brief Keeps track of the picked coins.
 * if the player is at an unpicked coin spot, does the work. 
 * @param data 
 * @return int 
 */
int	ft_pick_coin(t_data *data)
{
	int	i;
	int	j;
	int	coin_inst;

	i = 0;
	coin_inst = -1;
	while (i < data->map_h)
	{
		j = 0;
		while (j < data->map_w)
		{
			if (data->map_s[i][j] == 'C')
				coin_inst++;
			if (data->playerx == j && data->playery == i \
			&& data->img[C]->instances[coin_inst].z != -1)
			{
				data->coins--;
				mlx_set_instance_depth(&data->img[C]->instances[coin_inst], -1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

/**
 * @brief main hook checks if the game is able to be succeed!
 * 
 * @param param 
 */
void	ft_hook(void *param)
{
	t_data	*data;

	data = param;
	if (mlx_is_key_down(data->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(data->mlx);
	if (data->map_s[data->playery][data->playerx] == 'C')
		ft_pick_coin(data);
	if (data->map_s[data->playery][data->playerx] == 'E' && data->coins == 0)
		mlx_close_window(data->mlx);
}

static void	ft_steps(t_data *data)
{
	(data->steps)++;
	ft_putstr_fd("\nSteps:", 1);
	ft_putnbr_fd(data->steps, 1);
}

/**
 * @brief Hook for the keyboard.
 * 
 * @param keydata 
 * @param param 
 */
void	ft_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	data->f = 0;
	ft_movement_calc(data, keydata);
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS \
	&& data->f == 1)
		data->img[P]->instances[0].x += SQUARE;
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS \
	&& data->f == 1)
		data->img[P]->instances[0].x -= SQUARE;
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS \
	&& data->f == 1)
		data->img[P]->instances[0].y -= SQUARE;
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS \
	&& data->f == 1)
		data->img[P]->instances[0].y += SQUARE;
	if (data->f == 1)
		ft_steps(data);
}

/**
 * @brief Here you can place any mlx library hook function.
 * 
 * @param data 
 */
void	ft_set_hooks(t_data *data)
{
	mlx_key_hook(data->mlx, &ft_keyhook, data);
}
