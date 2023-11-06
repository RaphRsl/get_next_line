/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rroussel <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 14:29:57 by rroussel          #+#    #+#             */
/*   Updated: 2022/11/30 14:30:03 by rroussel         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void) {
	int fd = open("/mnt/nfs/homes/jopadova/projects/get_next_line/empty.txt", O_RDONLY);
	char *line;
	while ((line = get_next_line(fd)) != 0)
	{
		printf("%s", line);
		free (line);
	}
	close(fd);
    return (0);
}
