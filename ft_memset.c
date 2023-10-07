#include "libft.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)b)[i] = (unsigned char)c;
		i++;
	}
	return (b);
}

// #include <string.h>
// #include <stdio.h>
// int main(){
// 	char sf[] = "0123456789";
// 	printf("%s\n", sf);
// 	ft_memset(sf, 'a', sizeof(unsigned char)*3);
// 	printf("%s\n", sf);
// 	printf("\n");
// 	char so[] = "0123456789";
// 	printf("%s\n", so);
// 	memset(so, 'a', sizeof(unsigned char)*3);
// 	printf("%s\n", so);
// }

//  <レビューコメント>
// キャストは明示的にするべき
// man memsetに従いunsignedへキャスト
// 符号付きから符号無しへの変換を行う場合、符号拡張が発生し、意図しない結果になる可能性があるため、キャストによって符号拡張を防ぎます。

// ＜使い方＞
// 主にメモリブロックを特定の値で埋めるために使用されます。
// void *memset(void *ptr, int value, size_t num);
// ptr: メモリブロックの先頭へのポインタ
// value: 埋めたい値（通常は0から255までの整数値）
// num: 埋めるバイト数
// memset関数は、指定されたメモリブロック（ptrで指定）の先頭から num バイト分を、value で埋めます。これは通常、メモリブロックをクリアしたり、特定の値で初期化したりする際に使用されます。

// <void型ポインタからのキャストについて>
// void*型のポインタは通常のポインタと異なり、その中身の型にアクセスできません。そのため、b[i]のような操作は許可されていません。
// void*を適切な型にキャストします。この場合、bをunsigned char*型にキャストします。
// *(unsigned char *)(s + i):
// この式は、ポインタ s に整数 i を加えたアドレスにあるデータを unsigned char ポインタとしてキャストしてから、それを間接参照して取得します。
// 具体的には、s のアドレスに i バイトを加算して新しいアドレスを計算し、それを unsigned char ポインタにキャストして、そのアドレスに格納されているデータを取得します。
// ((unsigned char *)s)[i]:
// この式は、ポインタ s を unsigned char ポインタにキャストしてから、i 番目の要素を取得します。
// 具体的には、s を unsigned char ポインタにキャストし、そのアドレスから i 番目の要素を取得します。
// どちらの方法を選択するかは、コードの読みやすさや理解しやすさに依存します。両方の方法は同じ結果を得られます。

// <char str[0] = "";:>
// str 配列がサイズ 0 で宣言されています。しかし、C言語ではサイズが 0 の配列は正確には許可されておらず、コンパイラによっては許容されない場合もあります。このような状況では、コードが予測しない動作をする可能性があります。
// memset...NULLのときにsegmentation faultのためif(==NULL)return(NULL)要らない