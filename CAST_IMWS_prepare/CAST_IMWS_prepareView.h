
// CAST_IMWS_prepareView.h : CCAST_IMWS_prepareView ��Ľӿ�
//

#pragma once

class CCAST_IMWS_prepareView : public CScrollView
{
protected: // �������л�����
	CCAST_IMWS_prepareView();
	DECLARE_DYNCREATE(CCAST_IMWS_prepareView)

// ����
public:
	CCAST_IMWS_prepareDoc* GetDocument() const;

// ����
public:

// ��д
public:
	virtual void OnDraw(CDC* pDC);  // ��д�Ի��Ƹ���ͼ
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// ʵ��
public:
	virtual ~CCAST_IMWS_prepareView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// ���ɵ���Ϣӳ�亯��
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void ShowImg();
	afx_msg void OnGongenngLoad();

public:
	CImage img;
	CRect img_rect;

	afx_msg BOOL OnMouseWheel(UINT nFlags, short zDelta, CPoint pt);
	virtual void OnInitialUpdate();
	afx_msg void OnShowLoad();
	afx_msg void OnShowset();
	afx_msg void OnShowSpesec1();
	afx_msg void OnFindData();
	afx_msg void OnCmpHrzn();
	afx_msg void On32820();
};

#ifndef _DEBUG  // CAST_IMWS_prepareView.cpp �еĵ��԰汾
inline CCAST_IMWS_prepareDoc* CCAST_IMWS_prepareView::GetDocument() const
   { return reinterpret_cast<CCAST_IMWS_prepareDoc*>(m_pDocument); }
#endif

