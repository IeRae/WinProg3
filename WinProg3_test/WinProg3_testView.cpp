
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
	ON_WM_RBUTTONDOWN()
END_MESSAGE_MAP()

// CWinProg3_testView ����/�Ҹ�

CWinProg3_testView::CWinProg3_testView()
{
	// TODO: ���⿡ ���� �ڵ带 �߰��մϴ�.
	//start_x = 0; start_y = 0;
	typeOfGate = 0;
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
	case OUTPUTTRUE:
		bit.LoadBitmapW(IDB_OUTPUT_TRUE);
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

	if(typeOfGate != 0){
		
		//�� ȸ�� ������ �����ϴ� �κ�
		for (int i = 0; i < Gates.GetSize(); i++) {
			CString msg;
			msg.Format(_T("true"));
			/*
			try{
			//if(pDoc->test(2))	AfxMessageBox(msg);
			//pDoc->getLogic(Gates[i]);
			}
			catch (int e) {
				AfxMessageBox(_T("error : pDoc"));
			}
			*/
			//pDoc->getLogic(Gates[i]);
			//Gates[i].outputArray[Gates[i].outputArrayIndex] = pDoc->getLogic(Gates[i]);
		}
		
		CDC dcmem;
		dcmem.CreateCompatibleDC(&(*pDC));
		

		//�� ����Ʈ�� �׷��ִ� �κ�
		if (start_x != 0) {
			for (int i = 0; i < Gates.GetSize(); i++) {
				CBitmap bitmap;
				BITMAP bminfo;

				loadBitmap(bitmap, bminfo, Gates[i].GateId);
				
				if(Gates[i].bmSizeFlag == false){
					Gates[i].setBmSize(bminfo.bmWidth, bminfo.bmHeight);
					Gates[i].bmSizeFlag = true;
				}
				

				dcmem.SelectObject(&bitmap);
				pDC->BitBlt(Gates[i].x, Gates[i].y, Gates[i].width, Gates[i].height, &dcmem, 0, 0, SRCCOPY);
				pDC->TextOut(Gates[i].x + 1, Gates[i].y + Gates[i].height + 5, Gates[i].lable);
				
				int index;
				for (int j = 0; j < Lines.GetSize(); j++) {
					
					
					//Gate�� �Է°� �Ҵ�
					index = Lines[j].endGateIndex;
					if (index == i) {
						if(Gates[i].inputArrayIndex < Gates[i].fixedInputIndex)
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
		
	}

	/*

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
				
				CInfoDialog dlg = new CInfoDialog;

				dlg.lable = Gates[i].lable;	//��ȭ ���ڷ� ���� �ʱ�ȭ

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

	

	
	//

	CView::OnRButtonDown(nFlags, point);
}
