
// WinProg3_test.h : WinProg3_test ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// CWinProg3_testApp:
// �� Ŭ������ ������ ���ؼ��� WinProg3_test.cpp�� �����Ͻʽÿ�.
//

class CWinProg3_testApp : public CWinApp
{
public:
	CWinProg3_testApp();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CWinProg3_testApp theApp;
