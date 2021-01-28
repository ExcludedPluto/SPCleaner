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

		size_t location = line.find(",");	// ��ǥ�� ã��. ��ǥ�� �ִٴ� ��, ��λ����� 0 ��� 1,2,3�� �Է��ߴٴ� ��.
		size_t location_2 = 0;
		while (1)
		{
			if (location != string::npos)		//ã������. ��λ����� 0�� �Է����� �ʰ�, ������ �͸� �Է���
			{
				string line_m = line.substr(location_2, location);
				location_2 = location + 1;
				location = line.find(",", location + 1);
				choose_2[i] = atoi(line_m.c_str());
				i++;

			}
			else if (location == string::npos)	//��ã���� ��.
			{
				string line_m = line.substr(location_2, line.length() - location_2);
				choose_2[i] = atoi(line_m.c_str());
				break;
			}
		}


		if (choose_2[0] == 0)		//��ã���� �� choose_2[0] �� 0�� ����ǰ�, ��λ����̹Ƿ� ��λ���
		{
			deinsSP_all();
		}
		else
		{							//ã���� ��, Ư�� ���ϸ� ����
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

		//��ü numSp_re���� ����ڰ� �� �����ϸ� �ȵǴ� ���α׷��� 2�� ǥ��
		for (int i = 0; i <21; i++)
		{
			int k = choose_2[i];

			if (k == 0)		//k=0�̸� choose_2�� ������ ��� ��. ����
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


		//ù��°�� veraport. 
		//1ǥ�ð� �Ǿ������� ������ ���α׷�.
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