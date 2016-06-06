// InputInfoDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "WinProg3_test.h"
#include "InputInfoDialog.h"
#include "afxdialogex.h"


// CInputInfoDialog ��ȭ �����Դϴ�.

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


// CInputInfoDialog �޽��� ó�����Դϴ�.


BOOL CInputInfoDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.
	
	


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
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CInputInfoDialog::OnOK()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	UpdateData(true);
	GetDlgItemText(IDC_EDIT1, inputLable);
	clock_number = clock_combo.GetCurSel();
	EndDialog(IDOK);
	CDialogEx::OnOK();
}


void CInputInfoDialog::OnCancel()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	EndDialog(IDCANCEL);
	CDialogEx::OnCancel();
}


void CInputInfoDialog::OnBnClickedCheck1()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.

	checkClock = IsDlgButtonChecked(IDC_CHECK1);

	//üũ�ڽ� ���¿� ���� �޺��ڽ� ��ȭ ����
	if (checkClock) {
		GetDlgItem(IDC_COMBO1)->EnableWindow(true);
	}
	else
	{
		GetDlgItem(IDC_COMBO1)->EnableWindow(false);
	}
}
