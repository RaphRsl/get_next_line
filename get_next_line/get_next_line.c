/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:59:32 by rroussel          #+#    #+#             */
/*   Updated: 2022/11/30 17:34:45 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*front_of_nl(const char *line)
{
	char	*adrr_to_return;
	int		i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	if (line[i] != '\0' && line[i] == '\n')
		i++;
	adrr_to_return = ft_calloc_upd(i + 1, sizeof(char));
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

char	*behind_nl(const char *line)
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
	adrr_to_return = ft_calloc_upd((j - i) + 1, sizeof(char));
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

void	ft_read_line(int fd, char **big_table, char **buffer)
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
			free_str(&tmp_buf, big_table, buffer);
			return ;
		}
		tmp_buf[nb_bytes_read] = '\0';
		*buffer = ft_strdup(*big_table);
		free_str(big_table, 0, 0);
		*big_table = ft_join(*buffer, tmp_buf);
		free_str(buffer, 0, 0);
		if (check_if_nl(*big_table))
			break ;
	}
	free_str(&tmp_buf, 0, 0);
}

char	*line_parsing(char **big_table, char **buffer)
{
	char	*line;

	*buffer = ft_strdup(*big_table);
	free_str(big_table, 0, 0);
	*big_table = behind_nl(*buffer);
	line = front_of_nl(*buffer);
	free_str(buffer, 0, 0);
	return (line);
}

char	*get_next_line(int fd)
{
	static char	*big_table = NULL;
	char		*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	line = NULL;
	buffer = NULL;
	ft_read_line(fd, &big_table, &buffer);
	if (big_table != NULL && *big_table != '\0')
		line = line_parsing(&big_table, &buffer);
	if (!line || *line == '\0')
	{
		free_str(&big_table, &line, &buffer);
		return (NULL);
	}
	return (line);
}
