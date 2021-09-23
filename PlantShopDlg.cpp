
// PlantShopDlg.cpp : implementation file
//

#include "pch.h"
#include <fstream>
#include <list>
#include <string>
#include "framework.h"
#include "PlantShop.h"
#include "BasePlant.h"
#include "FlowerPlant.h"
#include "SpicePlant.h"
#include "FlowerGift.h"
#include "FlowerColor.h"
#include "PlantShopDlg.h"
#include "afxdialogex.h"
using namespace std;

#ifdef _DEBUG
#define new DEBUG_NEW
#endif
#include "InsertDlg.h"
#include "DeleteDlg.h"
#include "SelectDlg.h"

CTypedPtrList <CObList, BasePlant*> listPlants;
POSITION pos;

class CAboutDlg : public CDialogEx {
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
END_MESSAGE_MAP()


// CPlantShopDlg dialog



CPlantShopDlg::CPlantShopDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_PLANTSHOP_DIALOG, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CPlantShopDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CPlantShopDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &CPlantShopDlg::OnBnClickedInsertBtn)
	ON_BN_CLICKED(IDC_ExportBtn, &CPlantShopDlg::OnBnClickedExportbtn)
	ON_BN_CLICKED(IDC_IMPORT_BTN, &CPlantShopDlg::OnBnClickedImportBtn)
	ON_BN_CLICKED(IDC_REMOVE_BTN, &CPlantShopDlg::OnBnClickedRemoveBtn)
	ON_BN_CLICKED(IDC_EDIT_BTN, &CPlantShopDlg::OnBnClickedEditBtn)
END_MESSAGE_MAP()


// CPlantShopDlg message handlers

BOOL CPlantShopDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon

	// TODO: Add extra initialization here

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CPlantShopDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CPlantShopDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting
		CDialogEx::OnPaint();
		draw(&dc);
		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CPaintDC dc(this);
		CDialogEx::OnPaint();
		draw(&dc);
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CPlantShopDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CPlantShopDlg::draw(CPaintDC* pDC) {
	CString num;
	int x = 30, y = 25, i = 0;
	int spacing = 60;

	pos = listPlants.GetHeadPosition();
	while (pos)	{
		num.Format(_T("%d"), ++i);

		y += spacing;
		BasePlant* iplant;

		iplant = listPlants.GetNext(pos);
		iplant->DrawNumber(pDC, x, y, num + _T("."));
		iplant->Draw(pDC, x + 25, y);
	}
}

void CPlantShopDlg::OnBnClickedInsertBtn() {
	InsertDlg insertDlg;
	if (insertDlg.DoModal() == IDOK) {
		pushNewPlant(insertDlg);
	}
	reDraw();
}


void CPlantShopDlg::OnBnClickedRemoveBtn()
{
	DeleteDlg deleteDlg;
	if (deleteDlg.DoModal() == IDOK) {
		if (deleteDlg.toDelete > listPlants.GetSize())
			AfxThrowInvalidArgException();
		else {
			pos = listPlants.FindIndex(deleteDlg.toDelete - 1);
			listPlants.RemoveAt(pos);
		}
	}
	reDraw();
}


void CPlantShopDlg::OnBnClickedExportbtn()
{
	ofstream myfile("PlantsSaveSize.txt");
	myfile << listPlants.GetSize();
	myfile.close();
	CFile file;

	file.Open(L"PlantsSave.hse", CFile::modeCreate | CFile::modeWrite);
	CArchive ar(&file, CArchive::store);

	listPlants.Serialize(ar);

	ar.Close();
	file.Close();
}


void CPlantShopDlg::OnBnClickedImportBtn(){
	int size;
	listPlants.RemoveAll();

	string line;
	ifstream myfile("PlantsSaveSize.txt");
	while (getline(myfile, line))
	{
		size = stoi(line);
	}

	CFile file;
	file.Open(L"PlantsSave.hse", CFile::modeRead);
	CArchive ar(&file, CArchive::load);
	int type;
	
	listPlants.Serialize(ar);

	ar.Close();
	file.Close();
	myfile.close();

	reDraw();
}


void CPlantShopDlg::OnBnClickedEditBtn(){
	SelectDlg selectDlg;
	if (selectDlg.DoModal() == IDOK) {
		if (selectDlg.toEdit > listPlants.GetSize())
			AfxThrowInvalidArgException();
		else {
			pos = listPlants.FindIndex(selectDlg.toEdit - 1);
			BasePlant *iplant = listPlants.GetAt(pos);
			InsertDlg insertDlg;

			insertDlg.type = iplant->GetType();
			insertDlg.name = iplant->GetName();
			insertDlg.greeting = iplant->GetGreeting();
			insertDlg.color = iplant->GetColor();
			insertDlg.quantity = iplant->GetQuantity();
			insertDlg.date = iplant->GetDate();

			if (insertDlg.DoModal() == IDOK) {
				pushNewPlant(insertDlg);

				pos = listPlants.FindIndex(selectDlg.toEdit - 1);
				listPlants.RemoveAt(pos);
			}
		}
	}
	reDraw();
}

void CPlantShopDlg::reDraw()
{
	CPaintDC dc(this);
	draw(&dc);
	Invalidate();
	UpdateWindow();
}

void CPlantShopDlg::pushNewPlant(InsertDlg& insertDlg) {
	switch (insertDlg.type) {
		case 1: {
			FlowerPlant* plant = new FlowerPlant(insertDlg.name, insertDlg.date.GetDay(), insertDlg.date.GetMonth(), insertDlg.date.GetYear());
			listPlants.AddTail(plant);
			break;
		}case 2: {
			FlowerColor* plant = new FlowerColor(insertDlg.name, insertDlg.date.GetDay(), insertDlg.date.GetMonth(), insertDlg.date.GetYear(), insertDlg.plantColor.GetColor());
			listPlants.AddTail(plant);
			break;
		}case 3: {
			FlowerGift* plant = new FlowerGift(insertDlg.name, insertDlg.date.GetDay(), insertDlg.date.GetMonth(), insertDlg.date.GetYear(), insertDlg.greeting);
			listPlants.AddTail(plant);
			break;
		}case 4: {
			SpicePlant* plant = new SpicePlant(insertDlg.name, insertDlg.plantColor.GetColor(), insertDlg.quantity);
			listPlants.AddTail(plant);
			break;
		}
	}
}