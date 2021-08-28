#pragma once


// DeleteDlg dialog

class DeleteDlg : public CDialogEx
{
	DECLARE_DYNAMIC(DeleteDlg)

public:
	DeleteDlg(CWnd* pParent = nullptr);   // standard constructor
	virtual ~DeleteDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DELETE_DIALOG };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	DECLARE_MESSAGE_MAP()
public:
	int toDelete;
	afx_msg void OnEnChangePlantNumInput();
	CEdit toDeleteInput;
};
