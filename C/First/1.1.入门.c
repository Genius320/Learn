#include <stdio.h>

int main()
{
	printf("hello world!\n");
	//printf("hello world!\c"); 	//[Warning] unkown escape sequence:'\c'
	printf("\7");
	//printf("\a");//�����
	return 0; 
} 
