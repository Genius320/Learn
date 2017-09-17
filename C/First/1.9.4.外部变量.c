#include <stdio.h>
#define MAXLINE 100

int getline();
void copy();

int max;				// ĿǰΪֹ���ֵ���еĳ��� 
char line[MAXLINE];		//��ǰ�������� 
char longest[MAXLINE];	//����� 

int main()
{
	int len;				//��ǰ�г���
	extern int max;			//��ÿ����Ҫ�����ⲿ�����ĺ����У�����������Ӧ���ⲿ������˵��������
	extern char longest[];
	 
	max = 0;
	while((len = getline()) > 0)
	{
		printf("len = %d\n", len);
		if(len > max)
		{
			max = len;
			copy();	
		}	
	} 
	if(max > 0)
	{
		printf("max = %d, %s", max, longest);
	}
	return 0;
}

/*getline��������һ�ж��뵽line�в������䳤��*/
int getline()
{
	
	int c, i;
	extern char line[];
	
	for(i = 0; (c = getchar()) != EOF && c != '\n'; ++i)
	{
		if(i < MAXLINE - 2)
		{
			line[i] = c;
		}		
	}
	if(c == '\n')
	{
		line[i] = c;
		++i;	
	}
	line[i] = '\0';
	return i-1;
}

/*copy��������line���Ƶ�longest*/
void copy()
{
	int i;
	extern char line[], longest[];
	i = 0;
	while((longest[i] = line [i]) != '\0')
		++i;
}

