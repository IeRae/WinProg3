
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

#include <afxtempl.h>
#include "InfoDialog.h"
#include "InputInfoDialog.h"

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
	ON_COMMAND(ID_OUTPUT_BUTTON, &CWinProg3_testView::OnOutputButton)
	ON_COMMAND(ID_INPUT_BUTTON, &CWinProg3_testView::OnInputButton)
	ON_COMMAND(ID_LINE, &CWinProg3_testView::OnLine)
	ON_COMMAND(ID_7SEGMENT, &CWinProg3_testView::OnSevenSegment)
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
END_MESSAGE_MAP()

// CWinProg3_testView ����/�Ҹ�

CWinProg3_testView::CWinProg3_testView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	//start_x = 0; start_y = 0;
	typeOfGate = 0;
	test = false;
	//Gates.SetSize(100);
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

void CWinProg3_testView::loadBitmap(CBitmap& bit, BITMAP& bminfo,int bmindex) {
	switch (bmindex)
	{
	case ANDSHAPE:
		bit.LoadBitmapW(IDB_AND);
		break;
	case ORSHAPE:
		bit.LoadBitmapW(IDB_OR);
		break;
	case NOTSHAPE:
		bit.LoadBitmapW(IDB_NOT);
		break;
	case NANDSHAPE:
		bit.LoadBitmapW(IDB_NAND);
		break;
	case NORSHAPE:
		bit.LoadBitmapW(IDB_NOR);
		break;
	case XORSHAPE:
		bit.LoadBitmapW(IDB_XOR);
		break;
	case SEVENSEGMENT:
		break;		
	case LINESHAPE:
		break;
	case OUTPUTTRUE:
		bit.LoadBitmapW(IDB_OUTPUT_TRUE);
		break;
	case OUTPUTFALSE:
		bit.LoadBitmapW(IDB_OUTPUT_FALSE);
		break;
	case INPUTTRUE:
		bit.LoadBitmapW(IDB_INPUT_TRUE);
		break;
	case INPUTFALSE:
		bit.LoadBitmapW(IDB_INPUT_FALSE);
		break;
	default:
		break;
	}
	//AfxMessageBox(_T("�з�"));
	bit.GetBitmap(&bminfo);
	//AfxMessageBox(_T("�Ϸ�"));
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

		//�� ȸ�� ������ �����ϴ� �κ�
		for (int i = 0; i < Gates.GetSize(); i++) {
			//pDoc->getLogic(Gates[i]);
			Gates[i].outputArray[Gates[i].outputArrayIndex] = pDoc->getLogic(Gates[i]);
		}

		CDC dcmem;
		dcmem.CreateCompatibleDC(&(*pDC));


		//�� ����Ʈ�� �׷��ִ� �κ�
		if (start_x != 0) {
			for (int i = 0; i < Gates.GetSize(); i++) {
				CBitmap bitmap;
				BITMAP bminfo;

				loadBitmap(bitmap, bminfo, Gates[i].GateId);

				//��Ʈ�� ũ�⸦ �����ϴ� �κ�
				if (Gates[i].bmSizeFlag == false) {
					Gates[i].setBmSize(bminfo.bmWidth, bminfo.bmHeight);
					Gates[i].bmSizeFlag = true;
				}


				dcmem.SelectObject(&bitmap);
				pDC->BitBlt(Gates[i].x, Gates[i].y, Gates[i].width, Gates[i].height, &dcmem, 0, 0, SRCCOPY);


				//���� ����ϴ� �κ�
				pDC->TextOut(Gates[i].x + 1, Gates[i].y + Gates[i].height + 5, Gates[i].lable);

				int index;
				for (int j = 0; j < Lines.GetSize(); j++) {


					//Gate�� �Է°� �Ҵ�
					index = Lines[j].endGateIndex;
					if (index == i) {
						if (Gates[i].inputArrayIndex < Gates[i].fixedInputIndex)
							Gates[i].inputArray[Gates[i].inputArrayIndex++] = Lines[j].endBoolValue;
						else
							AfxMessageBox(_T("�߸��� �� ȸ�� ����"));
					}

					//Gate�� ��°� �Ҵ�
					index = Lines[j].startGateIndex;
					if (index == i) {
						if (Gates[i].outputArrayIndex < Gates[i].fixedOutputIndex)
							Lines[j].startBoolValue = Gates[i].outputArray[Gates[i].outputArrayIndex++];
						else
							AfxMessageBox(_T("�߸��� �� ȸ�� ����"));
					}
				}
			}
		}
		/*
		if (typeOfGate = SEVENSEGMENT & start_x !=0) {	//7���׸�Ʈ �׸���
			time[0] = 0;
			//�� ����
			CPen pen(PS_SOLID, 1, RGB(200, 200, 200));
			CBrush red = (RGB(255, 0, 0));
			CBrush white = (RGB(255, 255, 255));

			int select;
			Y = 50;
			X = start_x;

			select = time[0];
				CPoint point_1[6] = { { X,Y },{ X + 10,Y - 5 },{ X + 40,Y - 5 },{ X + 50,Y },{ X + 40,Y + 5 },{ X + 10,Y + 5 } };	//�ð� ��� ��ǥ �׸���
				CPoint point_6[6] = { { X + 53,Y + 3 },{ X + 58,Y + 13 },{ X + 58,Y + 43 },{ X + 53,Y + 53 },{ X + 48,Y + 43 },{ X + 48,Y + 13 } };
				CPoint point_7[6] = { { X + 53,Y + 59 },{ X + 58, Y + 69 },{ X + 58,Y + 99 },{ X + 53,Y + 109 },{ X + 48,Y + 99 },{ X + 48,Y + 69 } };
				CPoint point_2[6] = { { X,Y + 112 },{ X + 10,Y + 107 },{ X + 40,Y + 107 },{ X + 50,Y + 112 },{ X + 40,Y + 117 },{ X + 10,Y + 117 } };
				CPoint point_5[6] = { { X - 3,Y + 59 },{ X + 3,Y + 69 },{ X + 3,Y + 99 },{ X - 3,Y + 109 },{ X - 8,Y + 99 },{ X - 8,Y + 69 } };
				CPoint point_4[6] = { { X - 3,Y + 3 },{ X + 3,Y + 13 },{ X + 3,Y + 43 },{ X - 3,Y + 53 },{ X - 8,Y + 43 },{ X - 8,Y + 13 } };
				CPoint point_3[6] = { { X,Y + 56 },{ X + 10,Y + 51 },{ X + 40,Y + 51 },{ X + 50,Y + 56 },{ X + 40,Y + 61 },{ X + 10,Y + 61 } };
				pDC->SelectObject(pen);


				//				  1
				//			 ---------
				//		4	|    3    | 6
				//			 ---------
				//		5	|         | 7
				//			 ---------
				//               2


				seg1 = seg2 = seg3 = seg4 = seg5 = seg6 = seg7 = false;
				switch (select)	//����ġ���� ���� ���׸�Ʈ ����
				{
				case 0: seg1 = seg2 = seg4 = seg5 = seg6 = seg7 = true;	break;
				case 1:	seg6 = seg7 = true; break;
				case 2: seg1 = seg6 = seg3 = seg5 = seg2 = true; break;
				case 3: seg1 = seg6 = seg3 = seg7 = seg2 = true; break;
				case 4: seg4 = seg3 = seg6 = seg7 = true;	break;
				case 5: seg1 = seg4 = seg3 = seg7 = seg2 = true; break;
				case 6: seg1 = seg4 = seg5 = seg2 = seg7 = seg3 = true; break;
				case 7: seg1 = seg6 = seg7 = true; break;
				case 8: seg1 = seg2 = seg3 = seg4 = seg5 = seg6 = seg7 = true; break;
				case 9: seg1 = seg3 = seg4 = seg6 = seg7 = seg2 = true; break;
				}



				if (seg1) {	//�� ���׸�Ʈ�� ���ۼ���
					pDC->SelectObject(red);
					pDC->Polygon(point_1, 6);
				}
				else {
					pDC->SelectObject(white);
					pDC->Polygon(point_1, 6);
				}

				if (seg2) {
					pDC->SelectObject(red);
					pDC->Polygon(point_2, 6);
				}
				else {
					pDC->SelectObject(white);
					pDC->Polygon(point_2, 6);
				}

				if (seg3) {
					pDC->SelectObject(red);
					pDC->Polygon(point_3, 6);
				}
				else {
					pDC->SelectObject(white);
					pDC->Polygon(point_3, 6);
				}

				if (seg4) {
					pDC->SelectObject(red);
					pDC->Polygon(point_4, 6);
				}
				else {
					pDC->SelectObject(white);
					pDC->Polygon(point_4, 6);
				}

				if (seg5) {
					pDC->SelectObject(red);
					pDC->Polygon(point_5, 6);
			}
				else {
					pDC->SelectObject(white);
					pDC->Polygon(point_5, 6);
		}

				if (seg6) {
					pDC->SelectObject(red);
					pDC->Polygon(point_6, 6);
	}
				else {
					pDC->SelectObject(white);
					pDC->Polygon(point_6, 6);
				}

				if (seg7) {
					pDC->SelectObject(red);
					pDC->Polygon(point_7, 6);
				}
				else {
					pDC->SelectObject(white);
					pDC->Polygon(point_7, 6);
				}
				InvalidateRect(NULL, false);

		}




	}


			//���α׸���
	if (start_point.x != 0) {
		for (int i = 0; i < Lines.GetSize(); i++) {

			CClientDC dc(this);
			dc.MoveTo(Lines[i].s_point.x, Lines[i].s_point.y);
			dc.LineTo(Lines[i].e_point.x, Lines[i].e_point.y);
		}
	}

	// Ʈ�� ��Ʈ�� ����
	m_tree.Create(WS_CHILD | WS_VISIBLE | WS_BORDER |
		TVS_HASBUTTONS | TVS_HASLINES | TVS_LINESATROOT,
		CRect(10, 10, 180, 180), this, IDC_TREE1);

	// �̹��� ����Ʈ ������ �ʱ�ȭ
	CImageList il;
	il.Create(IDB_BITMAP2, 16, 1, RGB(255, 255, 255));

	// �̹��� ����Ʈ ����
	m_tree.SetImageList(&il, TVSIL_NORMAL);
	il.Detach();

	// 1���� �ʱ�ȭ
	HTREEITEM hGate = m_tree.InsertItem(_T("������Ʈ"), 0, 0, TVI_ROOT, TVI_LAST);
	HTREEITEM hInOut = m_tree.InsertItem(_T("�Է�/���"), 0, 0, TVI_ROOT, TVI_LAST);

	// 2-���� �ʱ�ȭ
	m_tree.InsertItem(_T("AND"), 1, 1, hGate, TVI_LAST);
	m_tree.InsertItem(_T("OR"), 1, 1, hGate, TVI_LAST);
	m_tree.InsertItem(_T("NOT"), 1, 1, hGate, TVI_LAST);
	m_tree.InsertItem(_T("NAND"), 1, 1, hGate, TVI_LAST);
	m_tree.InsertItem(_T("NOR"), 1, 1, hGate, TVI_LAST);
	m_tree.InsertItem(_T("XOR"), 1, 1, hGate, TVI_LAST);

	m_tree.InsertItem(_T("�Է�"), 1, 1, hInOut, TVI_LAST);
	m_tree.InsertItem(_T("���"), 1, 1, hInOut, TVI_LAST);
	*/
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

	CString msg;

	start_x = point.x;
	start_y = point.y;

	Gate* temp = new Gate(typeOfGate, start_x, start_y);

	Gates.Add(*temp);

	//msg.Format(_T("site x : %d, y : %d"), start_x, start_y);

	//AfxMessageBox(msg);

	CClientDC dc(this);
	//dc.MoveTo(point.x, point.y);


	/*
	//���λ����κ�
	start_point = point;
	Line* tempL = new Line(true, 1, true, 1, start_point, end_point);
	Lines.Add(*tempL);



	for (int i = 0; i < Gates.GetSize(); i++) {
		if ((point.x >= (Gates[i].x + Gates[i].width - 10)) && (point.x <= (Gates[i].x + Gates[i].width + 10)))
			if ((point.y >= Gates[i].y + Gates[i].height / 2 - 10) && (point.y <= (Gates[i].y + Gates[i].height / 2 + 10))) {
				
				//���α׸���
				if (start_point.x != 0) {
					for (int i = 0; i < Lines.GetSize(); i++) {

						CClientDC dc(this);
						dc.MoveTo(Lines[i].s_point.x, Lines[i].s_point.y);
						dc.LineTo(Lines[i].e_point.x, Lines[i].e_point.y);
					}
				}


			}
	}
	*/

	Invalidate();
}




