
// SPCleanerDlg.cpp: 구현 파일
//

#include "pch.h"
#include "framework.h"
#include "SPCleaner.h"
#include "SPCleanerDlg.h"

#include <afxdialogex.h>
#include <atlpath.h>
#include <iostream>
#include <fstream>
#include <string>
#include <atlconv.h>
#include <vector>
#include "Search.h"
#include "classify.h"


#define _WIN32_WINNT 0x0500 //윈도우 2000에서만 돌아간다고 명시하는것. 윈도우 2000이상에 있는 함수를 사용할때 적음
#ifdef _DEBUG
#define new DEBUG_NEW
#endif

#ifdef _UNICODE				//UNICODE가 정의되어잇으면
#define cout wcout			//cout이 아니라 wcout 사용. wchar_t 를 사용한 출력이다.
#endif

using namespace std;

/*************************************************************************************/
//전역변수
CFont m_font;
int numSP_re[21] = { 0, };			//현존 프로그램 기록
int inBK_re[17][5] = { 0 };			//현존 은행라인에 프로그램 저장
string pathSP[21] = {
	"C:\\Program Files\\Wizvera\\Veraport20",
	"C:\\Program Files\\AhnLab\\Safe Transaction",
	"C:\\Program Files(x86)\\AhnLab\ASP\\Components\\aosmgr",
	"C:\\Program Files(x86)\\SoftForum\\XecureWeb\\AnySign",
	"C:\\Program Files(x86)\\AlphaSecure\\ZeroKeeper",
	"C:\\Program Files(x86)\\MarkAny\\WebDRMNoAX",
	"C:\\Program Files(x86)\\INITECH\\INISAFE Web EX Client",
	"C:\\Program Files(x86)\\INITECH\\INISAFE SandBox V1",
	"C:\\Program Files(x86)\\IPinside_LWS",
	"C:\\Program Files\\KeySharp\\kscertrelay",
	"C:\\Program Files(x86)\\WooriBank\\RealIp",
	"C:\\Program Files(x86)\\INITECH\\INISAFE MoaSign EX",
	"C:\\Program Files(x86)\\INCAInternet UnInstall\\nProtect Online Security",
	"C:\\Program Files(x86)\\DGBank\\RealIp",
	"C:\\Program Files(x86)\\INITECH\\INISAFE SmartManagerEX\\smartmanagerex",
	"C:\\Program Files(x86)\\RaonSecure\\TouchEn nxKey",
	"C:\\Program Files(x86)\\Wizvera\\Delfino - G3",
	"C:\\Program Files(x86)\\Initech\\SHTTP",
	"C:\\Program Files(x86)\\iniLINE\\CrossEX\\crossex",
	"C:\\Program Files(x86)\\InstallShield Installation Information\\{D448288F - D294 - 4E20 - 9573 - 13C8F4BAF56E}",
	"C:\\Program Files(x86)\\SoftForum\\XecureWeb\\ActiveX"
};
string nameSP[21] = {
	"unins000.exe",
	"V3Medic.exe",
	"ASPLnchr.exe",
	"uninst.exe",
	"zwSetx86z.exe",
	"Uninst_WebDRM.exe",
	"UnINIS_EX.exe",
	"uninst.exe",
	"I3Gmgr.exe",
	"SetupProgram.exe",
	"uninst.exe",
	"uninst.exe",
	"nProtectUninstaller.exe",
	"uninst.exe",
	"uninst.exe",
	"UnInstallCrossEX.exe",
	"unins000.exe",
	"uninst.exe",
	"ObCrossEXService.exe",
	"_Setup.dll",
	"ClientSM.exe"
};
vector<string> classifiedBK;
bool isBK;

/************************************************************************************/

// 응용 프로그램 정보에 사용되는 CAboutDlg 대화 상자입니다.

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

// 구현입니다.
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CSPCleanerDlg 대화 상자



CSPCleanerDlg::CSPCleanerDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SPCLEANER_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CSPCleanerDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_RICHEDIT21, m_mainEdit);
}

