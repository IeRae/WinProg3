
// winprog03View.cpp : Cwinprog03View 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다
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

// Cwinprog03View 생성/소멸

Cwinprog03View::Cwinprog03View()
{
	// TODO: 여기에 생성 코드를 추가합니다.

}

Cwinprog03View::~Cwinprog03View()
{
}

BOOL Cwinprog03View::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

	return CView::PreCreateWindow(cs);
}

// Cwinprog03View 그리기

void Cwinprog03View::OnDraw(CDC* /*pDC*/)
{
	Cwinprog03Doc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.
}


// Cwinprog03View 진단

#ifdef _DEBUG
void Cwinprog03View::AssertValid() const
{
	CView::AssertValid();
}

void Cwinprog03View::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cwinprog03Doc* Cwinprog03View::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cwinprog03Doc)));
	return (Cwinprog03Doc*)m_pDocument;
}
#endif //_DEBUG


// Cwinprog03View 메시지 처리기
