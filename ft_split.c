#include "libft.h"

static size_t	ft_count_words(char const *s, char c)
{
  size_t  i;
	size_t  count;

  i = 0;
	count = 0;
	while (s[i])
	{
		while (s[i] && s[i] == c)
			i++;
		if (s[i])
			count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static size_t	ft_word_len(char const *s, char c)
{
  size_t  i;

  i = 0;
	while (s[i] && s[i] != c)
    i++;
	return (i);
}

static void ft_free_strs(char **strs)
{
	size_t	i;

	i = 0;
	while (strs[i])
		free(strs[i++]);
	free(strs);
}

char	**ft_split(char const *s, char c)
{
  size_t  i;
	char    **strs;

	if (s == NULL)
		return (NULL);
	strs = (char **)malloc(sizeof(char *) * (ft_count_words(s, c) + 1));
	if (strs == NULL)
		return (NULL);
	i = 0;
	while (*s)
	{
    while (*s && *s == c)
      s++;
		if (*s != '\0')
  		strs[i++] = ft_substr(s, 0, ft_word_len(s, c));
    if (i > 0 && strs[i - 1] == NULL)
    {
      ft_free_strs(strs);
      return (NULL);
    }
		if (*s != '\0')
    	s = s + ft_word_len(s, c);
	}
  strs[i] = NULL;
	return (strs);
}

// ＜レビューコメント＞
// leakの可能性があるかも
// Freeするべき
// FT_SPLIT_TESTERというsplit専用のテスターがあるので、そちらのテスターもおすすめです
// 途中でmallocに失敗した際に、それまでに確保したメモリをちゃんとfreeする
// malloc -> ft_callocのほうがいい
// dpのmallocに失敗した場合、その前でft_strdupでコピーされた文字列がメモリリークする
// malloc失敗チェックの条件が誤っているので、malloc失敗時にfreeされない
// シングルポインタのmallocが途中で失敗した際のfreeで、無限ループとなるケースがありました
// free仕切れてないです。２次元配列だけでなく、その中身もfreeできるようにしましょう
// int型を使っている時がありましたが、オーバーフローする可能性がありそう
// substr失敗時に, それまでにmallocした領域すべてをfreeする必要がある
// Freeのあとはreturn(NULL)?。。。splitの戻り地がポインタだから
// リークチェックコマンド

// (i > 0 && strs[i - 1] == NULL)することにより、引数が("aaaaa", "a")などに対応
// i == 0の場合、&&のあとの式は確認されますか？
// いいえ、C言語の論理 AND (&&) 演算子は、左側の条件が false（0）の場合、右側の条件を評価しません。つまり、i == 0 の場合、右側の式 strs[i - 1] == NULL は評価されず、条件式全体は false となります。
// 最後のwhileループの中でif(*s != '\0')を展開すると’｛’を含め３行使うため、if (*s != '\0')２回とi++からの[i-1]を使うことで
// なんとか25行に収めることに成功

// if (*s != c)のところ最初にwhileでスキップさせる
// 連結じゃなくコピー上書きだからNULLで初期化なくていいのと、最後にヌルポインタ収納する必要ある

// malloc -> ft_callocのほうがいい
// という意見と
// null文字を埋めなければいけない関数内でのmallocはcallocに置き換えられます
// mallocの代わりにcallocを使用するのは、本来の目的以外のこともやってしまうので避けた方がよいかと思います
// という意見がある

// 本当はft_split内のs++のところもインデックスを使うように統一したかったが、25行制限のため断念...i++を省略してできるかやってみる
// ft_free_strsの戻り値はなにが正解？NULLが返せればなんでもいい？
// void もvoid *も戻り値はない
// ft_split関数内でft_free_strs関数が呼ばれる場合、通常はft_free_strs関数がvoid型を返すと仮定します。なぜなら、ft_free_strs関数はおそらくメモリを解放するためだけに使用されており、新しいデータを生成せず、何も返さないであろうからです。
// 慣習的には、void型にして、別でreturn(NULL)とするのが良さそう

// static void ft_free_strs(char **strs)関数内でreturn NULL;とした場合、コンパイルエラーが発生します。なぜなら、void型の関数は戻り値を持たないため、return文を使用して値を返すことはできません。NULLはポインタ型の特定の値で、void型の関数の戻り値として使用することはできません。
// static void *ft_free_strs(char **strs)関数内でreturn NULL;を使用することは、C言語の慣習に従えば許容されますが、一般的には無意味な操作とされます。なぜなら、この関数はメモリの解放を行うだけで、何らかのポインタを返す必要がないからです。
// 通常、メモリを解放する関数はvoid型の戻り値を持ち、メモリ解放の操作を行いますが、戻り値を返しません。return NULL;を記述しても、呼び出し元のコードには影響を与えません。