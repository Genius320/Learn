#include <stdio.h>

void fun1()
{
	printf("fun1():�޲��޷���ֵ����\n");
}

void fun2(int a)
{
	printf("fun2():�в��޷���ֵ�ĺ���������%d\n", a);
}

int fun3()
{
	printf("fun3():���з���ֵ�ĺ���\n");
	return 0;
}

int fun4(int a)
{
	printf("fun4():�в��з���ֵ�ĺ���\n");
	//exit(250);		//��������
	return a;
}

int main()
{
	fun1();
	fun2(10);
	printf("fun3()����ֵΪ%d\n", fun3());
	printf("fun4()����ֵΪ%d\n", fun4(10));
	return 0;
}
