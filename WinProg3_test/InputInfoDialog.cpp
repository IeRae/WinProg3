// InputInfoDialog.cpp : 구현 파일입니다.
//

#include "stdafx.h"
#include "WinProg3_test.h"
#include "InputInfoDialog.h"
#include "afxdialogex.h"


// CInputInfoDialog 대화 상자입니다.

IMPLEMENT_DYNAMIC(CInputInfoDialog, CDialogEx)

CInputInfoDialog::CInputInfoDialog(CWnd* pParent /*=NULL*/)
	: CDialogEx(IDD_DIALOG2, pParent)
	, inputLable(_T(""))
	, checkClock(FALSE)
{
	InitCommonControls();
}

CInputInfoDialog::~CInputInfoDialog()
{
}

void CInputInfoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, clock_combo);
	DDX_Text(pDX, IDC_EDIT1, inputLable);
	DDX_Check(pDX, IDC_CHECK1, checkClock);
}


BEGIN_MESSAGE_MAP(CInputInfoDialog, CDialogEx)
	ON_BN_CLICKED(IDC_CHECK1, &CInputInfoDialog::OnBnClickedCheck1)
END_MESSAGE_MAP()


// CInputInfoDialog 메시지 처리기입니다.


BOOL CInputInfoDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  여기에 추가 초기화 작업을 추가합니다.
	
	


	CString hzmsg;
	hzmsg.Format(_T("1Hz"));
	clock_combo.InsertString(HZTIMES_1, hzmsg);
	hzmsg.Format(_T("10Hz"));
	clock_combo.InsertString(HZTIMES_10, hzmsg);
	hzmsg.Format(_T("100Hz"));
	clock_combo.InsertString(HZTIMES_100, hzmsg);

	clock_combo.SetCurSel(HZTIMES_1);

	clock_combo.IsWindowEnabled();

	
	return TRUE;  // return TRUE unless you set the focus to a control
				  // 예외: OCX 속성 페이지는 FALSE를 반환해야 합니다.
}


void CInputInfoDialog::OnOK()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	UpdateData(true);
	GetDlgItemText(IDC_EDIT1, inputLable);
	clock_number = clock_combo.GetCurSel();
	EndDialog(IDOK);
	CDialogEx::OnOK();
}


void CInputInfoDialog::OnCancel()
{
	// TODO: 여기에 특수화된 코드를 추가 및/또는 기본 클래스를 호출합니다.
	EndDialog(IDCANCEL);
	CDialogEx::OnCancel();
}


void CInputInfoDialog::OnBnClickedCheck1()
{
	// TODO: 여기에 컨트롤 알림 처리기 코드를 추가합니다.

	checkClock = IsDlgButtonChecked(IDC_CHECK1);

	//체크박스 상태에 따른 콤보박스 변화 설정
	if (checkClock) {
		GetDlgItem(IDC_COMBO1)->EnableWindow(true);
	}
	else
	{
		GetDlgItem(IDC_COMBO1)->EnableWindow(false);
	}
}
