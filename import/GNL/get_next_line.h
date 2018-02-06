/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rolevy <rolevy@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/13 17:22:36 by mbeilles          #+#    #+#             */
/*   Updated: 2017/10/06 13:31:57 by rolevy           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# define BUFF_SIZE 32

# include <string.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "../libft/libft.h"

typedef struct	s_fd_buffer
{
	char				*buff;
	int					fd;
	int					j;
	struct s_fd_buffer	*next;
}				t_fd_buffer;

int				get_next_line(int fd, char **line);

#endif
