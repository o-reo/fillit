/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.h                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 16:21:48 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 17:07:56 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# define BUFF_SIZE 5
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <libft.h>
# include <fcntl.h>

int		get_next_line(int const fd, char **line);

#endif
