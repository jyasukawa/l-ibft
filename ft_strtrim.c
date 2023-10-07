#include "libft.h"

char	*ft_strtrim(char const *s1, char const *set)
{
  size_t  i;
	size_t	len;

	if (s1 == NULL || set == NULL)
		return (NULL);
  i = 0;
	while (s1[i] && ft_strchr(set, (int)s1[i]))
		i++;
  len = ft_strlen(s1);
  if (i == len)
		return (ft_strdup(""));
	while (len != i && ft_strchr(set, (int)s1[len]))
		len--;
	return (ft_substr(&s1[i], 0, (len - i + 1)));
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
// char	*ft_strchr(const char *s, int c)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 	{
// 		if (s[i] == (char)c)
// 			return ((char *)(&s[i]));
// 		i++;
// 	}
// 	if ((char)c == '\0')
// 		return ((char *)(&s[i]));
// 	return (NULL);
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
// char	*ft_substr(char const *s, unsigned int start, size_t len)
// {
// 	size_t	s_len;
// 	char		*sub;

// 	if (s == NULL)
// 		return (NULL);
// 	s_len = ft_strlen((char *)s);
// 	if (s_len <= start)
// 		return (ft_strdup(""));
// 	if (s_len <= len)
// 		len = s_len - start;
// 	sub = (char *)malloc(sizeof(char) * (len + 1));
// 	if (sub == NULL)
// 		return (NULL);
// 	ft_strlcpy(sub, (char *)&s[start], (len + 1));
// 	return (sub);
// }
// int	main(void)
// {
// 	char const	s1[] = "fashfdsafhds";
// 	char const	set[] = "fds";
// 	printf("%s", ft_strtrim(s1, set));
// }

// <PDF>
// Function name ft_strtrim
// Prototype char *ft_strtrim(char const *s1, char const *set);
// Turn in files -
// Parameters s1: The string to be trimmed.
// set: The reference set of characters to trim.
// Return value The trimmed string.
// NULL if the allocation fails.
// External functs. malloc
// Description Allocates (with malloc(3)) and returns a copy of
// ’s1’ with the characters specified in ’set’ removed
// from the beginning and the end of the string.

// ＜PDF解説＞
// ft_strtrim 関数は、指定された文字セット set に含まれる文字を文字列 s1 の先頭と末尾から取り除いた、新しい文字列を生成して返す関数です。この関数は、動的なメモリ確保に malloc を使用します。
// この関数には以下のパラメータがあります：
// s1: トリムする対象の文字列。
// set: トリム対象の文字セット。
// 関数の挙動は以下の通りです：
// s1 の先頭から set に含まれない文字が現れる位置まで移動し、その位置を記録します。これがトリムされた文字列の先頭となります。
// s1 の末尾から set に含まれない文字が現れる位置まで移動し、その位置を記録します。これがトリムされた文字列の末尾となります。
// トリムされた文字列の長さを計算します。
// トリムされた文字列の長さの新しい文字列用にメモリを動的に確保します。
// s1 の先頭から記録した位置から、末尾から記録した位置までの文字列をコピーします。
// 新しい文字列にヌル終端文字 '\0' を追加します。
// 新しい文字列へのポインタを返します。
// メモリの確保に失敗した場合、関数は NULL を返します。生成された新しい文字列を使用した後、通常は free 関数を使用してメモリを解放する必要があります。

// ＜レビューコメント＞
// end-startの計算している箇所で、unsigned型同士で引き算をした結果負の値となり、結果オーバーフローして大きな値が引数に入ってしまう可能性がありました。
// 関数内のエラー処理について、動的に確保された領域の返り値が必要かもしれません
// setがNULLの時にセグフォするので変更したほうがいい
// strchrをつかえるといい
// ft_substrを使っているため、結果の文字列の長さがUNSIGNED_MAXを超える場合、意図したものと異なる文字列が返される可能性があります
// substrの第二引数にsize_tの変数を渡していました
// 新しくメモリを確保しない場合があり、仕様に沿わない
// substrを使用できそうです
// libcには無いLibftオリジナル関数は不正な入力値を入れてもクラッシュしてはいけないとPDFに記載がありますので入力値チェックを実装したほうが良い
// set=NULL で return (s) により double free が起こりそう
// endを0までではなく、startまでdecrimentさせる形にしたほうがよりよい実装になるかと思いました
// setだけがNULLだった場合の処理については、機械採点的にはs1をそのまま返すという実装のほうがよいのかもしれませんが、解釈の余地がある部分だと思いますので、私はOKとさせて頂きます
// 空文字を返す場合は、strdup("")を返したほうがいいかも。空文字がstackメモリ上に置かれているので

// <メモ>
// 最初のs1[len]が終端ヌル文字でもft_strchrはカバーしてくれる
// if (i == len)　この条件式とstartまでのdecrimentで最後の　len - iがマイナスになることはない。
// でも(int)とかにキャストして計算するほうが安全？
// 。。。size_t型変数をintでキャストするのはintの範囲外の数値の際に、値が変わってしまうので避ける方がいい
// substrの第二引数にsize_tの変数を渡し、結果の文字列の長さがUNSIGNED_MAXを超える場合がないよう０を引数として渡す
// endを0までではなく、startまでdecrimentさせる形にしたほうがよりよい実装になるかと思いました
// if (i == len)
// 		return (ft_strdup(""));がないとft_substrは２mallocする
// setだけがNULLだった場合の処理については、機械採点的にはs1をそのまま返すという実装のほうがよいのかもしれませんが、解釈の余地がある部分だと思いますので、私はOKとさせて頂きます
// という意見と
// set=NULL で return (s) により double free が起こりそう
// という意見もある