#include <stdio.h>
#include <string.h>

int main()
{
    //��һ���ַ������飬C������û���ַ������ͣ���char[]����
    char *a[] = {"A", "B", "C", "D"};
    char *b[] = {"B", "C"};

    //��ȡ��Ҫ�Ƚϵ���������ĳ���
    int lenA = sizeof(a) / sizeof(a[0]);
    int lenB = sizeof(b) / sizeof(b[0]);
    //printf("lenA = %d, lenB = %d\n", lenA, lenB);

    //�жϲ�����Ƿ��ظ�
    int i = 0, j = 0, k = 0;
    for (i = 0; i < lenA; ++i)
    {
        for (j = 0; strcmp(a[i], b[j]) != 0; ++j)
        {
            if (j == lenB - 1)
            {
                //�����ﴦ���ظ���Ԫ��a[i]
                printf("%s\n", a[i]);
            }
        }
    }

    return 0;
}
