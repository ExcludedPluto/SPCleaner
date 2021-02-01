#include <windows.h>
#include <atlpath.h>
#include <atlconv.h>
#include <string>
#include <algorithm>
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
		"C:\\\\Program Files\\\\Wizvera\\\\Veraport20\\\\unins000.exe",
		"C:\\\\Program Files\\\\AhnLab\\\\Safe Transaction\\\\V3Medic.exe",
		"C:\\\\Program Files (x86)\\\\AhnLab\\ASP\\\\Components\\\\aosmgr\\\\ASPLnchr.exe",
		"C:\\\\Program Files (x86)\\\\SoftForum\\\\XecureWeb\\\\AnySign\\\\uninst.exe",
		"C:\\\\Program Files (x86)\\\\AlphaSecure\\\\ZeroKeeper\\\\zwSetx86z.exe",
		"C:\\\\Program Files (x86)\\\\MarkAny\\\\maepsrt\\\\uninst_ePageSaferRT.exe",
		"C:\\\\Program Files (x86)\\\\INITECH\\\\INISAFE Web EX Client\\\\UnINIS_EX.exe",
		"C:\\\\Program Files (x86)\\\\INITECH\\\\INISAFE SandBox V1\\\\uninst.exe",
		"C:\\\\Program Files (x86)\\\\IPinside_LWS\\\\I3GSvcManager.exe",
		"C:\\\\Program Files\\\\KeySharp\\\\kscertrelay\\\\SetupProgram.exe",
		"C:\\\\Program Files (x86)\\\\WooriBank\\\\RealIp\\\\uninst.exe",
		"C:\\\\Program Files (x86)\\\\INITECH\\\\INISAFE MoaSign EX\\\\uninst.exe",
		"C:\\\\Program Files (x86)\\\\INCAInternet UnInstall\\\\nProtect Online Security\\\\nProtectUninstaller.exe",
		"C:\\\\Program Files (x86)\\\\DGBank\\\\RealIp\\\\uninst.exe",
		"C:\\\\Program Files (x86)\\\\INITECH\\\\INISAFE SmartManagerEX\\\\smartmanagerex\\\\uninst.exe",
		"C:\\\\Windows\\\\SysWOW64\\\\CKSetup32.exe",
		"C:\\\\Program Files (x86)\\\\Wizvera\\\\Delfino-G3\\\\unins000.exe",
		"C:\\\\Program Files (x86)\\\\Initech\\\\SHTTP\\\\uninst.exe",
		"C:\\\\Program Files (x86)\\\\iniLINE\\\\CrossEX\\\\crossex\\\\UnInstallCrossEXLocal.exe",
		"C:\\\\Program Files (x86)\\\\InstallShield Installation Information\\\\{D448288F-D294-4E20-9573-13C8F4BAF56E}\\\\setup.exe",
		"C:\\\\Program Files (x86)\\\\SoftForum\\\\XecureWeb\\\\xw_setup.exe"
	};
