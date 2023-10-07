#include "libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	s_len;

	s_len = ft_strlen(src);
	if (dstsize == 0)
		return (s_len);
	i = 0;
	while (i < (dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (s_len);
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
// int main(){
//   char src[50] = "abcdefg";
//   char dst[50] = "0123";
//   printf("Before: %s\n", dst);
//   strlcpy(dst, src, 30);
//   printf("After: %s\n", dst);
//   printf("\n");
//   char src2[50] = "abcdefg";
//   char dst2[50] = "0123";
//   printf("Before: %s\n", dst2);
//   ft_strlcpy(dst2, src2, 30);
//   printf("After: %s\n", dst2);
//   return(0);
// }

// <レビューコメント>
// dstの終端でコピーが終わっていました。whileの条件式 && dst[i]を無くすと本家の関数と同じ挙動を示します
// 本家はdst,srcどちらか片方、または両方=NULLでセグフォ。そのため、ft_strlenを呼び出す際にNULLチェックしなくて大丈夫、セグフォするべき

// ＜memcpyとの違い＞
// 戻り値や、引数のデータ型、ヌル文字でもコピーを続けるか、などがある