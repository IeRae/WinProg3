
// WinProg3_testDoc.cpp : CWinProg3_testDoc 클래스의 구현
//

#include "stdafx.h"
// SHARED_HANDLERS는 미리 보기, 축소판 그림 및 검색 필터 처리기를 구현하는 ATL 프로젝트에서 정의할 수 있으며
// 해당 프로젝트와 문서 코드를 공유하도록 해 줍니다.
#ifndef SHARED_HANDLERS
#include "WinProg3_test.h"
#endif

#include "MainFrm.h"
#include "WinProg3_testDoc.h"
#include "WinProg3_testView.h"
#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CWinProg3_testDoc

IMPLEMENT_DYNCREATE(CWinProg3_testDoc, CDocument)

BEGIN_MESSAGE_MAP(CWinProg3_testDoc, CDocument)
END_MESSAGE_MAP()


// CWinProg3_testDoc 생성/소멸

CWinProg3_testDoc::CWinProg3_testDoc()
{
	// TODO: 여기에 일회성 생성 코드를 추가합니다.

}

CWinProg3_testDoc::~CWinProg3_testDoc()
{
}

BOOL CWinProg3_testDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: 여기에 재초기화 코드를 추가합니다.
	// SDI 문서는 이 문서를 다시 사용합니다.

	return TRUE;
}




// CWinProg3_testDoc serialization

void CWinProg3_testDoc::Serialize(CArchive& ar)
{

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();
	CWinProg3_testView* pView = (CWinProg3_testView*)pFrame->GetActiveView();
	if (ar.IsStoring())	//저장
	{
		/*
		int count_line;
		count_line = pView->Lines.GetCount();
		ar << count_line;
		for (int j = 0; j < count_line; j++) {

			CArray<Line, Line&> Lines2;	//논리 회로 선 객체 리스트
			//Line* tempL = new Line(TRUE, 1, 1, 0, 0);		
			//Lines2 = pView->Lines;
			Lines2.Serialize(ar);
			
		//	Lines.Add(*tempL);

			pView->Lines.ElementAt(j);
		}
		int count_gate;
		count_gate = pView->Lines.GetCount();
		ar << count_gate;
		for (int i = 0; i < count_gate; i++) {
			pView->Gates.GetAt(i)->Serilaize(ar);
		}
		*/
		// TODO: 여기에 저장 코드를 추가합니다.
	}
	else //불러오기
	{ /*
		int count_line;
		int count_gate;
		ar >> count_line;
		for (int j = 0; j < count_line; j++) {
			ar >> pView->Lines.GetAt[j];
			Line* tempL = new Line(TRUE, 1, 1, 0, 0);
			tempL->Serialze(ar);


			Lines.Add(*tempL);

			pView->Lines.GetAt[j]->Serilaize(ar);
		}

		ar >> count_gate;
		ar << count_line;
		*/
		// TODO: 여기에 로딩 코드를 추가합니다.
	}
}

bool CWinProg3_testDoc::getLogic(Gate& Gates) {
	Logic LFunction;
	bool result;


	switch (Gates.GateId)
	{
	case ANDSHAPE:
		result =  LFunction.And_Operator(Gates.inputArray[0], Gates.inputArray[1]);
		break;
	case ORSHAPE:
		result = LFunction.Or_Operator(Gates.inputArray[0], Gates.inputArray[1]);
		break;
	case NANDSHAPE:
		result = LFunction.Nand_Operator(Gates.inputArray[0], Gates.inputArray[1]);
		break;
	case NOTSHAPE:
		result = LFunction.Not_Operator(Gates.inputArray[0]);
		break;
	case NORSHAPE:
		result =  LFunction.Nor_Operator(Gates.inputArray[0], Gates.inputArray[1]);
		break;
	case XORSHAPE:
		result =  LFunction.Xor_Operator(Gates.inputArray[0], Gates.inputArray[1]);
		break;
	case INPUTTRUE:
		result = true;
		break;
	case INPUTFALSE:
		result = false;
		break;
	case OUTPUTFALSE:
	case OUTPUTTRUE:
		result =  Gates.inputArray[0];
		break;
	case DFFSHAPE:
		result = LFunction.DFlipFlop_Operator(Gates.inputArray[0], Gates.inputArray[1]);
	case JKFFSHAPE:
		result = LFunction.JKFlipFlop_Opertor(Gates.inputArray[0], Gates.inputArray[1], Gates.inputArray[2]);
	case TFFSHAPE:
		result = LFunction.TFlipFlop_Opertor(Gates.inputArray[0], Gates.inputArray[1]);
		break;
	default:
		//AfxMessageBox(_T("error : not find gate number"));
		return false;
	}
	return result;

	exit(1);
}

void CWinProg3_testDoc::SevenSegment(bool& seg1, bool& seg2, bool& seg3, bool& seg4, bool& seg5, bool& seg6, bool& seg7, int& select)
{
	seg1 = seg2 = seg3 = seg4 = seg5 = seg6 = seg7 = false;
	switch (select)	//스위치문에 의해 세그먼트 결정
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

}


bool CWinProg3_testDoc::test(int i) {
	if (i == 3) return true;
	else return false;
}

#ifdef SHARED_HANDLERS

// 축소판 그림을 지원합니다.
void CWinProg3_testDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// 문서의 데이터를 그리려면 이 코드를 수정하십시오.
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// 검색 처리기를 지원합니다.
void CWinProg3_testDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// 문서의 데이터에서 검색 콘텐츠를 설정합니다.
	// 콘텐츠 부분은 ";"로 구분되어야 합니다.

	// 예: strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CWinProg3_testDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = NULL;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != NULL)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CWinProg3_testDoc 진단

#ifdef _DEBUG
void CWinProg3_testDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CWinProg3_testDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CWinProg3_testDoc 명령
