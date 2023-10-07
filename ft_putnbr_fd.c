#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	nbr;

	nbr = (long)n;
	if (nbr < 0)
	{
		write(fd, "-", 1);
    nbr = nbr * (-1);
	}
	if (nbr > 9)
		ft_putnbr_fd(nbr / 10, fd);
	ft_putchar_fd((nbr % 10 + '0'), fd);
}

// void	ft_putchar_fd(char c, int fd)
// {
// 	write(fd, &c, 1);
// }
// int main()
// {
// 	int n = -25455;
// 	ft_putnbr_fd(n, 1);
// }

// ＜レビューコメント＞
// INT_MINの時に例外処理をしているのがintが32bitである時は問題ないですが、intが32bitでない処理系の時に上手く動かないと思うので、そこが少し気になりました
// 引っかかっている人が割と多いのですが、この関数では標準関数がwriteしか許可されておらず、コード内で標準関数mallocを含むft_itoaを使ってしまっているため、「Forbidden function」となってしまいます
// itoa の失敗を確認したほうがいいかもしれない