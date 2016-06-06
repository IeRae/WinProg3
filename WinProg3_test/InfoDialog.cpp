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
ON_EN_CHANGE(IDC_EDIT1, &CInfoDialog::OnEnChangeEdit1)
ON_BN_CLICKED(IDC_BUTTON1, &CInfoDialog::OnBnClickedButton1)
ON_BN_CLICKED(IDC_BUTTON2, &CInfoDialog::OnBnClickedButton2)
ON_BN_CLICKED(IDC_BUTTON3, &CInfoDialog::OnBnClickedButton3)
ON_BN_CLICKED(IDC_BUTTON4, &CInfoDialog::OnBnClickedButton4)
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
	GetDlgItemText(IDC_EDIT1, lable);
	CDialogEx::OnCancel();
}


void CInfoDialog::OnEnChangeEdit1()
{
	// TODO:  RICHEDIT ��Ʈ���� ���, �� ��Ʈ����
	// CDialogEx::OnInitDialog() �Լ��� ������ 
	//�ϰ� ����ũ�� OR �����Ͽ� ������ ENM_CHANGE �÷��׸� �����Ͽ� CRichEditCtrl().SetEventMask()�� ȣ������ ������
	// �� �˸� �޽����� ������ �ʽ��ϴ�.

	// TODO:  ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CInfoDialog::OnBnClickedButton1()
{

	rote = 1;
	UpdateData(true);

	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CInfoDialog::OnBnClickedButton2()
{

	rote = 2;
	UpdateData(true);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CInfoDialog::OnBnClickedButton3()
{
	rote = 3;
	UpdateData(true);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}


void CInfoDialog::OnBnClickedButton4()
{
	rote = 4;
	UpdateData(true);
	// TODO: ���⿡ ��Ʈ�� �˸� ó���� �ڵ带 �߰��մϴ�.
}
