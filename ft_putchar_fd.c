#include "libft.h"

void	ft_putchar_fd(char c, int fd)
{
	write(fd, &c, 1);
}

// int main()
// {
// 	ft_putchar_fd('A', 1);
// }

// ＜メモ＞
// ファイルディスクリプタは0からはじまる１がおなじみ標準出力