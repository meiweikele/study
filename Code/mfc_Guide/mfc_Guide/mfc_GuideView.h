
// mfc_GuideView.h : Cmfc_GuideView 类的接口
//

#pragma once


class Cmfc_GuideView : public CView
{
protected: // 仅从序列化创建
	Cmfc_GuideView();
	DECLARE_DYNCREATE(Cmfc_GuideView)

// 特性
public:
	Cmfc_GuideDoc* GetDocument() const;

// 操作
public:

// 重写
public:
	virtual void OnDraw(CDC* pDC);  // 重写以绘制该视图
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// 实现
public:
	virtual ~Cmfc_GuideView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 生成的消息映射函数
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnPaint();
};

#ifndef _DEBUG  // mfc_GuideView.cpp 中的调试版本
inline Cmfc_GuideDoc* Cmfc_GuideView::GetDocument() const
   { return reinterpret_cast<Cmfc_GuideDoc*>(m_pDocument); }
#endif