BEGIN_MESSAGE_MAP(CSPCleanerDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDOK, &CSPCleanerDlg::OnBnClickedOk)
	ON_WM_GETMINMAXINFO()
	ON_BN_CLICKED(IDCANCEL, &CSPCleanerDlg::OnBnClickedCancel)
END_MESSAGE_MAP()


// CSPCleanerDlg 메시지 처리기

BOOL CSPCleanerDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 시스템 메뉴에 "정보..." 메뉴 항목을 추가합니다.

	// IDM_ABOUTBOX는 시스템 명령 범위에 있어야 합니다.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// 이 대화 상자의 아이콘을 설정합니다.  응용 프로그램의 주 창이 대화 상자가 아닐 경우에는
	//  프레임워크가 이 작업을 자동으로 수행합니다.
	SetIcon(m_hIcon, TRUE);			// 큰 아이콘을 설정합니다.
	SetIcon(m_hIcon, FALSE);		// 작은 아이콘을 설정합니다.

	// TODO: 여기에 추가 초기화 작업을 추가합니다.

	m_font.CreateFont(15, 0, 0, 0, FW_NORMAL, FALSE, FALSE, 0, DEFAULT_CHARSET,
		OUT_DEFAULT_PRECIS, CLIP_DEFAULT_PRECIS, DEFAULT_QUALITY,
		DEFAULT_PITCH | FF_SWISS, _T("굴림체"));
	GetDlgItem(IDC_STATIC)->SetFont(&m_font);
	// ***********************************************************************************
	// Search 시작 
	int numSP = 0;

	for (int i = 0; i < 21; i++)
	{
		USES_CONVERSION; //유니코드와 안시 사이의 변환을 간단하게 해줌.
		//CString : wchar_t	형으로 유니코드 문자열 지원
		CString Path = A2T(pathSP[i].c_str());  //	A2T : ANSI를 유니코드로 바꿔줌, .c_str() : string을 char*로 바꿔줌.
		SearchSP* Sclass = new SearchSP(Path, _T(".exe"), nameSP[i], numSP, numSP_re);
		Sclass->FindFiles();

		numSP++;
	}

	//classifiedBK 파일에 현재 존재하는 은행을 번호 : 은행명으로 기록
	classify classify_a(numSP_re, inBK_re, classifiedBK);
	isBK = classify_a.checkBK();	//존재하는 기관없을 시 0, 있으면 1 반환

	CSPCleanerDlg::PrintMain();

	// **************************************************************************************//

	return TRUE;  // 포커스를 컨트롤에 설정하지 않으면 TRUE를 반환합니다.
}

void CSPCleanerDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// 대화 상자에 최소화 단추를 추가할 경우 아이콘을 그리려면
//  아래 코드가 필요합니다.  문서/뷰 모델을 사용하는 MFC 애플리케이션의 경우에는
//  프레임워크에서 이 작업을 자동으로 수행합니다.

void CSPCleanerDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 그리기를 위한 디바이스 컨텍스트입니다.

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 클라이언트 사각형에서 아이콘을 가운데에 맞춥니다.
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 아이콘을 그립니다.
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

// 사용자가 최소화된 창을 끄는 동안에 커서가 표시되도록 시스템에서
//  이 함수를 호출합니다.
HCURSOR CSPCleanerDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CSPCleanerDlg::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	CDialogEx::OnOK();
}


void CSPCleanerDlg::OnGetMinMaxInfo(MINMAXINFO* lpMMI)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	lpMMI->ptMinTrackSize.x = 460;
	lpMMI->ptMinTrackSize.y = 260;
	lpMMI->ptMaxTrackSize.x = 460;
	lpMMI->ptMaxTrackSize.y = 260;
	CDialogEx::OnGetMinMaxInfo(lpMMI);
}


void CSPCleanerDlg::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}

void  CSPCleanerDlg::PrintMain() {
	if (isBK) {
		for (int i = 0; i < classifiedBK.size(); i++) {
			CSPCleanerDlg::m_mainEdit.ReplaceSel(CA2T(classifiedBK[i].c_str()));
		}
	}
	else {
		CSPCleanerDlg::m_mainEdit.ReplaceSel(CA2T(classifiedBK[0].c_str()));
	}
}