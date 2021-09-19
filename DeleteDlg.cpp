// DeleteDlg.cpp : implementation file

#include "pch.h"
#include "PlantShop.h"
#include "DeleteDlg.h"
#include "afxdialogex.h"


// DeleteDlg dialog

IMPLEMENT_DYNAMIC(DeleteDlg, CDialogEx)

DeleteDlg::DeleteDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DELETE_DIALOG, pParent) {
	toDelete = -1;
}

DeleteDlg::~DeleteDlg(){}

void DeleteDlg::DoDataExchange(CDataExchange* pDX){
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_PLANT_NUM_INPUT, toDeleteInput);
}


BEGIN_MESSAGE_MAP(DeleteDlg, CDialogEx)
	ON_EN_CHANGE(IDC_PLANT_NUM_INPUT, &DeleteDlg::OnEnChangePlantNumInput)
END_MESSAGE_MAP()

void DeleteDlg::OnEnChangePlantNumInput(){
	CString toDeleteTxt;
	toDeleteInput.GetWindowText(toDeleteTxt);
	toDelete = _ttoi(toDeleteTxt);
	CWnd* okbtn = GetDlgItem(IDOK);
	if (toDeleteTxt.IsEmpty()) okbtn->EnableWindow(FALSE);
	else okbtn->EnableWindow(TRUE);

	toDelete = _ttoi(toDeleteTxt);
}
