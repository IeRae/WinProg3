
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
	ON_COMMAND(ID_Branch, &CWinProg3_testView::OnBranch)
	ON_COMMAND(ID_DFF, &CWinProg3_testView::OnDFF)
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	//ON_BN_CLICKED(IDC_BUTTON1, &CWinProg3_testView::OnBnClickedButton1)
END_MESSAGE_MAP()

// CWinProg3_testView ����/�Ҹ�

CWinProg3_testView::CWinProg3_testView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	//start_x = 0; start_y = 0;
	typeOfGate = NONE;
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
	case BRANCH:
		bit.LoadBitmapW(IDB_BRANCH);
		break;
	case DFLIPFLOP:
		bit.LoadBitmapW(IDB_DFF);
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

				if((Gates[i].GateId != LINESHAPE) || (Gates[i].GateId != NONE)){

					/*
					//output ����Ʈ�� ���� Ȯ��
					if ((Gates[i].GateId == OUTPUTFALSE) && (Gates[i].outputArray[0] == true)) {
						Gates[i].GateId = OUTPUTTRUE;
					}
					else if ((Gates[i].GateId == OUTPUTTRUE) && (Gates[i].outputArray[0] == false))
						Gates[i].GateId = OUTPUTFALSE;
						


					if ((Gates[i].GateId == INPUTFALSE) || (Gates[i].GateId == INPUTTRUE)) {
						CString msg;
						msg.Format(_T("%d"), Gates[i].outputArray[0]);
						//AfxMessageBox(msg);
					}*/
							

					loadBitmap(bitmap, bminfo, Gates[i].GateId);
						
					//CString msg;
					//msg.Format(_T(" �Ҹ��� : %d "), rotate2);
					//AfxMessageBox(msg);
					
						//	if (view_rote == TRUE) {
						Bitmap *pBitmap3;
						//pBitmap3 = Bitmap::FromResource(AfxGetInstanceHandle(), (WCHAR*)MAKEINTRESOURCE(IDB_BITMAP2));
						pBitmap3 = Bitmap::FromHBITMAP((HBITMAP)bitmap.m_hObject, NULL);
						//	CClientDC dc(this);

			//			if (Gates[i].rota == true) {
							switch (Gates[i].rota)
							{
							case 0:
								break;
							case 1:
								pBitmap3->RotateFlip(Rotate180FlipNone);
								break;
							case 2:
								pBitmap3->RotateFlip(Rotate90FlipNone);
								break;
							case 3:
								pBitmap3->RotateFlip(Rotate90FlipY);
								break;
							}

							//	CBitmap memBitmap; //Bitmap�� �޾Ƽ� �׸��Ե� CBitmap�Դϴ�.
							//	bitmap.CreateCompatibleBitmap(&(*pDC), pBitmap3->GetWidth(), pBitmap3->GetHeight());
							//	memBitmap.CreateCompatibleBitmap(&(*pDC), pBitmap3->GetWidth(), pBitmap3->GetHeight());
							dcmem.SelectObject(&bitmap);
							Graphics graphicsMem(dcmem.GetSafeHdc());
							graphicsMem.DrawImage(pBitmap3, 0, 0); //CBitmap ������ Bitmap �̹����� �׷��ݴϴ�.
							delete pBitmap3; //������ pBitmap�� ������ ������ �����Ƿ� delete ��ŵ�ϴ�.
					//	}
				

				//��Ʈ�� ũ�⸦ �����ϴ� �κ�
				if (Gates[i].bmSizeFlag == false) {
					Gates[i].setBmSize(bminfo.bmWidth, bminfo.bmHeight);
					Gates[i].bmSizeFlag = true;
				}
				


				dcmem.SelectObject(&bitmap);
				pDC->BitBlt(Gates[i].x, Gates[i].y, Gates[i].width, Gates[i].height, &dcmem, 0, 0, SRCCOPY);
				
				pDC->TextOut(Gates[i].x + 1, Gates[i].y + Gates[i].height + 5, Gates[i].lable);
				}
											
			//typeOfGate = LINESHAPE;
			}
		}
		
		if (typeOfGate == SEVENSEGMENT && start_x != 0) {	//7���׸�Ʈ �׸���
			time[0] = 0;
			//�� ����
			CPen pen(PS_SOLID, 1, RGB(200, 200, 200));
			CBrush red = (RGB(255, 0, 0));
			CBrush white = (RGB(255, 255, 255));
			time[0] = 0;
			//�� ����
			int select;
			X = start_x2;
			//Y = 150;
			Y = start_y2;

			select = time[0];
			CPoint point_1[6] = { { X,Y },{ X + 10,Y - 5 },{ X + 40,Y - 5 },{ X + 50,Y },{ X + 40,Y + 5 },{ X + 10,Y + 5 } };	//7���׸�Ʈ ��� ��ǥ �׸���
			CPoint point_6[6] = { { X + 53,Y + 3 },{ X + 58,Y + 13 },{ X + 58,Y + 43 },{ X + 53,Y + 53 },{ X + 48,Y + 43 },{ X + 48,Y + 13 } };
			CPoint point_7[6] = { { X + 53,Y + 59 },{ X + 58, Y + 69 },{ X + 58,Y + 99 },{ X + 53,Y + 109 },{ X + 48,Y + 99 },{ X + 48,Y + 69 } };
			CPoint point_2[6] = { { X,Y + 112 },{ X + 10,Y + 107 },{ X + 40,Y + 107 },{ X + 50,Y + 112 },{ X + 40,Y + 117 },{ X + 10,Y + 117 } };
			CPoint point_5[6] = { { X - 3,Y + 59 },{ X + 3,Y + 69 },{ X + 3,Y + 99 },{ X - 3,Y + 109 },{ X - 8,Y + 99 },{ X - 8,Y + 69 } };
			CPoint point_4[6] = { { X - 3,Y + 3 },{ X + 3,Y + 13 },{ X + 3,Y + 43 },{ X - 3,Y + 53 },{ X - 8,Y + 43 },{ X - 8,Y + 13 } };
			CPoint point_3[6] = { { X,Y + 56 },{ X + 10,Y + 51 },{ X + 40,Y + 51 },{ X + 50,Y + 56 },{ X + 40,Y + 61 },{ X + 10,Y + 61 } };
			pDC->SelectObject(pen);

			//�Լ�ȣ��
			pDoc->SevenSegment(seg1, seg2, seg3, seg4, seg5, seg6, seg7, select);

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
		
		

	//���λ���
	if (start_point.x != 0) {
		for (int i = 0; i < Lines.GetSize(); i++) {
				if (Lines[i].Drawline == TRUE) {
					CClientDC dc(this);
					dc.MoveTo(Lines[i].s_point.x, Lines[i].s_point.y);
					dc.LineTo(Gates[Lines[i].endGateIndex].x, Gates[Lines[i].endGateIndex].y + Gates[Lines[i].endGateIndex].height / 2);
				
					CString msg;
					msg.Format(_T("%d : in %d "), Lines[i].startGateIndex, Lines[i].BoolValue);
					//AfxMessageBox(msg);
				}
			}
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

	//if (typeOfGate != LINESHAPE) {
		//CString msg;

	
	if (typeOfGate != LINESHAPE && typeOfGate !=SEVENSEGMENT) {

		start_x = point.x;
		start_y = point.y;
		Gate* temp = new Gate(typeOfGate, start_x, start_y);

		Gates.Add(*temp);

	}else if(typeOfGate == LINESHAPE){
		CClientDC dc(this);
	
		drawline = FALSE;
			
			//AfxMessageBox(_T("����"));
		//old_end_point = start_point;
		for (int i = 0; i < Gates.GetSize(); i++) {
				//AfxMessageBox(_T("Ž��"));
				if ((point.x >= (Gates[i].x + Gates[i].width - 50)) && (point.x <= (Gates[i].x + Gates[i].width + 50))){
					if ((point.y >= Gates[i].y + Gates[i].height / 2 - 10) && (point.y <= (Gates[i].y + Gates[i].height / 2 + 10))) {
						//AfxMessageBox(_T("in"));
					//	dc.MoveTo(point.x, point.y);	
						
						start_point = point;
						drawline = TRUE;
						from = i;
							//AfxMessageBox(_T("������ ����ҳ�"));
					}
				}
		}
	}else if(typeOfGate == SEVENSEGMENT){
		drawSeg = TRUE; 
		start_x2 = point.x;
		start_y2 = point.y;


	}
		//AfxMessageBox(_T("������ ����"));
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
void CWinProg3_testView::OnBranch()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	typeOfGate = BRANCH;
}

void CWinProg3_testView::OnDFF()
{
	// TODO: ���⿡ ��� ó���� �ڵ带 �߰��մϴ�.
	typeOfGate = DFLIPFLOP;
}



void CWinProg3_testView::OnRButtonDown(UINT nFlags, CPoint point)
{


	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.

	//�� ����Ʈ�� �´� ��ȭ ���� ȣ�� �� �� ����
	for (int i = 0; i < Gates.GetSize(); i++) {

		if ((point.x >= Gates[i].x) && (point.x <= (Gates[i].x + Gates[i].width)))
			if ((point.y >= Gates[i].y) && (point.y <= (Gates[i].y + Gates[i].height))) {

				if ((Gates[i].GateId == OUTPUTTRUE) || (Gates[i].GateId == OUTPUTFALSE)) {
					CString msg;
					msg.Format(_T("%d"), Gates[i].outputArray[0]);
					AfxMessageBox(msg);
				}

				//�Է� gate �϶� �Է� ��ȭ ���� ȣ��
				if ((Gates[i].GateId == INPUTTRUE) || (Gates[i].GateId == INPUTFALSE)) {

					int clocktype;
					CInputInfoDialog dlg = new CInputInfoDialog;
					//��ȭ ���ڷ� ���� �ʱ�ȭ
					dlg.inputLable = Gates[i].lable;

					int result = dlg.DoModal();
					if (result == IDOK) {
						//��ȭ���ڷ� ���� ������ ����
						Gates[i].lable = dlg.inputLable;
						clocktype = dlg.clock_number;

						clockinfo temp;
						temp.gateIndex = i;

						if (dlg.checkClock == true) {
							switch (clocktype) {
							case HZTIMES_1:
								temp.clocktype = 100;
								//SetTimer(1,1000,NULL);
								//AfxMessageBox(_T("1"));
								break;
							case HZTIMES_10:
								temp.clocktype = 10;
								//SetTimer(1, 100, NULL);
								//AfxMessageBox(_T("10"));

								break;
							case HZTIMES_100:
								temp.clocktype = 1;
								//SetTimer(1, 10, NULL);
								//AfxMessageBox(_T("100"));
								break;
							}
							Clocks.Add(temp);
							SetTimer(1, 10, NULL);
						}
						else if (dlg.checkClock == false) {
							//���� Ŭ�� ��� ����
							for (int j = 0; j < Clocks.GetSize(); j++) {
								if (Clocks[j].gateIndex == i)
									Clocks.RemoveAt(j);
							}
							//KillTimer(1);
						}
						//Invalidate();
					}
					else if (result == IDCANCEL) {
						Gates[i].lable = _T("");
						//Invalidate();
					}
				}
				else {

					CInfoDialog dlg = new CInfoDialog;

					//��ȭ ���ڷ� ���� �ʱ�ȭ
					dlg.lable = Gates[i].lable;
			
					int result = dlg.DoModal();
					if (result == IDOK) {
						Gates[i].lable = dlg.lable;
						view_rote = dlg.rote;
						Gates[i].rota = dlg.rote;

						//Invalidate();
					}
					else if (result == IDCANCEL) {
						Gates[i].lable = _T("");
						//Invalidate();
					}



					Invalidate();

					CView::OnRButtonDown(nFlags, point);
				}
			}
	}
}

void CWinProg3_testView::OnMouseMove(UINT nFlags, CPoint point)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	CClientDC dc(this);
	CPen pen;
	
	pen.CreatePen(PS_SOLID, 10, RGB(255, 255, 0));

	dc.SelectObject(pen);
	//drawline == FALSE;
	

	/*
	if((typeOfGate == LINESHAPE) && (drawline == true)){
		if ((nFlags&&MK_LBUTTON) == MK_LBUTTON)
		{
			
			dc.MoveTo(start_x, start_y);
			dc.LineTo(point.x, point.y);
			Invalidate();
		}
	}*/

	if ((typeOfGate == LINESHAPE) && (drawline == true)) {
	if ((nFlags&&MK_LBUTTON) == MK_LBUTTON)
	{

			end_point = point;
			CClientDC dc(this);

			CPen Pen, WPen, *oldPen;
			WPen.CreatePen(PS_SOLID, 2, RGB(255, 255, 255));//����� ���� �����.
			Pen.CreatePen(PS_SOLID, 2, RGB(255, 5, 5));//�˻��� ���� �����.
			oldPen = dc.SelectObject(&WPen);//old�� �־��ش�.
			dc.MoveTo(start_point.x, start_point.y);
			dc.LineTo(old_end_point.x, old_end_point.y);
			dc.SelectObject(oldPen);//����ġ�� ���� ���´�. 
			Pen.DeleteObject(); //���� ���� �Ѵ�. 
			oldPen = dc.SelectObject(&Pen);//old�� �ݵ�� �־��ش�.
			dc.MoveTo(start_point.x, start_point.y);
			dc.LineTo(end_point.x, end_point.y);
			dc.SelectObject(oldPen);//����ġ�� ���� ���´�. 
			Pen.DeleteObject(); //���� ���� �Ѵ�. 
			old_end_point = end_point;
		}
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

	Line* tempL = new Line(TRUE, 1, 1, start_point, end_point);

	end_point = point;

	for (int j = 0; j < Gates.GetSize(); j++) {
		if ((end_point.x >= (Gates[j].x - 50)) && (end_point.x <= (Gates[j].x + 50)))
			if ((end_point.y >= (Gates[j].y + Gates[j].height / 2 - 10)) && (end_point.y <= (Gates[j].y + Gates[j].height / 2 + 10))) {
				to = j;

				tempL->Drawline = drawline;
				tempL->Finish = finish;
				tempL->startGateIndex = from;
				tempL->BoolValue = Gates[from].outputArray[0];
				tempL->endGateIndex = to;
				Lines.Add(*tempL);

				Gates[to].inputArray[0] = Gates[from].outputArray[0];
				AfxMessageBox(Gates[to].lable);

				if ((Gates[to].GateId == OUTPUTFALSE) || (Gates[to].GateId == OUTPUTTRUE)) {
					if (Gates[to].inputArray[0] == true)
						Gates[to].GateId = OUTPUTTRUE;
					else if (Gates[to].inputArray[0] == false)
						Gates[to].GateId = OUTPUTFALSE;
				}

				/*
				if (Gates[to].inputArrayIndex < Gates[to].fixedInputIndex)
					Gates[to].inputArray[Gates[to].inputArrayIndex++] = tempL->BoolValue;
				else
					AfxMessageBox(_T("�߸��� �� ȸ�� ���� �Է°� �Ҵ�"));
					*/
				

			}

		//���� ����ϴ� �κ�
		for (int k = 0; k < Lines.GetSize(); k++) {

		

			//Gate�� ��°� �Ҵ�
			/*
			if (Lines[k].startGateIndex == j) {
				if (Gates[j].outputArrayIndex < Gates[j].fixedOutputIndex)
					Lines[k].BoolValue = Gates[j].outputArray[Gates[j].outputArrayIndex++];
				else
					AfxMessageBox(_T("�߸��� �� ȸ�� ���� ��°� �Ҵ�"));
			}else
			*/
			//Gate�� �Է°� �Ҵ�
			if (Lines[k].endGateIndex == j) {
				
			}
		}
	}

	drawline = FALSE;
	Invalidate();
}


void CWinProg3_testView::OnLine()
{
	typeOfGate = LINESHAPE;

}

void CWinProg3_testView::OnSevenSegment()
{
	typeOfGate = SEVENSEGMENT;
	CClientDC dc(this);
	OnDraw(&dc);
}


void CWinProg3_testView::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
	Rect r;
	for (int i = 0; i < Clocks.GetSize(); i++) {
		if(((Clocks[i].clocktime)++)%Clocks[i].clocktype== 0){
			if (Gates[Clocks[i].gateIndex].GateId == INPUTTRUE) {
				Gates[Clocks[i].gateIndex].GateId = INPUTFALSE;
				Gates[Clocks[i].gateIndex].outputArray[0] = false;
				//�ϰ� ���� 
				Gates[Clocks[i].gateIndex].edge = false;
			}
			else if (Gates[Clocks[i].gateIndex].GateId == INPUTFALSE) {
				Gates[Clocks[i].gateIndex].GateId = INPUTTRUE;
				Gates[Clocks[i].gateIndex].outputArray[0] = true;
				//��� ����
				Gates[Clocks[i].gateIndex].edge = true;
			}
		}
		r = { Gates[i].x,Gates[i].y,Gates[i].width,Gates[i].height };
		
		//InvalidateRect((LPRECT)&r, 1);
	}

	Invalidate();
	

	CView::OnTimer(nIDEvent);
}
