
// winprog03View.cpp : Cwinprog03View Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�
#ifndef SHARED_HANDLERS
#include "winprog03.h"
#endif

#include "winprog03Doc.h"
#include "winprog03View.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cwinprog03View

IMPLEMENT_DYNCREATE(Cwinprog03View, CView)

BEGIN_MESSAGE_MAP(Cwinprog03View, CView)
END_MESSAGE_MAP()

// Cwinprog03View ����/�Ҹ�

Cwinprog03View::Cwinprog03View()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

Cwinprog03View::~Cwinprog03View()
{
}

BOOL Cwinprog03View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// Cwinprog03View �׸���

void Cwinprog03View::OnDraw(CDC* /*pDC*/)
{
	Cwinprog03Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// Cwinprog03View ����

#ifdef _DEBUG
void Cwinprog03View::AssertValid() const
{
	CView::AssertValid();
}

void Cwinprog03View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cwinprog03Doc* Cwinprog03View::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cwinprog03Doc)));
	return (Cwinprog03Doc*)m_pDocument;
}
#endif //_DEBUG


// Cwinprog03View �޽��� ó����
