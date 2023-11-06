/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/29 14:17:08 by rroussel          #+#    #+#             */
/*   Updated: 2022/11/30 17:34:56 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*front_of_nl_b(const char *line)
{
	char	*adrr_to_return;
	int		i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] != '\0' && line[i] == '\n')
		i++;
	adrr_to_return = ft_calloc_upd_b(i + 1, sizeof(char));
	if (!adrr_to_return)
		return (NULL);
	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
	{
		adrr_to_return[i] = line[i];
		i++;
	}
	if (line[i] == '\n')
	{
		adrr_to_return[i] = line[i];
		i++;
	}
	return (adrr_to_return);
}

char	*behind_nl_b(const char *line)
{
	char	*adrr_to_return;
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (line && line[j])
		j++;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] != '\0' && line[i] == '\n')
		i++;
	adrr_to_return = ft_calloc_upd_b((j - i) + 1, sizeof(char));
	if (!adrr_to_return)
		return (NULL);
	j = 0;
	while (line[i + j])
	{
		adrr_to_return[j] = line[i + j];
		j++;
	}
	return (adrr_to_return);
}

void	ft_read_line_b(int fd, char **big_table, char **buffer)
{
	char	*tmp_buf;
	int		nb_bytes_read;

	tmp_buf = (char *)malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tmp_buf)
		return ;
	nb_bytes_read = 1;
	while (nb_bytes_read > 0)
	{
		nb_bytes_read = read(fd, tmp_buf, BUFFER_SIZE);
		if (nb_bytes_read == -1)
		{
			free_str_b(&tmp_buf, big_table, buffer);
			return ;
		}
		tmp_buf[nb_bytes_read] = '\0';
		*buffer = ft_strdup_b(*big_table);
		free_str_b(big_table, 0, 0);
		*big_table = ft_join_b(*buffer, tmp_buf);
		free_str_b(buffer, 0, 0);
		if (check_if_nl_b(*big_table))
			break ;
	}
	free_str_b(&tmp_buf, 0, 0);
}

char	*line_parsing_b(char **big_table, char **buffer)
{
	char	*line;

	*buffer = ft_strdup_b(*big_table);
	free_str_b(big_table, 0, 0);
	*big_table = behind_nl_b(*buffer);
	line = front_of_nl_b(*buffer);
	free_str_b(buffer, 0, 0);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*big_table[FOPEN_MAX];
	char		*buffer;
	char		*line;

	if (fd < 0 || fd >= FOPEN_MAX || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	buffer = NULL;
	ft_read_line_b(fd, &big_table[fd], &buffer);
	if (big_table[fd] != NULL && *big_table[fd] != '\0')
		line = line_parsing_b(&big_table[fd], &buffer);
	if (!line || *line == '\0')
	{
		free_str_b(&big_table[fd], &line, &buffer);
		return (NULL);
	}
	return (line);
}
