
// mfc_Guide.h : mfc_Guide Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// Cmfc_GuideApp:
// �йش����ʵ�֣������ mfc_Guide.cpp
//

class Cmfc_GuideApp : public CWinApp
{
public:
	Cmfc_GuideApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cmfc_GuideApp theApp;
