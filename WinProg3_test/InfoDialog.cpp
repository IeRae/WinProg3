// InfoDialog.cpp : ���� �����Դϴ�.
//

#include "stdafx.h"
#include "WinProg3_test.h"
#include "InfoDialog.h"
#include "afxdialogex.h"


// CInfoDialog ��ȭ �����Դϴ�.

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
END_MESSAGE_MAP()


// CInfoDialog �޽��� ó�����Դϴ�.


BOOL CInfoDialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// TODO:  ���⿡ �߰� �ʱ�ȭ �۾��� �߰��մϴ�.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // ����: OCX �Ӽ� �������� FALSE�� ��ȯ�ؾ� �մϴ�.
}


void CInfoDialog::OnBnClickedOk()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	UpdateData(true);

	CDialogEx::OnOK();
}


//void CInfoDialog::OnBnClickedCancel()
//{
//	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
//	CDialogEx::OnCancel();
//}


void CInfoDialog::OnOK()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	UpdateData(true);
	EndDialog(IDOK);

	//CDialogEx::OnOK();
}


void CInfoDialog::OnBnClickedCancel()
{
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
	CDialogEx::OnCancel();
}


void CInfoDialog::OnCancel()
{
	// TODO: ���⿡ Ư��ȭ�� �ڵ带 �߰� ��/�Ǵ� �⺻ Ŭ������ ȣ���մϴ�.
	EndDialog(IDCANCEL);
	//CDialogEx::OnCancel();
}
