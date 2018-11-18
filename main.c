/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 18:53:22 by akotilie          #+#    #+#             */
/*   Updated: 2018/11/11 18:53:24 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fractol.h"

int		exit_x(void)
{
	exit(1);
}

int		mnp_key(int key, t_f *tf)
{
	mlx_destroy_image(tf->mlx_ptr, tf->img_ptr);
	tf->img_ptr = mlx_new_image(tf->mlx_ptr, 600, 600);
	tf->d = mlx_get_data_addr(tf->img_ptr, &(tf->bpp), &(tf->sl), &(tf->ei));
//	manager(key, tf);
	mlx_put_image_to_window(tf->mlx_ptr, tf->win_ptr, tf->img_ptr, 0, 0);
//	help_text(tf, 0xFFFFFF);
	return (0);
}

void	put_pxl(t_f *tf, int x, int y, int c)
{
	int i;

	i = (tf->sl * y) + x * 4;
	if (c == 0)
		c = (int)0xffffff;
	tf->d[i] = c % 4 * 64;//c;
	tf->d[++i] = c % 8 * 32;//c >> 8;
	tf->d[++i] = c % 16 * 16;// c >> 16;
	tf->d[++i] = 0;
}

void	easy_malderbrot(t_f *tf)
{
	double xa = -2.0;
	double xb = 1.0;
	double ya = -1.5;
	double yb = 1.5;
  
	int maxIt = 255;

	int imgx = 600;
	int imgy = 600;
  
  	int y = -1;
  	int x = -1;
  	int i = -1;
  
  	double zx;
  	double zy;
  	double z;
	double c;

	while (++y < imgy)
	{
    	zy = y * (yb - ya) / (imgy - 1)  + ya;
		while (++x < imgx)
		{
       		zx = x * (xb - xa) / (imgx - 1)  + xa;
       		z = zx + zy;//* 1j;
        	c = z;
			while (++i < maxIt)
			{
            	if (ABS(z) > 2.0)
				 	break ;
            	z = z * z + c;
			}
        	put_pxl(tf, x, y, i);
		}
	}
}

int		main(int argc, char **argv)
{
	t_f		tf;

	tf.mlx_ptr = mlx_init();

	tf.win_ptr = mlx_new_window(tf.mlx_ptr, 600, 600, "fractol");
	tf.img_ptr = mlx_new_image(tf.mlx_ptr, 600, 600);
	tf.d = mlx_get_data_addr(tf.img_ptr, &(tf.bpp), &(tf.sl), &(tf.ei));

	easy_malderbrot(&tf);

	mlx_put_image_to_window(tf.mlx_ptr, tf.win_ptr, tf.img_ptr, 0, 0);
	mlx_loop(tf.mlx_ptr);//
/*	help_text(&tf, 0xFFFFFF);
	mlx_hook(tf.win_ptr, 2, 5, mnp_key, &tf);
	mlx_hook(tf.win_ptr, 17, 1L << 17, exit_x, "fdf");
	mlx_loop(tf.mlx_ptr);
	free_type(&tf);*/
	return (0);
}
