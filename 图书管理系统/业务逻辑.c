#include"MyCreat_library.h"
//修改图书信息
void Change_Library_Information(Context* Con){
	while (1) {
		system("cls");
		printf("               **********  欢迎  **********\n\n"
			"********************** 修改图书库信息 ************************\n\n\n"
			"*            ============ 1-查览图书目录  ===========          *\n"
			"*                                                              *\n"
			"*            ============ 2-添加图书     ===========           *\n"
			"*                                                              *\n"
			"*            ============ 3-修改图书     ===========           *\n"
			"*                                                              *\n"
			"*            ============ 4-删除图书===========                *\n"
			"*                                                              *\n"
			"*            ============ 0-返回上一步===========              *\n"
			"*                                                              *\n"
			"****************************************************************\n"
			" * * * * * * *请输入您的选择 ->  ");
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

		default: printf("您输入了未知的命令,请根据操作选项进行操作"); break;
		}
	}
}
//修改用户信息
void Change_Users_Information(Context* Con)
{
	while (1) {
		system("cls");
		printf("               **********  欢迎  **********\n\n"
			"********************** 修改用户信息 ************************\n\n\n"
			"*            ============ 1-查用户目录     ===========         *\n"
			"*                                                              *\n"
			"*            ============ 2-添加用户       ===========         *\n"
			"*                                                              *\n"
			"*            ============ 3-修改用户信息   ===========         *\n"
			"*                                                              *\n"
			"*            ============ 4-添加管理员     ===========         *\n"
			"*                                                              *\n"
			"*            ============ 5-修改管理员信息 ===========         *\n"
			"*                                                              *\n"
			"*            ============ 6-删除用户       ===========         *\n"
			"*                                                              *\n"
			"*            ============ 7-删除管理员     ===========         *\n"
			"*                                                              *\n"
			"*            ============ 0-返回上一步===========              *\n"
			"*                                                              *\n"
			"****************************************************************\n"
			" * * * * * * *请输入您的选择 ->  ");
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
		default: printf("您输入了未知的命令,请根据操作选项进行操作"); break;
		}
	}
}
//浏览图书
void Reading_Books(Context* Con){
	Node* P = NULL, *Buff = NULL;
	int i = 1;
	for (Buff = Con->BookName.Next; Buff; Buff = Buff->Next) {
		char T[100];
		strcpy_s(T, 100, FindB(Buff->label)->Type);

		printf("图书类型： %s\n", T);
		int i = 0;
		for (i = 0, P = Buff; P; P = P->Next) {
			if (strcmp(T, FindB(P->label)->Type) == 0) {
				printf("%s\n", P->label);
				printf("%s\n", FindB(P->label)->S.Write);
				printf("_____________________\n");
			}
		}

		printf("是否继续 1 继续  任意键返回上一步 :\n");
		int X = 0;
		X = Choice();
		system("cls");
		if (X != 1) { break; }
	}
	
	return 0;
}
//新添加图书
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
		printf("操作成功!!!\n");
		printf("是否继续 1 继续  任意键返回上一步 :\n");
		int X = 0;
		X = Choice();
		system("cls");
		if (X != 1) { break; }
	}

	return 0;
}
//修改图书
void Change_Books(Context* Con) {
	char Name[100];
	while (1) {
		printf("请输入查找的书名 :");
		gets(Name);
		printf("\n");
		Book* B = FindB(Name);

		if (B == NULL) {
			break;
		}
		else {
			Print_B(B);
			printf("1 修改图书作者 2 修改图书位置信息 3修改图书数量 4 修改图书类型：5 修改图书编号\n");
			int C = Choice();
			if (C == 1) {
				printf("请输入修改 的作者名字:");
				gets(B->S.Write);
			}
			if (C == 2) {
				printf("请输入修改的位置信息:");
				scanf_s("%d", &B->S.Location);
			}
			if (C == 3) {
				printf("请输入修改的图书数量:");
				scanf_s("%d", &B->Init);
			}
			if (C == 4) {
				printf("请输入修改的图书类型:");
				scanf_s("%d", B->Type);
			}
			if (C == 5) {
				printf("请输入修改的图书编号:");
				scanf_s("%d", B->Serial_number);
			}
			//printf("你输入了未知的信息\n");
			AddB(B);
			printf("操作成功!!!\n");
		}
		printf("是否继续 1 继续  任意键返回上一步 :\n");
		int X = 0;
		X = Choice();
		if (X != 1) { break; }
	}
}
//添加用户
void Add_Users(int p, Context* Con) {			// 1 添加用户  2 添加管理员
	while (1) {
		if (p == 1) {
			User* P = MakeNew_User(1);			//创建一个新的用户
			Print_U(P);							//显示创建的用户
			AddU(P);							//添加用户到用户库

			Con->PeopleNumber++;				//用户数量 ++

			List_add(&Con->People, MakeNew_Node(P->Account));	//添加账号 在 用户目录中
			printf("操作成功!!!\n");
		}
		else {
			User* P = MakeNew_User(1);			//创建一个新的用户
			P->Is = 1;							//设置为管理员
			Print_U(P);							//显示创建的用户
			AddU(P);							//添加用户到用户库
			printf("操作成功!!!\n");
		}

		printf("是否继续 1 继续  任意键返回上一步 :\n");
		int X = 0;
		X = Choice();
		if (X != 1) { break; }
	}

	return 0;
}
//修改用户
void Change_Users(int p, Context* Con) {// 1 用户  2 管理员
	char Name[100];
	while (1) {
		printf("请输入查找的用户账户 ：");
		gets(Name);
		printf("\n");
		User* P = NULL;
		if (p == 1) {
			P = FindU(1, Name);			//查找一个用户  1（在用户库找）Name (用户的账号)
		}
		else {
			P = FindU(2, Name);			//查找一个用户  1（在用户库找）Name (用户的账号)
		}

		if (P == NULL) {
			break;
		}
		else {
			Print_U(P);
			printf("1 修改密码 2 修改昵称 ：");
			int C = Choice();
			if (C == 1) {
				printf("请输入修改 的密码:");
				gets(P->password);
			}
			if (C == 2) {
				printf("请输入修改的昵称:");
				gets(P->Nickname);
			}

			//printf("你输入了未知的信息\n");
			AddU(P);
		}
		printf("是否继续 1 继续  任意键返回上一步 :\n");
		int X = 0;
		X = Choice();
		if (X != 1) { break; }
	}
}
//删除用户
void Deal_Users(int p, Context* Con) {
	char Name[100];
	while (1) {
		printf("请输入查找的用户账户 ：");
		gets(Name);
		printf("\n");
		User* P = NULL;
		if (p == 1) {
			P = FindU(1, Name);			//查找一个用户  1（在用户库找）Name (用户的账号)
			if (P != NULL) {
				Print_U(P);
				char A[100];
				strcpy_s(A, 100, FindF(DATABASE, Name));
				remove(A);
				List_del(&Con->People, Name);
				Con->PeopleNumber--;
			}
			
		}else {
			P = FindU(2, Name);			//查找一个用户  1（在管理员库找）Name (用户的账号)
			if (P != NULL) {
				Print_U(P);
				remove(FindF("ADMINDER", Name));
			}
		}
		printf("是否继续 1 继续  任意键返回上一步 :\n");
		int X = 0;
		X = Choice();
		if (X != 1) { break; }
	}
}
//删除图书
void Deal_Book(Context* Con) {
	char Name[100];
	while (1) {
		printf("请输入查找的图书 ：");
		gets(Name);					//获取书名
		printf("\n");				
		Book* P = NULL;				
		P = FindB(Name);			//查找图书
		if (P != NULL) {			
			Print_B(P);
			char A[100];
			strcpy_s(A, 100, FindF(DATABASE, Name));
			remove(A);
			List_del(&Con->BookName, Name);
			Con->BookNumber--;
		}
		printf("是否继续 1 继续  任意键返回上一步 :\n");
		int X = 0;
		X = Choice();
		if (X != 1) { break; }
	}
}
//选择
int Choice() {
	int X = 0, x = 0;
	printf("请输入选项  :");
	scanf_s("%d", &X); x = getchar();
	printf("\n");
	return X;
}
//借书
void Borrow_books(User* U) {
	printf("请输入您要借阅的图书名称：");
	char Name[100];

	gets(Name);
	if (U->N < 5) {
		Book* B = FindB(Name);

		
		if (B == NULL) { printf("似乎图书库中没有这本书\n"); return 0; }
		if (B->Init == 0) { printf("图书已经被借完了！！\n"); return 0; }

		Print_B(B);

		B->Init--;
		strcpy_s( U->Book[U->N].label, 100, B->Name);
		U->N++;
		printf("操作成功！！！\n");
		AddB(B);
		AddU(U);
	}
	else {
		printf("你只能借阅不超过5本书籍\n");
	}
	
	printf("按任意键返回上一步。"); int X = Choice();
}
//还书
void Return_Book(User* U) {
	if (U->N == 0) {printf("您还没有借书哦！！\n");return 0;}
	Print_U(U);
	printf("请输入还的书的序号（从 1 开始）\n");
	
	int X = Choice();

	if (X <= 0 && X > U->N) {
		printf("请输入正确的还书序号\n");
		printf("按任意键返回上一步。"); X = Choice();
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
	printf("操作成功！！！\n");
	AddU(U);
	printf("按任意键返回上一步。");X = Choice();
}
//模糊搜索图书
void Search_Book(Context* Con) {
	
	while (1) {
		printf("请输入搜索关键字!!!(可以是作者或者书名关键字或者图书种类)\n");
		char Keyworld[100];
		gets(Keyworld);

		int a = Keyworld[0], b = Keyworld[1], T = 0 ;			//根据前两个输入字符的ASSIC码来实现模糊搜索 T 记录相识的图书输出几次

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
		if (T == 0) {printf("可能你输入的关键字不够关键，你可以再试试看！！\n");}			//如果图书一本都没有输出就认为关键字不关键
		printf("是否继续 1 继续  任意键返回上一步 :\n");
		int X = 0;
		
		X = Choice();
		system("cls");
		if (X != 1) {break;}
	}
}
//输出标签信息
Node* OutputPeo(Node* P) {
	for (P; P; P = P->Next) {
		printf("%s", P->label);
		printf("\n");
		printf("按任意键继续\n");
		int X = 0;

		X = Choice();
	}
	return NULL;
}
