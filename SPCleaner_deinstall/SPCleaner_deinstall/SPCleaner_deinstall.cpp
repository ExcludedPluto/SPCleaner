#include "stdafx.h"
#include "Windows.h"
#include "deinstall.h"
#include "fstream"
#include "string"

#define _WIN32_WINNT 0x0500
int main()
{
	//�����۾��̹Ƿ�, deinstall ������ �ʿ�����Ƿ� ����
	//�ܼ�â ����ä ����
	remove("deinstall.txt");
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);

	int numSP_re[21] = { 0, };

	//record2�� �ִ� ���� ����. record2���� �����ϴ� �������α׷� ��ϸ� ��������
	std::ifstream num_in_re("record_2.txt");
	for (int i = 0; i < 21; i++)
	{
		num_in_re >> numSP_re[i];
	}
	num_in_re.close();
	remove("record_2.txt");

	//���� ����
	deinstall deinstall_a(numSP_re);
	deinstall_a.choose();
	remove("choose_2.txt");


	exit(0);
	return 0;
}

