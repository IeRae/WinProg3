#pragma once
#include "OScopeCtrl.h"
#include "afxwin.h"

// CGraphInfoDialog ��ȭ �����Դϴ�.

class CGraphInfoDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CGraphInfoDialog)

public:
	CGraphInfoDialog(CWnd* pParent = NULL);   // ǥ�� �������Դϴ�.
	virtual ~CGraphInfoDialog();
	
	COScopeCtrl *_rtGraph;

	bool istrue;



// ��ȭ ���� �������Դϴ�.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV �����Դϴ�.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
	void passingbool(bool a);
	
};
