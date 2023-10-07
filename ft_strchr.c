#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char)c)
			return ((char *)(&s[i]));
		i++;
	}
	if ((char)c == '\0')
		return ((char *)(&s[i]));
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	*str = "Hello World";
// 	char	*ptr = ft_strchr(str, 'e');
// 	printf("%s\n", ptr);
// 	char	*str2 = "Hello World";
// 	char	*ptr2 = strchr(str2, 'e');
// 	printf("%s\n", ptr2);
// }

// <メモ>
// インデックス変数にsize_t型を使う
// 戻り値をconst char* から普通のchar*に明示的にキャストしてそろえる
// s == NULLのとき、本家もセグフォ

// ＜アドレスのキャストについて（参照とは別！！！）＞
// (char *)(&s[i]):
// これは、配列 s の i 番目の要素へのポインタを取得し、それを char ポインタにキャストしています。つまり、&s[i] のポインタを char ポインタとして解釈しています。
// (char *)&s[i]:
// こちらは、配列 s の i 番目の要素を char ポインタとして解釈し、そのポインタを取得しています。言い換えれば、s[i] の要素を char ポインタとして扱っています。
// 両方の方法は、s 配列の i 番目の要素にアクセスし、それを char ポインタとして扱うことを意味しています。したがって、一般的な用途ではどちらの方法も同じ結果をもたらします