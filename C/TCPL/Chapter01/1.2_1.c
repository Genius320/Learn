#include <stdio.h>
/*
    �� fahr = 0, 20, ..., 30ʱ��
    �ֱ��ӡ�����¶��������¶ȶ��ձ�
*/
int main()
{

    int fahr, celsius;
    int lower, upper, step;

    lower = 0;
    upper = 300;
    step = 20;

    fahr = lower;
    while (fahr <= upper) {
        celsius = 5*(fahr-32)/9;
        printf("%d\t%d\n", fahr, celsius);
        fahr = fahr + step;
    }
}