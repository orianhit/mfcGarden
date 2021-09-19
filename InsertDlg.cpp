// InsertDlg.cpp : implementation file
//

#include "pch.h"
#include "PlantShop.h"
#include "InsertDlg.h"
#include "afxdialogex.h"
#include "BasePlant.h"
#include "FlowerPlant.h"
#include "SpicePlant.h"
#include "FlowerColor.h"
#include "FlowerGift.h"

static char* TypeOptions[4] = { "Flower", "Color Flower", "Gift Flower", "Spice" };


// InsertDlg dialog

IMPLEMENT_DYNAMIC(InsertDlg, CDialogEx)


BOOL InsertDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    if (quantity) {
        CString quantityTxt;
        quantityTxt.Format(_T("%d"), quantity);
        plantQuantity.SetWindowText(quantityTxt);
    }

    if (name) plantName.SetWindowText(name);
    else plantName.SetWindowText(_T("Your plant name"));

    switch (type) {
        case 1: {
            flowerOption.SetCheck(TRUE);
            OnBnClickedFlowerOption();
            break;
        }case 2: {
            flowerColorOption.SetCheck(TRUE);
            OnBnClickedFlowerColorOption();
            break;
        }case 3: {
            giftFlowerOption.SetCheck(TRUE);
            OnBnClickedGiftFlowerOption();
            break;
        }case 4: {
            spiceOption.SetCheck(TRUE);
            OnBnClickedSpiceOption();
            break;
        }
    }

    plantGreeting.SetWindowText(greeting);
    plantColor.SetColor(color);
    plantDate.SetCurSel(date);

    return TRUE;
}

InsertDlg::InsertDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_INSERT_PLANT, pParent){
}

InsertDlg::~InsertDlg()
{
}

void InsertDlg::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_PLANT_NAME, plantName);
    DDX_Control(pDX, IDC_PLANT_COLOR, plantColor);
    DDX_Control(pDX, IDC_GREETING, plantGreeting);
    DDX_Control(pDX, IDC_DATE, plantDate);
    DDX_Control(pDX, IDC_FLOWER_OPTION, flowerOption);
    DDX_Control(pDX, IDOK, OK_btn);
    DDX_Control(pDX, IDC_COLOR_FLOWER_OPTION, flowerColorOption);
    DDX_Control(pDX, IDC_GIFT_FLOWER_OPTION, giftFlowerOption);
    DDX_Control(pDX, IDC_SPICE_OPTION, spiceOption);
    DDX_Control(pDX, IDC_PLANT_QUANTITY, plantQuantity);
}


BEGIN_MESSAGE_MAP(InsertDlg, CDialogEx)
    ON_BN_CLICKED(IDC_FLOWER_OPTION, &InsertDlg::OnBnClickedFlowerOption)
    ON_BN_CLICKED(IDC_COLOR_FLOWER_OPTION, &InsertDlg::OnBnClickedFlowerColorOption)
    ON_BN_CLICKED(IDC_GIFT_FLOWER_OPTION, &InsertDlg::OnBnClickedGiftFlowerOption)
    ON_BN_CLICKED(IDC_SPICE_OPTION, &InsertDlg::OnBnClickedSpiceOption)
    ON_BN_CLICKED(IDOK, &InsertDlg::OnBnClickedOk)
END_MESSAGE_MAP()


void InsertDlg::OnBnClickedFlowerOption()
{
    plantColor.EnableWindow(FALSE);
    plantGreeting.EnableWindow(FALSE);
    plantQuantity.EnableWindow(FALSE);
    plantDate.EnableWindow(TRUE);

    OK_btn.EnableWindow(TRUE);
}


void InsertDlg::OnBnClickedFlowerColorOption()
{
    plantColor.EnableWindow(TRUE);
    plantGreeting.EnableWindow(FALSE);
    plantQuantity.EnableWindow(FALSE);
    plantDate.EnableWindow(TRUE);

    OK_btn.EnableWindow(TRUE);
}


void InsertDlg::OnBnClickedGiftFlowerOption()
{
    plantColor.EnableWindow(FALSE);
    plantGreeting.EnableWindow(TRUE);
    plantQuantity.EnableWindow(FALSE);
    plantDate.EnableWindow(TRUE);

    OK_btn.EnableWindow(TRUE);
}


void InsertDlg::OnBnClickedSpiceOption()
{
    plantColor.EnableWindow(TRUE);
    plantGreeting.EnableWindow(FALSE);
    plantQuantity.EnableWindow(TRUE);
    plantDate.EnableWindow(FALSE);

    OK_btn.EnableWindow(TRUE);
}


void InsertDlg::OnBnClickedOk()
{
    CString quantityTxt;
    color = plantColor.GetColor();
    plantDate.GetCurSel(date);
    plantName.GetWindowText(name);
    plantGreeting.GetWindowText(greeting);
    plantQuantity.GetWindowText(quantityTxt);
    quantity = _ttoi(quantityTxt);

    

    if (flowerOption.GetCheck()) {
        type = 1;
    } else if (flowerColorOption.GetCheck()) {
        type = 2;
    } else if (giftFlowerOption.GetCheck()) {
        type = 3;
    } else {
        type = 4;
    }
    CDialogEx::OnOK();
}
