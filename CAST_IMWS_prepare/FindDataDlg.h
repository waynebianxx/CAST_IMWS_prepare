#pragma once


// FindDataDlg �Ի���

class FindDataDlg : public CDialogEx
{
	DECLARE_DYNAMIC(FindDataDlg)

public:
	FindDataDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~FindDataDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG4 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
