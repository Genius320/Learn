#include <stdio.h>

int main()
{
	char c;
	while((c = getchar()) != EOF)
	//��CTRL + Z����EOF��end of file���ļ����� 
	{
		//printf("%d\n", c); 
		putchar(c);
	}
	printf("EOF = %d\n", EOF); 
	//��<stdio.h>
	return 0;
}
