/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:59:31 by aperis            #+#    #+#             */
/*   Updated: 2022/10/20 20:30:25 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	init_data(t_data *data)
{
	(data)->perpwalldist = 0;
	(data)->hit = 0;
	(data)->mapx = (int)(data)->posx ;
	(data)->mapy = (int)(data)->posy ;
	(data)->movespeed = 0.2;
	(data)->rotspeed = 0.075 * 1.8;
}

void	init_game(t_data *data)
{
	data->rotspeed = 0;
	data->movespeed = 0;
	data->dirx = 0;
	data->diry = 0;
	data->planex = 0;
	data->planey = 0;
	data->camerax = 0;
	data->rayposx = 0;
	data->rayposy = 0;
	data->olddirx = 0;
	data->olddiry = 0;
	data->oldplanex = 0;
	data->oldplaney = 0;
	data->raydirx = 0;
	data->raydiry = 0;
	data->mapx = 0;
	data->mapy = 0;
	data->deltadistx = 0;
	data->deltadisty = 0;
	data->perpwalldist = 0;
	data->sidedistx = 0;
	init_game2(data);
}

void	init_direction(t_data *data)
{
	if (data->pos == 'N')
		data->dirx = -1;
	if (data->pos == 'S')
		data->dirx = 1;
	if (data->pos == 'E')
		data->diry = 1;
	if (data->pos == 'W')
		data->diry = -1;
	if (data->pos == 'N')
		data->planey = 1;
	if (data->pos == 'S')
		data->planey = -1;
	if (data->pos == 'E')
		data->planex = 1;
	if (data->pos == 'W')
		data->planex = -1;
}

void	init_game2(t_data *data)
{
	data->sidedisty = 0;
	data->stepx = 0;
	data->stepy = 0;
	data->hit = 0;
	data->side = 0;
	data->lineheight = 0;
	data->drawstart = 0;
	data->drawend = 0;
	data->rotate_left = 0;
	data->rotate_right = 0;
	data->right = 0;
	data->left = 0;
	data->front = 0;
	data->back = 0;
	data->posx = data->pos_x;
	data->posy = data->pos_y;
	init_direction(data);
}

void	init_path_text(t_data *data)
{
	data->north_path = NULL;
	data->south_path = NULL;
	data->east_path = NULL;
	data->west_path = NULL;
	data->floor_info = NULL;
	data->ceiling_info = NULL;
}
