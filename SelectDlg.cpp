// SelectDlg.cpp : implementation file
//

#include "pch.h"
#include "PlantShop.h"
#include "SelectDlg.h"
#include "afxdialogex.h"


// SelectDlg dialog

IMPLEMENT_DYNAMIC(SelectDlg, CDialogEx)

SelectDlg::SelectDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_SELECT_DIALOG, pParent)
{

}

SelectDlg::~SelectDlg()
{
}

void SelectDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PLANT_NUM_INPUT, toEditInput);
}


BEGIN_MESSAGE_MAP(SelectDlg, CDialogEx)
	ON_EN_CHANGE(IDC_PLANT_NUM_INPUT, &SelectDlg::OnEnChangePlantNumInput)
END_MESSAGE_MAP()


// SelectDlg message handlers


void SelectDlg::OnEnChangePlantNumInput()
{
	CString toEditTxt;
	toEditInput.GetWindowText(toEditTxt);
	toEdit = _ttoi(toEditTxt);
	CWnd* okbtn = GetDlgItem(IDOK);
	if (toEditTxt.IsEmpty()) okbtn->EnableWindow(FALSE);
	else okbtn->EnableWindow(TRUE);

	toEdit = _ttoi(toEditTxt);
}
