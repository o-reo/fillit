/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   fill.h                                           .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 18:29:35 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/27 16:00:49 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef		FILL_H
# define	FILL_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include "libft.h"

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;
typedef struct		s_tetris
{
	t_point			blocs[4];
}					t_tetris;
t_tetris			**read_tetris(t_tetris **tets, char *filename);
t_tetris			*to_tetris(char **bloc);
void				print_tetris(t_tetris *tet);
int					try_grid(t_tetris **tets, int size);
#endif
