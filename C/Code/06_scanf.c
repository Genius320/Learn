
#include <stdio.h>

int main()
{
	int a;
	printf("������a��");
	scanf("%d", &a);
	printf("a = %d\n", a);

	int b;
	int c;
	printf("������b c:");
	scanf("%d %d", &b, &c);
	printf("b = %d, c = %d\n", b, c);

	//�����һ����\n��������
	char d;
	scanf("%c", &d);
	//d = getchar();

	char e;
	printf("�������ַ�e��");
	scanf("%c", &e);
	//e = getchar();
	printf("e = %c\n", e);

	return 0;
}
