/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kcetin <kcetin@student.42istanbul.com.t    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/14 13:33:44 by kcetin            #+#    #+#             */
/*   Updated: 2022/02/03 10:52:56 by kcetin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*move_line(char *s)
{
	char	*dest;

	dest = ft_strchr(s, '\n');
	if (!dest)
	{
		free(s);
		return (NULL);
	}
	if (*(dest + 1))
		dest = ft_strdup(dest + 1);
	else
		dest = NULL;
	free(s);
	return (dest);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*dest;
	char		buffer[BUFFER_SIZE + 1];
	int			size;

	size = read(fd, buffer, BUFFER_SIZE);
	if (size == -1)
		return (NULL);
	buffer[size] = 0;
	while (size > 0)
	{
		if (!s)
			s = ft_strdup(buffer);
		else
			s = ft_strjoin(s, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
		size = read(fd, buffer, BUFFER_SIZE);
		buffer[size] = 0;
	}
	dest = ft_substr(s, 0, ft_strchr(s, '\n') - s + 1);
	s = move_line(s);
	return (dest);
}

/*
#include "get_next_line.h"
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

int main()
{
    int fd1 = open("test.txt", O_RDONLY);


    int i = 1;
    char *nl;
    nl = get_next_line(fd1);
    
    while (i < 10)
    {
        nl = get_next_line(fd1);
        printf("%s", nl);
        i++;
    }
    close (fd1);
}
*/