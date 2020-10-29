
// cameraDlg.h : ͷ�ļ�
//

#pragma once
#include "halconcpp.h"
using namespace HalconCpp;


// CcameraDlg �Ի���
class CcameraDlg : public CDialogEx
{
// ����
public:
	CcameraDlg(CWnd* pParent = NULL);	// ��׼���캯��

	HObject  ho_Image;
	HTuple  hv_AcqHandle;
	HTuple m_HWindowID;
	HTuple m_FGHandle, m_ImageWidth, m_ImageHeight;

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_CAMERA_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��

	HANDLE hThread;
	DWORD ThreadID;


// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
	afx_msg void OnBnClickedButton2();
};

void ThreadFunc(LPVOID lpParam);
