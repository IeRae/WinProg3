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
{

}

CInputInfoDialog::~CInputInfoDialog()
{
}

void CInputInfoDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_COMBO1, clock_combo);
	DDX_Text(pDX, IDC_EDIT1, inputLable);
}


BEGIN_MESSAGE_MAP(CInputInfoDialog, CDialogEx)
END_MESSAGE_MAP()


// CInputInfoDialog �޽��� ó�����Դϴ�.


BOOL CInputInfoDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

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
