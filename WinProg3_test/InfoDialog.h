#pragma once


// CInfoDialog ��ȭ �����Դϴ�.

class CInfoDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CInfoDialog)

public:
	CInfoDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CInfoDialog();



// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	CString lable;
	virtual BOOL OnInitDialog();
	afx_msg void OnBnClickedOk();
//	afx_msg void OnBnClickedCancel();
	virtual void OnOK();
	afx_msg void OnBnClickedCancel();
	virtual void OnCancel();
	afx_msg void OnEnChangeEdit1();
	afx_msg void OnBnClickedButton1();
	bool rotate=0;
	int rote;
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