public:
	deinstall(int *numSP_re_m)
	{
		numSP_re = numSP_re_m;
		BOOL f64 = FALSE;
		BOOL isWin64 = IsWow64Process(GetCurrentProcess(), &f64) && f64;
		if (!isWin64) {
			for (int i = 0; i < 21; i++) {
				int index = PCSP[i].find(" (x86)", 18);
				if (index != string::npos)
					PCSP[i].replace(index, 5, "");
			}
		}
	}
	void choose(CString choosedSPList)
	{
		int i = 0;
		
		for (int k = 0; k < 21; k++)
			choose_2[k] = 0;

		CT2CA pszConvertedAnsiString(choosedSPList);
		string line(pszConvertedAnsiString);

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


		if (choose_2[0] != 0)		//못찾았을 때 choose_2[0] 엔 0이 저장되고, 모두삭제이므로 모두삭제
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
			ShellExecute(NULL, A2T("open"), Path, A2T("/INITPROCWND"), NULL, SW_SHOW);
			ShellExecute(NULL, A2T("open"), A2T("C:\\Program Files (x86)\\Wizvera\\Common\\wpmsvc\\unins000.exe"), A2T("/INITPROCWND"), NULL, SW_SHOW);
			num_PCSP++;
			Sleep(1000);
		}

		int j = 0;
		for (int i = 0; i < 21; i++)
		{
			int k = numSP_re[i];

			if (k == 1)
			{
				if (i == 1)
				{
					for (j; j < i; j++)
						num_PCSP++;
					PCSPst[num_PCSP] = PCSP[num_PCSP];
					USES_CONVERSION;
					CString Path = A2T(PCSPst[num_PCSP].c_str());
					CString parameter = _T("-Uninstall");
					ShellExecute(NULL, A2T("open"), Path, parameter, NULL, SW_SHOW);
					j++;
					num_PCSP++;
					Sleep(2000);
				}
				else if (i == 2)
				{
					for (j; j < i; j++)
						num_PCSP++;
					PCSPst[num_PCSP] = PCSP[num_PCSP];
					USES_CONVERSION;
					CString Path = A2T(PCSPst[num_PCSP].c_str());
					CString parameter = _T("-Uninstall");
					ShellExecute(NULL, A2T("open"), Path, parameter, NULL, SW_SHOW);
					j++;
					num_PCSP++;
					Sleep(1000);
				}
				else if (i == 8)
				{
					for (j; j < i; j++)
						num_PCSP++;
					PCSPst[num_PCSP] = PCSP[num_PCSP];
					USES_CONVERSION;
					CString Path = A2T(PCSPst[num_PCSP].c_str());
					CString parameter = _T("-uninstall");
					ShellExecute(NULL, A2T("open"), Path, parameter, NULL, SW_SHOW);
					j++;
					num_PCSP++;
					Sleep(1000);
				}
				else if (i == 15)
				{
					for (j; j < i; j++)
						num_PCSP++;
					PCSPst[num_PCSP] = PCSP[num_PCSP];
					USES_CONVERSION;
					CString Path = A2T(PCSPst[num_PCSP].c_str());
					CString parameter = _T("-uninstall appm");
					ShellExecute(NULL, A2T("open"), Path, parameter, NULL, SW_SHOW);
					j++;
					num_PCSP++;
					Sleep(1000);
				}
				else if (i == 16)
				{
					for (j; j < i; j++)
						num_PCSP++;
					PCSPst[num_PCSP] = PCSP[num_PCSP];
					USES_CONVERSION;
					CString Path = A2T(PCSPst[num_PCSP].c_str());
					CString parameter = _T("-uninstall");
					ShellExecute(NULL, A2T("open"), Path, parameter, NULL, SW_SHOW);
					ShellExecute(NULL, A2T("open"), A2T("C:\\Program Files (x86)\\Wizvera\\Common\\wpmsvc\\unins000.exe"), A2T("/INITPROCWND"), NULL, SW_SHOW);
					j++;
					num_PCSP++;
					Sleep(1000);
				}
				else
				{
					for (j; j < i; j++)
						num_PCSP++;
					PCSPst[num_PCSP] = PCSP[num_PCSP];
					USES_CONVERSION;
					CString Path = A2T(PCSPst[num_PCSP].c_str());
					ShellExecute(NULL, A2T("open"), Path, NULL, NULL, SW_SHOW);
					j++;
					num_PCSP++;
					Sleep(1000);
				}

			}
		}

		if (j != 17)
			for (j; j < 17; j++)
				num_PCSP++;

		for (int i = 17; i < 21; i++)
		{
			int k = numSP_re[i];

			if (k == 1)
			{
				if (i == 20)
				{
					for (j; j < i; j++)
						num_PCSP++;
					PCSPst[num_PCSP] = PCSP[num_PCSP];
					USES_CONVERSION;
					CString Path = A2T(PCSPst[num_PCSP].c_str());
					CString parameter = _T("-ui");
					ShellExecute(NULL, A2T("open"), Path, parameter, NULL, SW_SHOW);
					j++;
					num_PCSP++;
					Sleep(1000);
				}
				else
				{
					for (j; j < i; j++)
						num_PCSP++;
					PCSPst[num_PCSP] = PCSP[num_PCSP];
					USES_CONVERSION;
					CString Path = A2T(PCSPst[num_PCSP].c_str());
					ShellExecute(NULL, A2T("open"), Path, NULL, NULL, SW_SHOW);
					j++;
					num_PCSP++;
					Sleep(1000);
				}
			}
		}
	}
	void deinsSP_tar()
	{
		int check = 0;
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
	}
};

#endif