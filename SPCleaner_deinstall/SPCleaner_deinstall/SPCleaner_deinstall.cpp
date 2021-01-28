#include "stdafx.h"
#include "Windows.h"
#include "deinstall.h"
#include "fstream"
#include "string"

#define _WIN32_WINNT 0x0500
int main()
{
	//삭제작업이므로, deinstall 파일은 필요없으므로 삭제
	//콘솔창 숨긴채 진행
	remove("deinstall.txt");
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);

	int numSP_re[21] = { 0, };

	//record2에 있는 내용 복사. record2에는 현존하는 보안프로그램 목록만 적혀있음
	std::ifstream num_in_re("record_2.txt");
	for (int i = 0; i < 21; i++)
	{
		num_in_re >> numSP_re[i];
	}
	num_in_re.close();
	remove("record_2.txt");

	//삭제 진행
	deinstall deinstall_a(numSP_re);
	deinstall_a.choose();
	remove("choose_2.txt");


	exit(0);
	return 0;
}

