
// RM32PT.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CRM32PTApp: 
// �йش����ʵ�֣������ RM32PT.cpp
//

class CRM32PTApp : public CWinApp
{
public:
	CRM32PTApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CRM32PTApp theApp;