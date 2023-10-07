#include "libft.h"

static size_t	ft_numlen(long nbr)
{
	size_t	i;

	i = 0;
	if (nbr <= 0)
		i++;
	while (nbr != 0)
	{
		nbr = nbr / 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
  size_t	len;
  long    nbr;
	char    *str;
	
	nbr = (long)n;
	len = ft_numlen(nbr);
	str = (char *)malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	str[len] = '\0';
  len--;
	if (nbr == 0)
		str[0] = '0';
	if (nbr < 0)
	{
		str[0] = '-';
		nbr = nbr * (-1);
	}
	while (nbr != 0)
	{
		str[len] = (nbr % 10) + '0';
		nbr = nbr / 10;
		len--;
	}
	return (str);
}

// #include <stdio.h>
// int	main(void)
// {
// 	int	n;

// 	n = -2147483648;
// 	printf("%s", ft_itoa(n));
// 	return (0);
// }

// ＜レビューコメント＞
// mallocしたメモリ領域の最後の文字がNULL文字になっていない
// 引数が0のときのメモリ確保で無駄がある(2だけメモリ確保でOK)
// INT_MINの時に例外処理をしているのがintが32bitである時は問題ないですが、intが32bitでない処理系の時に上手く動かないと思うので、そこが少し気になりました

// ＜メモ＞
// longからintへのキャストはしないよう、ft_numlen(long nbr)の引数もlong
// len--は二箇所とも短縮できるが、可読性と悩む
// (nbr > 0)か(nbr != 0)に統一する,上は(nbr > 0)にするなら手前でマイナスをプラスに変える必要あり