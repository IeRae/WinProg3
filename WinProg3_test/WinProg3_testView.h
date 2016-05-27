
// WinProg3_testView.h : CWinProg3_testView 클래스의 인터페이스

#define IDC_TREE1 100
#pragma once

class CWinProg3_testView : public CView
{
protected: // serialization에서만 만들어집니다.
	CWinProg3_testView();
	DECLARE_DYNCREATE(CWinProg3_testView)

	// 특성입니다.
public:
	CWinProg3_testDoc* GetDocument() const;
	CTreeCtrl m_tree;
	//위치 지정 변수
	int start_x;
	int start_y;
	bool drawline;
	int count;


	int time[2];
	int X, Y;
	bool seg1, seg2, seg3, seg4, seg5, seg6, seg7;
	
	
	CPoint start_point;
	CPoint end_point;


	CArray<Gate, Gate&> Gates; // 논리게이트 객체 리스트
	CArray<Line, Line&> Lines;	//논리 회로 선 객체 리스트

	int typeOfGate;
	
	
	// 작업입니다.
public:
	void loadBitmap(CBitmap& bit, BITMAP& bminfo, int bmindex);

	// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

	// 구현입니다.
public:
	virtual ~CWinProg3_testView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

	// 생성된 메시지 맵 함수
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

#ifndef _DEBUG  // WinProg3_testView.cpp의 디버그 버전
inline CWinProg3_testDoc* CWinProg3_testView::GetDocument() const
{
	return reinterpret_cast<CWinProg3_testDoc*>(m_pDocument);
}
#endif

