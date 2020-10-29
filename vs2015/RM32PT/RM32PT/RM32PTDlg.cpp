// RM32PTDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "RM32PT.h"
#include "RM32PTDlg.h"
#include "afxdialogex.h"

#include "PCI_DMC.h"
#include "PCI_DMC_Err.h"

#include <iostream>

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


// CRM32PTDlg �Ի���



CRM32PTDlg::CRM32PTDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_RM32PT_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRM32PTDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CRM32PTDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CRM32PTDlg::OnBnClickedButton1)
	ON_BN_CLICKED(IDC_CHECK1, &CRM32PTDlg::OnBnClickedCheck1)
	ON_BN_CLICKED(IDC_BUTTON2, &CRM32PTDlg::OnBnClickedButton2)
	ON_BN_CLICKED(IDC_BUTTON3, &CRM32PTDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CRM32PTDlg ��Ϣ�������

BOOL CRM32PTDlg::OnInitDialog()
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

void CRM32PTDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRM32PTDlg::OnPaint()
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
HCURSOR CRM32PTDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



/* PCI-DMC */
const unsigned short cstMaxCardNum = 16;
/*Global*/
I16 gDMCExistCards = 0;
U16 gDMCCardNo, gpDMCCardNoList[cstMaxCardNum] = { 0 };
U16 gpDeviceInfo[cstMaxCardNum], gpNodeID[32] = { 0 }, gNodeNum;
U16 SlotID;
U32 gpSlaveTable[cstMaxCardNum][4];
U16 PortNoX = 0, PortNoY = 1;

void CRM32PTDlg::OnBnClickedButton1()//��ʼ����ť
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	/* gDMCExistCards �����ᱻ���� PC �� PCI-DMC-01 ������*/
	_DMC_01_open(&gDMCExistCards);

	unsigned short i, CardNo;
	for (i = 0; i<gDMCExistCards; i++)
	{
		/* ȡ�� PC �ϵ� i �����俨�ţ����ż� Switch ָ�����ض�Ӧ����ֵ*/
		_DMC_01_get_CardNo_seq(i, &CardNo);
		gpDMCCardNoList[i] = CardNo;
		gDMCCardNo = CardNo;

		_DMC_01_pci_initial(gDMCCardNo); // ��ʼ�����俨
		_DMC_01_initial_bus(gDMCCardNo); // ͨѶЭ���ʼ��

		/*��ʾ Card No */
		SetDlgItemInt(IDC_STATIC2, CardNo);
	}
}


void CRM32PTDlg::OnBnClickedButton2()//��������ť
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	unsigned int i = 0, lMask = 0x1;

	_DMC_01_start_ring(gDMCCardNo, 0);
	SlotID = _DMC_01_get_device_table(gDMCCardNo, &gpDeviceInfo[gDMCCardNo]);
	_DMC_01_get_node_table(gDMCCardNo, &gpSlaveTable[gDMCCardNo][0]);

	gNodeNum = 0;
	for (i = 0; i<32; i++)
	{
		if ((gpSlaveTable[gDMCCardNo][0] >> i) & lMask)
		{
			gpNodeID[gNodeNum] = (unsigned short)(i + 1);
			gNodeNum++;
		}
	}
	/*��ʾ Node ID */
	SetDlgItemInt(IDC_STATIC3, gNodeNum);
	/*��ʾ Slot ID */
	SetDlgItemInt(IDC_STATIC4, SlotID);
}


void CRM32PTDlg::OnBnClickedButton3()//�Ͽ���ť
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
	
	unsigned short i;

	for (i = 0; i<gDMCExistCards; i++) {
		_DMC_01_reset_card(gpDMCCardNoList[i]);
	}
	_DMC_01_close();

	CString str;
	str = "";
	SetDlgItemText(IDC_STATIC2, str);
	SetDlgItemText(IDC_STATIC3, str);
	SetDlgItemText(IDC_STATIC4, str);
}


BOOL m_bRun;
DWORD WINAPI ThreadFunc(PVOID pParam)
{
	m_bRun = TRUE;
	while (m_bRun)
	{
		U16 rt;
		U16 input_value[8] = { 0 };

		_DMC_01_get_rm_input_value(gDMCCardNo, gNodeNum, SlotID, PortNoX, &input_value[0]);
		rt = input_value[0];

		if (rt == 7) //��������
		{
			_DMC_01_set_rm_output_active(gDMCCardNo, gNodeNum, SlotID, 1);
			_DMC_01_set_rm_output_value(gDMCCardNo, gNodeNum, SlotID, PortNoY, 1);
		}
		if (rt == 0) //��ͣ
		{
			_DMC_01_set_rm_output_active(gDMCCardNo, gNodeNum, SlotID, 1);
			_DMC_01_set_rm_output_value(gDMCCardNo, gNodeNum, SlotID, PortNoY, 0);
		}
	}
	ExitThread(0);
}


void CRM32PTDlg::OnBnClickedCheck1()//������ť
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������

	int state = ((CButton *)GetDlgItem(IDC_CHECK1))->GetCheck(); //��ȡcheck��ť״̬

	if (state == 1)
	{
		CreateThread(NULL, 0, ThreadFunc, NULL, 0, NULL);
	}
	if (state == 0)
	{
		m_bRun = FALSE;
		_DMC_01_set_rm_output_active(gDMCCardNo, gNodeNum, SlotID, 1);
		_DMC_01_set_rm_output_value(gDMCCardNo, gNodeNum, SlotID, PortNoY, 0);
	}
}