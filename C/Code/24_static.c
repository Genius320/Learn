#include <stdio.h>

extern void fun();

int main()
{
	fun();
	fun();
	fun();

	return 0;
}

void fun()
{
	//static�ֲ������ڱ���׶ξͷ���ռ䣬�뿪�������ͷţ�ֻ���ó�����ʼ��
	static int i = 0;
	++i;
	printf("i = %d\n", i);
}
