#include "libft.h"

void	ft_putstr_fd(char *s, int fd)
{
	size_t	i;

	if (s == NULL)
		return ;
  i = 0;
	while (s[i])
	{
		write(fd, &s[i], 1);
		i++;
	}
}

// int main()
// {
// 	ft_putstr_fd("aaa", 1);
// }

// ＜メモ＞
// 戻り値がvoidつまりなにも返さないため、コードを極限まで短くすれば２行
// void	ft_putstr_fd(char *s, int fd)
// {
// 	if (s)
// 		write(fd, s, ft_strlen(s));
// }
// しかし、ft_strlenを呼び出し、かつその中でwhileループしている