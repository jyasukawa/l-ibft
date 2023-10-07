#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((const unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)(&s[i]));
		i++;
	}
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>
// int	main(void)
// {
// 	char	*str = "Hello World";
// 	char	*ptr = ft_memchr(str, 'e', 3);
// 	printf("%s\n", ptr);
// 	char	*str2 = "Hello World";
// 	char	*ptr2 = memchr(str2, 'e', 3);
// 	printf("%s\n", ptr2);
// }

// <メモ>
// 戻り値は(void *)(s + i)にするか分かれる
// ...その上の行でのキャストを*(unsigned char *)(s + i)ならそうする、とか統一したほうがいい
// strchrと引数の数も異なる