void CWinProg3_testView::OnAndGate()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	typeOfGate = ANDSHAPE;
}

void CWinProg3_testView::OnOrGate()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	typeOfGate = ORSHAPE;
}

void CWinProg3_testView::OnNotGate()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	typeOfGate = NOTSHAPE;
}

void CWinProg3_testView::OnNandGate()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	typeOfGate = NANDSHAPE;
}

void CWinProg3_testView::OnNorGate()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	typeOfGate = NORSHAPE;
}


void CWinProg3_testView::OnXorGate()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	typeOfGate = XORSHAPE;
}


void CWinProg3_testView::OnOutputButton()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	typeOfGate = OUTPUTTRUE;
}


void CWinProg3_testView::OnRButtonDown(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	
	//�� ����Ʈ�� �´� ��ȭ ���� ȣ�� �� �� ����
	for (int i = 0; i < Gates.GetSize(); i++){

		if((point.x >= Gates[i].x) && (point.x <= (Gates[i].x + Gates[i].width)))
			if ((point.y >= Gates[i].y) && (point.y <= (Gates[i].y + Gates[i].height))) {
				
				//�Է� gate �϶� �Է� ��ȭ ���� ȣ��
				if ((Gates[i].GateId == INPUTTRUE) || (Gates[i].GateId == INPUTFALSE)) {
					
					int clocktype;
					CInputInfoDialog dlg = new CInputInfoDialog;
					//��ȭ ���ڷ� ���� �ʱ�ȭ
					dlg.inputLable = Gates[i].lable;
					dlg.checkClock = test;

					int result = dlg.DoModal();
					if (result == IDOK) {
						//��ȭ���ڷ� ���� ������ ����
						Gates[i].lable = dlg.inputLable;
						clocktype = dlg.clock_number;
						test = dlg.checkClock;

						if(dlg.checkClock){
							switch (clocktype) {
							case HZTIMES_1:
								SetTimer(1,1000,NULL);
								AfxMessageBox(_T("1"));
								break;
							case HZTIMES_10:
								SetTimer(1, 100, NULL);
								AfxMessageBox(_T("10"));
								break;
							case HZTIMES_100:
								SetTimer(1, 10, NULL);
								AfxMessageBox(_T("100"));
								break;
							}
						}
						else {
							KillTimer(1);
						}

						Invalidate();
					}
					else if (result == IDCANCEL) {
						Gates[i].lable = _T("");
						Invalidate();
					}
				}else{
					
				CInfoDialog dlg = new CInfoDialog;

				//��ȭ ���ڷ� ���� �ʱ�ȭ
				dlg.lable = Gates[i].lable;

				int result = dlg.DoModal();
				if (result == IDOK) {
					Gates[i].lable = dlg.lable;
					Invalidate();
				}
				else if (result == IDCANCEL) {
					Gates[i].lable = _T("");
					Invalidate();
				}
				
		

				}
				
			}
		
	}

	CView::OnRButtonDown(nFlags, point);
}


