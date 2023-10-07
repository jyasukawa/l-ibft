#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int	size;

	size = 0;
	while (lst != NULL)
	{
		lst = lst->next;
    size++;
	}
	return (size);
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

// 	// リストのサイズを取得して表示
// 	int size = ft_lstsize(myList);
// 	printf("List size: %d\n", size);

// 	// リストを解放
// 	while (myList != NULL)
// 	{
// 			t_list *temp = myList;
// 			myList = myList->next;
// 			free(temp);
// 	}
// 	// リストには2つのノードが含まれており、そのサイズは2となります
// 	return 0;
// }

// <PDF>
// Function name ft_lstsize
// Prototype int ft_lstsize(t_list *lst);
// Turn in files -
// Parameters lst: The beginning of the list.
// Return value The length of the list
// External functs. None
// Description Counts the number of nodes in a list.

// ＜PDF解説＞
// ft_lstsize 関数は、与えられたリスト内のノードの数を数える関数です。以下にこの関数の挙動を簡潔に説明します：
// ft_lstsize 関数は、1 つの引数 lst を受け取ります。これはリストの最初のノードを指すポインタです。
// 関数を呼び出すと、リスト内のノードの数が数えられます。
// リスト内の各ノードは、その次のノードを指す next ポインタを持っています。
// ft_lstsize 関数は、リストの最初のノードから始めて、次のノードが存在する限りカウントを増やし、最終的にリスト内のノードの総数を返します。
// この関数を使用すると、リスト内のノードの数を簡単に取得できます。