#pragma once


// InsertDlg dialog

class InsertDlg : public CDialogEx
{
	DECLARE_DYNAMIC(InsertDlg)

public:
	BOOL OnInitDialog();
	InsertDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~InsertDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_INSERT_PLANT };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	CEdit plantName;
	CMFCColorButton plantColor;
	CEdit plantGreeting;
	CMonthCalCtrl plantDate;
	CButton flowerOption;
	afx_msg void OnBnClickedFlowerOption();
	afx_msg void OnBnClickedColorFlowerOption();
	afx_msg void OnBnClickedGiftFlowerOption();
	afx_msg void OnBnClickedSpiceOption();
	CButton OK_btn;
	afx_msg void OnBnClickedOk();
	CButton colorFlowerOption;
	CButton giftFlowerOption;
	CButton spiceOption;
	CEdit plantQuantity;

	COleDateTime date;
	CString name;
	CString greeting;
	int quantity;
	int type;
};
