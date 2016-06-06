// InfoDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "WinProg3_test.h"
#include "InfoDialog.h"
#include "afxdialogex.h"


// CInfoDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(CInfoDialog, CDialogEx)

CInfoDialog::CInfoDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, lable(_T(""))
{

}

CInfoDialog::~CInfoDialog()
{
}

void CInfoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, lable);
}


BEGIN_MESSAGE_MAP(CInfoDialog, CDialogEx)
	ON_BN_CLICKED(IDOK, &CInfoDialog::OnBnClickedOk)
//	ON_BN_CLICKED(IDCANCEL, &CInfoDialog::OnBnClickedCancel)
ON_BN_CLICKED(IDCANCEL, &CInfoDialog::OnBnClickedCancel)
ON_EN_CHANGE(IDC_EDIT1, &CInfoDialog::OnEnChangeEdit1)
ON_BN_CLICKED(IDC_BUTTON1, &CInfoDialog::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON2, &CInfoDialog::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON3, &CInfoDialog::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON4, &CInfoDialog::OnBnClickedButton4)
END_MESSAGE_MAP()


// CInfoDialog 메시지 처리기입니다.


BOOL CInfoDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CInfoDialog::OnBnClickedOk()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	UpdateData(true);

	CDialogEx::OnOK();
}


//void CInfoDialog::OnBnClickedCancel()
//{
//	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
//	CDialogEx::OnCancel();
//}


void CInfoDialog::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	UpdateData(true);
	EndDialog(IDOK);

	//CDialogEx::OnOK();
}


void CInfoDialog::OnBnClickedCancel()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
	CDialogEx::OnCancel();
}


void CInfoDialog::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	EndDialog(IDCANCEL);
	GetDlgItemText(IDC_EDIT1, lable);
	CDialogEx::OnCancel();
}


void CInfoDialog::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT 컨트롤인 경우, 이 컨트롤은
	// CDialogEx::OnInitDialog() 함수를 재지정 
	//하고 마스크에 OR 연산하여 설정된 ENM_CHANGE 플래그를 지정하여 CRichEditCtrl().SetEventMask()를 호출하지 않으면
	// 이 알림 메시지를 보내지 않습니다.

	// TODO:  여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CInfoDialog::OnBnClickedButton1()
{

	rote = 1;
	UpdateData(true);

	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CInfoDialog::OnBnClickedButton2()
{

	rote = 2;
	UpdateData(true);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CInfoDialog::OnBnClickedButton3()
{
	rote = 3;
	UpdateData(true);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}


void CInfoDialog::OnBnClickedButton4()
{
	rote = 4;
	UpdateData(true);
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.
}
