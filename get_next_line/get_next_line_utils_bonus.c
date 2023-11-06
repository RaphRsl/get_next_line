/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:17:52 by rroussel          #+#    #+#             */
/*   Updated: 2022/11/30 17:35:11 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

int	check_if_nl_b(const char *str)
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

char	*ft_join_b(const char *s1, const char *s2)
{
	char	*string;
	int		len;
	int		i;

	len = 0;
	if (!s1 && !s2)
		return (NULL);
	while (s1 && s1[len])
		len++;
	i = 0;
	while (s2 && s2[i])
		i++;
	string = ft_calloc_upd_b(len + i + 1, sizeof(char));
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

char	*ft_strdup_b(const char *s1)
{
	char	*s2;
	int		i;

	if (!s1)
		return (ft_strdup_b(""));
	i = 0;
	while (s1[i])
		i++;
	s2 = ft_calloc_upd_b(i + 1, sizeof(char));
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

void	*ft_calloc_upd_b(size_t count, size_t size)
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

void	free_str_b(char **str, char **s2, char **s3)
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
