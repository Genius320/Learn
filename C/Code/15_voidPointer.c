#include <stdio.h>

int main()
{
	//����һ������ָ�룬����ָ���κ����͵ı���
	void *p = NULL;

	int a = 10;
	p = &a;

	*(int *)p = 100;
	printf("*p = %d\n", *(int *)p);

	return 0;
}
