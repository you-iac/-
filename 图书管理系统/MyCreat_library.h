#pragma once
#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#include<time.h>
#include<Windows.h>

#define CONTXT		"C:\\Users\\28695\\OneDrive\\�ĵ�\\C����\\ͼ�����ϵͳ\\"
#define DATABASE	"C:\\Users\\28695\\OneDrive\\�ĵ�\\C����\\ͼ�����ϵͳ\\ͼ���\\"
#define USER		"C:\\Users\\28695\\OneDrive\\�ĵ�\\C����\\ͼ�����ϵͳ\\�û���Ϣ\\"
#define ADMINDER	"C:\\Users\\28695\\OneDrive\\�ĵ�\\C����\\ͼ�����ϵͳ\\����Ա��Ϣ\\"


typedef struct {
	char Write[100];		//����
	int Location;			//λ�ñ��
	struct tm AddTime;		//���ʱ��
	struct tm CanRTime;		//Ԥ��ʱ��
} Situation;

typedef struct  {
	char Serial_number[20];		//�鼮���
	char Name[100];			//����
	char Type[100];
	Situation S;			//�鼮������Ϣ
	int Init;				//�鼮����
	struct node* Next;
} Book;

typedef struct N{		//Ŀ¼��¼һ�������� ���� �飩��һ����Ϣ���㴢��
	char label[100];
	struct node* Next;
} Node;
typedef Node List;


typedef struct C {		//Ŀ¼��¼һ�������� ���� �飩��һ����Ϣ���㴢��
	Node BookName;
	long long BookNumber;
	Node People;
	long long PeopleNumber;
} Context;


typedef struct {
	char Account[100];	//�˺�
	char password[100];	//����
	char Nickname[100]; //�ǳ�
	Node Book[5];		//ÿ������� 5 ����
	int N;
	int Is;
} User;



Node* Initialize(Context* P, char FContext[], char FName[]);	//��ȡ����
Node* Store_data(Context* P, char FContext[], char FName[]);	//��������
Node*		MakeNew_Node(char Label[]);							//�����±�ǩ�ڵ�
Book*		MakeNew_Book(int P);								//��������
Situation*	Make_Situation(int P);								//����ͼ�������Ϣ
struct tm*	Make_Time(int P);									//����ʱ����Ϣ
User*		MakeNew_User(int P);								// 0 �����յ� people 1 �����ǿ�
Book*		Print_B(Book* book_List);							//���һ���鼮
Situation*	Print_Situation(Situation* S);
User*		Print_U(User* U);									//���һ��PEOPLE��Ϣ
Book* FindB(char BookName[]);									//Ѱ��ͼ�鷵��
Book* AddB(Book* B);											//���һ���µ�ͼ��
User* FindU(int P, char Text[]);								//Ѱ���û���1����ͨ�û���2������Ա   ���˺Ų���
User* AddU(User* U);											//����û�
char* FindF(char FContext[], char FName[]);						//���� λ�� �� �ļ��� �����������λ�ö�λ���ַ��� ����


void Login_System(Context* Con);						//����ϵͳ
void Visitors_Login(Context* Con);						//�ο͵���
void Users_Login(Context* Con);							//�û�����
void Administrator_Login(Context* Con);					//����Ա����
void Change_Self(User* U);								//�޸ĸ�����Ϣ
User* Login(int P, Context* Con);						//������֤

void Change_Library_Information(Context* Con);			//�޸�ͼ����Ϣ
void Change_Users_Information(Context* Con);			//�޸��û���Ϣ
void Reading_Books(Context* Con);						//���ͼ��
void Add_Books(Context* Con);							//�����ͼ��
void Change_Books(Context* Con);						//�޸�ͼ��
void Add_Users(int p, Context* Con);					//����û�
void Change_Users(int p, Context* Con);					//�޸��û�
void Deal_Users(int p, Context* Con);					//ɾ���û�
void Deal_Book(Context* Con);							//ɾ��ͼ��
int	 Choice();											//ѡ��
void Borrow_books(User* U);								//����
void Return_Book(User* U);								//����
void Search_Book(Context* Con);							//ģ������ͼ��
Node* OutputPeo(Node* P);								//�����ǩ��Ϣ
int	 CheckB(Book* B);

Node* List_output(Node* L);					//�����ǩ
Node* List_add(Node* list, Node* L);		//�����ͷ����ӵĽڵ�ָ�룬��β����ӣ�Ȼ�󷵻�
Node* List_del(Node* list, char Name[]);	//ɾ��
int	  int_size(double a, double b);