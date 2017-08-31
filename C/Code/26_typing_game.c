#include <stdio.h>
#include <conio.h>
#define MAX 51
void help();
void start(char *str);
void on_game(char *str);

int main()
{
	char str[MAX] = {0};
	while (1)
	{
		help();		//��Ϸ˵���˵�
		start(str); //���������ĸ
		getch();
		on_game(str);	  //��ʼ��Ϸ
		if (getch() == 27) //ESC
		{
			break;
		}
		system("cls"); //����
	}
	return 0;
}

void help()
{
	printf("\n*******************************************");
	printf("\n*����������޷��˳�������������� _ ��ʾ��*");
	printf("\n*���������ʼ��Ϸ����������ĸʱ��ʼ��ʱ�� *");
	printf("\n*******************************************\n\n");
}

void start(char *str)
{
	srand((unsigned int)time(NULL));
	int i;
	for (i = 0; i < MAX - 1; ++i)
	{
		*(str + i) = rand() % 26 + 'a';
	}

	*(str + i) = '\0';
}

void on_game(char *str)
{
	char ch;
	int i;
	int count = 0;
	time_t t_start, t_end;

	system("cls");
	printf("\n%s\n", str);

	for (i = 0; i < MAX - 1; ++i)
	{
		ch = getch();
		if (i == 0)
		{
			t_start = time(NULL);
		}
		if (ch == *(str + i))
		{
			putchar(ch);
			++count;
		}
		else
			putchar('_');
	}

	t_end = time(NULL);

	printf("\n������룡\n��ʱ %ld s\n", t_end - t_start);
	printf("��ȷ��%lf %%\n", ((double)count / (MAX - 1)) * 100);
}
