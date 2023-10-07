#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t  s1_len;
	size_t  s2_len;
  char    *str;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	s1_len = ft_strlen(s1);
	s2_len = ft_strlen(s2);
	str = (char *)malloc(sizeof(char) * (s1_len + s2_len + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, (s1_len + 1));
	ft_strlcpy(&str[s1_len], s2, (s2_len + 1));
	return (str);
}

// #include <stdio.h>
// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }
// size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
// {
// 	size_t	i;
// 	size_t	s_len;

// 	s_len = ft_strlen(src);
// 	if (dstsize == 0)
// 		return (s_len);
// 	i = 0;
// 	while (i < (dstsize - 1) && src[i])
// 	{
// 		dst[i] = src[i];
// 		i++;
// 	}
// 	dst[i] = '\0';
// 	return (s_len);
// }
// int main()
// {
// 	char str1[] = "Welcome to ";
// 	char str2[] = "the world of 42";
// 	printf("The string is : %s\n", ft_strjoin(str1, str2));
// }

// <PDF>
// Function name ft_strjoin
// Prototype char *ft_strjoin(char const *s1, char const *s2);
// Turn in files -
// Parameters s1: The prefix string.
// s2: The suffix string.
// Return value The new string.
// NULL if the allocation fails.
// External functs. malloc
// Description Allocates (with malloc(3)) and returns a new
// string, which is the result of the concatenation
// of ’s1’ and ’s2’.

// ＜PDF解説＞
// ft_strjoin 関数は、2つの文字列 s1 と s2 を連結して新しい文字列を生成し、その新しい文字列へのポインタを返す関数です。この関数は、動的なメモリ確保に malloc を使用します。
// この関数には以下のパラメータがあります：
// s1: 接頭辞（prefix）として使用される文字列。
// s2: 接尾辞（suffix）として使用される文字列。
// 関数の挙動は以下の通りです：
// s1 と s2 の両方の文字列の長さを計算します。
// 両方の文字列の長さを合計した長さの新しい文字列用にメモリを動的に確保します。
// s1 の内容を新しい文字列にコピーし、その後に s2 の内容をコピーします。
// 新しい文字列の最後にはヌル終端文字 '\0' が追加されます。
// 新しい文字列へのポインタが返されます。
// メモリの確保に失敗した場合、関数は NULL を返します。生成された新しい文字列を使用した後、通常は free 関数を使用してメモリを解放する必要があります。