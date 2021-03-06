#pragma once
#include "afxwin.h"


// CInputInfoDialog 대화 상자입니다.

class CInputInfoDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CInputInfoDialog)

public:
	CInputInfoDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CInputInfoDialog();

// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox clock_combo;
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	CString inputLable;
	int clock_number;
	BOOL checkClock;
	afx_msg void OnBnClickedCheck1();
	afx_msg void OnBnClickedButton2();
	int rote2;
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
	afx_msg void OnBnClickedButton5();
};
