#include"MyCreat_library.h"

int main(int argv, char *arg[])
{
	Context Con;
	Con.BookNumber = Con.PeopleNumber = 0;							//��ʼ��ͼ�����û�������
	Con.BookName.Next = Initialize(&Con, DATABASE, "ͼ��Ŀ¼");		//��ȡͼ��Ŀ¼
	Con.People.Next	  =	Initialize(&Con, USER, "�û�Ŀ¼");			//��ȡ�û�Ŀ¼
	Login_System(&Con);
	
	Store_data(&Con, DATABASE, "ͼ��Ŀ¼");
	Store_data(&Con, USER, "�û�Ŀ¼");
}