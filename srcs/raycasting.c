/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycasting.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aperis <aperis@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/12 18:48:40 by aperis            #+#    #+#             */
/*   Updated: 2022/10/16 13:58:35 by aperis           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../cub.h"

void	ft_init_raycast(t_data **data)
{
	if ((*data)->raydiry == 0)
		(*data)->deltadistx = 0;
	else if ((*data)->raydirx == 0)
		(*data)->deltadistx = 1;
	else
		(*data)->deltadistx = sqrt(1 + ((*data)->raydiry
					* (*data)->raydiry) / ((*data)->raydirx
					* (*data)->raydirx));
	if ((*data)->raydirx == 0)
		(*data)->deltadisty = 0;
	else if ((*data)->raydiry == 0)
		(*data)->deltadisty = 1;
	else
		(*data)->deltadisty = sqrt(1 + ((*data)->raydirx
					* (*data)->raydirx) / ((*data)->raydiry
					* (*data)->raydiry));
}

void	init_step_and_sidedist(t_data **data)
{
	if ((*data)->raydirx < 0)
	{
		(*data)->stepx = -1;
		(*data)->sidedistx = ((*data)->rayposx
				- (*data)->mapx) * (*data)->deltadistx;
	}
	else
	{
		(*data)->stepx = 1;
		(*data)->sidedistx = ((*data)->mapx + 1.0
				- (*data)->rayposx) * (*data)->deltadistx;
	}
	if ((*data)->raydiry < 0)
	{
		(*data)->stepy = -1;
		(*data)->sidedisty = ((*data)->rayposy
				- (*data)->mapy) * (*data)->deltadisty;
	}
	else
	{
		(*data)->stepy = 1;
		(*data)->sidedisty = ((*data)->mapy + 1.0
				- (*data)->rayposy) * (*data)->deltadisty;
	}
}

void	touch_wall(t_data **data)
{
	while ((*data)->hit == 0)
	{
		if ((*data)->sidedistx < (*data)->sidedisty)
		{
			(*data)->sidedistx += (*data)->deltadistx;
			(*data)->mapx += (*data)->stepx;
			(*data)->side = 0;
		}
		else
		{
			(*data)->sidedisty += (*data)->deltadisty;
			(*data)->mapy += (*data)->stepy;
			(*data)->side = 1;
		}
		if ((*data)->map[(*data)->mapx][(*data)->mapy] == '1')
			(*data)->hit = 1;
	}
}

void	find_wall(t_data **data)
{
	touch_wall(data);
	if ((*data)->side == 0)
		(*data)->perpwalldist = ((*data)->mapx - (*data)->rayposx
				+ (1 - (*data)->stepx) / 2) / (*data)->raydirx;
	else
		(*data)->perpwalldist = ((*data)->mapy - (*data)->rayposy
				+ (1 - (*data)->stepy) / 2) / (*data)->raydiry;
	(*data)->lineheight = (int)(HEIGHTSCREEN / (*data)->perpwalldist);
	(*data)->drawstart = -((*data)->lineheight) / 2 + HEIGHTSCREEN / 2;
	if ((*data)->drawstart < 0)
		(*data)->drawstart = 0;
	(*data)->drawend = (*data)->lineheight / 2 + HEIGHTSCREEN / 2;
	if ((*data)->drawend >= HEIGHTSCREEN)
		(*data)->drawend = HEIGHTSCREEN - 1;
}