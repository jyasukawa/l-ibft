#include "libft.h"

t_list	*ft_lstnew(void *content)
{
	t_list	*new;

	new = (t_list *)malloc(sizeof(t_list));
	if (new == NULL)
		return (NULL);
	new->content = content;
	new->next = NULL;
	return (new);
}

// #include <stdio.h>
// int main()
// {
//     int *content = (int *)malloc(sizeof(int));
//     if (content == NULL)
//         return 1;
//     *content = 4246363;
//     t_list *new = ft_lstnew(content);
//     if (new != NULL)
// 			printf("Content: %d\n", *(int *)new->content);
//     else
// 			printf("new creation failed\n");
//     free(content);
//     free(new);
// }

// ＜テスト関数解説＞
// (int *)new->content は new->content の型を int* にキャストしています。これにより、content メンバが指すデータを int 型として解釈します。
// 通常、このデータは void* 型として格納されており、何らかの型（この場合は int 型）にキャストする必要があります。
// *(int *)new->content は、new->content のポインタを解除し、int 型のデータにアクセスします。これにより、new->content が指す int 型データの値が取得されます。

// <PDF>
// Function name ft_lstnew
// Prototype t_list *ft_lstnew(void *content);
// Turn in files -
// Parameters content: The content to create the node with.
// Return value The new node
// External functs. malloc
// Description Allocates (with malloc(3)) and returns a new node.
// The member variable ’content’ is initialized with
// the value of the parameter ’content’. The variable
// ’next’ is initialized to NULL.

// ＜PDF解説＞
// ft_lstnew 関数は、単方向リンクリストの新しいノードを作成するための関数です。以下はその挙動を詳しく説明します：
// t_list 構造体:
// ft_lstnew 関数は t_list という名前の構造体を使用します。この構造体は、リンクリストのノードを表現します。通常、この構造体は以下のように定義されます：
// Copy code
// typedef struct s_list
// {
//     void *content;
//     struct s_list *next;
// } t_list;
// void *content: リンクリストの各ノードには content と呼ばれるデータポインタが含まれます。これはノードが保持するデータへのポインタです。どの型のデータでも格納できるように void * 型として定義されています。
// struct s_list *next: 各ノードは次のノードへのポインタ next を持っており、リンクリストを形成します。
// ft_lstnew 関数の引数:
// void *content: 新しいノードに格納するデータへのポインタを受け取ります。
// 関数の動作:
// メモリの確保: ft_lstnew 関数は malloc 関数を使用して新しいノード用のメモリ領域を動的に確保します。このメモリ領域は t_list 構造体のサイズ分だけ確保されます。
// メンバーの初期化:
// content メンバー: 新しいノードの content メンバーには、引数として受け取った content ポインタが格納されます。これにより、新しいノードは指定されたデータを保持します。
// next メンバー: next メンバーは新しいノードがリンクリスト内で次のノードを指すポインタで、初期化時点では NULL に設定されます。
// 戻り値:
// ft_lstnew 関数は新しいノードのポインタを返します。つまり、新しいノードの先頭へのポインタが返されます。
// この関数を使用することで、リンクリストの新しいノードを作成し、データを初期化してリンクリストに挿入することができます。通常、リンクリストの操作を行う際に、このような新しいノードを動的に生成して使用します。

// ＜メモ＞
// content が NULL の場合を例外処理で弾くと、テスターに引っかかる
// ft_lstnew 関数の引数 content が NULL の場合、関数は正常に動作し、新しいノードが作成されます。新しいノードの content メンバーには NULL ポインタが格納されます。このようにして、ノードがデータを持たずに初期化されたリストを作成できます。ただし、この場合、そのノードは実際には何もデータを保持していないことに注意してください。
// 構造体はその仕様から、実用的なプログラムの場合は相当な領域を使用することが考えられます
// サイズの大きな構造体変数を関数に値渡しするのは合理的ではありません
// 時間もかかるし、容量（スタックといいます）も必要です
// ということは参照渡しが望ましいということになります
// 構造体変数を参照渡しするには構造体変数のポインタが必要です
// 問題はアクセス方法です。構造体のポインタはドット演算子は使えません
// 代わりに、構造体変数がポインタであることを明示的に表すアロー演算子 ( -> )を用います
// person2 sato, *p1;
//     p1 = &sato; // 実体のアドレス
//     p1->age = 20; // ポインタを使ってメンバの初期化
// (*p).name　と　p->nameは同じ意味,,,参照渡し
// 構造体のポインタ変数からメンバ変数にアクセスするにはアロー演算子を使用する、と覚えておきましょう。

// ＜リスト構造（リンクリスト）とは＞
// struct new {
//     int number; /* 会員番号 */
//     char name[256]; /* 会員名 */
//     struct new *next; /* 次のノード */
// };
// number と name がデータ部にあたり、next がポインタ部にあたります。
// さらに、この next は次のノードを指すポインタであり、指す対象のデータはノード構造体で表現される他のノードですので next の型は struct new * である必要があります。
// 例えば下記のように処理を行えば、new1 の次の位置に new2 が、new2の次の位置に new3 が存在するようなリストを作成することができます（head はリストの先頭ノードを指すポインタ）。
//  (リストの作成例)
// struct new new1, new2, new3;
// struct new *head;
// /* new1の次の位置にあるノードを設定 */
// new1.next = &new2;
// /* new2の次の位置にあるノードを設定 */
// new2.next = &new3;
// /* new3の次の位置にあるノードはなし */
// new3.next = NULL;
// /* リストの先頭ノードを設定 */
// head = &new1;

// ＜配列とのデータ構造の違い＞
// ここまで解説してきたように、リスト構造におけるノードには “データ部” と “ポインタ部” が必要です。前述の通り、今回はポインタ部をポインタとしています。
// その一方で、配列におけるノードが持つのはデータ部のみです（このページでは配列の要素のことをノードを呼ばせていただきます）。配列にはポインタ部は不要です。
// なぜ配列では、ポインタ部は不要なのでしょうか？
// その答えは、配列の各ノードはメモリの配置的に、”次のノードが必ず次のアドレス” に存在するという制約があるからです。