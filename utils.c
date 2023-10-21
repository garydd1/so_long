/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/16 14:10:59 by dgarizad          #+#    #+#             */
/*   Updated: 2023/04/16 21:47:02 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_error(char *err)
{
	ft_putstr_fd(err, 2);
	exit(-1);
}

int	ft_free_sprites(t_data *data)
{
	int	i;

	i = 0;
	while (i < SPRITES_COUNT)
	{
		free(data->xpm[i]);
		free(data->xpm[i]->texture.pixels);
		i++;
	}
	return (0);
}

/**
 * @brief pops the first node of the queue.
 * 
 * @param queue 
 * @return t_queue* 
 */
t_queue	*ft_mary_poppins(t_queue *queue)
{
	t_queue	*aux;

	aux = queue->next;
	queue->next = queue->next->next;
	aux->next = NULL;
	return (aux);
}

int	ft_movement_calc(t_data *data, mlx_key_data_t keydata)
{
	if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS && \
	data->map_s[data->playery][data->playerx + 1] != '1')
	{
		data->f = 1;
		data->playerx += 1;
	}
	if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS && \
	data->map_s[data->playery][data->playerx - 1] != '1')
	{
		data->f = 1;
		data->playerx -= 1;
	}
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS && \
	data->map_s[data->playery - 1][data->playerx] != '1')
	{
		data->f = 1;
		data->playery -= 1;
	}
	if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS && \
	data->map_s[data->playery + 1][data->playerx] != '1')
	{
		data->f = 1;
		data->playery += 1;
	}
	return (0);
}
