
// WinProg3_testView.h : CWinProg3_testView Ŭ������ �������̽�

#define IDC_TREE1 100
#pragma once

class CWinProg3_testView : public CView
{
protected: // serialization������ ��������ϴ�.
	CWinProg3_testView();
	DECLARE_DYNCREATE(CWinProg3_testView)

	// Ư���Դϴ�.
public:
	CWinProg3_testDoc* GetDocument() const;
	CTreeCtrl m_tree;
	//��ġ ���� ����
	int start_x;
	int start_y;
	bool drawline;
	int count;


	int time[2];
	int X, Y;
	bool seg1, seg2, seg3, seg4, seg5, seg6, seg7;
	
	
	CPoint start_point;
	CPoint end_point;


	CArray<Gate, Gate&> Gates; // ������Ʈ ��ü ����Ʈ
	CArray<Line, Line&> Lines;	//�� ȸ�� �� ��ü ����Ʈ

	int typeOfGate;
	
	
	// �۾��Դϴ�.
public:
	void loadBitmap(CBitmap& bit, BITMAP& bminfo, int bmindex);

	// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

	// �����Դϴ�.
public:
	virtual ~CWinProg3_testView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnNandGate();
	afx_msg void OnAndGate();
	afx_msg void OnOrGate();
	afx_msg void OnNotGate();
	afx_msg void OnNorGate();
	afx_msg void OnXorGate();
	afx_msg void OnOutputButton();
	afx_msg void OnRButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	void OnInputButton();
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	void OnLine();
	void OnSevenSegment();
};

#ifndef _DEBUG  // WinProg3_testView.cpp�� ����� ����
inline CWinProg3_testDoc* CWinProg3_testView::GetDocument() const
{
	return reinterpret_cast<CWinProg3_testDoc*>(m_pDocument);
}
#endif

