/* ************************************************************************** */
/*                                                          LE - /            */
/*                                                              /             */
/*   ft_strcmp.c                                      .::    .:/ .      .::   */
/*                                                 +:+:+   +:    +:  +:+:+    */
/*   By: eruaud <marvin@le-101.fr>                  +:+   +:    +:    +:+     */
/*                                                 #+#   #+    #+    #+#      */
/*   Created: 2017/11/23 09:41:43 by eruaud       #+#   ##    ##    #+#       */
/*   Updated: 2017/11/23 09:41:45 by eruaud      ###    #+. /#+    ###.fr     */
/*                                                         /                  */
/*                                                        /                   */
/* ************************************************************************** */

int		ft_strcmp(const char *s1, const char *s2)
{
	int i;
	int cmp;

	cmp = 0;
	i = 0;
	while (s1[i] && !cmp)
	{
		cmp = ((unsigned char *)s1)[i] - ((unsigned char *)s2)[i];
		i++;
	}
	if (!s1[i] && s2[i])
		return (-(unsigned char)s2[i]);
	return (cmp);
}
