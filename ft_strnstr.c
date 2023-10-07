#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	i;
	size_t	n_len;

	if (needle[0] == '\0')
		return ((char *)haystack);
	if (len == 0)
		return (NULL);
	n_len = ft_strlen(needle);
  i = 0;
	while (haystack[i] && (n_len + i) <= len)
	{
		if (ft_strncmp((&haystack[i]), needle, n_len) == 0)
			return ((char *)(&haystack[i]));
		i++;
	}
	return (NULL);
}

// #include <string.h>
// #include <stdio.h>
// size_t	ft_strlen(const char *s)
// {
// 	size_t	i;

// 	i = 0;
// 	while (s[i])
// 		i++;
// 	return (i);
// }
// int	ft_strncmp(const char *s1, const char *s2, size_t n)
// {
// 	size_t	i;

// 	if (n == 0)
// 		return (0);
//   i = 0;
// 	while ((i < n - 1) && (s1[i] == s2[i]) && s1[i])
// 		i++;
// 	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
// }
// int	main(void)
// {
// 	char	*haystack = NULL;
// 	char	*needle = "fake";
// 	size_t	len = 3;
// 	printf("%s\n", ft_strnstr(haystack, needle, len));
// 	printf("%s\n", strnstr(haystack, needle, len));
// 	return (0);
// }

// <メモ>
// (haystack[i] && (n_len + i) <= len)を((n_len + i) <= len && haystack[i])してしまうと、
// 引数が(NULL, "fake", 3)のときに本家はセグフォするのにNULLが返されてしまう
// 引数１のみ'\0' ...NULL
// 引数１ が NULL かつ len = 0 の時...NULL
// ("hello", "hello", 1) ...NULL
// 片方のみまたは両方NULL...セグフォ（len == 0)の場合を除く