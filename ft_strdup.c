#include "libft.h"

char	*ft_strdup(const char *s1)
{
  size_t	s_len;
	char		*dst;

	s_len = ft_strlen(s1);
	dst = (char *)malloc(sizeof(char) * (s_len + 1));
	if (dst == NULL)
  {
    errno = ENOMEM;
		return (NULL);
  }
	ft_strlcpy(dst, s1, (s_len + 1));
	return (dst);
}

// #include <string.h>
// #include <stdio.h>
// int main()
// {
// 	char *s1 = "aaaa";
// 	char *s2 = NULL;

// 	char *d1 = strdup(s1);
// 	char *d2 = ft_strdup(s2);
// 	printf("%s\n", d1);
// 	printf("%s\n", d2);
// 	return (0);
// }

// <メモ>
// s1 == NULLで本家もセグフォ
// memcpyも使用可能だが、自動でヌル止めをしてくれるstrlcpyのほうが安心？
// strncpy()は終端文字￥０までしか転送しないが、
// memcpy()は終端文字￥０を超えて指定のサイズまで転送します。
// strncpy()は残りを￥０で埋めます。
// memcpy()は第2引数で領域外参照が発生して動作不明となります。
// ※このプログラムの例では転送元は8byteしかないのに16byte読み込むので領域外参照のバグとなります。
// memcpyとstrlcpyには、戻り値や強制ヌル止めが異なる