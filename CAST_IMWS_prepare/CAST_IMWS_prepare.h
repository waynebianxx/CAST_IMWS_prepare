
// CAST_IMWS_prepare.h : CAST_IMWS_prepare Ӧ�ó������ͷ�ļ�
//
#pragma once

#ifndef __AFXWIN_H__
	#error "�ڰ������ļ�֮ǰ������stdafx.h�������� PCH �ļ�"
#endif

#include "resource.h"       // ������


// CCAST_IMWS_prepareApp:
// �йش����ʵ�֣������ CAST_IMWS_prepare.cpp
//

class CCAST_IMWS_prepareApp : public CWinAppEx
{
public:
	CCAST_IMWS_prepareApp();


// ��д
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// ʵ��
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CCAST_IMWS_prepareApp theApp;
