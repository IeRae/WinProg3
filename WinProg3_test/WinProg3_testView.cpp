
// WinProg3_testView.cpp : CWinProg3_testView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�
#ifndef SHARED_HANDLERS
#include "WinProg3_test.h"
#endif

#include "WinProg3_testDoc.h"
#include "WinProg3_testView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWinProg3_testView

IMPLEMENT_DYNCREATE(CWinProg3_testView, CView)

BEGIN_MESSAGE_MAP(CWinProg3_testView, CView)
END_MESSAGE_MAP()

// CWinProg3_testView ����/�Ҹ�

CWinProg3_testView::CWinProg3_testView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.

}

CWinProg3_testView::~CWinProg3_testView()
{
}

BOOL CWinProg3_testView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs�� �����Ͽ� ���⿡��
	//  Window Ŭ���� �Ǵ� ��Ÿ���� �����մϴ�.

	return CView::PreCreateWindow(cs);
}

// CWinProg3_testView �׸���

void CWinProg3_testView::OnDraw(CDC* /*pDC*/)
{
	CWinProg3_testDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.
}


// CWinProg3_testView ����

#ifdef _DEBUG
void CWinProg3_testView::AssertValid() const
{
	CView::AssertValid();
}

void CWinProg3_testView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWinProg3_testDoc* CWinProg3_testView::GetDocument() const // ����׵��� ���� ������ �ζ������� �����˴ϴ�.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinProg3_testDoc)));
	return (CWinProg3_testDoc*)m_pDocument;
}
#endif //_DEBUG


// CWinProg3_testView �޽��� ó����
