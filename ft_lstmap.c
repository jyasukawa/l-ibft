#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new_lst;
	t_list	*node;

	if (lst == NULL || f == NULL || del == NULL)
		return (NULL);
	new_lst = NULL;
	while (lst != NULL)
	{
		node = ft_lstnew(f(lst->content));
		if (node == NULL)
		{
			ft_lstclear(&new_lst, del);
			return (NULL);
		}
		ft_lstadd_back(&new_lst, node);
		lst = lst->next;
	}
	return (new_lst);
}

// #include <stdlib.h>
// #include <ctype.h>
// #include <string.h>
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
// t_list	*ft_lstlast(t_list *lst)
// {
// 	if (lst == NULL)
// 		return (NULL);
// 	while (lst->next != NULL)
// 		lst = lst->next;
// 	return (lst);
// }
// void	ft_lstadd_back(t_list **lst, t_list *new)
// {
//   t_list	*tmp;

// 	if (lst == NULL || new == NULL)
// 		return ;
// 	if (*lst != NULL)
// 	{
// 		tmp = ft_lstlast(*lst);
//     tmp->next = new;
// 	}
// 	else
// 		*lst = new;
// }
// void	ft_lstdelone(t_list *lst, void (*del)(void *))
// {
// 	if (lst == NULL || del == NULL)
// 		return ;
// 	del(lst->content);
// 	free(lst);
// }
// void	ft_lstclear(t_list **lst, void (*del)(void *))
// {
// 	t_list	*tmp;

// 	if (lst == NULL || del == NULL)
// 		return ;
// 	while (*lst != NULL)
// 	{
// 		tmp = (*lst)->next;
// 		ft_lstdelone(*lst, del);
// 		*lst = tmp;
// 	}
// 	*lst = NULL;
// }
// // テスト用の関数1：文字列を大文字に変換する関数
// void *toupper_str(void *content)
// {
// 	char *str = (char *)content;
// 	char *new_str = (char *)malloc(strlen(str) + 1);
// 	if (new_str == NULL)
// 		return (NULL);
// 	int i = 0;
// 	while (str[i])
// 	{
// 		new_str[i] = toupper(str[i]);
// 		i++;
// 	}
// 	new_str[i] = '\0';
// 	return (new_str);
// }
// // テスト用の関数2：文字列を解放する関数
// void del_str(void *content)
// {
// 	free(content);
// }
// int main(void)
// {
// 	// テスト用のリストを作成
// 	t_list *lst = ft_lstnew(strdup("apple"));
// 	ft_lstadd_back(&lst, ft_lstnew(strdup("banana")));
// 	ft_lstadd_back(&lst, ft_lstnew(strdup("cherry")));

// 	// リストの内容を大文字に変換した新しいリストを作成
// 	t_list *new_lst = ft_lstmap(lst, toupper_str, del_str);

// 	// 新しいリストの内容を表示
// 	t_list *current = new_lst;
// 	while (current != NULL)
// 	{
// 		printf("%s\n", (char *)current->content);
// 		current = current->next;
// 	}

// 	// リストを解放
// 	ft_lstclear(&lst, del_str);
// 	ft_lstclear(&new_lst, del_str);
// 	return (0);
// }

// <PDF>
// Function name ft_lstmap
// Prototype t_list *ft_lstmap(t_list *lst, void *(*f)(void *),
// void (*del)(void *));
// Turn in files -
// Parameters lst: The address of a pointer to a node.
// f: The address of the function used to iterate on
// the list.
// del: The address of the function used to delete
// the content of a node if needed.
// Return value The new list.
// NULL if the allocation fails.
// External functs. malloc, free
// Description Iterates the list ’lst’ and applies the function
// ’f’ on the content of each node. Creates a new
// list resulting of the successive applications of
// the function ’f’. The ’del’ function is used to
// delete the content of a node if needed.

// ＜PDF解説＞
// ft_lstmap 関数は、指定されたリスト lst をイテレートし、各ノードのコンテンツに対して指定された関数 f を適用し、その結果を新しいリストとして返す関数です。以下にこの関数の挙動を簡潔に説明します：
// ft_lstmap 関数は、3 つの引数を受け取ります。lst はリストへのポインタであり、f はリストの各ノードのコンテンツに適用される関数へのポインタです。また、del はノードのコンテンツを削除するための関数へのポインタです。
// 関数を呼び出すと、指定されたリスト lst の各ノードが順番にイテレートされます。
// 各ノードのコンテンツに対して、指定された関数 f が適用されます。この関数 f はノードのコンテンツを引数として受け取り、そのコンテンツを変更したり、新しいデータを生成したりします。
// 各ノードのコンテンツに対して関数 f が適用され、その結果が新しいリストに追加されます。
// リスト内のすべてのノードがイテレートされ、新しいリストが作成されます。新しいリストは、各ノードのコンテンツに関数 f を適用した結果から構築されます。
// もし、ノードのコンテンツを削除する必要がある場合（例: メモリの解放が必要な場合）、del 関数が使用され、必要なクリーンアップ処理が行われます。
// 新しいリストが正常に作成された場合、そのリストへのポインタが返されます。ただし、メモリの割り当てに失敗した場合、NULL が返されます。
// この関数を使用することで、元のリストの各ノードに対して変換や操作を行い、それを新しいリストとして取得できます。