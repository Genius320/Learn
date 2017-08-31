#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "des.h"

#define SIZE_4K 1024*4

void menu();
void EncFile();
void DecFile();

int main()
{
    int cmd = 0;
    while(1)
    {
        menu();
        printf("cmd:");
        scanf("%d", &cmd);
        //printf("cmd = %c\n", cmd);
        switch(cmd)
        {
        case 1:
            EncFile();
            break;
        case 2:
            DecFile();
            break;        
        case 3:
            system("cls");
            break;
        default:
            exit(0);
            break;
        }
    } 
    system("pause");
    return 0;
}

void menu()
{
	printf("=====================\n");
	printf("1 encrypt file\n");
	printf("2 decrypt file\n");
	printf("3 clear\n");
	printf("4 exit\n");
	printf("=====================\n");
}

void EncFile()
{
    FILE *rFd = NULL;
	FILE *wFd = NULL;
	char rPath[512] = { 0 }; //Դ�ļ�·���� ��Ҫ�����ļ�·
	char wPath[512] = { 0 }; //Ŀ��·���� ������ܺ���ļ�
	unsigned char srcBuf[SIZE_4K] = { 0 }; //SIZE_4K
	int rLen = 0;
	unsigned char dstBuf[SIZE_4K] = { 0 }; //SIZE_4K
	int wLen = 0;
	int ret = 0;
    printf("please enter the file you want to encrypt:");
	scanf("%s", rPath);

	printf("please enter the file after encrypt:");
	scanf("%s", wPath);

    //��Դ�ļ�
    rFd = fopen(rPath, "rb+");
    if(rFd == NULL)
    {
        perror("EncFile fopen rPath");
        return;
    }

    //��Ŀ���ļ�
    wFd = fopen(wPath, "wb+");
    if(wFd == NULL)
    {
        perror("EncFile fopen wPath");
        return;
    }

    //ѭ�����ļ�������SIZE_4K
    while((rLen = fread(srcBuf, 1, SIZE_4K, rFd)) == SIZE_4K)
    {
        //�����ļ�
        ret = DesEnc_raw(srcBuf, rLen, dstBuf, &wLen);
        if(ret != 0)
        {
            printf("DesEnc_raw err\n");
            goto End;
            return;
        }
        //д�����ļ�
        ret = fwrite(dstBuf, 1, wLen, wFd);
        if(ret != wLen)
        {
            printf("EncFile write_raw err\n");
            goto End;
            return;
        }
    }
    //�����ļ���С��SIZE_4K
    ret = DesEnc(srcBuf, rLen, dstBuf, &wLen);
    if(ret != 0)
    {
        printf("DesEnc err\n");
        goto End;
        return;
    }
    //д�����ļ�
    ret = fwrite(dstBuf, 1, wLen, wFd);
    if(ret != wLen)
    {
        printf("EncFile write err\n");
        goto End;
        return;
    }
//�ر��ļ�
End:
    if(rFd != NULL)
        fclose(rFd);
    if(wFd != NULL)
        fclose(wFd);

}

void DecFile()
{
    FILE *rFd = NULL;
	FILE *wFd = NULL;
	char rPath[512] = { 0 }; //Դ�ļ�·���� ��Ҫ��ȡ�ļ�·
	char wPath[512] = { 0 }; //Ŀ��·���� ������ܺ���ļ�
	unsigned char srcBuf[SIZE_4K] = { 0 }; //SIZE_4K
	int rLen = 0;
	unsigned char dstBuf[SIZE_4K] = { 0 }; //SIZE_4K
	int wLen = 0;
	int ret = 0;
    printf("please enter the file you want to decrypt:");
	scanf("%s", rPath);

	printf("please enter the file after decrypt:");
	scanf("%s", wPath);

    //��Դ�ļ�
    rFd = fopen(rPath, "rb+");
    if(rFd == NULL)
    {
        perror("DecFile fopen rPath");
        return;
    }

    //��Ŀ���ļ�
    wFd = fopen(wPath, "wb+");
    if(wFd == NULL)
    {
        perror("DecFile fopen wPath");
        return;
    }

    //ѭ�����ļ�������SIZE_4K
    while((rLen = fread(srcBuf, 1, SIZE_4K, rFd)) == SIZE_4K)
    {
        //�����ļ�
        ret = DesDec_raw(srcBuf, rLen, dstBuf, &wLen);
        if(ret != 0)
        {
            printf("DesDec_raw err\n");
            goto End;
            return;
        }
        //д�����ļ�
        ret = fwrite(dstBuf, 1, wLen, wFd);
        if(ret != wLen)
        {
            printf("DecFile write_raw err\n");
            goto End;
            return;
        }
    }
    //�����ļ���С��SIZE_4K
    ret = DesDec(srcBuf, rLen, dstBuf, &wLen);
    if(ret != 0)
    {
        printf("DesDec err\n");
        goto End;
        return;
    }
    //д�����ļ�
    ret = fwrite(dstBuf, 1, wLen, wFd);
    if(ret != wLen)
    {
        printf("DecFile write err\n");
        goto End;
        return;
    }
//�ر��ļ�
End:
    if(rFd != NULL)
        fclose(rFd);
    if(wFd != NULL)
        fclose(wFd);

}