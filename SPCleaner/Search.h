#include <Windows.h>
#include <atlpath.h>
#include <atlconv.h>
#include <string>

#ifndef __Search_H__
#define __Search_H__


class SearchSP
{
private:
	const CString& strRootPath;	//삭제파일 주소
	std::string& checkSP_2;		//삭제파일 이름
	int numSP;					//삭제파일 번호
	int* numSP_re;				//삭제파일 리스트
public:
	SearchSP(const CString& strR, std::string& chSP_2, int nSP, int *numSP_re_m);
	void FindFiles();
	void numSP_record();
};
SearchSP::SearchSP(const CString& strR,  std::string& chSP_2, int nSP, int *numSP_re_m) :
	strRootPath(strR), checkSP_2(chSP_2), numSP(nSP)
{
	numSP_re = numSP_re_m;
}


//현재 클래스에 저장된 주소로 들어가서, 파일이름이 일치하는 것을 찾음. 있으면 넘어온 numSP의 현재 번호에 1을 표시하여 메인 함수도 알수있게함.

void SearchSP::FindFiles()
{
	CString strFileToFind = strRootPath;
	ATLPath::Append(CStrBuf(strFileToFind, MAX_PATH), _T("*.*"));

	WIN32_FIND_DATA findData = { 0, };
	HANDLE hFileFind = ::FindFirstFile(strFileToFind, &findData);
	if (hFileFind == INVALID_HANDLE_VALUE)
	{
		return;
	}
	else
	{
		do
		{
			USES_CONVERSION;
			if (T2A((LPTSTR)(LPCTSTR)findData.cFileName) == checkSP_2)
			{
				numSP_record();
			}

		} while (::FindNextFile(hFileFind, &findData));

		::FindClose(hFileFind);
	}
}
void SearchSP::numSP_record()
{
	numSP_re[numSP] = 1;
}

#endif
