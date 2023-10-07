#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	size_t	s_len;
	char		*sub;

	if (s == NULL)
		return (NULL);
	s_len = ft_strlen(s);
	if (s_len <= start)
		return (ft_strdup(""));
	if (s_len <= len)
		len = s_len - start;
	sub = (char *)malloc(sizeof(char) * (len + 1));
	if (sub == NULL)
		return (NULL);
	ft_strlcpy(sub, &s[start], (len + 1));
	return (sub);
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
// char	*ft_strdup(const char *s1)
// {
//   size_t	s_len;
// 	char		*dst;

// 	s_len = ft_strlen(s1);
// 	dst = (char *)malloc(sizeof(char) * (s_len + 1));
// 	if (dst == NULL)
//   {
//     errno = ENOMEM;
// 		return (NULL);
//   }
// 	ft_strlcpy(dst, s1, (s_len + 1));
// 	return (dst);
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
// int main(){
//   char src[50] = "abcdefg";
//   char *dst = ft_substr(src, 2, 5);
//   printf("Before: %s\n", src);
//   printf("After: %s\n", dst);
// }

// <PDF>
// Function name ft_substr
// Prototype char *ft_substr(char const *s, unsigned int start,
// size_t len);
// Turn in files -
// Parameters s: The string from which to create the substring.
// start: The start index of the substring in the
// string ’s’.
// len: The maximum length of the substring.
// Return value The substring.
// NULL if the allocation fails.
// External functs. malloc
// Description Allocates (with malloc(3)) and returns a substring
// from the string ’s’.
// The substring begins at index ’start’ and is of
// maximum size ’len’.

// ＜PDF解説＞
// ft_substr 関数は、与えられた文字列 s から新しい部分文字列（substring）を生成して返す関数です。この関数はメモリを動的に確保するために malloc を使用します。
// この関数には以下のパラメータがあります：
// s: 部分文字列を生成する元の文字列。
// start: 部分文字列が元の文字列 s から始まる位置のインデックス。
// len: 部分文字列の最大の長さ。
// 関数の挙動は以下の通りです：
// 引数 s から指定された位置 start から始まる部分文字列を作成します。
// 部分文字列の長さは len で指定された最大長を超えないように制限されます。指定した位置 start から len 文字までの部分文字列を作成します。
// 新しい部分文字列は動的なメモリ領域に確保され、そのアドレスが返されます。
// メモリの確保に失敗した場合、関数は NULL を返します。
// 注意点として、使用後に生成された部分文字列のメモリを解放する責任があります。通常、 free 関数を使用してメモリを解放します。

// <メモ>
// ft_strlenの引数でキャスト必要なし
// manがない関数
// 最初にNULLチェック...ft_strlenやft_strlcpyでセグフォしない
// len == 0はなくても同じ結果になるが、早めに例外処理しておく
// 同様にs_len < startても同じ結果になるが、<= として早めに例外処理しておく
// len >= s_len - start と = を含めるのは下の式と被ってしまうから避ける　 len >= s_lenでも同義だが可読性は落ちる？
// len = s_len - start;とすることで余計なmallocメモリ確保を防ぐ
// 。。。できればunsignedの引き算はしたくなかったが、s_len <= startによってマイナスになることはない
// const char *s ではなく char const *sであることに注意
// 今回は連結ではなくコピー（上書き）だからmallocした領域をヌル文字で初期化しなくていい？
// NULLと空文字列の違いは何ですか？
// NULL」と「空文字列」の違い｜「分かりそう」で「分からない ...
// NULLは、何もない「状態」を指す用語です。 それに対して、空文字列は長さ0の「文字列」です。