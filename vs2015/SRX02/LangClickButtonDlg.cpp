
// LangClickButtonDlg.cpp : ʵ���ļ�
//

#include "stdafx.h"
#include "LangClickButton.h"
#include "LangClickButtonDlg.h"
#include "afxdialogex.h"

#include "Python.h"

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


// CLangClickButtonDlg �Ի���



CLangClickButtonDlg::CLangClickButtonDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_LANGCLICKBUTTON_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CLangClickButtonDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CLangClickButtonDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON3, &CLangClickButtonDlg::OnBnClickedButton3)
END_MESSAGE_MAP()


// CLangClickButtonDlg ��Ϣ�������

BOOL CLangClickButtonDlg::OnInitDialog()
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

void CLangClickButtonDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CLangClickButtonDlg::OnPaint()
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
HCURSOR CLangClickButtonDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}




BOOL m_bRun;
int Clicked1 = 0;
DWORD WINAPI ThreadFunc(PVOID pParam)
{
	//����Python����
	Py_Initialize();
	PyRun_SimpleString("import sys");
	PyRun_SimpleString("sys.path.append('./py/')");
	PyObject* pModule = PyImport_ImportModule("run");
	PyObject* pFunc1 = PyObject_GetAttrString(pModule, "WriteBool");
	PyObject* pFunc2 = PyObject_GetAttrString(pModule, "ReadBool");

	CLangClickButtonDlg *pDlg = (CLangClickButtonDlg *)pParam;

	m_bRun = TRUE;
	while (m_bRun)
	{
		PyObject* pArgs = PyTuple_New(1);
		PyTuple_SetItem(pArgs, 0, Py_BuildValue("s", "V130.1"));
		PyObject* pReturn = PyEval_CallObject(pFunc2, pArgs);
		int nResult;
		PyArg_Parse(pReturn, "i", &nResult);
		if (nResult == 1)
		{
			CString str;
			str = "��λ���";
			pDlg->SetDlgItemText(IDC_STATIC3, str);

			m_bRun = FALSE;
			Clicked1 = 0;
			break;
		}
	}
	return 0;
}

