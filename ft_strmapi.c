#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
  size_t	i;
	char    *str;

  if (s == NULL || f == NULL)
  return (NULL);
  str = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1));
  if (str == NULL)
    return (NULL);
  i = 0;
  while (s[i])
  {
    str[i] = f(i, s[i]);
    i++;
  }
  str[i] = '\0';
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
// char uppercase_char(unsigned int index, char c)
// {
//   (void)index;
//   if (c >= 'a' && c <= 'z') 
//       return c - 'a' + 'A';
//   return c;
// }
// int main() {
//     const char *input = "Hello, world!";
//     char *result = ft_strmapi(input, uppercase_char);
//     printf("Result: %s\n", result);
//     free(result);
//     return 0;
// }

// <PDF>
// Function name ft_strmapi
// Prototype char *ft_strmapi(char const *s, char (*f)(unsigned
// int, char));
// Turn in files -
// Parameters s: The string on which to iterate.
// f: The function to apply to each character.
// Return value The string created from the successive applications
// of ’f’.
// Returns NULL if the allocation fails.
// External functs. malloc
// Description Applies the function ’f’ to each character of the
// string ’s’, and passing its index as first argument
// to create a new string (with malloc(3)) resulting
// from successive applications of ’f’.

// ＜PDF解説＞
// ft_strmapi 関数は、与えられた文字列 s の各文字に対して指定された関数 f を適用し、その結果を新しい文字列として返す関数です。以下に、関数の挙動を解説します：
// 引数 s は対象となる文字列です。
// 引数 f は、各文字に対して適用する関数ポインタです。この関数は2つの引数を受け取ります。第1引数は文字のインデックス（0から始まる）であり、第2引数は対応する文字です。この関数は新しい文字を生成し、その文字を返します。
// 関数の主なステップ：
// 新しい文字列を格納するために必要なメモリ領域を割り当てます。このメモリ割り当てには malloc 関数が使用されます。
// 対象の文字列 s を順番に走査し、各文字に関数 f を適用します。このとき、文字の位置（インデックス）と文字自体が関数 f に渡されます。
// 関数 f が新しい文字を生成し、それを新しい文字列に追加していきます。新しい文字列のサイズは s の元の文字列よりも小さいか等しい場合もあります。
// すべての文字を処理したら、新しい文字列が完成します。そして、その文字列へのポインタが返されます。
// 注意点：
// メモリ割り当てに失敗した場合、関数は NULL を返します。
// 新しい文字列は必要なメモリを確保するため、呼び出し元がこのメモリを解放する責任を負います。

// ＜レビューコメント＞
// 文字列の長さがUNSIGNED_MAXを超えている場合にi++で無限ループが生じないようsize_t
// fがNULLの時の対応をするとなお良い気がします
// if (!s) に!fをつけたほうが安全です
// 文字列のインデックスがunsigend intなので、文字列の長さがUNSIGNED_MAXを超えている場合に無限ループが生じる
// char (*f)(unsigned int, char)がNULLの場合の処理もした方が良いかと思います
// libcには無いLibftオリジナル関数は不正な入力値を入れてもクラッシュしてはいけないとPDFに記載がありますので、入力値チェックを実装したほうが良い
// iはsize_tにしておいた方がいいのではないか