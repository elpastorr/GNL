#include <stdio.h>
#include "get_next_line.h"

int	main(int ac, char **av)
{
	char	*s;
	int	fd = open("empty", O_RDONLY);
	(void)ac;
	while ((s = get_next_line(fd)))
	{
		printf("%s", s);
		free(s);
	}
	close(fd);
	return (0);
}
