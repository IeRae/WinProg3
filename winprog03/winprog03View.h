
// winprog03View.h : Cwinprog03View Ŭ������ �������̽�
//

#pragma once


class Cwinprog03View : public CView
{
protected: // serialization������ ��������ϴ�.
	Cwinprog03View();
	DECLARE_DYNCREATE(Cwinprog03View)

// Ư���Դϴ�.
public:
	Cwinprog03Doc* GetDocument() const;

// �۾��Դϴ�.
public:

// �������Դϴ�.
public:
	virtual void OnDraw(CDC* pDC);  // �� �並 �׸��� ���� �����ǵǾ����ϴ�.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// �����Դϴ�.
public:
	virtual ~Cwinprog03View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ������ �޽��� �� �Լ�
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // winprog03View.cpp�� ����� ����
inline Cwinprog03Doc* Cwinprog03View::GetDocument() const
   { return reinterpret_cast<Cwinprog03Doc*>(m_pDocument); }
#endif

