
// winprog03.h : winprog03 ���� ���α׷��� ���� �� ��� ����
//
#pragma once

#ifndef __AFXWIN_H__
	#error "PCH�� ���� �� ������ �����ϱ� ���� 'stdafx.h'�� �����մϴ�."
#endif

#include "resource.h"       // �� ��ȣ�Դϴ�.


// Cwinprog03App:
// �� Ŭ������ ������ ���ؼ��� winprog03.cpp�� �����Ͻʽÿ�.
//

class Cwinprog03App : public CWinApp
{
public:
	Cwinprog03App();


// �������Դϴ�.
public:
	virtual BOOL InitInstance();

// �����Դϴ�.
	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern Cwinprog03App theApp;
