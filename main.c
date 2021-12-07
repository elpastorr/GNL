#include <stdio.h>
#include "get_next_line.h"

int	main()
{
	int	i = 43;
	char	*s;
	int	fd = open("ekip.txt", O_RDONLY);
	while (i--)
	{
		s = get_next_line(fd);
		printf("%s", s);
		free(s);
	}
	close(fd);
	return (0);
}
