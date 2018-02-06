/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   header.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/30 16:00:28 by rolevy            #+#    #+#             */
/*   Updated: 2018/02/06 06:12:26 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#ifndef HEADER_H
# define HEADER_H

# include "../import/minilibx/mlx.h"
# include "../import/libft/libft.h"
# include "../import/GNL/get_next_line.h"
# include "key_codes_macos.h"
# include "../import/minilibx/event.h"
# include <stdio.h>
# include <math.h>
# include <stdlib.h>
# include <fcntl.h>
# include <stdint.h>
# include <pthread.h>

/*
***                                 - Macros -
*** --------------------------------- Input Color ------------------------------
*/

# define RED			"\x1B[31m"
# define GREEN			"\x1B[32m"
# define YELLOW			"\x1B[33m"
# define BLUE			"\x1B[34m"
# define MAG			"\x1B[35m"

/*
*** ------------------------------ Render Color --------------------------------
*/

# define BLACK			0, 0, 0, 0
# define WHITE			255, 255, 255, 255

/*
*** ------------------------------ Quadrant ------------------------------------
*/

# define ITER_MAX		100
# define MDL_DEFAULT	{(t_complex){-3.5, -2.0}, (t_complex){3.5, 2.0}}
# define MDL			MDL_DEFAULT
# define JULIA_DEFAULT	{(t_complex){-3.5, -2.0}, (t_complex){3.5, 2.0}}
# define JULIA_QUAD		JULIA_DEFAULT

/*
*** ------------------------------ Screen resulotion ---------------------------
*/

# define WIDTH			1280
# define HEIGHT			720


/*
*** ------------------------------ Mouse ---------------------------------------
*/

# define MOUSE_UNLOCK	0
# define MOUSE_LOCK		1

/*
*** ----------------------------- ZOOM -----------------------------------------
*/

# define ZOOM_P			0.8
# define ZOOM_M			1 / ZOOM_P

/*
***                       - Structures -
*** ------------------------- Image --------------------------------------------
*/

typedef	struct			s_img
{
	void				*img_ptr;
	void				*img_str;
	int					bpp;
	int					endian;
	int					l;
	int					x;
	int					y;
}						t_img;


/*
*** ------------------------- Fratal enum --------------------------------------
*/

typedef enum			e_fract_type
{
	MANDELBROT = 0,
	JULIA,
	FRACT_MAX
}						t_fract_type;

/*
*** ------------------------------ Complex -------------------------------------
*/

typedef	struct			s_pos
{
	int					x;
	int					y;
}						t_pos;

typedef struct			s_complex
{
	double				real;
	double				imaginary;
}						t_complex;

typedef struct			s_delta
{
	double				x;
	double				y;
}						t_delta;

/*
*** ------------------------- Coords fix ---------------------------------------
*/

typedef struct				s_coord
{
	int					x;
	int					y;
}						t_coord;

/*
*** ------------------------------ Quadrant ------------------------------------
*/

typedef struct			s_quadrant
{
	t_complex			origin;
	t_complex			end;
}						t_quadrant;

/*
*** ------------------------------- Fractal ------------------------------------
*/

typedef struct s_env t_env;

typedef struct			s_fract
{
	char				*name;
	int					length;
	int					(*function)(t_env *);
	t_fract_type		fractal;
	t_quadrant			default_quad;
	t_quadrant			quadrant;
	
}						t_fract;
/*
*** ----------------------- Environnement --------------------------------------
*/

typedef struct			s_env
{
	int					height;
	int					width;
	t_fract_type		type;
	void				*mlx;
	void				*win;
	t_img				*img;
	t_complex			mouse_pos;
	t_complex			mouse_lock;
	t_fract				fract;
	char				*arg;
	int					mouse_state;
	int					start_col;
	int					end_col;
}						t_env;




/*
*** ----------------------------- Color ----------------------------------------
*/

typedef struct			s_color
{
	int					r;
	int					g;
	int					b;
	int					a;
	int					color;
}						t_color;

/*
*** ------------------------ Input ---------------------------------------------
*/

typedef	enum			e_key_type
{
	QUIT,
	NEXT,
	KEY_MAX
}						t_key_type;

typedef struct			s_key
{
	int					input;
	int					(*function)();
	t_key_type			type;
}						t_key;

typedef enum			e_mouse_type
{
	ZOOM_MIN,
	ZOOM_PLUS,
	JULIA_SET,
	MOUSE_MAX
}						t_mouse_type;

typedef struct			s_mouse
{
	int 				input;
	int					(*function)(t_env *env, t_complex c);
	t_mouse_type		type;
}						t_mouse;

/*
*** ---------------------------- Display ---------------------------------------
*/

typedef enum			e_display_func
{
	EXIT,
	FRACTAL_CHOSEN,
	NOT_SUPPORT,
	DISPLAY_MAX
}						t_display_func;

typedef struct			s_display_void
{
	void				(*function)(void *);
	t_display_func		type;
}						t_display_void;

typedef enum			e_fract_disp
{
	D_CHANGE,
	D_MOUSE_STATE,
	FRACT_DISP_MAX
}						t_fract_disp;

typedef struct			s_display
{
	void				(*function)(t_env *);
	t_fract_disp		type;
}						t_display;

/*
***                            - FUNCTION -
*** ---------------------------- Fractales -------------------------------------
*/

int						mandelbrot(t_env *env);
int						julia(t_env *env);

/*
*** -------------------------- Creation Functions ------------------------------
*/

t_env					*create_env(t_env *env);
t_img					*create_img(t_env *env, int x, int y);

/*
*** --------------------------- Set Functions ----------------------------------
*/

t_color					set_color(int r, int g, int b, int a);
void					set_pixel(int x, int y, t_img *img, t_color col);

/*
*** --------------------------- Hook Functions ---------------------------------
*/

void        			hook(t_env *env);
int     				hook_keyboard(int input, t_env *env);
int                     hook_mouse(int input, int x, int y, t_env *env);

/*`
*** --------------------------- Quit -------------------------------------------
*/

int						quit();

/*
*** -------------------------- Mouse -------------------------------------------
*/

int						zoom(t_env *env, t_complex c);
int						dezoom(t_env *env, t_complex c);
int                     lock_mouse(t_env *env, t_complex c);
int                     set_mouse_pos(int x, int y, t_env *env);

/*
*** ---------------------------- Keyboard --------------------------------------
*/

int     				next(int input, t_env *env);

/*
*** ------------------------------ Color -------------------------------------- 
*/

int						get_color_argb(char a, char r, char g, char b);
int						interpolate(uint32_t start, uint32_t end, double p);

/*
*** ---------------------------- Display --------------------------------------
*/

void            		exit_fract();
void            		fract_select(void *name);
void            		change(t_env *name);
void            		not_supported(void *name);
void            		mouse_state(t_env *env);

/*
*** --------------------------- Tabs -------------------------------------------
*/

t_fract					*get_tab(void);
int						*get_palette(void);
t_display_void     		*get_disptab_void(void);
t_display				*get_disptab(void);

t_mouse					*get_mouse_tab(void);

#endif
