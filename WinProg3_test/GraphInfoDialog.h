#pragma once
#include "OScopeCtrl.h"
#include "afxwin.h"

// CGraphInfoDialog 대화 상자입니다.

class CGraphInfoDialog : public CDialogEx
{
	DECLARE_DYNAMIC(CGraphInfoDialog)

public:
	CGraphInfoDialog(CWnd* pParent = NULL);   // 표준 생성자입니다.
	virtual ~CGraphInfoDialog();
	
	COScopeCtrl *_rtGraph;

	bool istrue;



// 대화 상자 데이터입니다.
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV 지원입니다.

	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL OnInitDialog();
	afx_msg void OnTimer(UINT_PTR nIDEvent);
	afx_msg void OnDestroy();
	void passingbool(bool a);
	
};
