#include"MyCreat_library.h"

int main(int argv, char *arg[])
{
	Context Con;
	Con.BookNumber = Con.PeopleNumber = 0;							//初始化图书与用户的数量
	Con.BookName.Next = Initialize(&Con, DATABASE, "图书目录");		//获取图书目录
	Con.People.Next	  =	Initialize(&Con, USER, "用户目录");			//获取用户目录
	Login_System(&Con);
	
	Store_data(&Con, DATABASE, "图书目录");
	Store_data(&Con, USER, "用户目录");
}