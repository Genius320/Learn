#include <stdio.h>

int main()
{
	int a = 10;
	//const ����*p����ָ����ָ���ڴ�ֻ��
	const int *p = &a;
	//*p = 100;		//assignment of read-only location '*p'
	p = NULL;

	return 0;
}
