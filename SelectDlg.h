#pragma once


// SelectDlg dialog

class SelectDlg : public CDialogEx
{
	DECLARE_DYNAMIC(SelectDlg)

public:
	SelectDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~SelectDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_SELECT_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int toEdit;
	CEdit toEditInput;
	afx_msg void OnEnChangePlantNumInput();
};
