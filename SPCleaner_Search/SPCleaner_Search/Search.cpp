#include "stdafx.h"
#include "Windows.h"
#include "atlpath.h"
#include "iostream"
#include "cstdio"
#include "fstream"
#include "string"
#include "atlconv.h"
#include "Search.h"
#include "classify.h"


#define _WIN32_WINNT 0x0500 //������ 2000������ ���ư��ٰ� ����ϴ°�. ������ 2000�̻� �ִ� �Լ��� ����Ҷ� ����
#ifdef _UNICODE				//UNICODE�� ���ǵǾ�������
#define cout wcout			//cout�� �ƴ϶� wcout ���. wchar_t �� ����� ����̴�.
#endif

int main()
{
	remove("deinstall.txt");
	remove("record_2.txt");
	remove("choose_2.txt");
	HWND hWnd = GetConsoleWindow();	//�ܼ� ����鼭 ����
	ShowWindow(hWnd, SW_HIDE);

	int numSP = 0;

	std::string PathSP;
	std::ifstream Readfile_P("PathSP.txt");

	std::string checkSP;
	std::ifstream Readfile_C("CheckSP.txt");


	int numSP_re[21] = { 0, };
	int inBK_re[17][5] = { 0 };

	for (int i = 0; i < 21; i++)
	{
		getline(Readfile_P, PathSP);
		getline(Readfile_C, checkSP);
		USES_CONVERSION; //�����ڵ�� �Ƚ� ������ ��ȯ�� �����ϰ� ����.
		//CString : wchar_t	������ �����ڵ� ���ڿ� ����
		CString Path = A2T(PathSP.c_str());  //	A2T : ANSI�� �����ڵ�� �ٲ���, .c_str() : string�� char*�� �ٲ���.
		SearchSP *Sclass = new SearchSP(Path, _T(".exe"), checkSP, numSP, numSP_re);
		Sclass->FindFiles();

		numSP++;
	}
	Readfile_P.close();
	Readfile_C.close();

	//classifiedBK ���Ͽ� ���� �����ϴ� ������ ��ȣ : ��������� ���
	classify classify_a(numSP_re, inBK_re);
	int check = classify_a.checkBK();

	//record ���Ͽ� ���� �����ϴ� ���� ���� + ����� ���
	std::ofstream num_in_re;
	num_in_re.open("record.txt");
	for (int i = 0; i < 21; i++)
	{
		num_in_re << numSP_re[i] << "\t";
	}
	for (int i = 0; i < 17; i++)
	{
		for (int k = 0; k < 5; k++)
		{
			num_in_re << inBK_re[i][k] << "\t";
		}
	}
	num_in_re << check;
	num_in_re.close();

	TCHAR programpath[_MAX_PATH];
	GetCurrentDirectory(_MAX_PATH, programpath);

	USES_CONVERSION;
	CString Path_1 = "\\eliminator_3.exe";
	CString Path_2 = programpath;
	CString Path = Path_2 + Path_1;
	ShellExecute(NULL, A2T("open"), Path, NULL, NULL, SW_SHOW); //eliminator 3 ����

	exit(1);
	return 0;
}

