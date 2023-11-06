/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 17:00:10 by rroussel          #+#    #+#             */
/*   Updated: 2022/11/30 17:35:06 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	check_if_nl(const char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_join(const char *s1, const char *s2)
{
	char	*string;
	int		len;
	int		i;

	len = 0;
	i = 0;
	if (!s1 && !s2)
		return (NULL);
	while (s1 && s1[len])
		len++;
	while (s2 && s2[i])
		i++;
	string = ft_calloc_upd(len + i + 1, sizeof(char));
	if (!string)
		return (NULL);
	len = -1;
	while (s1 && s1[++len])
		string[len] = s1[len];
	i = -1;
	while (s2 && s2[++i])
		string[len + i] = s2[i];
	return (string);
}

char	*ft_strdup(const char *s1)
{
	char	*s2;
	int		i;

	if (!s1)
		return (ft_strdup(""));
	i = 0;
	while (s1[i])
		i++;
	s2 = ft_calloc_upd(i + 1, sizeof(char));
	if (!s2)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		s2[i] = s1[i];
		i++;
	}
	return (s2);
}

void	*ft_calloc_upd(size_t count, size_t size)
{
	void			*string;
	unsigned char	*adrr;
	size_t			total;

	total = count * size;
	string = malloc(total);
	if (!string)
		return (NULL);
	adrr = (unsigned char *)string;
	while (total != 0)
	{
		*adrr = '\0';
		adrr++;
		total--;
	}
	return (string);
}

void	free_str(char **str, char **s2, char **s3)
{
	if (str && *str)
	{
		free(*str);
		*str = NULL;
	}
	if (s2 && *s2)
	{
		free(*s2);
		*s2 = NULL;
	}
	if (s3 && *s3)
	{
		free(*s3);
		*s3 = NULL;
	}
}
