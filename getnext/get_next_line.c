/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   get_next_line.c                                  .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/29 15:58:24 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/12/27 16:31:15 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

#include "get_next_line.h"

int			get_new_index(char *str, int len)
{
	int		newline;

	if (!str)
		return (-1);
	newline = 0;
	while (len-- && str[newline] != '\n')
		newline++;
	if (str[newline] != '\n')
		return (-1);
	return (newline);
}

int			copy_line(char **ptr)
{
	char	*tmp;

	tmp = ft_strdup(*ptr);
	free(*ptr);
	*ptr = ft_strsub(tmp, get_new_index(tmp, ft_strlen(tmp)) + 1,
			ft_strlen(tmp) - get_new_index(tmp, ft_strlen(tmp)));
	free(tmp);
	return (1);
}

char		*str_merge(char *s1, char *s2)
{
	char	*str;

	str = ft_strjoin(s1, s2);
	free(s1);
	return (str);
}

int			get_next_line(int const fd, char **line)
{
	char					buff[BUFF_SIZE + 1];
	static char				*str = NULL;
	int						end;

	if (read(fd, NULL, 0))
		return (-1);
	while ((end = read(fd, buff, BUFF_SIZE)))
	{
		buff[end] = '\0';
		str = !str ? ft_strdup(buff) : str_merge(str, buff);
		if (get_new_index(str, ft_strlen(str)) >= 0)
		{
			*line = ft_strsub(str, 0, get_new_index(str, ft_strlen(str)));
			return (copy_line(&str));
		}
	}
	if (str && ft_strlen(str) > 0 && !end)
	{
		*line = ft_strdup(str);
		str = NULL;
		return (1);
	}
	return (0);
}
