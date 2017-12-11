/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 15:58:24 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/11 18:18:40 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"
#include <string.h>

int			get_new_index(char *str)
{
	int		newline;

	newline = 0;
	while (str[newline] && str[newline] != '\n')
		newline++;
	if (str[newline] != '\n')
		return (-1);
	return (newline);
}

int			get_next_line(int const fd, char **line)
{
	char					buff[BUFF_SIZE + 1];
	static char				*str = NULL;
	int						end;

	if (read(fd, NULL, 0))
		return (-1);
	end = BUFF_SIZE;
	while (end)
	{
		end = read(fd, buff, BUFF_SIZE);
		buff[end] = '\0';
		str = !str ? ft_strdup(buff) : ft_strjoin(str, buff);
		if (get_new_index(str) >= 0)
		{
			*line = ft_strsub(str, 0, get_new_index(str));
			str = ft_strsub(str, get_new_index(str) + 1,
							ft_strlen(str) - get_new_index(str));
			return (1);
		}
		else if (end < BUFF_SIZE && end)
			*line = ft_strdup(str);
		if (get_new_index(str) >= 0 || (end < BUFF_SIZE && end))
			return (1);
	}
	return (0);
}
