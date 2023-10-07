#include "libft.h"

int	ft_toupper(int c)
{
	if (c >= 'a' && c <= 'z')
		return (c - ('a' - 'A'));
	return (c);
}

// #include <ctype.h>
// #include <stdio.h>
// int main(){
// 	printf("%c\n", ft_toupper('a'));
// 	printf("%c\n", toupper('a'));
// }

// ＜メモ＞
// %cフォーマット指定子を使う