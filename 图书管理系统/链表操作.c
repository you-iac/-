#include"MyCreat_library.h"
//�����ǩ
Node* List_output(Node* L)		//������� X == 1 ���ȫ�� X == 2 �������
{
	Node* p = L;
	if (L == NULL) {
		printf("����û������\n");
		return NULL;
	}
	else {	
		int i = 0;
		printf("  %02d %-30s %-30s �ڿ�����\n", i, "����", "����");
		for (i = 1; p; p = p->Next, i++) {
			printf("%02d %-30s %-30s %-03d\n " , i, p->label, FindB(p->label)->S.Write, FindB(p->label)->Init);
			printf("--------------------------------\n");
			if (i % 10 == 0) {
				printf("�Ƿ��������� Y & N   :");
				
				int X = 0, x = 0;
				scanf_s("%c", &X); x = getchar();
				printf("--------------------------------");
				printf("\n");
				system("cls");
				printf("%d %10s %10s %03d\n ", i, "����", "����", "�ڿ�����");
				if (x == 'n' || X == 'N') { return L; }

			}
		}
	}
	printf("�������������");int X = Choice();
	return 0;
}
//���
Node* List_add(Node* list, Node* L)					//�����ͷ����ӵĽڵ�ָ�룬��β����ӣ�Ȼ�󷵻�
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
//ɾ��
Node* List_del(Node* list, char Name[]) {
	if (list == NULL) { printf("�� ���� List_del �д����˿յ��б�"); return 0; }
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

//���ش�С
int int_size(double a, double b) {
	return a > b ? 1 : 0;
}
