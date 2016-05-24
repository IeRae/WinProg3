
// WinProg3_testView.h : CWinProg3_testView Ŭ������ �������̽�

#define MAX 1024

#pragma once
struct Gate {
	//��Ʈ�� ����
	int GateId;
	int x;
	int y;
	
	//�Է°� ����
	bool inputArray[MAX];
	int inputArrayIndex;
	
	//��°� ����
	bool outputArray[MAX];
	int outputArrayIndex;
	Gate() {}
	Gate(int a, int b, int c) { GateId = a; x = b; y = c; }
};

struct Line {
	//���� bool value ����
	bool startBoolValue;

	//���� Gate index
	int startGateIndex;
	
	//���� bool value ����
	bool endBoolValue;
	
	//���� Gate index
	int endGateIndex;

	Line() {}
	Line(bool start, int start_in, bool end, int end_in) { startBoolValue = start; startGateIndex = start_in; endBoolValue = end; endGateIndex = end_in; }
};

class CWinProg3_testView : public CView
{
protected: // serialization������ ��������ϴ�.
	CWinProg3_testView();
	DECLARE_DYNCREATE(CWinProg3_testView)

	// Ư���Դϴ�.
public:
	CWinProg3_testDoc* GetDocument() const;

	//��ġ ���� ����
	int start_x;
	int start_y;

	CArray<Gate, Gate&> Gates; // ������Ʈ ��ü ����Ʈ
	CArray<Line, Line&> Lines;	//�� ȸ�� �� ��ü ����Ʈ

	int typeOfGate;
	void CWinProg3_testView::loadBitmap(CBitmap& bit, BITMAP& bminfo, int bmindex);
	// �۾��Դϴ�.
public:

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
};

#ifndef _DEBUG  // WinProg3_testView.cpp�� ����� ����
inline CWinProg3_testDoc* CWinProg3_testView::GetDocument() const
{
	return reinterpret_cast<CWinProg3_testDoc*>(m_pDocument);
}
#endif

