#include"MyCreat_library.h"
//�޸�ͼ����Ϣ
void Change_Library_Information(Context* Con){
	while (1) {
		system("cls");
		printf("               **********  ��ӭ  **********\n\n"
			"********************** �޸�ͼ�����Ϣ ************************\n\n\n"
			"*            ============ 1-����ͼ��Ŀ¼  ===========          *\n"
			"*                                                              *\n"
			"*            ============ 2-���ͼ��     ===========           *\n"
			"*                                                              *\n"
			"*            ============ 3-�޸�ͼ��     ===========           *\n"
			"*                                                              *\n"
			"*            ============ 4-ɾ��ͼ��===========                *\n"
			"*                                                              *\n"
			"*            ============ 0-������һ��===========              *\n"
			"*                                                              *\n"
			"****************************************************************\n"
			" * * * * * * *����������ѡ�� ->  ");
		int X = -1;
		scanf_s("%d", &X); getchar();
		printf("\n");
		system("cls");
		switch (X)
		{
			case 0: return 0; break;
			case 1: List_output(Con->BookName.Next);	break;
			case 2: Add_Books(Con);						break;
			case 3:	Change_Books(Con);					break;
			case 4: Deal_Book(Con);						break;

		default: printf("��������δ֪������,����ݲ���ѡ����в���"); break;
		}
	}
}
//�޸��û���Ϣ
void Change_Users_Information(Context* Con)
{
	while (1) {
		system("cls");
		printf("               **********  ��ӭ  **********\n\n"
			"********************** �޸��û���Ϣ ************************\n\n\n"
			"*            ============ 1-���û�Ŀ¼     ===========         *\n"
			"*                                                              *\n"
			"*            ============ 2-����û�       ===========         *\n"
			"*                                                              *\n"
			"*            ============ 3-�޸��û���Ϣ   ===========         *\n"
			"*                                                              *\n"
			"*            ============ 4-��ӹ���Ա     ===========         *\n"
			"*                                                              *\n"
			"*            ============ 5-�޸Ĺ���Ա��Ϣ ===========         *\n"
			"*                                                              *\n"
			"*            ============ 6-ɾ���û�       ===========         *\n"
			"*                                                              *\n"
			"*            ============ 7-ɾ������Ա     ===========         *\n"
			"*                                                              *\n"
			"*            ============ 0-������һ��===========              *\n"
			"*                                                              *\n"
			"****************************************************************\n"
			" * * * * * * *����������ѡ�� ->  ");
		int X = -1;
		scanf_s("%d", &X); getchar();
		printf("\n");
		system("cls");
		switch (X)
		{
		case 0: return 0; break;
		case 1: OutputPeo(Con->People.Next);			break;
		case 2: Add_Users(1, Con);						break;
		case 3:	Change_Users(1, Con);					break;
		case 4: Add_Users(2, Con);						break;
		case 5: Change_Users(2, Con);					break;
		case 6: Deal_Users(1, Con); break;
		case 7: Deal_Users(2, Con); break;
		default: printf("��������δ֪������,����ݲ���ѡ����в���"); break;
		}
	}
}
//���ͼ��
void Reading_Books(Context* Con){
	Node* P = NULL, *Buff = NULL;
	int i = 1;
	for (Buff = Con->BookName.Next; Buff; Buff = Buff->Next) {
		char T[100];
		strcpy_s(T, 100, FindB(Buff->label)->Type);

		printf("ͼ�����ͣ� %s\n", T);
		int i = 0;
		for (i = 0, P = Buff; P; P = P->Next) {
			if (strcmp(T, FindB(P->label)->Type) == 0) {
				printf("%s\n", P->label);
				printf("%s\n", FindB(P->label)->S.Write);
				printf("_____________________\n");
			}
		}

		printf("�Ƿ���� 1 ����  �����������һ�� :\n");
		int X = 0;
		X = Choice();
		system("cls");
		if (X != 1) { break; }
	}
	
	return 0;
}
//�����ͼ��
void Add_Books(Context* Con) {
	while (1) {
		Book* B = MakeNew_Book(1);
		Print_B(B);
		AddB(B);

		Con->BookNumber++;
		List_add(&Con->BookName, MakeNew_Node(B->Name));
		Node* P = Con->BookName.Next;
		for (; P; P = P->Next) {
			printf("%s\n", P->label);
		}
		printf("�����ɹ�!!!\n");
		printf("�Ƿ���� 1 ����  �����������һ�� :\n");
		int X = 0;
		X = Choice();
		system("cls");
		if (X != 1) { break; }
	}

	return 0;
}
//�޸�ͼ��
void Change_Books(Context* Con) {
	char Name[100];
	while (1) {
		printf("��������ҵ����� :");
		gets(Name);
		printf("\n");
		Book* B = FindB(Name);

		if (B == NULL) {
			break;
		}
		else {
			Print_B(B);
			printf("1 �޸�ͼ������ 2 �޸�ͼ��λ����Ϣ 3�޸�ͼ������ 4 �޸�ͼ�����ͣ�5 �޸�ͼ����\n");
			int C = Choice();
			if (C == 1) {
				printf("�������޸� ����������:");
				gets(B->S.Write);
			}
			if (C == 2) {
				printf("�������޸ĵ�λ����Ϣ:");
				scanf_s("%d", &B->S.Location);
			}
			if (C == 3) {
				printf("�������޸ĵ�ͼ������:");
				scanf_s("%d", &B->Init);
			}
			if (C == 4) {
				printf("�������޸ĵ�ͼ������:");
				scanf_s("%d", B->Type);
			}
			if (C == 5) {
				printf("�������޸ĵ�ͼ����:");
				scanf_s("%d", B->Serial_number);
			}
			//printf("��������δ֪����Ϣ\n");
			AddB(B);
			printf("�����ɹ�!!!\n");
		}
		printf("�Ƿ���� 1 ����  �����������һ�� :\n");
		int X = 0;
		X = Choice();
		if (X != 1) { break; }
	}
}
//����û�
void Add_Users(int p, Context* Con) {			// 1 ����û�  2 ��ӹ���Ա
	while (1) {
		if (p == 1) {
			User* P = MakeNew_User(1);			//����һ���µ��û�
			Print_U(P);							//��ʾ�������û�
			AddU(P);							//����û����û���

			Con->PeopleNumber++;				//�û����� ++

			List_add(&Con->People, MakeNew_Node(P->Account));	//����˺� �� �û�Ŀ¼��
			printf("�����ɹ�!!!\n");
		}
		else {
			User* P = MakeNew_User(1);			//����һ���µ��û�
			P->Is = 1;							//����Ϊ����Ա
			Print_U(P);							//��ʾ�������û�
			AddU(P);							//����û����û���
			printf("�����ɹ�!!!\n");
		}

		printf("�Ƿ���� 1 ����  �����������һ�� :\n");
		int X = 0;
		X = Choice();
		if (X != 1) { break; }
	}

	return 0;
}
//�޸��û�
void Change_Users(int p, Context* Con) {// 1 �û�  2 ����Ա
	char Name[100];
	while (1) {
		printf("��������ҵ��û��˻� ��");
		gets(Name);
		printf("\n");
		User* P = NULL;
		if (p == 1) {
			P = FindU(1, Name);			//����һ���û�  1�����û����ң�Name (�û����˺�)
		}
		else {
			P = FindU(2, Name);			//����һ���û�  1�����û����ң�Name (�û����˺�)
		}

		if (P == NULL) {
			break;
		}
		else {
			Print_U(P);
			printf("1 �޸����� 2 �޸��ǳ� ��");
			int C = Choice();
			if (C == 1) {
				printf("�������޸� ������:");
				gets(P->password);
			}
			if (C == 2) {
				printf("�������޸ĵ��ǳ�:");
				gets(P->Nickname);
			}

			//printf("��������δ֪����Ϣ\n");
			AddU(P);
		}
		printf("�Ƿ���� 1 ����  �����������һ�� :\n");
		int X = 0;
		X = Choice();
		if (X != 1) { break; }
	}
}
//ɾ���û�
void Deal_Users(int p, Context* Con) {
	char Name[100];
	while (1) {
		printf("��������ҵ��û��˻� ��");
		gets(Name);
		printf("\n");
		User* P = NULL;
		if (p == 1) {
			P = FindU(1, Name);			//����һ���û�  1�����û����ң�Name (�û����˺�)
			if (P != NULL) {
				Print_U(P);
				char A[100];
				strcpy_s(A, 100, FindF(DATABASE, Name));
				remove(A);
				List_del(&Con->People, Name);
				Con->PeopleNumber--;
			}
			
		}else {
			P = FindU(2, Name);			//����һ���û�  1���ڹ���Ա���ң�Name (�û����˺�)
			if (P != NULL) {
				Print_U(P);
				remove(FindF("ADMINDER", Name));
			}
		}
		printf("�Ƿ���� 1 ����  �����������һ�� :\n");
		int X = 0;
		X = Choice();
		if (X != 1) { break; }
	}
}
//ɾ��ͼ��
void Deal_Book(Context* Con) {
	char Name[100];
	while (1) {
		printf("��������ҵ�ͼ�� ��");
		gets(Name);					//��ȡ����
		printf("\n");				
		Book* P = NULL;				
		P = FindB(Name);			//����ͼ��
		if (P != NULL) {			
			Print_B(P);
			char A[100];
			strcpy_s(A, 100, FindF(DATABASE, Name));
			remove(A);
			List_del(&Con->BookName, Name);
			Con->BookNumber--;
		}
		printf("�Ƿ���� 1 ����  �����������һ�� :\n");
		int X = 0;
		X = Choice();
		if (X != 1) { break; }
	}
}
//ѡ��
int Choice() {
	int X = 0, x = 0;
	printf("������ѡ��  :");
	scanf_s("%d", &X); x = getchar();
	printf("\n");
	return X;
}
//����
void Borrow_books(User* U) {
	printf("��������Ҫ���ĵ�ͼ�����ƣ�");
	char Name[100];

	gets(Name);
	if (U->N < 5) {
		Book* B = FindB(Name);

		
		if (B == NULL) { printf("�ƺ�ͼ�����û���Ȿ��\n"); return 0; }
		if (B->Init == 0) { printf("ͼ���Ѿ��������ˣ���\n"); return 0; }

		Print_B(B);

		B->Init--;
		strcpy_s( U->Book[U->N].label, 100, B->Name);
		U->N++;
		printf("�����ɹ�������\n");
		AddB(B);
		AddU(U);
	}
	else {
		printf("��ֻ�ܽ��Ĳ�����5���鼮\n");
	}
	
	printf("�������������һ����"); int X = Choice();
}
//����
void Return_Book(User* U) {
	if (U->N == 0) {printf("����û�н���Ŷ����\n");return 0;}
	Print_U(U);
	printf("�����뻹�������ţ��� 1 ��ʼ��\n");
	
	int X = Choice();

	if (X <= 0 && X > U->N) {
		printf("��������ȷ�Ļ������\n");
		printf("�������������һ����"); X = Choice();
		return 0;
	}

	Book* B = FindB(U->Book[X-1].label);
	
	if (B != NULL) {
		B->Init++;
		AddB(B);
	}

	int i = 0;
	for (i = X - 1; i < 4; i++) {
		U->Book[i] = U->Book[i + 1];
	}
	U->N--;
	printf("�����ɹ�������\n");
	AddU(U);
	printf("�������������һ����");X = Choice();
}
//ģ������ͼ��
void Search_Book(Context* Con) {
	
	while (1) {
		printf("�����������ؼ���!!!(���������߻��������ؼ��ֻ���ͼ������)\n");
		char Keyworld[100];
		gets(Keyworld);

		int a = Keyworld[0], b = Keyworld[1], T = 0 ;			//����ǰ���������ַ���ASSIC����ʵ��ģ������ T ��¼��ʶ��ͼ���������

		Node* P = Con->BookName.Next;
		int i = 0;
		for (; P; P = P->Next) {
			for (i = 0; i < strlen(P->label) - 1; i++) {
				if (P->label[i] == a && P->label[i + 1] == b) {
					printf("%s\n\n", P->label);
					printf("%s\n", FindB(P->label)->S.Write);
					printf("%s\n", FindB(P->label)->Type);
					printf("------------------------\n");

					T++;

					break;
				}
			}
			if (strcmp(FindB(P->label)->S.Write, Keyworld) == 0) {

				printf("%s\n\n", P->label);
				printf("%s\n", FindB(P->label)->S.Write);
				printf("%s\n", FindB(P->label)->Type);

				printf("------------------------\n");

				T++;

				break;
			}
			if (strcmp(FindB(P->label)->Type, Keyworld) == 0) {

				printf("%s\n", P->label);
				printf("%s\n", FindB(P->label)->S.Write);
				printf("%s\n", FindB(P->label)->Type);

				printf("------------------------\n");

				T++;

				break;
			}
		}
		if (T == 0) {printf("����������Ĺؼ��ֲ����ؼ�������������Կ�����\n");}			//���ͼ��һ����û���������Ϊ�ؼ��ֲ��ؼ�
		printf("�Ƿ���� 1 ����  �����������һ�� :\n");
		int X = 0;
		
		X = Choice();
		system("cls");
		if (X != 1) {break;}
	}
}
//�����ǩ��Ϣ
Node* OutputPeo(Node* P) {
	for (P; P; P = P->Next) {
		printf("%s", P->label);
		printf("\n");
		printf("�����������\n");
		int X = 0;

		X = Choice();
	}
	return NULL;
}
