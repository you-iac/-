#include"MyCreat_library.h"

//0 = 黑色	8 = 灰色
//1 = 蓝色	9 = 淡蓝色
//2 = 绿色	A = 淡绿色
//3 = 湖蓝色	B = 淡浅绿色
//4 = 红色	C = 淡红色
//5 = 紫色	D = 淡紫色
//6 = 黄色	E = 淡黄色
//7 = 白色	F = 亮白色

//登入系统
void Login_System(Context* Con) {
	system("color b1");
	while (1) {
		printf( "               **********  欢迎  **********\n\n"
				"********************** 图书信息管理系统 ************************\n\n\n"
				"*            ============ 1-用户登入     ===========           *\n"
				"*                                                              *\n"
				"*            ============ 2-以游客身份登入===========          *\n"
				"*                                                              *\n"
				"*            ============ 3-管理员身份登入===========          *\n"
				"*                                                              *\n"
				"*            ============ 0-结束程序     ===========           *\n"
				"*                                                              *\n"
				"****************************************************************\n"
				" * * * * * * *请输入您的选择 ->  ");
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
			default: printf("您输入了未知的命令,请根据操作选项进行操作");
		}
	}
}
//游客登入
void Visitors_Login(Context* Con) {
	system("color e2");
	while (1) {
		system("cls");
		printf("               **********  欢迎  **********\n\n"
			"********************** 图书信息管理系统 ************************\n\n\n"
			"*            ============ 1-搜索图书     ===========           *\n"
			"*                                                              *\n"
			"*            ============ 2-查览图书目录  ===========          *\n"
			"*                                                              *\n"
			"*            ============ 3.创建新账户(并返回登录) =========== *\n"
			"*                                                              *\n"
			"*            ============ 0-返回上一步    ===========          *\n"
			"*                                                              *\n"
			"****************************************************************\n"
			" * * * * * * *请输入您的选择 ->  ");
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
			default: printf("您输入了未知的命令,请根据操作选项进行操作"); break;
		}
	}
}
//用户登入
void Users_Login(Context* Con) {
	User* U = Login(1, Con);
	
	system("color f3");
	while (1) {
		system("cls");
		printf("               **********  欢迎  **********\n\n"
			"********************** 图书信息管理系统 ************************\n\n\n"
			"*            ============ 1-搜索图书      ===========           *\n"
			"*                                                               *\n"
			"*            ============ 2-查看图书馆概况===========           *\n"
			"*                                                               *\n"
			"*            ============ 3-查览图书目录  ===========           *\n"
			"*                                                               *\n"
			"*            ============ 4-借书          ===========           *\n"
			"*                                                               *\n"
			"*            ============ 5-还书          ===========           *\n"
			"*                                                               *\n"
			"*            ============ 6-查看个人信息  ===========           *\n"
			"*                                                               *\n"
			"*            ============ 7-修改个人信息  ===========           *\n"
			"*                                                               *\n"
			"*            ============ 0-返回上一步    ===========           *\n"
			"*                                                               *\n"
			"****************************************************************\n"
			" * * * * * * *请输入您的选择 ->  ");
		int X = -1;
		scanf_s("%d", &X); getchar();
		printf("\n");
		system("cls");

		switch (X)
		{
		case 1: Search_Book(Con);										break;		//模糊搜索图书
		case 2: The_Library(Con);										break;
		case 3: Reading_Books(Con);										break;		//输出图书目录信息
		case 4: Borrow_books(U);										break;		//借书
		case 5: Return_Book(U);											break;		//还书
		case 6: Print_U(U); printf("按任意键返回上一步。"); X = Choice();	break;		//输出个人信息
		case 7: Change_Self(U);											break;		//修改个人信息
		case 0: return 0;												break;		//结束

		default: printf("您输入了未知的命令,请根据操作选项进行操作"); break;
		}
	}
}
//管理员登入
void Administrator_Login(Context* Con) {
	User* U =  Login(2, Con);
	
	system("color f4");
	while (1) {
		system("cls");
		printf("               **********  欢迎  **********\n\n"
			"********************** 图书信息管理系统 ************************\n\n\n"
			"*            ============ 1-查览图书      ===========          *\n"
			"*                                                              *\n"
			"*            ============ 2-修改图书库信息===========          *\n"
			"*                                                              *\n"
			"*            ============ 3-修改用户信息  ===========          *\n"
			"*                                                              *\n"
			"*            ============ 4-查看此账号信息===========          *\n"
			"*                                                              *\n"
			"*            ============ 0-返回上一步    ===========          *\n"
			"*                                                              *\n"
			"****************************************************************\n"
			" * * * * * * *请输入您的选择 ->  ");
		int X = -1;
		scanf_s("%d", &X); getchar();
		printf("\n");
		system("cls");

		switch (X)
		{
		case 1: Reading_Books(Con);															break;
		case 2: Change_Library_Information(Con);											break;
		case 3: Change_Users_Information(Con);												break;
		case 4: Print_U(FindU(2, U->Account)); printf("按任意键返回上一步。"); X = Choice();	break;
		case 0:	return 0; break;
		default: printf("您输入了未知的命令,请根据操作选项进行操作");							break;
		}
	}
}
//登入验证
User* Login(int P, Context* Con) {
	while (1) {
		printf("请输入账号：");
		char Co[100];
		gets(Co);
		printf("\n");

		printf("请输入密码：");
		char Pass[100];
		gets(Pass);
		printf("\n");

		User* U = FindU(P, Co);

		if (U != NULL) {
			if (strcmp(Pass, U->password) == 0) {
				printf("登入成功!!!\n");
				return U;
			}
			else {
				printf("密码错误!!!\n");
			}
		}
		else {
			printf("用户名错误!!!\n");
		}
		printf("是否继续 1 继续  任意键返回上一步 :\n");
		int X = 0;
		X = Choice();
		if (X != 1) { break; }
	}
	
}
//修改个人信息
void Change_Self(User* U) {
	Print_U(U);
	printf("1 修改密码 2 修改昵称  \n");
	int C = Choice();
	if (C == 1) {
		printf("请输入修改 的密码:");
		gets(U->password);
	}
	if (C == 2) {
		printf("请输入修改的昵称:");
		gets(U->Nickname);
	}
}
