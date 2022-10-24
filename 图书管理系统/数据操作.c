#include"MyCreat_library.h"
//读取数据
Node* Initialize(Context* P, char FContext[], char FName[])			//传入链表和操作 1用户库信息，2管理员库信息
{
	
	Node* Buff = NULL;
	printf("读取%s中\n", FName);
	
	FILE* F = NULL;
	char Fa[200];
	strcpy_s(Fa, 200,FindF(FContext, FName));
	fopen_s(&F, Fa, "r");
	if (F != NULL) {
		
		while (1) {
			Node* L = MakeNew_Node("");					//创建一个BUFF节点
			
			fread(L, sizeof(Node), 1, F);				//读取操作，将信息读到BUFF L 中
			L->Next = NULL;
			if (feof(F) != 0) { free(L); break; }		//读取查找判断结束条件
			L->Next = Buff, Buff = L;
			if (strcmp(FName, "图书目录") == 0) {
				P->BookNumber = P->BookNumber + FindB(L->label)->Init;
			}
			else {
				P->PeopleNumber++;
			}
		}
		fclose(F);
	}
	else { printf("无法打开文件\n"); }
	printf("读取数据成功！！！\n");

	return Buff;
}
//储存数据
Node* Store_data(Context* P, char FContext[], char FName[]) {
	Node* L = NULL;
	if ( strcmp(FName , "图书目录") == 0 ){
		L = P->BookName.Next;
	}
	else {
		L = P->People.Next;
	}

	printf("储存%s中\n", FName);

	FILE* F = NULL;
	char Fa[200];
	strcpy_s(Fa, 200, FindF(FContext, FName));
	fopen_s(&F, Fa, "w");
	if (F != NULL) {
		while (L) {
			fwrite(L, sizeof(Node), 1, F);			//读取操作，将信息读到BUFF L 中
			L = L->Next;
		}
		fclose(F);
	}
	else { printf("无法打开文件\n"); }
	printf("储存数据成功！！！\n");
	
	return 0;
}


//创建新标签节点
Node* MakeNew_Node(char Label[]) {
	Node* p = (Node*)malloc(sizeof(Node));
	p->Next = NULL;
	strcpy_s(p->label, 100, Label);
	return p;
}

