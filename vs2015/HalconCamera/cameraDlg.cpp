
// cameraDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "camera.h"
#include "cameraDlg.h"
#include "afxdialogex.h"

#include "halconcpp.h"
using namespace HalconCpp;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// ����Ӧ�ó��򡰹��ڡ��˵���� CAboutDlg �Ի���

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

// ʵ��
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


// CcameraDlg �Ի���



CcameraDlg::CcameraDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_CAMERA_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CcameraDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CcameraDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CcameraDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_BUTTON2, &CcameraDlg::OnBnClickedButton2)
END_MESSAGE_MAP()


// CcameraDlg ��Ϣ�������

BOOL CcameraDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// ��������...���˵�����ӵ�ϵͳ�˵��С�

	// IDM_ABOUTBOX ������ϵͳ���Χ�ڡ�
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
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

	// ���ô˶Ի����ͼ�ꡣ  ��Ӧ�ó��������ڲ��ǶԻ���ʱ����ܽ��Զ�
	//  ִ�д˲���
	SetIcon(m_hIcon, TRUE);			// ���ô�ͼ��
	SetIcon(m_hIcon, FALSE);		// ����Сͼ��

	// TODO: �ڴ���Ӷ���ĳ�ʼ������

	return TRUE;  // ���ǽ��������õ��ؼ������򷵻� TRUE
}

void CcameraDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

// �����Ի��������С����ť������Ҫ����Ĵ���
//  �����Ƹ�ͼ�ꡣ  ����ʹ���ĵ�/��ͼģ�͵� MFC Ӧ�ó���
//  �⽫�ɿ���Զ���ɡ�

void CcameraDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // ���ڻ��Ƶ��豸������

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// ʹͼ���ڹ����������о���
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// ����ͼ��
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//���û��϶���С������ʱϵͳ���ô˺���ȡ�ù��
//��ʾ��
HCURSOR CcameraDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}


volatile BOOL m_bRun;
volatile BOOL m_bShowFlag;
void CcameraDlg::OnBnClickedButton1()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	CWnd * pWnd = AfxGetApp()->GetMainWnd();
	if (m_bShowFlag)
	{
		m_bRun = TRUE;
	}
	else
	{
		hThread = CreateThread(NULL,
			0,
			(LPTHREAD_START_ROUTINE)ThreadFunc,
			this, //����������ָ��
			0,
			&ThreadID);
	}
}

void ThreadFunc(LPVOID lpParam)
{
	//ָ��ת��
	CcameraDlg * pMainWindow;
	pMainWindow = (CcameraDlg *)lpParam; //ǿ��ת��Ϊ������ָ��
	HTuple HWindowID;
	CRect Rect;
	CWnd * pWnd = pMainWindow->GetDlgItem(IDC_STATIC);
	HWindowID = (Hlong)pWnd->m_hWnd;
	pWnd->GetWindowRect(&Rect);

	//�򿪴��ڣ����ÿ��
	OpenWindow(0, 0, Rect.Width(), Rect.Height(), HWindowID, "visible", "", &(pMainWindow->m_HWindowID));

	//��ʾ�����׽��ͼ��
	OpenFramegrabber("GigEVision2", 0, 0, 0, 0, 0, 0, "progressive", -1, "default",
		-1, "false", "default", "d47c443017eb_OMRONSENTECH_STCMBA503POE", 0, -1, &(pMainWindow->hv_AcqHandle));

	GrabImageStart(pMainWindow->hv_AcqHandle, -1);
	ClearWindow(pMainWindow->m_HWindowID);
	GrabImage(&(pMainWindow->ho_Image), pMainWindow->hv_AcqHandle);
	GetImagePointer1((pMainWindow->ho_Image), NULL, NULL, &(pMainWindow->m_ImageWidth), &(pMainWindow->m_ImageHeight));
	SetPart(pMainWindow->m_HWindowID, 0, 0, pMainWindow->m_ImageHeight - 1, pMainWindow->m_ImageWidth - 1);
	m_bShowFlag = TRUE;//��������״̬
	m_bRun = TRUE;

	while (m_bShowFlag)
	{
		if (m_bRun)
		{
			GrabImageAsync(&(pMainWindow->ho_Image), pMainWindow->hv_AcqHandle, -1);
			DispObj(pMainWindow->ho_Image, pMainWindow->m_HWindowID);
			Sleep(50);
		}
	}
	ClearWindow(pMainWindow->m_HWindowID);
	CloseFramegrabber(pMainWindow->hv_AcqHandle);
	CloseWindow(pMainWindow->m_HWindowID);
	ExitThread(0);
}


void CcameraDlg::OnBnClickedButton2()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	m_bRun = FALSE;
	m_bShowFlag = FALSE;
}
