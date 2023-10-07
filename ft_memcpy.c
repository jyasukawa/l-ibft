#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	size_t	i;

	if (dst == NULL && src == NULL)
		return (NULL);
  i = 0;
	while (i < n)
	{
		((unsigned char *)dst)[i] = ((const unsigned char *)src)[i];
			i++;
	}
	return (dst);
}

// #include <string.h>
// #include <stdio.h>
// int main(){
//   char src[50] = "abcdefg";
//   char dst[50] = "0123";
//   printf("Before: %s\n", dst);
//   memcpy(dst, src, 30);
//   printf("After: %s\n", dst);
//   printf("\n");
//   char src2[50] = "abcdefg";
//   char dst2[50] = "0123";
//   printf("Before: %s\n", dst2);
//   ft_memcpy(dst2, src2, 30);
//   printf("After: %s\n", dst2);
//   return(0);
// }

// <レビューコメント>
// srcとdstの一方のみがNULLの場合、本家はsegvします。 
// srcのキャストがconst修飾子を忘れている
// 両方NULLのとき、セグフォにならないようにした方が良い（本家ではNULLがかえされる）
//  if (dest == src) return (dest); とすることで、自分自身をコピーするループに入らないことができ、かつ、dest もsrcもNULLだったときの例外処理も2行で住んでいます？？？
// ...If dst and src overlap, behavior is undefined.（manページより）

// ＜dstとsrcが両方NULLのとき＞
// C言語の標準規格において、memcpy 関数の dst と src が両方とも NULL ポインタである場合、挙動は未定義とされています。未定義の挙動は、コンパイラや実行環境によって異なる結果が生じる可能性があり、プログラムの安定性や予測性が損なわれる可能性があります

// ＜dst==srcのとき＞
// memcpy 関数の仕様によれば、dst と src が同じメモリ領域を指している場合、挙動は不定です。つまり、結果が予測できない可能性があります。このような状況は避けるべきです
// memcpy 関数において、dst と src が同じメモリ領域を指している場合、memcpy の挙動は不定です。このため、memcpy 関数の返り値も不定となります。

// ＜memcpyの説明＞
// コピー元とコピー先の指定：memcpy関数は、コピー元とコピー先のメモリブロックへのポインタを受け取ります。つまり、どのメモリブロックからどのメモリブロックにデータをコピーするかを指定できます。
// コピーのサイズ指定：memcpy関数は、コピーするデータのサイズをバイト単位で指定する必要があります。通常、サイズはコピー元のメモリブロックのサイズと一致する必要があります。コピー先のメモリブロックは、コピー元のデータを収容できるだけの十分なサイズを持っている必要があります。
// オーバーラップの許容：memcpyは、コピー元とコピー先のメモリブロックがオーバーラップしている場合、正確なコピーを保証しません。つまり、同じデータをコピー元とコピー先の一部に含む場合、結果が不定になります。このため、オーバーラップが発生しないように注意する必要があります。
// バイト単位のコピー：memcpy関数はバイト単位でデータをコピーします。コピーするデータはバイト列として扱われ、ポインタから指定された位置から連続したバイトがコピーされます。
// 戻り値：memcpy関数は、コピー先のメモリブロックの先頭を指すポインタを返します。通常、戻り値を確認する必要はありません。