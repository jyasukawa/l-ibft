#include "libft.h"

void	ft_putendl_fd(char *s, int fd)
{
	if (s == NULL)
		return ;
	ft_putstr_fd(s, fd);
	write(fd, "\n", 1);
}

// void	ft_putstr_fd(char *s, int fd)
// {
// 	size_t	i;

// 	if (s == NULL)
// 		return ;
//   i = 0;
// 	while (s[i])
// 	{
// 		write(fd, &s[i], 1);
// 		i++;
// 	}
// }
// int main()
// {
// 	ft_putendl_fd("aaa", 1);
// }