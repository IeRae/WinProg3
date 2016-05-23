
// WinProg3_testView.cpp : CWinProg3_testView Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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
	ON_WM_LBUTTONDOWN()
	ON_COMMAND(ID_NAND_GATE, &CWinProg3_testView::OnNandGate)
	ON_COMMAND(ID_AND_GATE, &CWinProg3_testView::OnAndGate)
	ON_COMMAND(ID_OR_GATE, &CWinProg3_testView::OnOrGate)
	ON_COMMAND(ID_NOT_GATE, &CWinProg3_testView::OnNotGate)
	ON_COMMAND(ID_NOR_GATE, &CWinProg3_testView::OnNorGate)
	ON_COMMAND(ID_XOR_GATE, &CWinProg3_testView::OnXorGate)
END_MESSAGE_MAP()

// CWinProg3_testView ����/�Ҹ�

CWinProg3_testView::CWinProg3_testView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	start_x = start_y = 0;
	typeOfGate = 0;
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

void CWinProg3_testView::OnDraw(CDC* pDC)
{
	CWinProg3_testDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: ���⿡ ���� �����Ϳ� ���� �׸��� �ڵ带 �߰��մϴ�.

	if (typeOfGate != 0) {
		CBitmap bitmap;
		BITMAP bminfo;
		switch (typeOfGate)
		{
		case 1:

			bitmap.LoadBitmapW(IDB_AND);
			break;
		case 2:
			bitmap.LoadBitmapW(IDB_OR);
			break;
		case 3:
			bitmap.LoadBitmapW(IDB_NOT);
			break;
		case 4:
			bitmap.LoadBitmapW(IDB_NAND);
			break;
		case 5:
			bitmap.LoadBitmapW(IDB_NOR);
			break;
		case 6:
			bitmap.LoadBitmapW(IDB_XOR);
			break;
		default:

			break;
		}

		bitmap.GetBitmap(&bminfo);

		//

		CDC dcmem;
		dcmem.CreateCompatibleDC(&(*pDC));
		dcmem.SelectObject(&bitmap);


		for (int i = 0; i < Points.GetCount(); i++) {

			if (start_x != 0)	pDC->BitBlt(Points[i].x, Points[i].y, bminfo.bmWidth, bminfo.bmHeight, &dcmem, 0, 0, SRCCOPY);

		}
		//...
	}
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


void CWinProg3_testView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CView::OnLButtonDown(nFlags, point);


	//	start_x = point.x;
	//	start_y = point.y;  

	CPoint* points = new CPoint(point.x, point.y);
	start_x = point.x;
	start_y = point.y;
	Points.Add(point);
	current = Points.GetCount() - 1;

	Invalidate();
}




void CWinProg3_testView::OnAndGate()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	typeOfGate = 1;
}

void CWinProg3_testView::OnOrGate()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	typeOfGate = 2;
}

void CWinProg3_testView::OnNotGate()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	typeOfGate = 3;
}

void CWinProg3_testView::OnNandGate()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	typeOfGate = 4;
}

void CWinProg3_testView::OnNorGate()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	typeOfGate = 5;
}


void CWinProg3_testView::OnXorGate()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	typeOfGate = 6;
}
