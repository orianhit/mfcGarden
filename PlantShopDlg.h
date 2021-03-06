
// PlantShopDlg.h : header file
//

#pragma once

#include "InsertDlg.h"


// CPlantShopDlg dialog
class CPlantShopDlg : public CDialogEx
{
// Construction
public:
	CPlantShopDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_PLANTSHOP_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	void draw(CPaintDC* pDC);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedInsertBtn();
	afx_msg void OnBnClickedExportbtn();
	afx_msg void OnBnClickedImportBtn();
	afx_msg void OnBnClickedRemoveBtn();
	afx_msg void OnBnClickedEditBtn();
	void reDraw();
	void pushNewPlant(InsertDlg& insertDlg);
};
