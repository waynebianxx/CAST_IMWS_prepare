
// CAST_IMWS_prepareView.cpp : CCAST_IMWS_prepareView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
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

// CCAST_IMWS_prepareView ����/����

CCAST_IMWS_prepareView::CCAST_IMWS_prepareView()
{
	// TODO: �ڴ˴���ӹ������

}

CCAST_IMWS_prepareView::~CCAST_IMWS_prepareView()
{
}

BOOL CCAST_IMWS_prepareView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// CCAST_IMWS_prepareView ����

void CCAST_IMWS_prepareView::OnDraw(CDC* pDC)
{
	CCAST_IMWS_prepareDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO: �ڴ˴�Ϊ����������ӻ��ƴ���
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


// CCAST_IMWS_prepareView ���

#ifdef _DEBUG
void CCAST_IMWS_prepareView::AssertValid() const
{
	CView::AssertValid();
}

void CCAST_IMWS_prepareView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CCAST_IMWS_prepareDoc* CCAST_IMWS_prepareView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CCAST_IMWS_prepareDoc)));
	return (CCAST_IMWS_prepareDoc*)m_pDocument;
}
#endif //_DEBUG


// CCAST_IMWS_prepareView ��Ϣ�������


void CCAST_IMWS_prepareView::ShowImg()
{
	// TODO: �ڴ���������������
	float aa = 0;
	GetDlgItem(IDOK);
}


void CCAST_IMWS_prepareView::OnGongenngLoad()
{
	// TODO: �ڴ��������������� 
	CFileDialog dlg(TRUE, _T(".bmp"), _T("*.bmp"), OFN_HIDEREADONLY |
		OFN_OVERWRITEPROMPT, _T("JPEG�ļ�(*.JPEG)|*.JPEG|λͼ�ļ�(*.bmp)|*.bmp||"));
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
	// TODO: �ڴ������Ϣ�����������/�����Ĭ��ֵ
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

	// TODO: �ڴ����ר�ô����/����û���

	//��ʼ��������  
	CSize sizeTotal;
	// TODO: �������ͼ�ĺϼƴ�С  
	sizeTotal.cx = sizeTotal.cy = 10000;
	SetScrollSizes(MM_TEXT, sizeTotal);

	//���ó�ʼλ��  
	CRect re;
	GetClientRect(&re);
	this->SetScrollPos(SB_HORZ, 0);
	this->SetScrollPos(SB_VERT, 0);
}
