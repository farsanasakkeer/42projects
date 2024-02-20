/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fvaliyak <fvaliyak@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/29 17:41:52 by fvaliyak          #+#    #+#             */
/*   Updated: 2023/02/14 18:34:48 by fvaliyak         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pushswap.h"

size_t	ft_strlen(const char *s)
{
	int	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	occ(char const *s, char c)
{
	int	count;

	count = 0;
	while (*s)
		if (*(s++) != c)
			if (*s == c || !(*s))
				count++;
	return (count);
}

int	getword(const char *str, int start, int finish, t_stack *top)
{
	char	*word;
	int		i;
	int		j;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	j = ft_atoi(word, top);
	free (word);
	return (j);
}

int	*ft_split(char const *s, char c, t_stack *top)
{
	size_t	i;
	size_t	j;
	int		flag;
	int		*intstr;

	if (!s)
		return (0);
	intstr = malloc(occ(s, c) * sizeof(int));
	if (!intstr)
		return (0);
	i = -1;
	j = 0;
	flag = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && flag < 0)
			flag = i;
		else if ((s[i] == c || !s[i]) && flag >= 0)
		{
			intstr[j] = getword(s, flag, i, top);
			j++;
			flag = -1;
		}
	}
	return (intstr);
}
