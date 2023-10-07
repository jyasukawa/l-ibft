#include "libft.h"

void	ft_striteri(char *s, void (*f)(unsigned int, char *))
{
	size_t	i;

	if (s == NULL || f == NULL)
		return ;
	i = 0;
	while (s[i])
	{
		f(i, &s[i]);
		i++;
	}
}

// #include <stdio.h>
// void toUpperCase(unsigned int index, char *c)
// {
// 	(void)index;
// 	if (*c >= 'a' && *c <= 'z')
// 			*c = *c - 'a' + 'A';
// }
// int main() {
//     char input[] = "hello";
//     ft_striteri(input, toUpperCase);
//     printf("Modified String: %s\n", input);
// }

// <PDF>
// Function name ft_striteri
// Prototype void ft_striteri(char *s, void (*f)(unsigned int,
// char*));
// Turn in files -
// Parameters s: The string on which to iterate.
// f: The function to apply to each character.
// Return value None
// External functs. None
// Description Applies the function ’f’ on each character of
// the string passed as argument, passing its index
// as first argument. Each character is passed by
// address to ’f’ to be modified if necessary.

// ＜PDF解説＞
// ft_striteri 関数は、与えられた文字列 s の各文字に対して指定された関数 f を適用する関数です。以下に、関数の挙動を解説します：
// 引数 s は対象となる文字列です。
// 引数 f は、各文字に対して適用する関数ポインタです。この関数は2つの引数を受け取ります。第1引数は文字のインデックス（0から始まる）であり、第2引数は対応する文字へのポインタです。この関数を用いて必要に応じて文字を修正できます。
// 関数の主なステップ：
// 文字列 s を順番に走査します。
// 各文字に対して、関数 f が呼び出されます。このとき、文字の位置（インデックス）と文字自体へのポインタが関数 f に渡されます。
// 関数 f が各文字に対して行う処理を実行します。文字列 s が関数 f によって修正される場合、修正が行われます。
// すべての文字を処理したら、関数は終了します。この関数は新しい文字列を返すわけではなく、与えられた文字列 s を直接変更します。
// 注意点：
// 関数 f による修正が必要な場合、与えられた文字列 s は関数内部で変更され、呼び出し元にその変更が反映されます。
// ft_striteri 関数自体は新しい文字列を返しません。そのため、文字列の変更は元の文字列 s に対して行われます。

// ＜メモ、レビューコメント＞
// ft_strmapiのmallocしないバージョンとおもいきや、戻り値や引数の関数の型も異なる
// fがNULLの時の対応をするとなお良い気がします
// 文字列のインデックスがunsigend intなので、文字列の長さがUNSIGNED_MAXを超えている場合に無限ループが生じる