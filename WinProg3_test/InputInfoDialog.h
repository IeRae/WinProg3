#pragma once
#include "afxwin.h"


// CInputInfoDialog ��ȭ �����Դϴ�.

class CInputInfoDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CInputInfoDialog)

public:
	CInputInfoDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CInputInfoDialog();

// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG2 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CComboBox clock_combo;
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	virtual void OnCancel();
	CString inputLable;
	int clock_number;
};
