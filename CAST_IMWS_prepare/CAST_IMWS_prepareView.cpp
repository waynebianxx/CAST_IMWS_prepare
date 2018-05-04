
// CAST_IMWS_prepareView.cpp : CCAST_IMWS_prepareView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
#ifndef SHARED_HANDLERS
#include "CAST_IMWS_prepare.h"
#endif

#include "CAST_IMWS_prepareDoc.h"
#include "CAST_IMWS_prepareView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CCAST_IMWS_prepareView

IMPLEMENT_DYNCREATE(CCAST_IMWS_prepareView, CView)

BEGIN_MESSAGE_MAP(CCAST_IMWS_prepareView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_COMMAND(ID_32774, &CCAST_IMWS_prepareView::ShowImg)
	ON_COMMAND(ID_GONGENNG_LOAD, &CCAST_IMWS_prepareView::OnGongenngLoad)
	ON_WM_MOUSEWHEEL()
END_MESSAGE_MAP()

// CCAST_IMWS_prepareView 构造/析构

CCAST_IMWS_prepareView::CCAST_IMWS_prepareView()
{
	// TODO: 在此处添加构造代码

}

CCAST_IMWS_prepareView::~CCAST_IMWS_prepareView()
{
}

BOOL CCAST_IMWS_prepareView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: 在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// CCAST_IMWS_prepareView 绘制

void CCAST_IMWS_prepareView::OnDraw(CDC* pDC)
{
	CCAST_IMWS_prepareDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: 在此处为本机数据添加绘制代码
	if (!img.IsNull())
		img.Draw(pDC->GetSafeHdc(),img_rect);
}

void CCAST_IMWS_prepareView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CCAST_IMWS_prepareView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CCAST_IMWS_prepareView 诊断

#ifdef _DEBUG
void CCAST_IMWS_prepareView::AssertValid() const
{
	CView::AssertValid();
}

void CCAST_IMWS_prepareView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCAST_IMWS_prepareDoc* CCAST_IMWS_prepareView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCAST_IMWS_prepareDoc)));
	return (CCAST_IMWS_prepareDoc*)m_pDocument;
}
#endif //_DEBUG


// CCAST_IMWS_prepareView 消息处理程序


void CCAST_IMWS_prepareView::ShowImg()
{
	// TODO: 在此添加命令处理程序代码
	float aa = 0;
	GetDlgItem(IDOK);
}


void CCAST_IMWS_prepareView::OnGongenngLoad()
{
	// TODO: 在此添加命令处理程序代码 
	CFileDialog dlg(TRUE, _T(".bmp"), _T("*.bmp"), OFN_HIDEREADONLY |
		OFN_OVERWRITEPROMPT, _T("JPEG文件(*.JPEG)|*.JPEG|位图文件(*.bmp)|*.bmp||"));
	if (dlg.DoModal() == IDOK)
	{
		if (!img.IsNull())
		{
			img.Destroy();
		}
		img.Load(dlg.GetPathName());
		img_rect.left = 0;
		img_rect.right = img_rect.left + img.GetWidth();
		img_rect.top = 0;
		img_rect.bottom = img_rect.top + img.GetHeight();
		Invalidate();
	}
}


BOOL CCAST_IMWS_prepareView::OnMouseWheel(UINT nFlags, short zDelta, CPoint pt)
{
	// TODO: 在此添加消息处理程序代码和/或调用默认值
	float w = img_rect.right, h = img_rect.bottom;
	float scale = 1.0f + zDelta / 120.0*0.1f;
	w = w*scale;
	h = h*scale;
	img_rect.right = w < 1.0f ? 1 : w;
	img_rect.bottom = h < 1.0f ? 1 : h;
	Invalidate();
	return CView::OnMouseWheel(nFlags, zDelta, pt);
}


void CCAST_IMWS_prepareView::OnInitialUpdate()
{
	CScrollView::OnInitialUpdate();

	// TODO: 在此添加专用代码和/或调用基类

	//初始化滚动条  
	CSize sizeTotal;
	// TODO: 计算此视图的合计大小  
	sizeTotal.cx = sizeTotal.cy = 10000;
	SetScrollSizes(MM_TEXT, sizeTotal);

	//设置初始位置  
	CRect re;
	GetClientRect(&re);
	this->SetScrollPos(SB_HORZ, 0);
	this->SetScrollPos(SB_VERT, 0);
}
