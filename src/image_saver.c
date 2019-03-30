/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image_saver.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fdibbert <fdibbert@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/30 19:38:25 by fdibbert          #+#    #+#             */
/*   Updated: 2019/03/30 20:34:24 by fdibbert         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "rt.h"

static char	*return_null(void)
{
	char *str;

	str = malloc(sizeof(char) * 2);
	str[0] = '0';
	str[1] = '\0';
	return (str);
}

char		*itoa_fd(int color)
{
	int		i;
	int		check;
	char	*str;

	i = 0;
	if (color == 0)
		return (return_null());
	check = color;
	while (check)
	{
		check /= 10;
		i++;
	}
	str = malloc(sizeof(char) * i + 1);
	str[i] = '\0';
	while (color)
	{
		i--;
		str[i] = color % 10 + 48;
		color /= 10;
	}
	return (str);
}

void		init_ppm(int *fd)
{
	char *str;

	*fd = open("screenshot.ppm", O_RDWR | O_CREAT);
	if (*fd == -1)
		exit(0);
	write(*fd, "P3\n", 3);
	str = itoa_fd(WIN_H);
	ft_putstr_fd(str, *fd);
	free(str);
	write(*fd, " ", 1);
	str = itoa_fd(WIN_W);
	ft_putstr_fd(str, *fd);
	free(str);
	write(*fd, "\n255\n", 5);
}

void		save_image(int *mass, int iter)
{
	unsigned char	color[3];
	int				x;
	int				y;
	int				fd;
	char			*str;

	init_ppm(&fd);
	y = -1;
	while (++y < WIN_H)
	{
		x = -1;
		while (++x < WIN_W)
		{
			color[0] = (mass[x + y * WIN_H] >> 16) & 0xFF;
			color[1] = mass[x + y * WIN_H] & 0xFF;
			color[2] = (mass[x + y * WIN_H] >> 8) & 0xFF;
			iter = -1;
			while (++iter < 3)
			{
				str = itoa_fd(color[iter]);
				ft_putstr_fd(str, fd);
				free(str);
				write(fd, " ", 1);
			}
		}
		write(fd, "\n", 1);
	}
	close(fd);
}