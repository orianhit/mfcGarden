// InsertDlg.cpp : implementation file
//

#include "pch.h"
#include "PlantShop.h"
#include "InsertDlg.h"
#include "afxdialogex.h"
#include "AbstractPlant.h"
#include "FlowerPlant.h"
#include "SpicePlant.h"
#include "ColorFlower.h"
#include "FlowerGift.h"

static char* TypeOptions[4] = { "Flower", "Color Flower", "Gift Flower", "Spice" };


// InsertDlg dialog

IMPLEMENT_DYNAMIC(InsertDlg, CDialogEx)


BOOL InsertDlg::OnInitDialog()
{
    CDialog::OnInitDialog();

    OK_btn.EnableWindow(FALSE);
    plantName.SetWindowText(_T("Your plant name"));

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
    DDX_Control(pDX, IDC_COLOR_FLOWER_OPTION, colorFlowerOption);
    DDX_Control(pDX, IDC_GIFT_FLOWER_OPTION, giftFlowerOption);
    DDX_Control(pDX, IDC_SPICE_OPTION, spiceOption);
    DDX_Control(pDX, IDC_PLANT_QUANTITY, plantQuantity);
}


BEGIN_MESSAGE_MAP(InsertDlg, CDialogEx)
    ON_BN_CLICKED(IDC_FLOWER_OPTION, &InsertDlg::OnBnClickedFlowerOption)
    ON_BN_CLICKED(IDC_COLOR_FLOWER_OPTION, &InsertDlg::OnBnClickedColorFlowerOption)
    ON_BN_CLICKED(IDC_GIFT_FLOWER_OPTION, &InsertDlg::OnBnClickedGiftFlowerOption)
    ON_BN_CLICKED(IDC_SPICE_OPTION, &InsertDlg::OnBnClickedSpiceOption)
    ON_BN_CLICKED(IDOK, &InsertDlg::OnBnClickedOk)
END_MESSAGE_MAP()


void InsertDlg::OnBnClickedFlowerOption()
{
    plantColor.EnableWindow(FALSE);
    plantGreeting.EnableWindow(FALSE);
    plantQuantity.EnableWindow(FALSE);

    OK_btn.EnableWindow(TRUE);
}


void InsertDlg::OnBnClickedColorFlowerOption()
{
    plantColor.EnableWindow(TRUE);
    plantGreeting.EnableWindow(FALSE);
    plantQuantity.EnableWindow(FALSE);

    OK_btn.EnableWindow(TRUE);
}


void InsertDlg::OnBnClickedGiftFlowerOption()
{
    plantColor.EnableWindow(FALSE);
    plantGreeting.EnableWindow(TRUE);
    plantQuantity.EnableWindow(FALSE);

    OK_btn.EnableWindow(TRUE);
}


void InsertDlg::OnBnClickedSpiceOption()
{
    plantColor.EnableWindow(TRUE);
    plantGreeting.EnableWindow(FALSE);
    plantQuantity.EnableWindow(TRUE);

    OK_btn.EnableWindow(TRUE);
}


void InsertDlg::OnBnClickedOk()
{
    COleDateTime time;
    plantDate.GetCurSel(time);
    CString name;
    plantName.GetWindowText(name);
    CString greeting;
    plantGreeting.GetWindowText(greeting);
    CString quantityTxt;
    plantQuantity.GetWindowText(quantityTxt);
    int quantity = _ttoi(quantityTxt);
    

    if (flowerOption.GetCheck()) {
        AbstractPlant *fp = new FlowerPlant(name, time.GetDay(), time.GetMonth(), time.GetYear());
    } if (colorFlowerOption) {
        AbstractPlant* fp = new ColorFlower(name, time.GetDay(), time.GetMonth(), time.GetYear(), plantColor.GetColor());
    } if (giftFlowerOption) {
        AbstractPlant* fp = new FlowerGift(name, time.GetDay(), time.GetMonth(), time.GetYear(), greeting);
    } else {
        AbstractPlant* fp = new SpicePlant(name, plantColor.GetColor(), quantity);
    }
    CDialogEx::OnOK();
}
