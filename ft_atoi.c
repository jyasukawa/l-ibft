#include "libft.h"

static void ft_skip(const char **str, int *sign, size_t *i)
{
	while (((*str)[*i] >= 9 && (*str)[*i] <= 13) || (*str)[*i] == 32)
			(*i)++;
	if ((*str)[*i] == '-' || (*str)[*i] == '+')
	{
			if ((*str)[*i] == '-')
					*sign = -1;
			(*i)++;
	}
}

static int ft_isoverflow(long long nbr, unsigned int digit, int sign)
{
	if (sign < 0)
			return ((LONG_MIN + digit) / 10 > (-1) * nbr);
	if (sign > 0)
			return ((LONG_MAX - digit) / 10 < nbr);
	return (0);
}

int ft_atoi(const char *str)
{
	size_t		i;
	long long	nbr;
	int				sign;

	i = 0;
	nbr = 0;
	sign = 1;
	ft_skip(&str, &sign, &i);
	while (str[i] >= '0' && str[i] <= '9')
	{
		if (ft_isoverflow(nbr, (str[i] - '0'), sign))
		{
			if (sign == 1)
					return (-1);
			return (0);
		}
		nbr = (10 * nbr) + (str[i] - '0');
		i++;
	}
	return ((int)(sign * nbr));
}

// #include <stdio.h>
// int main()
// {
// 	int a = atoi("   -92233720368547526");
// 	printf("%d\n", a);
// 	int b = ft_atoi("   -92233720368547526");
// 	printf("%d\n", b);
// }

// <メモ>
// ft_atoi long型で宣言されてましたが、32bitですと4バイトになってしまうのでlong long 型の宣言の方が良いかと思いました 
// digit を long 型にすることも可能ですが、不必要に大きなデータ型を使用することはリソースの無駄です。digit は0から9の範囲しか取り得ないので、通常は unsigned int が適切です。
// atoiは+-が複数、または符号のあとにスペースがあると０
// int最大小値をこえると、longの最大小値をこえるまでループ

// ＜３２ビット＞
// ft_atoi 関数は、与えられた文字列を整数に変換するための関数です。通常、整数のデータ型には int が使用されますが、この関数では long 型が使われています。ただし、long 型のサイズは環境によって異なり、32ビットシステムでは通常4バイトです。したがって、long 型は32ビット環境では十分に大きな整数値を表現するのに十分ではない場合があります。
// したがって、特に大きな整数値を正確に処理する必要がある場合や、int 型では表現できない整数値を処理する場合には、代わりに long long 型を使用することが推奨されます。long long 型は64ビット環境でも8バイトのサイズで整数を表現でき、非常に大きな整数値も正確に処理できます。
// したがって、この関数が long long 型で宣言される場合、より大きな整数値を扱うことができるようになり、整数オーバーフローやアンダーフローのリスクを減らすことができます。ただし、適切なデータ型を選択する際には、プログラムが動作する環境や必要な精度に応じて選択する必要があります。