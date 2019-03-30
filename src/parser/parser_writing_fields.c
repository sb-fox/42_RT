/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_writing_fields.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eloren-l <eloren-l@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/28 18:46:21 by eloren-l          #+#    #+#             */
/*   Updated: 2019/03/30 14:11:24 by eloren-l         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static void	single_num_fields(char ***split, char **num, t_surf *surf)
{
	if (strcmp((*split)[0], "radius") == 0)
		surf->radius = ft_atod(num[0]);
	else if (strcmp((*split)[0], "specular") == 0)
		surf->specular = ft_atod(num[0]);
	else if (strcmp((*split)[0], "reflect") == 0)
		surf->reflect = ft_atod(num[0]);
	else if (strcmp((*split)[0], "transp") == 0)
		surf->transp = ft_atod(num[0]);
	else if (strcmp((*split)[0], "height") == 0)
		surf->max_height = ft_atod(num[0]);
	else if (strcmp((*split)[0], "tip") == 0)
		surf->min_height = ft_atod(num[0]);
	else if (strcmp((*split)[0], "angle") == 0)
		surf->radius = ft_atod(num[0]);
}

static void	triple_num_fields(char ***split, char **num, t_surf *surf)
{
	if (strcmp((*split)[0], "position") == 0)
		surf->position = (t_v){ft_atod(num[0]),
			ft_atod(num[1]), ft_atod(num[2])};
	else if (strcmp((*split)[0], "orientation") == 0)
		surf->orientation = (t_v){ft_atod(num[0]),
			ft_atod(num[1]), ft_atod(num[2])};
	else if (strcmp((*split)[0], "color") == 0)
		surf->color = (t_clr){ft_atoi(num[0]),
			ft_atoi(num[1]), ft_atoi(num[2])};
}

void		write_field(int fd, char ***split, char **line, t_surf *surf)
{
	char	**num;

	num = ft_strsplit((*split)[2], ' ');
	if (check_param_num(num, 1))
		single_num_fields(split, num, surf);
	else if (check_param_num(num, 3))
		triple_num_fields(split, num, surf);
	free_words(num);
	parse_next(fd, split, line);
}
