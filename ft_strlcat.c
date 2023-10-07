#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	d_len;
	size_t	s_len;

	s_len = ft_strlen(src);
	if (dstsize == 0)
		return (s_len);
	d_len = ft_strlen(dst);
	if (d_len >= dstsize)
		return (dstsize + s_len);
  i = 0;
	while (i < (dstsize - d_len - 1) && src[i])
	{
		dst[d_len + i] = src[i];
		i++;
	}
	dst[d_len + i] = '\0';
	return (d_len + s_len);
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
//   strlcat(dst, src, 30);
//   printf("After: %s\n", dst);
//   printf("\n");
//   char src2[50] = "abcdefg";
//   char dst2[50] = "0123";
//   printf("Before: %s\n", dst2);
//   ft_strlcat(dst2, src2, 30);
//   printf("After: %s\n", dst2);
//   return(0);
// }

// ＜レビューコメント＞
// 第１引数がNULLで、size == 0 の場合に本家はstrlen(src)を返す
// ...ft_strlen(dst)でセグフォにならないようにreturnする必要がある
// 第１引数がNULLで、size != 0 の場合に本家はsegfaultする
// ...ft_strlen(dst)のセグフォでいい
// 戻り値に必ずstrlen(src)はふくまれるため、src==NULLならそもそも本家もセグフォ
// strlcpyを使った実装方法もある