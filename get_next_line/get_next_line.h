/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <rroussel@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/22 16:58:06 by rroussel          #+#    #+#             */
/*   Updated: 2022/11/30 17:35:00 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stddef.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 100
# endif

char	*get_next_line(int fd);
char	*line_parsing(char **big_table, char **buffer);
void	ft_read_line(int fd, char **big_table, char **buffer);
char	*behind_nl(const char *line);
char	*front_of_nl(const char *line);
void	free_str(char **str, char **s2, char **s3);
void	*ft_calloc_upd(size_t count, size_t size);
char	*ft_strdup(const char *s1);
char	*ft_join(const char *s1, const char *s2);
int		check_if_nl(const char *str);

#endif