BOOL CLangClickButtonDlg::PreTranslateMessage(MSG * pMsg)
{
	if (Clicked1 == 0)
	{
		if (pMsg->message == WM_LBUTTONDOWN)//����������������Ϣ
		{
			//����Python����
			Py_Initialize();
			PyRun_SimpleString("import sys");
			PyRun_SimpleString("sys.path.append('./py/')");
			PyObject* pModule = PyImport_ImportModule("run");
			PyObject* pFunc1 = PyObject_GetAttrString(pModule, "WriteBool");
			PyObject* pFunc2 = PyObject_GetAttrString(pModule, "ReadBool");

			if (pMsg->hwnd == GetDlgItem(IDC_BUTTON1)->m_hWnd)//�жϰ��µ�λ���Ƿ�ΪĿ��button
			{
				PyObject* pArgs1 = PyTuple_New(2);
				PyTuple_SetItem(pArgs1, 0, Py_BuildValue("s", "V100.0")); //Y��+
				PyTuple_SetItem(pArgs1, 1, Py_BuildValue("i", 1));
				PyEval_CallObject(pFunc1, pArgs1);
				
				/*
				Py_Initialize();

				PyRun_SimpleString("import sys");
				PyRun_SimpleString("sys.path.append('./')");

				PyRun_SimpleString("import run");
				PyRun_SimpleString("run.WriteBool('V100.0', 1)");
				Py_Finalize();
				*/
			}
			if (pMsg->hwnd == GetDlgItem(IDC_BUTTON2)->m_hWnd)
			{
				PyObject* pArgs1 = PyTuple_New(2);
				PyTuple_SetItem(pArgs1, 0, Py_BuildValue("s", "V100.1")); //Y��-
				PyTuple_SetItem(pArgs1, 1, Py_BuildValue("i", 1));
				PyEval_CallObject(pFunc1, pArgs1);
			}
			if (pMsg->hwnd == GetDlgItem(IDC_BUTTON3)->m_hWnd)
			{
				PyObject* pArgs1 = PyTuple_New(2);
				PyTuple_SetItem(pArgs1, 0, Py_BuildValue("s", "V130.0")); //��λ
				PyTuple_SetItem(pArgs1, 1, Py_BuildValue("i", 1));
				PyEval_CallObject(pFunc1, pArgs1);

				CString str;
				str = "��λ��...";
				SetDlgItemText(IDC_STATIC3, str);

				PyObject* pArgs2 = PyTuple_New(2);
				PyTuple_SetItem(pArgs2, 0, Py_BuildValue("s", "V130.1"));
				PyTuple_SetItem(pArgs2, 1, Py_BuildValue("i", 0));
				PyEval_CallObject(pFunc1, pArgs2);

				Clicked1++;
				if (Clicked1 == 1)
				{
					CreateThread(NULL, NULL, ThreadFunc, this, 0, NULL);
				}
			}

			if (pMsg->hwnd == GetDlgItem(IDC_BUTTON4)->m_hWnd)
			{
				PyObject* pArgs1 = PyTuple_New(2);
				PyTuple_SetItem(pArgs1, 0, Py_BuildValue("s", "V110.0")); //X��+
				PyTuple_SetItem(pArgs1, 1, Py_BuildValue("i", 1));
				PyEval_CallObject(pFunc1, pArgs1);

				PyObject* pArgs2 = PyTuple_New(2);
				PyTuple_SetItem(pArgs2, 0, Py_BuildValue("s", "V120.0"));
				PyTuple_SetItem(pArgs2, 1, Py_BuildValue("i", 1));
				PyEval_CallObject(pFunc1, pArgs2);
			}
			if (pMsg->hwnd == GetDlgItem(IDC_BUTTON5)->m_hWnd)
			{
				PyObject* pArgs1 = PyTuple_New(2);
				PyTuple_SetItem(pArgs1, 0, Py_BuildValue("s", "V110.1")); //X��-
				PyTuple_SetItem(pArgs1, 1, Py_BuildValue("i", 1));
				PyEval_CallObject(pFunc1, pArgs1);

				PyObject* pArgs2 = PyTuple_New(2);
				PyTuple_SetItem(pArgs2, 0, Py_BuildValue("s", "V120.1"));
				PyTuple_SetItem(pArgs2, 1, Py_BuildValue("i", 1));
				PyEval_CallObject(pFunc1, pArgs2);
			}
		}

		else if (pMsg->message == WM_LBUTTONUP) //������̧��
		{
			//����Python����
			Py_Initialize();
			PyRun_SimpleString("import sys");
			PyRun_SimpleString("sys.path.append('./py/')");
			PyObject* pModule = PyImport_ImportModule("run");
			PyObject* pFunc1 = PyObject_GetAttrString(pModule, "WriteBool");
			PyObject* pFunc2 = PyObject_GetAttrString(pModule, "ReadBool");

			if (pMsg->hwnd == GetDlgItem(IDC_BUTTON1)->m_hWnd)
			{
				PyObject* pArgs1 = PyTuple_New(2);
				PyTuple_SetItem(pArgs1, 0, Py_BuildValue("s", "V100.0"));
				PyTuple_SetItem(pArgs1, 1, Py_BuildValue("i", 0));
				PyEval_CallObject(pFunc1, pArgs1);
			}
			if (pMsg->hwnd == GetDlgItem(IDC_BUTTON2)->m_hWnd)
			{
				PyObject* pArgs1 = PyTuple_New(2);
				PyTuple_SetItem(pArgs1, 0, Py_BuildValue("s", "V100.1"));
				PyTuple_SetItem(pArgs1, 1, Py_BuildValue("i", 0));
				PyEval_CallObject(pFunc1, pArgs1);
			}

			if (pMsg->hwnd == GetDlgItem(IDC_BUTTON4)->m_hWnd)
			{
				PyObject* pArgs1 = PyTuple_New(2);
				PyTuple_SetItem(pArgs1, 0, Py_BuildValue("s", "V110.0")); //X��+
				PyTuple_SetItem(pArgs1, 1, Py_BuildValue("i", 0));
				PyEval_CallObject(pFunc1, pArgs1);

				PyObject* pArgs2 = PyTuple_New(2);
				PyTuple_SetItem(pArgs2, 0, Py_BuildValue("s", "V120.0"));
				PyTuple_SetItem(pArgs2, 1, Py_BuildValue("i", 0));
				PyEval_CallObject(pFunc1, pArgs2);
			}
			if (pMsg->hwnd == GetDlgItem(IDC_BUTTON5)->m_hWnd)
			{
				PyObject* pArgs1 = PyTuple_New(2);
				PyTuple_SetItem(pArgs1, 0, Py_BuildValue("s", "V110.1")); //X��-
				PyTuple_SetItem(pArgs1, 1, Py_BuildValue("i", 0));
				PyEval_CallObject(pFunc1, pArgs1);

				PyObject* pArgs2 = PyTuple_New(2);
				PyTuple_SetItem(pArgs2, 0, Py_BuildValue("s", "V120.1"));
				PyTuple_SetItem(pArgs2, 1, Py_BuildValue("i", 0));
				PyEval_CallObject(pFunc1, pArgs2);
			}
		}
	}
	return CDialog::PreTranslateMessage(pMsg);
}


void CLangClickButtonDlg::OnBnClickedButton3()
{
	// TODO: �ڴ���ӿؼ�֪ͨ����������
}
