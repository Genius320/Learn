#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
	//��������
	//time(NULL)��ȡ��ͬ��ǰʱ��
	srand((unsigned int)time(NULL));
	//srand(100);

	int i, num;
	for (i = 0; i < 10; i++)
	{
		num = rand(); //rand()���������
		printf("num = %d\n", num);
	}
	return 0;
}
