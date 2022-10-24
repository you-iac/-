#include"MyCreat_library.h"
//输出标签
Node* List_output(Node* L)		//输出链表 X == 1 输出全部 X == 2 输出部分
{
	Node* p = L;
	if (L == NULL) {
		printf("库中没有数据\n");
		return NULL;
	}
	else {	
		int i = 0;
		printf("  %02d %-30s %-30s 在库数量\n", i, "书名", "作者");
		for (i = 1; p; p = p->Next, i++) {
			printf("%02d %-30s %-30s %-03d\n " , i, p->label, FindB(p->label)->S.Write, FindB(p->label)->Init);
			printf("--------------------------------\n");
			if (i % 10 == 0) {
				printf("是否继续输出？ Y & N   :");
				
				int X = 0, x = 0;
				scanf_s("%c", &X); x = getchar();
				printf("--------------------------------");
				printf("\n");
				system("cls");
				printf("%d %10s %10s %03d\n ", i, "书名", "作者", "在库数量");
				if (x == 'n' || X == 'N') { return L; }

			}
		}
	}
	printf("按任意键继续。");int X = Choice();
	return 0;
}
//添加
Node* List_add(Node* list, Node* L)					//传入表头和添加的节点指针，在尾部添加，然后返回
{
	if (list->Next == NULL) {
		list->Next = L;
	}
	else {
		Node* p = list;
		for (; p->Next; p = p->Next) {}
		p->Next = L;
	}
	return list;
}
//删除
Node* List_del(Node* list, char Name[]) {
	if (list == NULL) { printf("在 函数 List_del 中传入了空的列表"); return 0; }
	if (list == NULL) {
		return NULL;
	}
	else {
		if(strcmp(Name, list->label) == 0){
			return list->Next;
		}
		else {
			list->Next = List_del(list->Next, Name);
			return list;
		}
	}
}
//List swop(List p, List q) {
//	List r = MakeNew_Node(1);
//	*r = *p, * p = *q, * q = *r;
//
//	q->Next = p->Next;
//	p->Next = r->Next;
//	free(r);
//	return 0;
//}

//返回大小
int int_size(double a, double b) {
	return a > b ? 1 : 0;
}
