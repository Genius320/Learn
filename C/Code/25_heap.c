#include <stdio.h>
#include <stdlib.h>

int main()
{
	//malloc(�����ڴ�ռ�)������һ����ַ
	int *p = (int *)malloc(sizeof(int));
	*p = 10;
	printf("*p = %d\n", *p);
	//�ͷ���ǰ���õ��ڴ�
	if (NULL != p)
	{
		free(p);
		p = NULL;
	}
	//��������
	p = (int *)malloc(10 * sizeof(int));
	p[0] = 1;
	*(p + 0) = 1;
	printf("p[0] = %d\n", p[0]);
	if (NULL != p)
	{
		free(p);
		p = NULL;
	}
	return 0;
}
