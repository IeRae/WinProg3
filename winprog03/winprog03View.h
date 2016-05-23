
// winprog03View.h : Cwinprog03View 클래스의 인터페이스
//

#pragma once


class Cwinprog03View : public CView
{
protected: // serialization에서만 만들어집니다.
	Cwinprog03View();
	DECLARE_DYNCREATE(Cwinprog03View)

// 특성입니다.
public:
	Cwinprog03Doc* GetDocument() const;

// 작업입니다.
public:

// 재정의입니다.
public:
	virtual void OnDraw(CDC* pDC);  // 이 뷰를 그리기 위해 재정의되었습니다.
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// 구현입니다.
public:
	virtual ~Cwinprog03View();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// 생성된 메시지 맵 함수
protected:
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // winprog03View.cpp의 디버그 버전
inline Cwinprog03Doc* Cwinprog03View::GetDocument() const
   { return reinterpret_cast<Cwinprog03Doc*>(m_pDocument); }
#endif

