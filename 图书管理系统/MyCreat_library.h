#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include<Windows.h>

#define CONTXT		"C:\\Users\\28695\\OneDrive\\文档\\C语言\\图书管理系统\\"
#define DATABASE	"C:\\Users\\28695\\OneDrive\\文档\\C语言\\图书管理系统\\图书库\\"
#define USER		"C:\\Users\\28695\\OneDrive\\文档\\C语言\\图书管理系统\\用户信息\\"
#define ADMINDER	"C:\\Users\\28695\\OneDrive\\文档\\C语言\\图书管理系统\\管理员信息\\"


typedef struct {
	char Write[100];		//作者
	int Location;			//位置编号
	struct tm AddTime;		//入库时间
	struct tm CanRTime;		//预计时间
} Situation;

typedef struct  {
	char Serial_number[20];		//书籍编号
	char Name[100];			//书名
	char Type[100];
	Situation S;			//书籍基本信息
	int Init;				//书籍数量
	struct node* Next;
} Book;

typedef struct N{		//目录记录一个对象（人 或者 书）的一种信息方便储存
	char label[100];
	struct node* Next;
} Node;
typedef Node List;


typedef struct C {		//目录记录一个对象（人 或者 书）的一种信息方便储存
	Node BookName;
	long long BookNumber;
	Node People;
	long long PeopleNumber;
} Context;


typedef struct {
	char Account[100];	//账号
	char password[100];	//密码
	char Nickname[100]; //昵称
	Node Book[5];		//每个人最多 5 本书
	int N;
	int Is;
} User;



Node* Initialize(Context* P, char FContext[], char FName[]);	//读取数据
Node* Store_data(Context* P, char FContext[], char FName[]);	//储存数据
Node*		MakeNew_Node(char Label[]);							//创建新标签节点
Book*		MakeNew_Book(int P);								//创建新书
Situation*	Make_Situation(int P);								//创建图书情况信息
struct tm*	Make_Time(int P);									//创建时间信息
User*		MakeNew_User(int P);								// 0 创建空的 people 1 创建非空
Book*		Print_B(Book* book_List);							//输出一个书籍
Situation*	Print_Situation(Situation* S);
User*		Print_U(User* U);									//输出一个PEOPLE信息
Book* FindB(char BookName[]);									//寻找图书返回
Book* AddB(Book* B);											//添加一本新的图书
User* FindU(int P, char Text[]);								//寻找用户（1）普通用户（2）管理员   按账号查找
User* AddU(User* U);											//添加用户
char* FindF(char FContext[], char FName[]);						//传入 位置 和 文件名 传可用与绝对位置定位的字符串 返回


void Login_System(Context* Con);						//载入系统
void Visitors_Login(Context* Con);						//游客登入
void Users_Login(Context* Con);							//用户登入
void Administrator_Login(Context* Con);					//管理员登入
void Change_Self(User* U);								//修改个人信息
User* Login(int P, Context* Con);						//登入验证

void Change_Library_Information(Context* Con);			//修改图书信息
void Change_Users_Information(Context* Con);			//修改用户信息
void Reading_Books(Context* Con);						//浏览图书
void Add_Books(Context* Con);							//新添加图书
void Change_Books(Context* Con);						//修改图书
void Add_Users(int p, Context* Con);					//添加用户
void Change_Users(int p, Context* Con);					//修改用户
void Deal_Users(int p, Context* Con);					//删除用户
void Deal_Book(Context* Con);							//删除图书
int	 Choice();											//选择
void Borrow_books(User* U);								//借书
void Return_Book(User* U);								//还书
void Search_Book(Context* Con);							//模糊搜索图书
Node* OutputPeo(Node* P);								//输出标签信息
int	 CheckB(Book* B);

Node* List_output(Node* L);					//输出标签
Node* List_add(Node* list, Node* L);		//传入表头和添加的节点指针，在尾部添加，然后返回
Node* List_del(Node* list, char Name[]);	//删除
int	  int_size(double a, double b);