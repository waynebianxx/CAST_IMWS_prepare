#pragma once


// ShowDlg �Ի���

class ShowDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ShowDlg)

public:
	ShowDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ShowDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
