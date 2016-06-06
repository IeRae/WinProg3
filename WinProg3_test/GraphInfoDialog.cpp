// GraphInfoDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "WinProg3_test.h"
#include "GraphInfoDialog.h"
#include "afxdialogex.h"


// CGraphInfoDialog ��ȭ �����Դϴ�.

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


// CGraphInfoDialog �޽��� ó�����Դϴ�.


BOOL CGraphInfoDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();
	InitCommonControls();
	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	
	// ���Ƿν����� ��Ʈ���� ��ġ�� ���� ��������
	CRect rtGraph;
	GetDlgItem(IDC_GRAPH)->GetWindowRect(rtGraph);

	ScreenToClient(rtGraph);
	_rtGraph = new COScopeCtrl();      //cos,sin,tan 3���� �׷��� ����
	_rtGraph->Create(WS_VISIBLE | WS_CHILD, rtGraph, this, IDC_GRAPH);
	_rtGraph->SetRanges(-1, 2);
	_rtGraph->autofitYscale = true;
	_rtGraph->SetYUnits(_T("Value"));
	_rtGraph->SetXUnits(_T("Time"));
	_rtGraph->SetLegendLabel(_T("��"), 0);
	_rtGraph->SetPlotColor(RGB(255, 0, 0), 0);
	_rtGraph->InvalidateCtrl();

	// ���Ƿν����� ��Ʈ���� �׸��� ���� Ÿ�̸� �̺�Ʈ Ȱ��ȭ
	SetTimer(1000, 10, NULL);

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CGraphInfoDialog::OnTimer(UINT_PTR nIDEvent)
{
	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰� ��/�Ǵ� �⺻���� ȣ���մϴ�.
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

	// TODO: ���⿡ �޽��� ó���� �ڵ带 �߰��մϴ�.

	// ���Ƿν����� ��Ʈ�� ����
	delete _rtGraph;
}

void CGraphInfoDialog::passingbool(bool a){
	istrue = a;
}

