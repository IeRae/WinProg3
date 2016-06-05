#pragma once


// CInfoDialog 대화 상자입니다.

class CInfoDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CInfoDialog)

public:
	CInfoDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CInfoDialog();



// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

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
