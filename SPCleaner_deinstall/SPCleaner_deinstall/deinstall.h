#include "windows.h"
#include "atlpath.h"
#include "atlconv.h"
#include "fstream"
#include "string"
#include "iostream"
#include "algorithm"
#include <boost/filesystem/path.hpp>
#include <boost/filesystem/operations.hpp>
#include <boost/filesystem/fstream.hpp>


using namespace std;

#ifndef __deinstall_H__
#define __deinstall_H__

class deinstall
{
private:
	int *numSP_re;
	int choose_2[21];
public:
	deinstall(int *numSP_re_m)
	{
		numSP_re = numSP_re_m;
	}
	void choose()
	{
		int i = 0;
		
		for (int k = 0; k < 21; k++)
		{
			choose_2[k] = 0;
		}

		string line;
		std::ifstream choosed("choose_2.txt");
		getline(choosed, line);
		choosed.close();
		remove("choose_2.txt");

		size_t location = line.find(",");	// 쉼표를 찾음. 쉼표가 있다는 건, 모두삭제인 0 대신 1,2,3을 입력했다는 뜻.
		size_t location_2 = 0;
		while (1)
		{
			if (location != string::npos)		//찾았을때. 모두삭제인 0을 입력하지 않고, 삭제할 것만 입력함
			{
				string line_m = line.substr(location_2, location);
				location_2 = location + 1;
				location = line.find(",", location + 1);
				choose_2[i] = atoi(line_m.c_str());
				i++;

			}
			else if (location == string::npos)	//못찾았을 때.
			{
				string line_m = line.substr(location_2, line.length() - location_2);
				choose_2[i] = atoi(line_m.c_str());
				break;
			}
		}


		if (choose_2[0] == 0)		//못찾았을 때 choose_2[0] 엔 0이 저장되고, 모두삭제이므로 모두삭제
		{
			deinsSP_all();
		}
		else
		{							//찾았을 땐, 특정 파일만 삭제
			deinsSP_tar();
		}
	}
	void deinsSP_all()
	{
		std::ifstream PCSP("PCSP.txt");

		std::string PCSPst[21];
		int num_PCSP = 0;

		if (numSP_re[0] == 1)
		{
			getline(PCSP, PCSPst[num_PCSP]);
			USES_CONVERSION;
			CString Path = A2T(PCSPst[num_PCSP].c_str());
			ShellExecute(NULL, A2T("open"), Path, NULL, NULL, SW_SHOW);
			num_PCSP++;
		}

		PCSP.close();

		std::ifstream PCSP_2("PCSP.txt");

		int j = 0;
		for (int i = 0; i < 17; i++)
		{
			int k = numSP_re[i];

			if (k == 1)
			{
				if (i == 1)
				{
					for (j; j < i; j++)
					{
						getline(PCSP_2, PCSPst[num_PCSP]);
						num_PCSP++;
					}
					getline(PCSP_2, PCSPst[num_PCSP], '\n');
					boost::filesystem::remove_all(PCSPst[num_PCSP]);
					j++;
					num_PCSP++;
				}
				else if (i == 2)
				{
					for (j; j < i; j++)
					{
						getline(PCSP_2, PCSPst[num_PCSP]);
						num_PCSP++;
					}
					getline(PCSP_2, PCSPst[num_PCSP], '\n');
					boost::filesystem::remove_all(PCSPst[num_PCSP]);
					j++;
					num_PCSP++;
				}
				else if(i==8)
				{
					for (j; j < i; j++)
					{
						getline(PCSP_2, PCSPst[num_PCSP]);
						num_PCSP++;
					}
					getline(PCSP_2, PCSPst[num_PCSP], '\n');
					boost::filesystem::remove_all(PCSPst[num_PCSP]);
					j++;
					num_PCSP++;
				}
				else
				{
					for (j; j < i; j++)
					{
						getline(PCSP_2, PCSPst[num_PCSP]);
						num_PCSP++;
					}
					getline(PCSP_2, PCSPst[num_PCSP]);
					USES_CONVERSION;
					CString Path = A2T(PCSPst[num_PCSP].c_str());
					ShellExecute(NULL, A2T("open"), Path, NULL, NULL, SW_SHOW);
					j++;
					num_PCSP++;
				}
			}
		}

		if (j != 17)
		{
			for (j; j < 17; j++)
			{
				getline(PCSP_2, PCSPst[num_PCSP]);
				num_PCSP++;
			}
		}

		for (int i = 17; i < 21; i++)
		{
			int k = numSP_re[i];

			if (k == 1)
			{
				if (i == 20)
				{
					for (j; j < i; j++)
					{
						getline(PCSP_2, PCSPst[num_PCSP]);
						num_PCSP++;
					}
					getline(PCSP_2, PCSPst[num_PCSP], '\n');
					boost::filesystem::remove_all(PCSPst[num_PCSP]);
					j++;
					num_PCSP++;
				}
				else
				{
					for (j; j < i; j++)
					{
						getline(PCSP_2, PCSPst[num_PCSP]);
						num_PCSP++;
					}
					getline(PCSP_2, PCSPst[num_PCSP]);
					USES_CONVERSION;
					CString Path = A2T(PCSPst[num_PCSP].c_str());
					ShellExecute(NULL, A2T("open"), Path, NULL, NULL, SW_SHOW);
					j++;
					num_PCSP++;
				}
			}
		}
	}
	void deinsSP_tar()
	{
		std::ifstream PCSP("PCSP.txt");

		std::string PCSPst[21];
		int num_PCSP = 0;

		int check = 0;	//
		int j = 0;

		//전체 numSp_re에서 사용자가 고른 삭제하면 안되는 프로그램만 2로 표시
		for (int i = 0; i <21; i++)
		{
			int k = choose_2[i];

			if (k == 0)		//k=0이면 choose_2의 범위를 벗어난 것. 종료
				break;
			for(j; j<21;j++)
			{
				if (numSP_re[j] == 1)
				{
					check++;
					if (check == k)			
					{
						numSP_re[j] = 2;
						break;
					}
				}
			}
		}


		//첫번째는 veraport. 
		//1표시가 되어있으면 삭제할 프로그램.
		if (numSP_re[0] == 1)
		{
			getline(PCSP, PCSPst[num_PCSP]);
			USES_CONVERSION;
			CString Path = A2T(PCSPst[num_PCSP].c_str());
			ShellExecute(NULL, A2T("open"), Path, NULL, NULL, SW_SHOW);
			num_PCSP++;
		}
		
		PCSP.close();

		std::ifstream PCSP_2("PCSP.txt");

		j = 0;
		for (int i = 0; i < 17; i++)
		{
			int k = numSP_re[i];

			if (k == 1)
			{
				for (j; j < i; j++)
				{
					getline(PCSP_2, PCSPst[num_PCSP]);
					num_PCSP++;
				}
				getline(PCSP_2, PCSPst[num_PCSP]);
				USES_CONVERSION;
				CString Path = A2T(PCSPst[num_PCSP].c_str());
				ShellExecute(NULL, A2T("open"), Path, NULL, NULL, SW_SHOW);
				j++;
				num_PCSP++;
			}
		}

		if (j != 17)
		{
			for (j; j < 17; j++)
			{
				getline(PCSP_2, PCSPst[num_PCSP]);
				num_PCSP++;
			}
		}

		for (int i = 17; i < 21; i++)
		{
			int k = numSP_re[i];

			if (k == 1)
			{
				for (j; j < i; j++)
				{
					getline(PCSP_2, PCSPst[num_PCSP]);
					num_PCSP++;
				}
				getline(PCSP_2, PCSPst[num_PCSP]);
				USES_CONVERSION;
				CString Path = A2T(PCSPst[num_PCSP].c_str());
				ShellExecute(NULL, A2T("open"), Path, NULL, NULL, SW_SHOW);
				j++;
				num_PCSP++;
			}
		}
	}
};

#endif