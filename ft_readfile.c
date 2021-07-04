#include "so_long.h"
#include "./GetNextLine/get_next_line.h"
#include <fcntl.h>

void ft_readfile(char *file)
{
	int		fd;
	int		ret;
	char	*line;

	fd = open(file, O_RDONLY);
	ret = get_next_line(fd, &line);
	ft_printf("Map:\n");
	while (ret > 0)
	{
		ft_printf("%s\n", line);
		free(line);
		ret = get_next_line(fd, &line);
	}
	free(line);
	if (ret == -1)
		ft_printf("Read file error\n");
	close(fd);
}

void ft_getmap(char *file)
{
	ft_readfile(file);
}