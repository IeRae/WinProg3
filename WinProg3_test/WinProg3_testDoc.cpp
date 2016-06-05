
// WinProg3_testDoc.cpp : CWinProg3_testDoc Ŭ������ ����
//

#include "stdafx.h"
// SHARED_HANDLERS�� �̸� ����, ����� �׸� �� �˻� ���� ó���⸦ �����ϴ� ATL ������Ʈ���� ������ �� ������
// �ش� ������Ʈ�� ���� �ڵ带 �����ϵ��� �� �ݴϴ�.
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


// CWinProg3_testDoc ����/�Ҹ�

CWinProg3_testDoc::CWinProg3_testDoc()
{
	// TODO: ���⿡ ��ȸ�� ���� �ڵ带 �߰��մϴ�.

}

CWinProg3_testDoc::~CWinProg3_testDoc()
{
}

BOOL CWinProg3_testDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: ���⿡ ���ʱ�ȭ �ڵ带 �߰��մϴ�.
	// SDI ������ �� ������ �ٽ� ����մϴ�.

	return TRUE;
}




// CWinProg3_testDoc serialization

void CWinProg3_testDoc::Serialize(CArchive& ar)
{

	CMainFrame* pFrame = (CMainFrame*)AfxGetMainWnd();

	CWinProg3_testView* pView = (CWinProg3_testView*)pFrame->GetActiveView();

	if (ar.IsStoring())
	{
		ar << pView->Lines.GetSize();
		if (true)	//��ü ������
		{
			Serialize(ar);	//����

		}
		//����Ʈ�� ����

		// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	}
	else
	{
		// TODO: ���⿡ �ε� �ڵ带 �߰��մϴ�.
	}
}

bool CWinProg3_testDoc::getLogic(Gate& Gates) {
	Logic LFunction;

	switch (Gates.GateId)
	{
	case ANDSHAPE:
		return LFunction.And_Operator(Gates.inputArray[0], Gates.inputArray[1]);
	case ORSHAPE:
		return LFunction.Or_Operator(Gates.inputArray[0], Gates.inputArray[1]);
	case NANDSHAPE:
		return LFunction.Nand_Operator(Gates.inputArray[0], Gates.inputArray[1]);
	case NOTSHAPE:
		return LFunction.Not_Operator(Gates.inputArray[0]);
	case NORSHAPE:
		return LFunction.Nor_Operator(Gates.inputArray[0], Gates.inputArray[1]);
	case XORSHAPE:
		return LFunction.Xor_Operator(Gates.inputArray[0], Gates.inputArray[1]);
	case INPUTTRUE:
		return true;
	case INPUTFALSE:
		return false;
	default:
		//AfxMessageBox(_T("error : not find gate number"));
		return false;
	}

	exit(1); 
}


void CWinProg3_testDoc::SevenSegment(bool& seg1, bool& seg2, bool& seg3, bool& seg4, bool& seg5, bool& seg6, bool& seg7, int& select)
{
		

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



	
}


bool CWinProg3_testDoc::test(int i) {
	if (i == 3) return true;
	else return false;
}

#ifdef SHARED_HANDLERS

// ����� �׸��� �����մϴ�.
void CWinProg3_testDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// ������ �����͸� �׸����� �� �ڵ带 �����Ͻʽÿ�.
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

// �˻� ó���⸦ �����մϴ�.
void CWinProg3_testDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// ������ �����Ϳ��� �˻� �������� �����մϴ�.
	// ������ �κ��� ";"�� ���еǾ�� �մϴ�.

	// ��: strSearchContent = _T("point;rectangle;circle;ole object;");
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

// CWinProg3_testDoc ����

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


// CWinProg3_testDoc ���
