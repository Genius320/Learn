
#include <stdio.h>

int main()
{
	//����һ����ָ��
	int *p = NULL;
	int a = 10;
	//��a�ĵ�ַ����ָ�룬ָ��ָ��a
	p = &a;

	//����ָ����ָ����ڴ�
	if (p != NULL)
		*p = 100;

	//*p�ȼ���p[0]
	printf("*p = %d, a = %d, p[0] = %d\n", *p, a, p[0]);
	printf("p = %p, &a = %p\n", p, &a);
	printf("&p = %p\n", &p);

	return 0;
}
