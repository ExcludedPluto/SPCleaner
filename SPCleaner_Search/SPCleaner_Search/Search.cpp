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


#define _WIN32_WINNT 0x0500 //윈도우 2000에서만 돌아간다고 명시하는것. 윈도우 2000이상에 있는 함수를 사용할때 적음
#ifdef _UNICODE				//UNICODE가 정의되어잇으면
#define cout wcout			//cout이 아니라 wcout 사용. wchar_t 를 사용한 출력이다.
#endif

int main()
{
	remove("deinstall.txt");
	remove("record_2.txt");
	remove("choose_2.txt");
	HWND hWnd = GetConsoleWindow();	//콘솔 숨기면서 실행
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
		USES_CONVERSION; //유니코드와 안시 사이의 변환을 간단하게 해줌.
		//CString : wchar_t	형으로 유니코드 문자열 지원
		CString Path = A2T(PathSP.c_str());  //	A2T : ANSI를 유니코드로 바꿔줌, .c_str() : string을 char*로 바꿔줌.
		SearchSP *Sclass = new SearchSP(Path, _T(".exe"), checkSP, numSP, numSP_re);
		Sclass->FindFiles();

		numSP++;
	}
	Readfile_P.close();
	Readfile_C.close();

	//classifiedBK 파일에 현재 존재하는 은행을 번호 : 은행명으로 기록
	classify classify_a(numSP_re, inBK_re);
	int check = classify_a.checkBK();

	//record 파일에 현재 존재하는 파일 정보 + 은행명 기록
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
	ShellExecute(NULL, A2T("open"), Path, NULL, NULL, SW_SHOW); //eliminator 3 실핼

	exit(1);
	return 0;
}

