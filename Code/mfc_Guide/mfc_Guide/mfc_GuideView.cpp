
// mfc_GuideView.cpp : Cmfc_GuideView ���ʵ��
//

#include "stdafx.h"
// SHARED_HANDLERS ������ʵ��Ԥ��������ͼ������ɸѡ�������
// ATL ��Ŀ�н��ж��壬�����������Ŀ�����ĵ����롣
#ifndef SHARED_HANDLERS
#include "mfc_Guide.h"
#endif

#include "mfc_GuideDoc.h"
#include "mfc_GuideView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// Cmfc_GuideView

IMPLEMENT_DYNCREATE(Cmfc_GuideView, CView)

BEGIN_MESSAGE_MAP(Cmfc_GuideView, CView)
	// ��׼��ӡ����
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// Cmfc_GuideView ����/����

Cmfc_GuideView::Cmfc_GuideView()
{
	// TODO:  �ڴ˴���ӹ������

}

Cmfc_GuideView::~Cmfc_GuideView()
{
}

BOOL Cmfc_GuideView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  �ڴ˴�ͨ���޸�
	//  CREATESTRUCT cs ���޸Ĵ��������ʽ

	return CView::PreCreateWindow(cs);
}

// Cmfc_GuideView ����

void Cmfc_GuideView::OnDraw(CDC* pDC)
{
	Cmfc_GuideDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  �ڴ˴�Ϊ����������ӻ��ƴ���
	pDC->TextOutW(100, 100, TEXT("Ϊ�˲���"));

}


// Cmfc_GuideView ��ӡ

BOOL Cmfc_GuideView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// Ĭ��׼��
	return DoPreparePrinting(pInfo);
}

void Cmfc_GuideView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӷ���Ĵ�ӡǰ���еĳ�ʼ������
}

void Cmfc_GuideView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  ��Ӵ�ӡ����е��������
}


// Cmfc_GuideView ���

#ifdef _DEBUG
void Cmfc_GuideView::AssertValid() const
{
	CView::AssertValid();
}

void Cmfc_GuideView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cmfc_GuideDoc* Cmfc_GuideView::GetDocument() const // �ǵ��԰汾��������
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfc_GuideDoc)));
	return (Cmfc_GuideDoc*)m_pDocument;
}
#endif //_DEBUG


// Cmfc_GuideView ��Ϣ�������


void Cmfc_GuideView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  �ڴ������Ϣ�����������/�����Ĭ��ֵ

	CView::OnLButtonDown(nFlags, point);

	CString str;
	str.Format(TEXT("x = %d , y = %d"), point.x, point.y);
	MessageBox(str);
}

//������� OnDraw ��Ҫ����OnPaint�ˣ�ͬʱ���ڵĻ� OnPaint���OnDraw ���ǵ�
void Cmfc_GuideView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  �ڴ˴������Ϣ����������
	// ��Ϊ��ͼ��Ϣ���� CView::OnPaint()

	dc.TextOutW(100, 100, TEXT("Ϊ������"));
}
