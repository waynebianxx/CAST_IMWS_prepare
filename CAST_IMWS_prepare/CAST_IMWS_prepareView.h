
// CAST_IMWS_prepareView.h : CCAST_IMWS_prepareView 类的接口
//

#pragma once

class CCAST_IMWS_prepareView : public CScrollView
{
protected: // 仅从序列化创建
	CCAST_IMWS_prepareView();
	DECLARE_DYNCREATE(CCAST_IMWS_prepareView)

// 特性
public:
	CCAST_IMWS_prepareDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 实现
public:
	virtual ~CCAST_IMWS_prepareView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
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

#ifndef _DEBUG  // CAST_IMWS_prepareView.cpp 中的调试版本
inline CCAST_IMWS_prepareDoc* CCAST_IMWS_prepareView::GetDocument() const
   { return reinterpret_cast<CCAST_IMWS_prepareDoc*>(m_pDocument); }
#endif

