
// mfc_GuideView.cpp : Cmfc_GuideView 类的实现
//

#include "stdafx.h"
// SHARED_HANDLERS 可以在实现预览、缩略图和搜索筛选器句柄的
// ATL 项目中进行定义，并允许与该项目共享文档代码。
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
	// 标准打印命令
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CView::OnFilePrintPreview)
	ON_WM_LBUTTONDOWN()
	ON_WM_PAINT()
END_MESSAGE_MAP()

// Cmfc_GuideView 构造/析构

Cmfc_GuideView::Cmfc_GuideView()
{
	// TODO:  在此处添加构造代码

}

Cmfc_GuideView::~Cmfc_GuideView()
{
}

BOOL Cmfc_GuideView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO:  在此处通过修改
	//  CREATESTRUCT cs 来修改窗口类或样式

	return CView::PreCreateWindow(cs);
}

// Cmfc_GuideView 绘制

void Cmfc_GuideView::OnDraw(CDC* pDC)
{
	Cmfc_GuideDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;

	// TODO:  在此处为本机数据添加绘制代码
	pDC->TextOutW(100, 100, TEXT("为了部落"));

}


// Cmfc_GuideView 打印

BOOL Cmfc_GuideView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// 默认准备
	return DoPreparePrinting(pInfo);
}

void Cmfc_GuideView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加额外的打印前进行的初始化过程
}

void Cmfc_GuideView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO:  添加打印后进行的清理过程
}


// Cmfc_GuideView 诊断

#ifdef _DEBUG
void Cmfc_GuideView::AssertValid() const
{
	CView::AssertValid();
}

void Cmfc_GuideView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

Cmfc_GuideDoc* Cmfc_GuideView::GetDocument() const // 非调试版本是内联的
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(Cmfc_GuideDoc)));
	return (Cmfc_GuideDoc*)m_pDocument;
}
#endif //_DEBUG


// Cmfc_GuideView 消息处理程序


void Cmfc_GuideView::OnLButtonDown(UINT nFlags, CPoint point)
{
	// TODO:  在此添加消息处理程序代码和/或调用默认值

	CView::OnLButtonDown(nFlags, point);

	CString str;
	str.Format(TEXT("x = %d , y = %d"), point.x, point.y);
	MessageBox(str);
}

//如果有了 OnDraw 不要再有OnPaint了，同时存在的话 OnPaint会把OnDraw 覆盖掉
void Cmfc_GuideView::OnPaint()
{
	CPaintDC dc(this); // device context for painting
	// TODO:  在此处添加消息处理程序代码
	// 不为绘图消息调用 CView::OnPaint()

	dc.TextOutW(100, 100, TEXT("为了联盟"));
}
