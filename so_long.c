/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dgarizad <dgarizad@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/09 16:21:27 by dgarizad          #+#    #+#             */
/*   Updated: 2023/04/16 21:50:30 by dgarizad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <string.h>

// void	lseaks(void)
// {
// 	system("leaks -fullContent so_long");
// }
int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		ft_error(INPUT_NBR);
	ft_memset(&data, '\0', sizeof(data));
	ft_map_check(argc, argv, &data);
	ft_load_sprites(&data);
	return (0);
}
	// atexit(lseaks);