/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fractol.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: akotilie <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 18:53:33 by akotilie          #+#    #+#             */
/*   Updated: 2018/11/11 18:53:35 by akotilie         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FRACTOL_H
# define FRACTOL_H
# include <stdlib.h>
# include "libft/libft.h"
# include "mlx.h"
# include <unistd.h>
# include <math.h>

typedef	struct		s_f
{
	void			*mlx_ptr;
	void			*win_ptr;
	void			*img_ptr;
	char			*d; // data
	char			*err; // error message
	int				fn; // fractal name
	int				bpp; // bits per point
	int				sl; // size line
	int				ei; // endian
}					t_f;

int					mlx_key_hook (void *win_ptr, int (*funct_ptr)(),
					void *param);
int					mlx_loop (void *mlx_ptr);
void				*mlx_init();
void				*mlx_new_window(void *mlx_ptr, int size_x, int size_y,
					char *title);
void				*mlx_new_image(void *mlx_ptr, int width, int height);
char				*mlx_get_data_addr(void *img_ptr, int *bits_per_pixel,
					int *size_line, int *endian);
int					mlx_put_image_to_window(void *mlx_ptr, void *win_ptr,
					void *img_ptr, int x, int y);
int					mlx_string_put(void *mlx_ptr, void *win_ptr, int x, int y,
					int color, char *string);
int					mlx_destroy_image(void *mlx_ptr, void *img_ptr);
int					mlx_hook(void *win_ptr, int x_event, int x_mask,
					int (*funct)(), void *param);

#endif
