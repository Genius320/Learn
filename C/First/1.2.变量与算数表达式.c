#include <stdio.h>

/*	��fahr=0��200������300�ǣ���ӡ���϶������϶ȶ��ձ�
	�� = (5/9)(�H-32)
	�������汾 
*/
int main()
{
	int fahr;//���϶� 
	float celsius;//���϶� 
	
	int lower, upper;
	
	lower = 0;
	upper = 300;
	
	fahr = lower;
	while(fahr <= upper)
	{
		celsius = (5.0/9.0) * (fahr - 32);
		printf("%3d\t%6.1f\n", fahr, celsius);
		fahr += 20;
	}
}