//创建新书
Book* MakeNew_Book(int P)		//创建新节点         //创建节点  P == 0创建空节点 P == 1 创建新节点
{
	Book* L = (Book*)malloc(sizeof(Book));
	L->Next = NULL;

	if (P == 0) {
		char Serial_number[20] = "书籍编号";

		strcpy_s(L->Serial_number, 20, Serial_number);		//创建0书籍编号
		
		char Name[100] = "书名";		//创建一个书的名字叫书名
		strcpy_s(L->Name, 100, Name);
		
		char Type[100] = "类型";
		strcpy_s(L->Name, 100, Type);

		Situation* p = Make_Situation(0);
		L->S = *p;		//创建一个空的书籍情况
		free(p);
		L->Init = 0;
	}
	else {
		printf("请设置书籍编号：");
		gets(L->Serial_number);
		printf("\n");

		printf("请输入书籍名称：");
		gets(L->Name);
		printf("\n");

		printf("请为书籍分类：");
		gets(L->Type);
		printf("\n");

		Situation* p = Make_Situation(1);
		L->S = *p;		//创建一个书籍情况
		free(p);

		printf("请输入图书数量：");
		scanf_s("%d", &L->Init);
		
		int X = -1;
		while (X != 0) {
			X = CheckB(L);
		}
	}
	return L;
}
//创建图书情况信息
Situation* Make_Situation(int P)	//创建节点  P == 0创建空节点 P == 1 创建新
{
	Situation* S = (Situation*)malloc(sizeof(Situation));

	struct tm* p = NULL;
	if (P == 0) {
		char Write[100] = "作者";
		strcpy_s(S->Write, 100, Write);
		S->Location = 0;

		p = Make_Time(0);
		S->AddTime = *p;
		//free(p);
		p = Make_Time(0);
		S->CanRTime = *p;
		//free(p);
	}
	else {
		printf("请输入作者：");
		

		gets(S->Write);
		printf("\n");

		printf("请输入位置编号（数字编号）：");
		scanf_s("%d", &S->Location);
		printf("\n");

		p = Make_Time(1);
		S->AddTime = *p;
		//free(p);
		p = Make_Time(1);
		S->CanRTime = *p;
		//free(p);
	}
	return S;
}
//创建时间信息
struct tm* Make_Time(int P) {			//创建时间结构，0空，1获取当前时间 返回指针;
	struct tm p;
	time_t lt;
	if (P == 0) {
		lt = 0;
		localtime_s(&p, &lt);
	}
	else {
		lt = time(NULL);
		localtime_s(&p, &lt);
	}
	return &p;
}
//创建新节点
User* MakeNew_User(int P) {				// 0 创建空的 people 1 创建非空
	User* U = (User*)malloc(sizeof(User));

	if (P == 0) {
		strcpy_s(U->password, 100, "-1");
		U->Is = 0;
		U->N = 0;
	}
	else {
		printf("请输入账号：");
		gets(U->Account);

		printf("请输入密码：");
		gets(U->password);

		if (P == 1) {
			printf("请输入昵称：");
			gets(U->Nickname);
		}
		U->Is = 0;
		U->N = 0;

		CheckP(U);
	}
	return U;
}
//输出一个新图书
Book* Print_B(Book* book_List)	//输出一个书籍
{
	Book* L = book_List, *p = L;
	if (L == NULL) { 
		printf("在 Print_Node 中 传入了一个空指针\n");
	}
	else {
		printf("书籍编号 ：%s\n", L->Serial_number);
		printf("\n");
		
		printf("书名 ：   %s\n", L->Name);
		printf("\n");
		
		Print_Situation(&L->S);

		printf("图书类型 ：%s", L->Type);
		printf("\n");

		printf("书籍 %d 在库中\n", L->Init);
		printf("\n");
	}
	return 0;
}
//
Situation* Print_Situation(Situation* S) {
	if (S == NULL) {
		printf("在 Print_Situation 中 传入了一个空指针");
	}
	else {
		
		printf("书籍作者：            %s\n", S->Write);
		printf("\n");
		printf("书籍位置编号：        %d\n", S->Location);
		printf("\n");
		printf("书籍入库时间:         %d %d %d\n", S->AddTime.tm_year+1900, S->AddTime.tm_mon+1, S->AddTime.tm_mday);
		printf("\n");
		printf("书籍预计下次在库时间： %d %d %d\n", S->CanRTime.tm_year+1900, S->CanRTime.tm_mon+1, S->CanRTime.tm_mday);
		printf("\n");
	}
	return 0;
}
//输出一个PEOPLE信息
User* Print_U(User* U) {
	printf("账号：%s\n", U->Account);
	printf("\n");
	printf("昵称：%s\n", U->Nickname);
	printf("\n");
	if (U->Is == 0) {
		printf("账号密码：%s\n", U->password);
		printf("\n");
		int i = 0;
		printf("借阅图书：\n");
		printf("\n");
		for (i = 0; i < U->N; i++) {
			printf( "%d %s\n",i+1 , U->Book[i].label);
		}
		printf("\n");
	}

}
//寻找图书返回
Book* FindB(char BookName[]) {
	FILE* F = NULL;		//得到文件指针
	Book* B = MakeNew_Book(0);					//创建 空 Book 
	
	char Fa[200];
	strcpy_s(Fa, 200, FindF(DATABASE, BookName));

	fopen_s(&F, Fa, "r");
	if (F == NULL) {
		printf("库中没有%s\n", BookName);
		return 0;
	}
	else {
		fread(B, sizeof(Book), 1, F);			//读文件
	}
	fclose(F);									//关闭文件
	return B;
}
//添加一本新的图书
Book* AddB(Book* B) {
	FILE* F = NULL;		//得到文件指针

	char Fa[200];
	strcpy_s(Fa, 200, FindF(DATABASE, B->Name));

	fopen_s(&F, Fa, "w");		//得到用户文件指针
	if (F == NULL) { printf("在 AddB 函数 中 文件指针为空\n"); }
	else {
		fwrite(B, sizeof(Book), 1, F);		//写入
	}
	fclose(F);			//关闭文件
	return B;
}
//寻找用户（1）普通用户（2）管理员   按账号查找
User* FindU(int P, char Text[]) {
	FILE* F = NULL;
	User* U = MakeNew_User(0);

	char Fa[200];
	
	if (P == 1) {
		strcpy_s(Fa, 200, FindF(USER, Text));
		fopen_s( &F, Fa, "r");			//得到用户文件指针
	}
	else {
		strcpy_s(Fa, 200, FindF(ADMINDER, Text));
		fopen_s(&F, Fa, "r");		//得到管理员文件指针
	}
	
	if (F == NULL) { printf("库中找不到 %s\n", Text); return 0; }	//读文件
	else {
		fread(U, sizeof(User), 1, F);
	}
	fclose(F);											//关闭文件
	return U;
}
//添加用户
User* AddU(User* U) {
	FILE* F = NULL;
	char Fa[200];
	
	if (U->Is == 0) {
		strcpy_s(Fa, 200, FindF(USER, U->Account));
		fopen_s(&F, Fa, "w");			//得到用户文件指针
	}
	else {
		strcpy_s(Fa, 200, FindF(ADMINDER, U->Account));
		fopen_s(&F, Fa, "w");		//得到管理员文件指针
	}
	if (F == NULL) { printf("在 AddU 函数 中 文件指针为空\n"); }			//读文件
	else {
		fwrite(U, sizeof(User), 1, F);		//写入
	}
	
	fclose(F);			//关闭文件
	return U;
}
//传入 位置 和 文件名 传可用与绝对位置定位的字符串 返回
char* FindF(char FContext[], char FName[]) {
	char BUFF[200];					//中间字符串的作用
	strcpy_s(BUFF, 160, FContext);		//复制文件位置
	strcat_s(BUFF, 200, FName);		//添加文件名字
	strcat_s(BUFF, 200, ".txt");		//添加 字符串 .txt
	return BUFF;
}
//检查新建立的图书
int CheckB(Book* B) {

	int T = 0;
	FILE* F = NULL;
	char Fa[200];
	strcpy_s(Fa, 200, FindF(DATABASE, B->Name));

	fopen_s(&F, Fa, "r");
	if (F != NULL) {
		printf("这本 %d 已经存在库中\n", B->Name);
		printf("请重新设置：\n");
		printf("请输入书籍名称：");
		gets(B->Name);
		printf("\n");T++;
		fclose(F);
		
	}

	if (strlen(B->Name) == 0) {
		printf("图书 Name 字符串长度为空 可能出现了严重的错误\n");
		printf("请重新设置：\n");
		printf("请输入书籍名称：");
		gets(B->Name);
		printf("\n"); T++;
	}
	if (strlen(B->Serial_number) == 0) {
		printf("图书 Serial_number 字符串长度为空 可能出现了严重的错误\n");
		printf("请重新设置：\n");
		printf("请设置书籍编号：");
		gets(B->Serial_number);
		printf("\n"); T++;
	}
	if (strlen(B->Type) == 0) {
		printf("图书 Type 字符串长度为空 可能出现了严重的错误\n");
		printf("请重新设置：\n");
		printf("请为书籍分类：");
		gets(B->Type);
		printf("\n"); T++;
	}
	if (strlen(B->S.Write) == 0) {
		printf("图书 Write 字符串长度为空 可能出现了严重的错误\n");
		printf("请重新设置：\n");
		printf("请输入作者：");
		gets(B->S.Write);
		printf("\n"); T++;
	}

	return T;
}
int CheckP(User* B) {
	FILE* F = NULL;
	char Fa[200];
	strcpy_s(Fa, 200, FindF(DATABASE, B->Account));

	if (F != NULL) {
		printf(" %s 已经存在库中\n", B->Account);
		printf("请重新设置：\n");
		printf("重新输入账号：");
		gets(B->Account);
		printf("\n");
		fclose(F);
	}
	if (strlen(B->Account) == 0) {
		printf("图书 Account 字符串长度为空 可能出现了严重的错误\n");
		printf("请重新设置：\n");
		printf("请输入账号：");
		gets(B->Account);
		printf("\n");
	}
	if (strlen(B->password) == 0) {
		printf("图书 password 字符串长度为空 可能出现了严重的错误\n");
		printf("请重新设置：\n");
		printf("请输入密码：");
		gets(B->password);
		printf("\n");
	}

}

void The_Library(Context* Con) {
	
	printf("共有图书 %d 册\n\n", Con->BookNumber);

	printf("共有用户 %d 名\n\n", Con->PeopleNumber);

	int sum = 0;
	Node* p = Con->People.Next;
	
	while (p) {
		sum += FindU(1, p->label)->N;
		p = p->Next;
	}

	printf("共有 %d 本图书借出\n\n", sum);
	printf("按任意键继续。"); int X = Choice();
}