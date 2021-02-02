#include <Windows.h>
#include <atlpath.h>
#include <atlconv.h>
#include <string>

#ifndef __Search_H__
#define __Search_H__


class SearchSP
{
private:
	const CString& strRootPath;	//�������� �ּ�
	std::string& checkSP_2;		//�������� �̸�
	int numSP;					//�������� ��ȣ
	int* numSP_re;				//�������� ����Ʈ
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


//���� Ŭ������ ����� �ּҷ� ����, �����̸��� ��ġ�ϴ� ���� ã��. ������ �Ѿ�� numSP�� ���� ��ȣ�� 1�� ǥ���Ͽ� ���� �Լ��� �˼��ְ���.

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
