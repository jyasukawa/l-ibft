#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	ft_memset(s, 0, n);
}

// #include <string.h>
// #include <stdio.h>
// void	*ft_memset(void *b, int c, size_t len)
// {
// 	size_t	i;

// 	i = 0;
// 	while (i < len)
// 	{
// 		((unsigned char *)b)[i] = (unsigned char)c;
// 		i++;
// 	}
// 	return (b);
// }
// int main(){
// 	char sf[] = "0123456789";
// 	printf("%s\n", sf);
// 	ft_bzero(sf, sizeof(unsigned char)*3);
// 	printf("%s\n", sf);
// 	printf("\n");
// 	char so[] = "0123456789";
// 	printf("%s\n", so);
// 	bzero(so, sizeof(unsigned char)*3);
// 	printf("%s\n", so);
// }

//  <メモ>
// n == 0, *s == NULLの場合も本家と同じく動いた
 
//  ＜挙動について＞
// ft_bzero 関数は ft_memset 関数を内部で呼び出していますが、その結果の返り値は ft_memset の返り値には影響を与えません。言い換えると、ft_bzero 関数自体の返り値は void です
// bzero 関数（または ft_bzero 関数）に NULL ポインタが引数として渡された場合、通常はプログラムがクラッシュし、実行時エラーが発生します