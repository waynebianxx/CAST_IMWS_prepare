#pragma once


// InnerFactTestSetDlg �Ի���

class InnerFactTestSetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(InnerFactTestSetDlg)

public:
	InnerFactTestSetDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~InnerFactTestSetDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG6 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
