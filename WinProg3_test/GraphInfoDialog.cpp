// GraphInfoDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "WinProg3_test.h"
#include "GraphInfoDialog.h"
#include "afxdialogex.h"


// CGraphInfoDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(CGraphInfoDialog, CDialogEx)

CGraphInfoDialog::CGraphInfoDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG3, pParent)
{

}

CGraphInfoDialog::~CGraphInfoDialog()
{
}

void CGraphInfoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


BEGIN_MESSAGE_MAP(CGraphInfoDialog, CDialogEx)
	ON_WM_TIMER()
	ON_WM_DESTROY()
END_MESSAGE_MAP()


// CGraphInfoDialog 메시지 처리기입니다.


BOOL CGraphInfoDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	InitCommonControls();
	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
	// 오실로스코프 컨트롤이 위치할 영역 가져오기
	CRect rtGraph;
	GetDlgItem(IDC_GRAPH)->GetWindowRect(rtGraph);

	ScreenToClient(rtGraph);
	_rtGraph = new COScopeCtrl();      //cos,sin,tan 3개의 그래프 예약
	_rtGraph->Create(WS_VISIBLE | WS_CHILD, rtGraph, this, IDC_GRAPH);
	_rtGraph->SetRanges(-1, 2);
	_rtGraph->autofitYscale = true;
	_rtGraph->SetYUnits(_T("Value"));
	_rtGraph->SetXUnits(_T("Time"));
	_rtGraph->SetLegendLabel(_T("라벨"), 0);
	_rtGraph->SetPlotColor(RGB(255, 0, 0), 0);
	_rtGraph->InvalidateCtrl();

	// 오실로스코프 컨트롤을 그리기 위한 타이머 이벤트 활성화
	SetTimer(1000, 10, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CGraphInfoDialog::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: 여기에 메시지 처리기 코드를 추가 및/또는 기본값을 호출합니다.
	if (nIDEvent == 1000) {

		
		UpdateData(false);
		
		if(istrue == true){
			double value[2] = { 1, };
			_rtGraph->AppendPoints(value);
		}
		else{
			double value[2] = { 0, };
			_rtGraph->AppendPoints(value);
		}

		
		
	}

	CDialogEx::OnTimer(nIDEvent);
}


void CGraphInfoDialog::OnDestroy()
{
	CDialogEx::OnDestroy();

	// TODO: 여기에 메시지 처리기 코드를 추가합니다.

	// 오실로스코프 컨트롤 삭제
	delete _rtGraph;
}

void CGraphInfoDialog::passingbool(bool a){
	istrue = a;
}

