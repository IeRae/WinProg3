
// WinProg3_testView.h : CWinProg3_testView Ŭ������ �������̽�
//

#pragma once


class CWinProg3_testView : public CView
{
protected: // serialization������ ��������ϴ�.
	CWinProg3_testView();
	DECLARE_DYNCREATE(CWinProg3_testView)

// Ư���Դϴ�.
public:
	CWinProg3_testDoc* GetDocument() const;

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
};

#ifndef _DEBUG  // WinProg3_testView.cpp�� ����� ����
inline CWinProg3_testDoc* CWinProg3_testView::GetDocument() const
   { return reinterpret_cast<CWinProg3_testDoc*>(m_pDocument); }
#endif

