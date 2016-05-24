
// WinProg3_testView.h : CWinProg3_testView 클래스의 인터페이스

#define MAX 1024

#pragma once
struct Gate {
	//비트맵 정보
	int GateId;
	int x;
	int y;
	
	//입력값 정보
	bool inputArray[MAX];
	int inputArrayIndex;
	
	//출력값 정보
	bool outputArray[MAX];
	int outputArrayIndex;
	Gate() {}
	Gate(int a, int b, int c) { GateId = a; x = b; y = c; }
};

struct Line {
	//시작 bool value 변수
	bool startBoolValue;

	//시작 Gate index
	int startGateIndex;
	
	//종료 bool value 변수
	bool endBoolValue;
	
	//종료 Gate index
	int endGateIndex;

	Line() {}
	Line(bool start, int start_in, bool end, int end_in) { startBoolValue = start; startGateIndex = start_in; endBoolValue = end; endGateIndex = end_in; }
};

class CWinProg3_testView : public CView
{
protected: // serialization에서만 만들어집니다.
	CWinProg3_testView();
	DECLARE_DYNCREATE(CWinProg3_testView)

	// 특성입니다.
public:
	CWinProg3_testDoc* GetDocument() const;

	//위치 지정 변수
	int start_x;
	int start_y;

	CArray<Gate, Gate&> Gates; // 논리게이트 객체 리스트
	CArray<Line, Line&> Lines;	//논리 회로 선 객체 리스트

	int typeOfGate;
	void CWinProg3_testView::loadBitmap(CBitmap& bit, BITMAP& bminfo, int bmindex);
	// 작업입니다.
public:

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
};

#ifndef _DEBUG  // WinProg3_testView.cpp의 디버그 버전
inline CWinProg3_testDoc* CWinProg3_testView::GetDocument() const
{
	return reinterpret_cast<CWinProg3_testDoc*>(m_pDocument);
}
#endif

