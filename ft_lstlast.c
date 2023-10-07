#include "libft.h"

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next != NULL)
		lst = lst->next;
	return (lst);
}

// #include <stdio.h>
// t_list	*ft_lstnew(void *content)
// {
// 	t_list	*new;

// 	new = (t_list *)malloc(sizeof(t_list));
// 	if (new == NULL)
// 		return (NULL);
// 	new->content = content;
// 	new->next = NULL;
// 	return (new);
// }
// int main()
// {
// 	// リストの先頭ポインタ
// 	t_list *myList = NULL;

// 	// 新しいリストノードを作成
// 	int data1 = 42;
// 	t_list *node1 = ft_lstnew(&data1);

// 	int data2 = 99;
// 	t_list *node2 = ft_lstnew(&data2);

// 	// リストにノードを追加
// 	node1->next = node2;
// 	myList = node1;

// 	// リストの最後のノードを取得
// 	t_list *lastNode = ft_lstlast(myList);

// 	if (lastNode != NULL)
// 	{
// 		int *lastData = (int *)(lastNode->content);
// 		printf("Last Node Content: %d\n", *lastData);
// 	}
// 	else
// 		printf("List is empty.\n");

// 	// リストを解放
// 	while (myList != NULL)
// 	{
// 		t_list *temp = myList;
// 		myList = myList->next;
// 		free(temp);
// 	}
// 	return 0;
// }

// <PDF>
// Function name ft_lstlast
// Prototype t_list *ft_lstlast(t_list *lst);
// Turn in files -
// Parameters lst: The beginning of the list.
// Return value Last last of the list
// External functs. None
// Description Returns the last last of the list.

// ＜PDF解説＞
// ft_lstlast 関数は、与えられたリスト内で最後のノードを見つける関数です。以下にこの関数の挙動を簡潔に説明します：
// ft_lstlast 関数は、1 つの引数 lst を受け取ります。これはリストの最初のノードを指すポインタです。
// 関数を呼び出すと、リスト内で最後のノードを見つけます。
// リスト内の各ノードは、その次のノードを指す next ポインタを持っています。
// ft_lstlast 関数は、リストの最初のノードから始めて、次のノードが存在する限り次に進み、最終的に最後のノードを見つけます。
// 最後のノードが見つかったら、そのノードへのポインタを返します。
// この関数を使用すると、リスト内の最後のノードを簡単に取得できます。