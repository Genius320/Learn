#include <Windows.h>

int main()
{
	Sleep(3000);
	//��ָ���ľ��������Ϣ,����һ��������������Ϣ����vs spy�����
	SendMessage((HWND)0x000607B2, WM_LBUTTONDOWN, 0, 0);
	SendMessage((HWND)0x000607B2, WM_LBUTTONUP, 0, 0);
	return 0;
}
