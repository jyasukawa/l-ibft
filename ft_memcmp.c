#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	if (n == 0)
		return (0);
  i = 0;
	while (i < (n - 1) && (((unsigned char *)s1)[i] == ((unsigned char *)s2)[i]))
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}

// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	*s1 = "dfsd";
// 	char	*s2 = "dfsg";

// 	printf("%d\n", memcmp(s1, s2, 4));
// 	printf("%d\n", ft_memcmp(s1, s2, 4));
// }

// <メモ>
// 関数実装の構成はstrncmpとほとんど同じくした。ヌル文字で止まらないのは違い
// 第１引数、第２引数が両方NULLの場合に本家は0をリターン？？
// ...正確に定義されていないし実際セグフォしてる

// ＜memcmpのstrncmpとの違いについて＞
// memcmp関数は、2つのバイト列をバイト単位で比較するための関数です。文字列のNUL終端文字列には依存しません。
// この関数は、指定された長さ（n）だけバイト列を比較します。したがって、バイト列の比較に使用され、文字列として扱うことはありません。
// memcmp関数は、2つのバイト列が等しい場合には0を返し、異なる場合には等しいバイトの位置で最初に異なるバイトの値を基準に負の値または正の値を返します。