
// WinProg3_testView.cpp : CWinProg3_testView 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
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

// CWinProg3_testView 생성/소멸

CWinProg3_testView::CWinProg3_testView()
{
	// TODO: 여기에 생성 코드를 추가합니다.
	//start_x = 0; start_y = 0;
	typeOfGate = NONE;
	//Gates.SetSize(100);
}

CWinProg3_testView::~CWinProg3_testView()
{
}

BOOL CWinProg3_testView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: CREATESTRUCT cs를 수정하여 여기에서
	//  Window 클래스 또는 스타일을 수정합니다.

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
	//AfxMessageBox(_T("분류"));
	bit.GetBitmap(&bminfo);
	//AfxMessageBox(_T("완료"));
}
// CWinProg3_testView 그리기

void CWinProg3_testView::OnDraw(CDC* pDC)
{
	CWinProg3_testDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 여기에 원시 데이터에 대한 그리기 코드를 추가합니다.

		
		//논리 회로 연산을 실행하는 부분
		for (int i = 0; i < Gates.GetSize(); i++) {
			//pDoc->getLogic(Gates[i]);
			Gates[i].outputArray[Gates[i].outputArrayIndex] = pDoc->getLogic(Gates[i]);
		}
		
		CDC dcmem;
		dcmem.CreateCompatibleDC(&(*pDC));
		

		//논리 게이트를 그려주는 부분
		if (start_x != 0) {
			for (int i = 0; i < Gates.GetSize(); i++) {
				CBitmap bitmap;
				BITMAP bminfo;

				if((Gates[i].GateId != LINESHAPE) || (Gates[i].GateId != NONE)){

					/*
					//output 게이트의 정보 확인
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
					//msg.Format(_T(" 불리언값 : %d "), rotate2);
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

							//	CBitmap memBitmap; //Bitmap을 받아서 그리게될 CBitmap입니다.
							//	bitmap.CreateCompatibleBitmap(&(*pDC), pBitmap3->GetWidth(), pBitmap3->GetHeight());
							//	memBitmap.CreateCompatibleBitmap(&(*pDC), pBitmap3->GetWidth(), pBitmap3->GetHeight());
							dcmem.SelectObject(&bitmap);
							Graphics graphicsMem(dcmem.GetSafeHdc());
							graphicsMem.DrawImage(pBitmap3, 0, 0); //CBitmap 변수에 Bitmap 이미지를 그려줍니다.
							delete pBitmap3; //기존에 pBitmap이 존재할 이유가 없으므로 delete 시킵니다.
					//	}
				

				//비트맵 크기를 지정하는 부분
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
		
		if (typeOfGate == SEVENSEGMENT && start_x != 0) {	//7세그먼트 그리기
			time[0] = 0;
			//펜 설정
			CPen pen(PS_SOLID, 1, RGB(200, 200, 200));
			CBrush red = (RGB(255, 0, 0));
			CBrush white = (RGB(255, 255, 255));
			time[0] = 0;
			//펜 설정
			int select;
			X = start_x2;
			//Y = 150;
			Y = start_y2;

			select = time[0];
			CPoint point_1[6] = { { X,Y },{ X + 10,Y - 5 },{ X + 40,Y - 5 },{ X + 50,Y },{ X + 40,Y + 5 },{ X + 10,Y + 5 } };	//7세그먼트 모양 좌표 그리기
			CPoint point_6[6] = { { X + 53,Y + 3 },{ X + 58,Y + 13 },{ X + 58,Y + 43 },{ X + 53,Y + 53 },{ X + 48,Y + 43 },{ X + 48,Y + 13 } };
			CPoint point_7[6] = { { X + 53,Y + 59 },{ X + 58, Y + 69 },{ X + 58,Y + 99 },{ X + 53,Y + 109 },{ X + 48,Y + 99 },{ X + 48,Y + 69 } };
			CPoint point_2[6] = { { X,Y + 112 },{ X + 10,Y + 107 },{ X + 40,Y + 107 },{ X + 50,Y + 112 },{ X + 40,Y + 117 },{ X + 10,Y + 117 } };
			CPoint point_5[6] = { { X - 3,Y + 59 },{ X + 3,Y + 69 },{ X + 3,Y + 99 },{ X - 3,Y + 109 },{ X - 8,Y + 99 },{ X - 8,Y + 69 } };
			CPoint point_4[6] = { { X - 3,Y + 3 },{ X + 3,Y + 13 },{ X + 3,Y + 43 },{ X - 3,Y + 53 },{ X - 8,Y + 43 },{ X - 8,Y + 13 } };
			CPoint point_3[6] = { { X,Y + 56 },{ X + 10,Y + 51 },{ X + 40,Y + 51 },{ X + 50,Y + 56 },{ X + 40,Y + 61 },{ X + 10,Y + 61 } };
			pDC->SelectObject(pen);

			//함수호출
			pDoc->SevenSegment(seg1, seg2, seg3, seg4, seg5, seg6, seg7, select);

			if (seg1) {	//각 세그먼트별 동작설정
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
		
		

	//라인생성
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
	




// CWinProg3_testView 진단

#ifdef _DEBUG
void CWinProg3_testView::AssertValid() const
{
	CView::AssertValid();
}

void CWinProg3_testView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CWinProg3_testDoc* CWinProg3_testView::GetDocument() const // 디버그되지 않은 버전은 인라인으로 지정됩니다.
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CWinProg3_testDoc)));
	return (CWinProg3_testDoc*)m_pDocument;
}
#endif //_DEBUG


// CWinProg3_testView 메시지 처리기


void CWinProg3_testView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

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
			
			//AfxMessageBox(_T("진입"));
		//old_end_point = start_point;
		for (int i = 0; i < Gates.GetSize(); i++) {
				//AfxMessageBox(_T("탐색"));
				if ((point.x >= (Gates[i].x + Gates[i].width - 50)) && (point.x <= (Gates[i].x + Gates[i].width + 50))){
					if ((point.y >= Gates[i].y + Gates[i].height / 2 - 10) && (point.y <= (Gates[i].y + Gates[i].height / 2 + 10))) {
						//AfxMessageBox(_T("in"));
					//	dc.MoveTo(point.x, point.y);	
						
						start_point = point;
						drawline = TRUE;
						from = i;
							//AfxMessageBox(_T("시작점 잘잡았네"));
					}
				}
		}
	}else if(typeOfGate == SEVENSEGMENT){
		drawSeg = TRUE; 
		start_x2 = point.x;
		start_y2 = point.y;


	}
		//AfxMessageBox(_T("시작점 종료"));
		Invalidate();
	
}




void CWinProg3_testView::OnAndGate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	typeOfGate = ANDSHAPE;
}

void CWinProg3_testView::OnOrGate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	typeOfGate = ORSHAPE;
}

void CWinProg3_testView::OnNotGate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	typeOfGate = NOTSHAPE;
}

void CWinProg3_testView::OnNandGate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	typeOfGate = NANDSHAPE;
}

void CWinProg3_testView::OnNorGate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	typeOfGate = NORSHAPE;
}


void CWinProg3_testView::OnXorGate()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	typeOfGate = XORSHAPE;
}


void CWinProg3_testView::OnOutputButton()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	typeOfGate = OUTPUTTRUE;
}
void CWinProg3_testView::OnBranch()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	typeOfGate = BRANCH;
}

void CWinProg3_testView::OnDFF()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	typeOfGate = DFLIPFLOP;
}



void CWinProg3_testView::OnRButtonDown(UINT nFlags, CPoint point)
{


	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	//각 게이트에 맞는 대화 상자 호출 및 라벨 설정
	for (int i = 0; i < Gates.GetSize(); i++) {

		if ((point.x >= Gates[i].x) && (point.x <= (Gates[i].x + Gates[i].width)))
			if ((point.y >= Gates[i].y) && (point.y <= (Gates[i].y + Gates[i].height))) {

				if ((Gates[i].GateId == OUTPUTTRUE) || (Gates[i].GateId == OUTPUTFALSE)) {
					CString msg;
					msg.Format(_T("%d"), Gates[i].outputArray[0]);
					AfxMessageBox(msg);
				}

				//입력 gate 일때 입력 대화 상자 호출
				if ((Gates[i].GateId == INPUTTRUE) || (Gates[i].GateId == INPUTFALSE)) {

					int clocktype;
					CInputInfoDialog dlg = new CInputInfoDialog;
					//대화 상자로 정보 초기화
					dlg.inputLable = Gates[i].lable;

					int result = dlg.DoModal();
					if (result == IDOK) {
						//대화상자로 부터 정보를 받음
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
							//개별 클럭 기능 수정
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

					//대화 상자로 정보 초기화
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
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
			WPen.CreatePen(PS_SOLID, 2, RGB(255, 255, 255));//녹색의 선을 만든다.
			Pen.CreatePen(PS_SOLID, 2, RGB(255, 5, 5));//검색의 선을 만든다.
			oldPen = dc.SelectObject(&WPen);//old에 넣어준다.
			dc.MoveTo(start_point.x, start_point.y);
			dc.LineTo(old_end_point.x, old_end_point.y);
			dc.SelectObject(oldPen);//원위치로 돌려 놓는다. 
			Pen.DeleteObject(); //팬을 제거 한다. 
			oldPen = dc.SelectObject(&Pen);//old에 반드시 넣어준다.
			dc.MoveTo(start_point.x, start_point.y);
			dc.LineTo(end_point.x, end_point.y);
			dc.SelectObject(oldPen);//원위치로 돌려 놓는다. 
			Pen.DeleteObject(); //팬을 제거 한다. 
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

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
					AfxMessageBox(_T("잘못된 논리 회로 연결 입력값 할당"));
					*/
				

			}

		//라벨을 출력하는 부분
		for (int k = 0; k < Lines.GetSize(); k++) {

		

			//Gate의 출력값 할당
			/*
			if (Lines[k].startGateIndex == j) {
				if (Gates[j].outputArrayIndex < Gates[j].fixedOutputIndex)
					Lines[k].BoolValue = Gates[j].outputArray[Gates[j].outputArrayIndex++];
				else
					AfxMessageBox(_T("잘못된 논리 회로 연결 출력값 할당"));
			}else
			*/
			//Gate의 입력값 할당
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
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	Rect r;
	for (int i = 0; i < Clocks.GetSize(); i++) {
		if(((Clocks[i].clocktime)++)%Clocks[i].clocktype== 0){
			if (Gates[Clocks[i].gateIndex].GateId == INPUTTRUE) {
				Gates[Clocks[i].gateIndex].GateId = INPUTFALSE;
				Gates[Clocks[i].gateIndex].outputArray[0] = false;
				//하강 엣지 
				Gates[Clocks[i].gateIndex].edge = false;
			}
			else if (Gates[Clocks[i].gateIndex].GateId == INPUTFALSE) {
				Gates[Clocks[i].gateIndex].GateId = INPUTTRUE;
				Gates[Clocks[i].gateIndex].outputArray[0] = true;
				//상승 엣지
				Gates[Clocks[i].gateIndex].edge = true;
			}
		}
		r = { Gates[i].x,Gates[i].y,Gates[i].width,Gates[i].height };
		
		//InvalidateRect((LPRECT)&r, 1);
	}

	Invalidate();
	

	CView::OnTimer(nIDEvent);
}