void CWinProg3_testView::OnMouseMove(UINT nFlags, CPoint point)
{/*
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	CRect rect;
	CBrush brush(HS_CROSS, RGB(255, 255, 255));
	GetClientRect(rect);
	dc.Rectangle(rect.left, rect.top, rect.right, rect.bottom);

	if ((nFlags&&MK_LBUTTON) == MK_LBUTTON)
	{
		dc.MoveTo(start_x, start_y);
//		dc.LineTo(start_x, start_y);
	}
	*/


	if ((nFlags&&MK_LBUTTON) == MK_LBUTTON)
	{
		end_point = point;
	}
	
	CView::OnMouseMove(nFlags, point);
}


void CWinProg3_testView::OnInputButton()
{
	typeOfGate = INPUTTRUE;
}


void CWinProg3_testView::OnLButtonUp(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CClientDC dc(this);

	end_point = point;

	//dc.MoveTo(start_point.x, start_point.y);
	//dc.LineTo(end_point.x, end_point.y);

	count = 1;
	count++;

//******
//	Line* tempL = new Line(true, count, true, count, start_point, end_point);
//	Lines.Add(*tempL);



	//drawline = TRUE;
	

	//����϶��� ���� �׷��������




	Invalidate();
	CView::OnLButtonUp(nFlags, point);
}


void CWinProg3_testView::OnLine()
{
	typeOfGate = LINESHAPE;
	//drawline = TRUE;

}


void CWinProg3_testView::OnSevenSegment()
{
	typeOfGate = SEVENSEGMENT;
	CClientDC dc(this);
	OnDraw(&dc);	//�������ð����� OnDrawȣ��
}


void CWinProg3_testView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	CView::OnTimer(nIDEvent);
}
