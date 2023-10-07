#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
  i = 0;
	while ((i < n - 1) && (s1[i] == s2[i]) && s1[i])
		i++;
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	*s1 = "225";
// 	char	*s2 = "2222";

// 	printf("%d\n", strncmp(s1, s2, 5));
// 	printf("%d\n", ft_strncmp(s1, s2, 5));
// }

// <メモ>
// n == 0だった場合の例外処理を早めに終わらせた
// whileの条件式の中で(s1[i] || s2[i])にするかs1[i]にするかs2[i]にするかは同じ、片方のみにしてスッキリさせた
// 第１引数、第２引数両方がNULLまたは片方でもNULLの場合,本家ではセグフォ(size==0なら関係なく0をリターン)
// ３文字ならインデックス[2]をリターンしないといけないため、n - 1
// 戻り値はint型だが、manページにもとづきunsigned charに一時的キャストする