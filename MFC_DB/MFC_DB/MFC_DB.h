
// MFC_DB.h : PROJECT_NAME Ӧ�ó������ͷ�ļ�
//

#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"		// ������


// CMFC_DBApp:
// �йش����ʵ�֣������ MFC_DB.cpp
//

class CMFC_DBApp : public CWinApp
{
public:
	CMFC_DBApp();

// ��д
public:
	virtual BOOL InitInstance();

// ʵ��

	DECLARE_MESSAGE_MAP()
};

extern CMFC_DBApp theApp;