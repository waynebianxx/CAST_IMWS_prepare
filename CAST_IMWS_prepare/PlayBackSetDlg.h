#pragma once


// PlayBackSetDlg �Ի���

class PlayBackSetDlg : public CDialogEx
{
	DECLARE_DYNAMIC(PlayBackSetDlg)

public:
	PlayBackSetDlg(CWnd* pParent = NULL);   // ��׼���캯��
	virtual ~PlayBackSetDlg();

// �Ի�������
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG3 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV ֧��

	DECLARE_MESSAGE_MAP()
};
