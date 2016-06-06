
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
	ON_WM_RBUTTONDOWN()
	ON_WM_MOUSEMOVE()
	ON_WM_LBUTTONUP()
	ON_WM_TIMER()
	//ON_BN_CLICKED(IDC_BUTTON1, &CWinProg3_testView::OnBnClickedButton1)
	ON_COMMAND(ID_SET_LIB, &CWinProg3_testView::OnSetLib)
	ON_COMMAND(ID_TFF, &CWinProg3_testView::OnTff)
	ON_WM_LBUTTONDBLCLK()
	ON_COMMAND(ID_JKFF, &CWinProg3_testView::OnJkff)
	ON_COMMAND(ID_DFF, &CWinProg3_testView::OnDff)
	ON_COMMAND(ID_BRANCH, &CWinProg3_testView::OnBranch)
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

void CWinProg3_testView::loadBitmap(CBitmap& bit, BITMAP& bminfo, BagicGateType bmindex) {
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
	case TFFSHAPE:
		bit.LoadBitmapW(IDB_TFF); //tff 
		break;
	case DFFSHAPE:
		bit.LoadBitmapW(IDB_DFF); 
		break;
	case JKFFSHAPE:
		bit.LoadBitmapW(IDB_JKFF); 
		break;
	case LINEBRANCH:
		bit.LoadBitmapW(IDB_BRANCH_LINE);
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
		//Gate의 입력값 할당
		for (int i = 0; i < Gates.GetSize(); i++) {
			//pDoc->getLogic(Gates[i]);
			bool a[5];
			int ai = 0;
			for (int j = 0; j < Lines.GetSize(); j++) {
				if(i == Lines[j].endGateIndex){
					a[ai] = Lines[j].BoolValue;
					ai++;
				}
			}
			Gates[i].addInputArray(a, ai);
			
		}
		
		//gate의 출력값을 line에 할당
		for (int i = 0; i < Gates.GetSize(); i++) {
			for (int j = 0; j < Lines.GetSize(); j++) {
				if (i == Lines[j].startGateIndex) {
					Lines[j].BoolValue = pDoc->getLogic(Gates[i]);
				}
			}
		}
		
		CDC dcmem;
		dcmem.CreateCompatibleDC(&(*pDC));
		

		//논리 게이트를 그려주는 부분
		if (start_x != 0) {
			for (int i = 0; i < Gates.GetSize(); i++) {
				CBitmap bitmap;
				BITMAP bminfo;

				if ((Gates[i].GateId != LINESHAPE) || (Gates[i].GateId != NONE)) {


					//output 게이트의 정보 확인
					if ((Gates[i].GateId == OUTPUTFALSE) || (Gates[i].GateId == OUTPUTTRUE)) {
						if (Gates[i].inputArray[0] == true)
							Gates[i].GateId = OUTPUTTRUE;
						else if (Gates[i].inputArray[0] == false)
							Gates[i].GateId = OUTPUTFALSE;
					}

					loadBitmap(bitmap, bminfo, Gates[i].GateId);

					Bitmap *pBitmap3;
					pBitmap3 = Bitmap::FromHBITMAP((HBITMAP)bitmap.m_hObject, NULL);
					switch (Gates[i].rotate)
					{
					case 1:
						break;
					case 2:
						pBitmap3->RotateFlip(Rotate180FlipNone);
						break;
					case 3:
						pBitmap3->RotateFlip(Rotate90FlipNone);
						break;
					case 4:
						pBitmap3->RotateFlip(Rotate90FlipY);
						break;

					}
					/*
					if (Gates[i].rotate > 0)	//회전할시 라인 초기화
					{
						for (int i = 0; i < Gates.GetSize(); i++) {
							for (int j = 0; j < Lines.GetSize(); j++) {
								if (i == Lines[j].startGateIndex) {
									Lines[j].Drawline = false;
								}
							}
						}
					}*/

					dcmem.SelectObject(&bitmap);
					Graphics graphicsMem(dcmem.GetSafeHdc());
					graphicsMem.DrawImage(pBitmap3, 0, 0); //CBitmap 변수에 Bitmap 이미지를 그리기
					delete pBitmap3; 


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
				if (DrawSeg == true) {  //7세그먼트 그리기
					time[0] = 0;
					//펜 설정
					CPen pen(PS_SOLID, 1, RGB(200, 200, 200));
					CBrush red = (RGB(255, 0, 0));
					CBrush white = (RGB(255, 255, 255));
					time[0] = 0;
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
			}
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

/*
void CWinProg3_testView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	

	//if (typeOfGate != LINESHAPE) {
		//CString msg;

	start_x = point.x;
	start_y = point.y;
	
	if ((typeOfGate != LINESHAPE) && (typeOfGate != NONE)) {
		Gate* temp = new Gate(typeOfGate, start_x, start_y);

		if (typeOfGate == OUTPUTTRUE)
			temp->inputArray[0] = true;

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
	}
	else if (typeOfGate == SEVENSEGMENT) {
		start_x2 = point.x;
		start_y2 = point.y;
	}
	else if (typeOfGate == NONE) {
		for (int i = 0; i < Gates.GetSize(); i++) {

			if ((point.x >= Gates[i].x) && (point.x <= (Gates[i].x + Gates[i].width))) {
				if ((point.y >= Gates[i].y) && (point.y <= (Gates[i].y + Gates[i].height))) {
					if (Gates[i].GateId == INPUTTRUE) {
						Gates[i].GateId = INPUTFALSE;
						Gates[i].outputArray[0] = false;
						Gates[i].inputArray[0] = false;
					}
					else if (Gates[i].GateId == INPUTFALSE) {
						Gates[i].GateId = INPUTTRUE;
						Gates[i].outputArray[0] = true;
						Gates[i].inputArray[0] = true;
					}
				}
			}
		}
	}
		
	typeOfGate = NONE;
	Invalidate();
		

		CView::OnLButtonDown(nFlags, point);
}
*/



void CWinProg3_testView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.



	//if (typeOfGate != LINESHAPE) {
	//CString msg;

	start_x = point.x;
	start_y = point.y;

	if ((typeOfGate != LINESHAPE) && (typeOfGate != NONE) && typeOfGate != SEVENSEGMENT) {
		Gate* temp = new Gate(typeOfGate, start_x, start_y);

		if (typeOfGate == OUTPUTTRUE)
			temp->inputArray[0] = true;

		Gates.Add(*temp);
		typeOfGate = NONE;

	}
	else if (typeOfGate == SEVENSEGMENT) {
		start_x2 = point.x;
		start_y2 = point.y;


	}
	else if (typeOfGate == LINESHAPE && typeOfGate != SEVENSEGMENT) {
		CClientDC dc(this);

		drawline = FALSE;

		//AfxMessageBox(_T("진입"));
		//old_end_point = start_point;
		for (int i = 0; i < Gates.GetSize(); i++) {
			//AfxMessageBox(_T("탐색"));
			if ((point.x >= (Gates[i].x + Gates[i].width - 50)) && (point.x <= (Gates[i].x + Gates[i].width + 50))) {
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
	}
	else if (typeOfGate == NONE && typeOfGate != SEVENSEGMENT) {
		for (int i = 0; i < Gates.GetSize(); i++) {

			if ((point.x >= Gates[i].x) && (point.x <= (Gates[i].x + Gates[i].width))) {
				if ((point.y >= Gates[i].y) && (point.y <= (Gates[i].y + Gates[i].height))) {
					if (Gates[i].GateId == INPUTTRUE) {
						Gates[i].GateId = INPUTFALSE;
						Gates[i].outputArray[0] = false;
						Gates[i].inputArray[0] = false;
					}
					else if (Gates[i].GateId == INPUTFALSE) {
						Gates[i].GateId = INPUTTRUE;
						Gates[i].outputArray[0] = true;
						Gates[i].inputArray[0] = true;
					}
				}
			}
		}
	}

	//typeOfGate = NONE;
	Invalidate();


	CView::OnLButtonDown(nFlags, point);
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


void CWinProg3_testView::OnRButtonDown(UINT nFlags, CPoint point)
{


	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.

	

	//각 게이트에 맞는 대화 상자 호출 및 라벨 설정
	for (int i = 0; i < Gates.GetSize(); i++) {

		if ((point.x >= Gates[i].x) && (point.x <= (Gates[i].x + Gates[i].width)))
			if ((point.y >= Gates[i].y) && (point.y <= (Gates[i].y + Gates[i].height))) {
				
				
				CString msg;
				msg.Format(_T("%d"), Gates[i].inputArray[0]);
				AfxMessageBox(msg);
				
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
						Gates[i].rotate = dlg.rote;
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
			WPen.CreatePen(PS_SOLID, 2, RGB(255, 255, 255));//g흰색 펜 만들기
			Pen.CreatePen(PS_SOLID, 2, RGB(255, 5, 5));//검정색 펜 생성
			oldPen = dc.SelectObject(&WPen);//oldPen에 흰색펜 할당
			dc.MoveTo(start_point.x, start_point.y);
			dc.LineTo(old_end_point.x, old_end_point.y);
			dc.SelectObject(oldPen);//펜 복구
			Pen.DeleteObject(); //팬을 제거 
			oldPen = dc.SelectObject(&Pen);//검정색펜 할당
			dc.MoveTo(start_point.x, start_point.y);
			dc.LineTo(end_point.x, end_point.y);
			dc.SelectObject(oldPen);//펜 복구 
			Pen.DeleteObject(); //팬을 제거 
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
	DrawSeg = true;
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
				//하강 엣지 트리거 설정
				Gates[Clocks[i].gateIndex].edge = false;
			}
			else if (Gates[Clocks[i].gateIndex].GateId == INPUTFALSE) {
				Gates[Clocks[i].gateIndex].GateId = INPUTTRUE;
				Gates[Clocks[i].gateIndex].outputArray[0] = true;
				//상승 엣지 트리거 설정
				Gates[Clocks[i].gateIndex].edge = true;
			}
		}
		r = { Gates[i].x,Gates[i].y,Gates[i].width,Gates[i].height };
		
		//InvalidateRect((LPRECT)&r, 1);
	}

	Invalidate();
	

	CView::OnTimer(nIDEvent);
}



void CWinProg3_testView::OnSetLib()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	m_pTracker = new CRectTracker;
	/*
	if (m_pTracker->TrackRubberBand(this, POINT, 0)) {
	
	}
	*/
	m_pTracker = new CRectTracker;
}


void CWinProg3_testView::OnTff()
{
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
	typeOfGate = TFFSHAPE;
}


void CWinProg3_testView::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	



	for (int i = 0; i < Gates.GetSize(); i++) {
		if ((point.x >= Gates[i].x) && (point.x <= (Gates[i].x + Gates[i].width)))
			if ((point.y >= Gates[i].y) && (point.y <= (Gates[i].y + Gates[i].height))) {
				if (Gates[i].GateId == OUTPUTTRUE || Gates[i].GateId == OUTPUTFALSE) {

					CGraphInfoDialog dlg = new CGraphInfoDialog;

					//대화 상자로 정보 초기화
					dlg.istrue = Gates[i].inputArray[0];
					int result = dlg.DoModal();
					
					if (result == IDOK) {
						//대화상자로 부터 정보를 받음


					}
					else if (result == IDCANCEL) {
						//Invalidate();
					}
				}
			}
	}

	CView::OnLButtonDblClk(nFlags, point);
}


void CWinProg3_testView::OnJkff()
{

	typeOfGate = JKFFSHAPE;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CWinProg3_testView::OnDff()
{
	typeOfGate = DFFSHAPE;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}


void CWinProg3_testView::OnBranch()
{
	typeOfGate = LINEBRANCH;
	// TODO: 여기에 명령 처리기 코드를 추가합니다.
}
