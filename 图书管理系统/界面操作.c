#include"MyCreat_library.h"

//0 = ��ɫ	8 = ��ɫ
//1 = ��ɫ	9 = ����ɫ
//2 = ��ɫ	A = ����ɫ
//3 = ����ɫ	B = ��ǳ��ɫ
//4 = ��ɫ	C = ����ɫ
//5 = ��ɫ	D = ����ɫ
//6 = ��ɫ	E = ����ɫ
//7 = ��ɫ	F = ����ɫ

//����ϵͳ
void Login_System(Context* Con) {
	system("color b1");
	while (1) {
		printf( "               **********  ��ӭ  **********\n\n"
				"********************** ͼ����Ϣ����ϵͳ ************************\n\n\n"
				"*            ============ 1-�û�����     ===========           *\n"
				"*                                                              *\n"
				"*            ============ 2-���ο���ݵ���===========          *\n"
				"*                                                              *\n"
				"*            ============ 3-����Ա��ݵ���===========          *\n"
				"*                                                              *\n"
				"*            ============ 0-��������     ===========           *\n"
				"*                                                              *\n"
				"****************************************************************\n"
				" * * * * * * *����������ѡ�� ->  ");
		int X = -1;
		scanf_s("%d", &X); getchar();
		printf("\n");
		system("cls");
		switch (X)
		{
			case 1: Users_Login(Con);			break;
			case 2: Visitors_Login(Con);		break;
			case 3:Administrator_Login(Con);	break;
			case 0: return 0; break;
			default: printf("��������δ֪������,����ݲ���ѡ����в���");
		}
	}
}
//�ο͵���
void Visitors_Login(Context* Con) {
	system("color e2");
	while (1) {
		system("cls");
		printf("               **********  ��ӭ  **********\n\n"
			"********************** ͼ����Ϣ����ϵͳ ************************\n\n\n"
			"*            ============ 1-����ͼ��     ===========           *\n"
			"*                                                              *\n"
			"*            ============ 2-����ͼ��Ŀ¼  ===========          *\n"
			"*                                                              *\n"
			"*            ============ 3.�������˻�(�����ص�¼) =========== *\n"
			"*                                                              *\n"
			"*            ============ 0-������һ��    ===========          *\n"
			"*                                                              *\n"
			"****************************************************************\n"
			" * * * * * * *����������ѡ�� ->  ");
		int X = -1;
		scanf_s("%d", &X);  getchar();
		printf("\n");
		system("cls");

		switch (X)
		{
			case 1: Search_Book(Con);					break;
			case 2: List_output(Con->BookName.Next);	break;
			case 3: Add_Users(1, Con);					break;
			case 0:return 0; break;
			default: printf("��������δ֪������,����ݲ���ѡ����в���"); break;
		}
	}
}
//�û�����
void Users_Login(Context* Con) {
	User* U = Login(1, Con);
	
	system("color f3");
	while (1) {
		system("cls");
		printf("               **********  ��ӭ  **********\n\n"
			"********************** ͼ����Ϣ����ϵͳ ************************\n\n\n"
			"*            ============ 1-����ͼ��      ===========           *\n"
			"*                                                               *\n"
			"*            ============ 2-�鿴ͼ��ݸſ�===========           *\n"
			"*                                                               *\n"
			"*            ============ 3-����ͼ��Ŀ¼  ===========           *\n"
			"*                                                               *\n"
			"*            ============ 4-����          ===========           *\n"
			"*                                                               *\n"
			"*            ============ 5-����          ===========           *\n"
			"*                                                               *\n"
			"*            ============ 6-�鿴������Ϣ  ===========           *\n"
			"*                                                               *\n"
			"*            ============ 7-�޸ĸ�����Ϣ  ===========           *\n"
			"*                                                               *\n"
			"*            ============ 0-������һ��    ===========           *\n"
			"*                                                               *\n"
			"****************************************************************\n"
			" * * * * * * *����������ѡ�� ->  ");
		int X = -1;
		scanf_s("%d", &X); getchar();
		printf("\n");
		system("cls");

		switch (X)
		{
		case 1: Search_Book(Con);										break;		//ģ������ͼ��
		case 2: The_Library(Con);										break;
		case 3: Reading_Books(Con);										break;		//���ͼ��Ŀ¼��Ϣ
		case 4: Borrow_books(U);										break;		//����
		case 5: Return_Book(U);											break;		//����
		case 6: Print_U(U); printf("�������������һ����"); X = Choice();	break;		//���������Ϣ
		case 7: Change_Self(U);											break;		//�޸ĸ�����Ϣ
		case 0: return 0;												break;		//����

		default: printf("��������δ֪������,����ݲ���ѡ����в���"); break;
		}
	}
}
//����Ա����
void Administrator_Login(Context* Con) {
	User* U =  Login(2, Con);
	
	system("color f4");
	while (1) {
		system("cls");
		printf("               **********  ��ӭ  **********\n\n"
			"********************** ͼ����Ϣ����ϵͳ ************************\n\n\n"
			"*            ============ 1-����ͼ��      ===========          *\n"
			"*                                                              *\n"
			"*            ============ 2-�޸�ͼ�����Ϣ===========          *\n"
			"*                                                              *\n"
			"*            ============ 3-�޸��û���Ϣ  ===========          *\n"
			"*                                                              *\n"
			"*            ============ 4-�鿴���˺���Ϣ===========          *\n"
			"*                                                              *\n"
			"*            ============ 0-������һ��    ===========          *\n"
			"*                                                              *\n"
			"****************************************************************\n"
			" * * * * * * *����������ѡ�� ->  ");
		int X = -1;
		scanf_s("%d", &X); getchar();
		printf("\n");
		system("cls");

		switch (X)
		{
		case 1: Reading_Books(Con);															break;
		case 2: Change_Library_Information(Con);											break;
		case 3: Change_Users_Information(Con);												break;
		case 4: Print_U(FindU(2, U->Account)); printf("�������������һ����"); X = Choice();	break;
		case 0:	return 0; break;
		default: printf("��������δ֪������,����ݲ���ѡ����в���");							break;
		}
	}
}
//������֤
User* Login(int P, Context* Con) {
	while (1) {
		printf("�������˺ţ�");
		char Co[100];
		gets(Co);
		printf("\n");

		printf("���������룺");
		char Pass[100];
		gets(Pass);
		printf("\n");

		User* U = FindU(P, Co);

		if (U != NULL) {
			if (strcmp(Pass, U->password) == 0) {
				printf("����ɹ�!!!\n");
				return U;
			}
			else {
				printf("�������!!!\n");
			}
		}
		else {
			printf("�û�������!!!\n");
		}
		printf("�Ƿ���� 1 ����  �����������һ�� :\n");
		int X = 0;
		X = Choice();
		if (X != 1) { break; }
	}
	
}
//�޸ĸ�����Ϣ
void Change_Self(User* U) {
	Print_U(U);
	printf("1 �޸����� 2 �޸��ǳ�  \n");
	int C = Choice();
	if (C == 1) {
		printf("�������޸� ������:");
		gets(U->password);
	}
	if (C == 2) {
		printf("�������޸ĵ��ǳ�:");
		gets(U->Nickname);
	}
}
