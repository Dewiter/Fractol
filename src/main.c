/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 14:33:18 by rolevy            #+#    #+#             */
/*   Updated: 2018/02/06 05:52:32 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/header.h"

t_fract				*get_tab(void)
{
	static t_fract	tab[FRACT_MAX] =
	{{"mandelbrot", 10, &mandelbrot, MANDELBROT, MDL_DEFAULT, MDL},
	{"julia", 5, &julia, JULIA, JULIA_DEFAULT, JULIA_QUAD}};

	return (tab);
}

static t_fract		get_fract(char *input)
{
	int				i;
	t_fract			*tab;

	i = 0;
	tab = get_tab();
	while (i < FRACT_MAX)
	{
		if (ft_strlen(tab[i].name) == ft_strlen(input))
		{
			if (ft_strncmp(tab[i].name, input, tab[i].length) == 0)
			{
				get_disptab_void()[FRACTAL_CHOSEN].function(tab[i].name);
				return (tab[i]);
			}
		}
		i++;
	}
	get_disptab_void()[NOT_SUPPORT].function(input);
	exit(EXIT_SUCCESS);
}

int					draw(t_env *env)
{
	t_img			*img;

	env->type = env->fract.fractal;
	get_tab()[env->type].function(env);
	mlx_clear_window(env->mlx, env->win);
	mlx_put_image_to_window(env->mlx, env->win, env->img->img_ptr, 0, 0);
	hook(env);
	return (0);
}

int					main(int ac, char **av)
{
	t_env			*env;
	t_fract			fract;

	if (ac == 2)
	{
		fract = get_fract(av[1]);
		env = create_env(env);
		env->start_col = 0x00ff04;
		env->end_col = 0x24838b;
		env->fract = fract;
		mlx_loop_hook(env->mlx, draw, env);
		mlx_loop(env->mlx);
	}
	ft_putstr(BLUE"["MAG"FRACTOL"BLUE"]");
	ft_putstr(BLUE" [ "RED"✘ "BLUE"]");
	ft_putstr(RED" not enough or too much input given\n");
	return (0);
}
