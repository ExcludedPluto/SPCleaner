#include "windows.h"
#include "atlpath.h"
#include "atlconv.h"
#include "fstream"
#include "string"
#include "iostream"
#include "algorithm"
#include <filesystem>


using namespace std;

#ifndef __deinstall_H__
#define __deinstall_H__

class deinstall
{
private:
	int *numSP_re;
	int choose_2[21];
	string PCSP[21] = {
		"C:\\Program Files\\Wizvera\\Veraport20\\unins000.exe",
		"C:\\Program Files\\AhnLab\\Safe Transaction\\V3Medic.exe",
		"C:\\Program Files(x86)\\AhnLab\ASP\\Components\\aosmgr\\ASPLnchr.exe",
		"C:\\Program Files(x86)\\SoftForum\\XecureWeb\\AnySign\\uninst.exe",
		"C:\\Program Files(x86)\\AlphaSecure\\ZeroKeeper\\zwSetx86z.exe",
		"C:\\Program Files(x86)\\MarkAny\\maepsrt\\uninst_ePageSaferRT.exe",
		"C:\\Program Files(x86)\\INITECH\\INISAFE Web EX Client\\UnINIS_EX.exe",
		"C:\\Program Files(x86)\\INITECH\\INISAFE SandBox V1\\uninst.exe",
		"C:\\Program Files(x86)\\IPinside_LWS\\I3GSvcManager.exe",
		"C:\\Program Files\\KeySharp\\kscertrelay\\SetupProgram.exe",
		"C:\\Program Files(x86)\\WooriBank\\RealIp\\uninst.exe",
		"C:\\Program Files(x86)\\INITECH\\INISAFE MoaSign EX\\uninst.exe",
		"C:\\Program Files(x86)\\INCAInternet UnInstall\\nProtect Online Security\\nProtectUninstaller.exe",
		"C:\\Program Files(x86)\\DGBank\\RealIp\\uninst.exe",
		"C:\\Program Files(x86)\\INITECH\\INISAFE SmartManagerEX\\smartmanagerex\\uninst.exe",
		"C:\\Windows\\SysWOW64\\CKSetup32.exe",
		"C:\\Program Files(x86)\\Wizvera\\Delfino - G3\\unins000.exe",
		"C:\\Program Files(x86)\\Initech\\SHTTP\\uninst.exe",
		"C:\\Program Files(x86)\\iniLINE\\CrossEX\\crossex\\UnInstallCrossEXLocal.exe",
		"C:\\Program Files(x86)\\InstallShield Installation Information\\{D448288F - D294 - 4E20 - 9573 - 13C8F4BAF56E}\\setup.exe",
		"C:\\Program Files(x86)\\SoftForum\\XecureWeb\\xw_setup.exe"
	};
public:
	deinstall(int *numSP_re_m)
	{
		numSP_re = numSP_re_m;
	}
	void choose(CString choosedSPList)
	{
		int i = 0;
		
		for (int k = 0; k < 21; k++)
			choose_2[k] = 0;

		CT2CA pszConvertedAnsiString(choosedSPList);
		string line(pszConvertedAnsiString);

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


		if (choose_2[0] != 0)		//��ã���� �� choose_2[0] �� 0�� ����ǰ�, ��λ����̹Ƿ� ��λ���
			deinsSP_tar();
		deinsSP_all();
	}
	void deinsSP_all()
	{
		string PCSPst[21];
		int num_PCSP = 0;

		if (numSP_re[0] == 1)
		{
			PCSPst[num_PCSP] = PCSP[num_PCSP];
			USES_CONVERSION;
			CString Path = A2T(PCSPst[num_PCSP].c_str());
			ShellExecute(NULL, A2T("open"), Path, NULL, NULL, SW_SHOW);
			num_PCSP++;
		}

		int j = 0;
		for (int i = 1; i < 17; i++)
		{
			if (numSP_re[i] == 1)
			{
				for (j; j < i; j++)
					num_PCSP++;

				PCSPst[num_PCSP] = PCSP[num_PCSP];
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
				PCSPst[num_PCSP] = PCSP[num_PCSP];
				num_PCSP++;
			}
		}

		for (int i = 17; i < 21; i++)
		{
			if (numSP_re[i] == 1)
			{
				for (j; j < i; j++)
				{
					num_PCSP++;
				}
				PCSPst[num_PCSP] = PCSP[num_PCSP];
				USES_CONVERSION;
				CString Path = A2T(PCSPst[num_PCSP].c_str());
				ShellExecute(NULL, A2T("open"), Path, NULL, NULL, SW_SHOW);
				j++;
				num_PCSP++;

			}
		}
	}
	void deinsSP_tar()
	{
		int check = 0;
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
	}
};

#endif