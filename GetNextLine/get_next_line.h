#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include "../Libft/includes/libft.h"

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		get_next_line(int fd, char **line);

#endif
