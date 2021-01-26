#include "stdafx.h"
#include "Windows.h"
#include "string"
#include "compareBK.h"
#include "atlpath.h"
#include "atlconv.h"
#include "iostream"
#include "cstdio"
#include "fstream"

#define _WIN32_WINNT 0x0500


int main()
{
	//윈도우 숨긴채 실행
	HWND hWnd = GetConsoleWindow();
	ShowWindow(hWnd, SW_HIDE);	
	
	int numSP_re[21] = { 0, };	//프로그램 목록. 0 1로 나타냄 
	int inBK_re[17][5] = { 0 };	//각은행이 가지는 보안프로그램 목록을 저장. 한은행에 최대 5개까지 있음.
	int check =0;

	std::ifstream num_in_re("record.txt");

	for (int i = 0; i < 21; i++)
	{
		num_in_re >> numSP_re[i];
	}
	for (int i = 0; i < 17; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			num_in_re >> inBK_re[i][k];
		}
	}
	num_in_re >> check;
	num_in_re.close();
	remove("record.txt");
	remove("classifiedBK.txt");

	compareBK compare_a(inBK_re, numSP_re);
	compare_a.choose(check);

	remove("choose.txt");
	std::ofstream num_in_re2;
	num_in_re2.open("record_2.txt");
	for (int i = 0; i < 21; i++)
	{
		num_in_re2 << numSP_re[i]<< "\t";
	}

	compare_a.print();

	TCHAR programpath[_MAX_PATH];
	GetCurrentDirectory(_MAX_PATH, programpath);
	CString Path_1_f = "\\eliminator_5.exe";
	CString Path_2_f = programpath;
	CString Path_f = Path_2_f + Path_1_f;
	USES_CONVERSION;
	ShellExecute(NULL, A2T("open"), Path_f, NULL, NULL, SW_SHOW);
	
	
	exit(1);
    return 0;
}

