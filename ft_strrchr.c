#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	size_t	len;

	len = ft_strlen(s) + 1;
	while (len > 0)
	{
		len--;
		if (s[len] == (char)c)
			return ((char *)(&s[len]));
	}
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>
// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }
// int	main(void)
// {
// 	char	*str = "Hello World";
// 	char	*ptr = ft_strrchr(str, 'o');
// 	printf("%s\n", ptr);
// 	char	*str2 = "Hello World";
// 	char	*ptr2 = strrchr(str2, 'o');
// 	printf("%s\n", ptr2);
// }

// <メモ>
// インデックス変数にsize_t型を使う
// s == NULLのとき、本家もセグフォ...だからft_strlen使ってもいい
// +1しているのでs_lenではなくlenを変数名に使う
// わざわざ＋１して、デクリメントとすることで、終端ヌル文字からs[0]までの比較を可能にしている
// ただ+ 1がマジックナンバーになる、、
// while (len--) の条件式において、len がゼロの場合、評価後にデクリメントは行われず、ループが終了します
// つまりlen はマイナスになることはありません