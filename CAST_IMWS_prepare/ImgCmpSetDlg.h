#pragma once


// ImgCmpSetDlg �Ի���

class ImgCmpSetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(ImgCmpSetDlg)

public:
	ImgCmpSetDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~ImgCmpSetDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG5 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
