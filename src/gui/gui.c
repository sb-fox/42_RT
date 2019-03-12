/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gui.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloren-l <eloren-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/01 15:21:02 by sb_fox            #+#    #+#             */
/*   Updated: 2019/03/08 16:21:21 by eloren-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/rt.h"

/*
**	Draws whole GUI content on screen by putting appropriate mlx images.
*/

void			draw_gui(t_env *e)
{
	int	i;

	if (e->need_regui == 1)
	{
		i = -1;
		mlx_put_image_to_window(e->mlx.mlx_ptr, e->mlx.win_ptr, e->gui->pt_back_img, WIN_W, 0);
		while (++i < GUI_BT_NUM)
		{
			if (e->buttons[i]->state == 1)
				e->buttons[i]->ptimg = e->imgarr[2 * i + 1]->ptimg;
			else
				e->buttons[i]->ptimg = e->imgarr[2 * i]->ptimg;
			mlx_put_image_to_window(e->mlx.mlx_ptr, e->mlx.win_ptr, e->buttons[i]->ptimg,
								e->buttons[i]->pos.x, e->buttons[i]->pos.y);
		}
		draw_object_info(WIN_W, 0, e);
		e->need_regui = 0;
	}
}

/*
**	TODO:
**	1)	Rethink the way redraw/rerender uses. Or not. At least some checks
			should be done to avoid duplicate render()/draw_gui() calls.
**	2)	Depth changing buttons, rotations control switch.
*/
